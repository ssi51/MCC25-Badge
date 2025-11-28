/*
 * Project: MCC25 Badge - Party Sync Mode (ESP-NOW)
 * Description: Peer-to-Peer LED synchronization.
 * * How to use:
 * - Load this code onto TWO or more badges.
 * - Press Button A on ANY badge.
 * - All badges in range will instantly change to the same color.
 */

#include <esp_now.h>
#include <WiFi.h>
#include <FastLED.h>
#include <GyverOLED.h>

// ================= HARDWARE CONFIG =================
#define BTN_A_PIN   10
#define LED_PIN     7
#define LED_COUNT   4

// ================= GLOBALS =================
CRGB leds[LED_COUNT];
GyverOLED<SSD1306_128x64> oled;

// Pre-defined colors to cycle through
CRGB colorList[] = {
  CRGB::Red, 
  CRGB::Blue, 
  CRGB::Green, 
  CRGB::Purple, 
  CRGB::Orange, 
  CRGB::Cyan,
  CRGB::Black // Off
};
int currentColorIndex = 0;
const int totalColors = 7;

// Structure of the data we send over the air
typedef struct struct_message {
  int colorIdx;
} struct_message;

struct_message myData;

// Broadcast address (sends to everyone)
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// Info needed for ESP-NOW peer
esp_now_peer_info_t peerInfo;

// ================= CALLBACKS =================

// Function called when data is SENT
void OnDataSent(const wifi_tx_info_t *info, esp_now_send_status_t status) {
  // Optional: flash a tiny indicator pixel on OLED
  oled.setCursor(0, 7);
  oled.print(status == ESP_NOW_SEND_SUCCESS ? "TX: OK  " : "TX: Fail");
  oled.update();
}

// Function called when data is RECEIVED
void OnDataRecv(const esp_now_recv_info_t * info, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  
  // Update local color to match the party!
  currentColorIndex = myData.colorIdx;
  updateLEDs(currentColorIndex);
  
  // Update Display
  oled.clear();
  oled.setScale(2);
  oled.setCursor(10, 2);
  oled.print("PARTY");
  oled.setCursor(20, 4);
  oled.print("SYNC!");
  
  oled.setScale(1);
  oled.setCursor(0, 7);
  oled.print("RX from: ");
  // Print last byte of sender MAC for debug
  oled.print(info->src_addr[5], HEX); 
  oled.update();
}

// ================= HELPER FUNCTIONS =================

void updateLEDs(int idx) {
  fill_solid(leds, LED_COUNT, colorList[idx]);
  FastLED.show();
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  
  // Init Hardware
  pinMode(BTN_A_PIN, INPUT_PULLUP);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(40); // Keep it low to save battery
  
  oled.init();
  oled.clear();
  oled.setScale(2);
  oled.setCursor(5, 3);
  oled.print("SYNC RDY");
  oled.update();

  // Init WiFi in Station Mode (Required for ESP-NOW)
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    oled.clear();
    oled.print("ESP-NOW FAIL");
    oled.update();
    return;
  }

  // Register Callbacks
  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);

  // Register Peer (The Broadcast Address)
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}

// ================= LOOP =================
void loop() {
  // Check Button A
  if (digitalRead(BTN_A_PIN) == LOW) {
    delay(50); // Debounce
    if (digitalRead(BTN_A_PIN) == LOW) {
      
      // 1. Change YOUR color locally
      currentColorIndex++;
      if (currentColorIndex >= totalColors) currentColorIndex = 0;
      updateLEDs(currentColorIndex);

      // 2. Prepare data to send
      myData.colorIdx = currentColorIndex;

      // 3. Send to EVERYONE via ESP-NOW
      esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
      
      // 4. Update Display
      oled.clear();
      oled.setScale(2);
      oled.setCursor(10, 2);
      oled.print("LEADER"); // You are the leader now
      oled.update();

      // Wait until button release so we don't spam commands
      while(digitalRead(BTN_A_PIN) == LOW); 
    }
  }
}