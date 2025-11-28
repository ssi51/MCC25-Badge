# 🎆 Village Night Welcome

This is the initial "Hello World" firmware for the MCC25 Badge. It demonstrates the badge's multitasking capabilities by running a smooth graphics animation and LED control simultaneously without blocking.

### 📋 Features
* **OLED Display**: Scrolls the message *"Welcome to MCC 25' Village Night!"* from right to left using the `GyverOLED` engine.
* **RGB LEDs**: Cycles through Red, Green, Blue, and Off states every second using `FastLED`.
* **Non-Blocking Core**: Uses `millis()` for timing, ensuring the display animation remains fluid while LEDs update independently.

### 📦 Required Libraries
To compile this sketch, install these libraries via the Arduino Library Manager:
1.  **GyverOLED** (by AlexGyver)
2.  **FastLED** (by Daniel Garcia)
