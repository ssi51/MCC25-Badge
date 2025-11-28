#include <GyverOLED.h>
#include <FastLED.h>

/* WS2812 LED setting */
#define LED_COUNT           4
#define LED_PIN             7
CRGB leds[LED_COUNT];

/* OLED display (SSD1306 I2C, 128x64) */
GyverOLED<SSD1306_128x64> oled;

/* ----------- SCROLLING ENGINE VARIABLES ----------- */
const char* scrollTextStr = "Welcome to MCC 25' Village Night!";
int scrollX;              // current X position
int textWidth;            // total text width in pixels
unsigned long lastScrollUpdate = 0;
int scrollSpeed = 3;
uint8_t textScale = 2;

/* -------------- INITIALIZE SCROLL ENGINE ---------- */
void initScroll() {
  oled.setScale(textScale);
  textWidth = strlen(scrollTextStr) * 6 * textScale;
  scrollX = 128;  // start off right side
}

/* -------------- NON-BLOCKING SCROLLER -------------- */
void scrollEngine() {
  if (millis() - lastScrollUpdate >= scrollSpeed) {
    lastScrollUpdate = millis();

    oled.clear();
    oled.setScale(textScale);
    oled.setCursor(scrollX, 2);
    oled.print(scrollTextStr);
    oled.update();

    scrollX--;  // move left

    if (scrollX < -textWidth) {
      scrollX = 128; // restart from right
    }
  }
}


/* -------------------------- SETUP -------------------------- */
void setup()
{
  /* Initialize LEDs */
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(50);

  /* OLED init */
  oled.init();
  oled.clear();

  initScroll();   // start scrolling engine
}


/* --------------------------- LOOP --------------------------- */
void loop()
{
  scrollEngine();   // scroll text smoothly (non-blocking)
  rgb_update();     // LED animations still work normally
}


/* ------------------------ LED EFFECTS ------------------------ */
void rgb_update()
{
  static uint8_t state = 0;
  static unsigned long last = 0;

  if (millis() - last < 1000) return;  // update LEDs every 1 sec
  last = millis();

  switch (state) {
    case 0: fill_solid(leds, LED_COUNT, CRGB(15,0,0)); break;
    case 1: fill_solid(leds, LED_COUNT, CRGB(0,15,0)); break;
    case 2: fill_solid(leds, LED_COUNT, CRGB(0,0,15)); break;
    case 3: fill_solid(leds, LED_COUNT, CRGB(0,0,0)); break;
  }

  FastLED.show();
  state = (state + 1) % 4;
}
