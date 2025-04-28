#include "EspAlexaHandler.h"

Espalexa espalexa;

void beginEspAlexa() {
    for (int i = 0; i < DEVICE_COUNT; i++) {
        espalexa.addDevice(deviceNames[i].c_str(), [i](uint8_t b) { relayControl(i, b); });
    }
    espalexa.begin();
    Serial.println("Alexa devices initialized.");
}

void handleAlexa() {
    if (wifiConnected) {
        espalexa.loop();
    }
}
