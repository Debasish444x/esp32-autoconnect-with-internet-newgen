#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// LED Indicator
#define LED_PIN 2

// Relay Pin Configuration (Define as many as needed)
const int relayPins[] = {5,16,17,18,19,21,22,23};  // Add more pins here if needed [don't add more that 10, as esp alexa lib only supports 10 devices by default, you can change this in the library]

// Automatically determine the number of relays
#define DEVICE_COUNT (sizeof(relayPins) / sizeof(relayPins[0]))

// Device Naming Configuration
#define DEVICE_PREFIX "Home Device"  // Change this as needed
#define START_NUMBER 10              // The first device's number

// Array to store dynamically generated device names
extern String deviceNames[DEVICE_COUNT];

// Function to generate device names dynamically
void generateDeviceNames(); 
#endif  // CONFIG_H
