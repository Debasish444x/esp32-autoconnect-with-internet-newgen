#include "RelayControl.h"
#include "Config.h"

Preferences preferences;

void setupRelays() {
    preferences.begin("relayState", false);

    // Set relay pins as OUTPUT
    for (int i = 0; i < DEVICE_COUNT; i++) {
        pinMode(relayPins[i], OUTPUT);
    }

    restoreRelayStates();
}

void relayControl(uint8_t relayIndex, uint8_t brightness) {
    if (relayIndex >= DEVICE_COUNT) return;  // Prevent out-of-bounds access

    bool state = brightness > 0 ? LOW : HIGH;
    digitalWrite(relayPins[relayIndex], state);
    saveRelayState(relayIndex, state);
}

void restoreRelayStates() {
    for (int i = 0; i < DEVICE_COUNT; i++) {
        digitalWrite(relayPins[i], preferences.getBool(("relay" + String(i)).c_str(), HIGH));
    }
}

void saveRelayState(int relayIndex, bool state) {
    if (relayIndex >= DEVICE_COUNT) return;  // Prevent out-of-bounds access

    preferences.putBool(("relay" + String(relayIndex)).c_str(), state);
}
