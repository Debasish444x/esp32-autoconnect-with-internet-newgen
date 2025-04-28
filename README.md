# 🛠️ ESP32 WiFi Relay Controller with Alexa Integration

This project allows you to control multiple relays using an ESP32, with WiFi and Amazon Alexa (via Espalexa library) support.  
It automatically manages device names, relay states, WiFi reconnection, and internet checking.

---

## 📋 Features
- 🔌 Control multiple relays (dynamic number).
- 📡 Connects to WiFi automatically.
- 📶 Periodically checks for internet connectivity (Google 204 check).
- 👤 Works with Amazon Alexa (no additional Alexa skill required).
- 📂 Saves relay and internet states in non-volatile storage (Preferences / EEPROM).
- ⚙️ Fully **configurable** through a `Config.h` file:
  - Relay pins
  - Device name prefix
  - Starting device number
- 🔁 Automatically restores relay states on reboot.
- 🔥 Modular code structure (separate files for WiFi, Alexa, Relay, Storage, etc.)

---

## 📂 Project Structure
```
/ProjectRoot
│
├— Config.h        # Configuration for relay pins and device names
├— Config.cpp      # Handles device name generation
│
├— RelayControl.h  # Relay control declarations
├— RelayControl.cpp# Relay control implementation
│
├— EspAlexaHandler.h # Alexa integration declarations
├— EspAlexaHandler.cpp # Alexa device control
│
├— StorageManager.h # EEPROM/Preferences management
├— StorageManager.cpp
│
├— WiFiManager.h    # WiFi and Internet connection manager
├— WiFiManager.cpp
│
└— main.ino         # Arduino sketch (setup/loop only)

└— README.md        # This file
```

---

## ⚙️ Configuration

All key settings are inside `Config.h`:

```cpp
// Define relay pins
const int relayPins[] = {23, 22, 21, 19};

// Prefix for device names
const String DEVICE_PREFIX = "relay";

// Starting number for device naming
const int STARTING_DEVICE_NUMBER = 10;
```

📌 The system automatically:
- Counts the number of relays (`DEVICE_COUNT`)
- Generates device names like `relay10`, `relay11`, `relay12`, etc.

---
## 🧐 How it works

- **WiFiManager** connects to the given SSID/PASSWORD and keeps checking internet connection.
- **RelayControl** sets up pins, restores their last states, and saves any changes.
- **EspAlexaHandler** adds dynamically generated devices to Alexa using the `Espalexa` library.
- **ConfigManager** automatically handles relay names without manual input.

---

## 🚀 Getting Started

1. Clone/download this repository.
2. Update your **WiFi SSID** and **Password** in `WiFiManager.cpp`.
3. Modify relay pins or name settings in `Config.h` if needed.
4. Upload the project to your ESP32 using Arduino IDE or PlatformIO.
5. Discover devices in Alexa app (your ESP32 should appear automatically).
6. Control your relays via Alexa or manually.

---

## 📚 Libraries Used
- [Espalexa](https://github.com/Aircoookie/Espalexa)
- WiFi.h / Preferences.h (ESP32 Core libraries)
- HTTPClient.h

---

## 🛠️ Future Improvements (Suggestions)
- Add web-based configuration portal.
- OTA firmware updates.
- MQTT server integration.
- More flexible device types (dimmers, sensors, etc.)

---

## ❤️ Credits

Created with ❤️ using ESP32, Arduino, and lots of coffee ☕.

---

