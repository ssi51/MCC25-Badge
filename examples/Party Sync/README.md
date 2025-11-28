# 📡 Party Sync Mode

This firmware turns your MCC25 Badge into a connected "Party Device" using the **ESP-NOW** protocol. 

When any badge in the room presses the **A Button**, it takes control and forces *all* other badges nearby to change to the same LED color instantly.

### ✨ Features
* **Peer-to-Peer Networking**: Uses ESP-NOW (Connectionless WiFi) for ultra-low latency.
* **Broadcast Mode**: One message controls unlimited devices. No pairing required.
* **Dynamic Role Switching**: Any badge can become the "Leader" simply by pressing a button.
* **OLED Feedback**: Shows "LEADER" when you transmit, and "SYNCED!" when you receive a command.

### 🛠 Hardware Requirements
* MCC25 Badge (ESP32-C3)
* **Minimum 2 Badges** are required to see the effect!

### 📦 Library Dependencies
Ensure these are installed in Arduino IDE:
1.  **FastLED**
2.  **GyverOLED**

### 🚀 How to Test
1.  Upload this code to **Badge A**.
2.  Upload this code to **Badge B**.
3.  Power both on.
4.  Press **Button A** on Badge A -> Badge B will change color instantly.
5.  Press **Button A** on Badge B -> Badge A will change color instantly.
