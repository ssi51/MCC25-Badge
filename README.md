# MCC25 Badge

![Badge Status](https://img.shields.io/badge/Status-Active-brightgreen) ![Platform](https://img.shields.io/badge/Platform-ESP32--C3-blue) ![License](https://img.shields.io/badge/License-MIT-green)

## 🦇 Introduction

Welcome to the official repository for the **MCC 25' Badge**, a custom electronic conference badge based on the open-source [Hackbat Badge](https://hackaday.io/project/197688-hackbat-badge).

**📡 Repository Updates & Future Code**
This repository is the central hub for the MCC 25' Badge ecosystem. **It will be regularly updated with new firmware, games, and example codes.** We encourage you to "Watch" or "Star" this repository to get notified when new features are available to upload to your badge.

## ✨ Features

* **Wireless Connectivity**: Integrated 2.4GHz WiFi and Bluetooth 5.0 (LE) via the ESP32-C3.
* **Crisp Display**: 1.3-inch OLED screen for menus, games, and status updates.
* **Interactive Controls**: 6-button interface (D-Pad + A/B buttons) designed for gaming and navigation.
* **RGB Lighting**: 4x Addressable WS2812 LEDs for visual notifications and light shows.
* **Portable Power**: Runs on USB-C or AA batteries with dedicated power management.
* **Open Development**: Compatible with Arduino IDE and Espressif ESP-IDF.

## 🛠 Hardware Specifications

| Component | Specification |
| :--- | :--- |
| **Microcontroller** | Espressif **ESP32-C3** (RISC-V Single-core @ 160MHz) |
| **Display** | 1.3" OLED (SH110x / SSD1306 compatible) |
| **Connectivity** | WiFi 802.11b/g/n + Bluetooth LE 5.0 |
| **User Input** | 6 Push Buttons (Up, Down, Left, Right, A, B) |
| **LEDs** | 4 x WS2812B Addressable RGB LEDs |
| **Dimensions** | 100mm x 60mm |
| **Power Input** | USB Micro or 3x AA Battery Holder (Back mounted) |

## 🚀 Getting Started

### Prerequisites

To program the MCC25 Badge, you will need to install the necessary drivers and boards.

1.  **Install Arduino IDE**: Download from the [official website](https://www.arduino.cc/en/software).
2.  **Add ESP32 Board Manager**:
    * Go to `File` > `Preferences`.
    * Add the following URL to "Additional Board Manager URLs":
        `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
    * Go to `Tools` > `Board` > `Boards Manager`, search for "ESP32", and install.

### Flashing Your First Sketch

1.  Select the board: `ESP32C3 Dev Module`.
2.  Ensure `USB CDC On Boot` is set to "Enable" if you are using the USB port for serial debugging.
3.  Connect your MCC25 Badge via USB-Micro.
4.  Select the correct Port under `Tools` > `Port`.
5.  Upload the example `Blink` or `DisplayTest` sketch from the `/examples` folder in this repo.

## 🔋 Powering the Badge

The MCC25 Badge can be powered in two ways:
1.  **USB Mode**: Connect a USB Micro cable for power and programming.
2.  **Battery Mode**: Insert 3x AA batteries into the rear holder. Use the physical slide switch to toggle battery power ON/OFF.
    * *Note: Ensure batteries are removed if you are modifying hardware components.*

## 📂 Repository Structure

* `/examples` - Source code, future updates, and example sketches.
* `/hardware` - PCB design files (Gerbers, Schematics).
* `/docs` - Datasheets and additional documentation.

## 🤝 Credits & Acknowledgments

* **Original Design**: Based on the **Hackbat Badge** by [Pablo on Hackaday.io](https://hackaday.io/project/197688-hackbat-badge).
* **MCU**: Powered by Espressif Systems.

## 📄 License

This project is open-source.
