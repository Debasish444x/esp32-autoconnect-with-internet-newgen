#include "Config.h"

// Define the deviceNames array
String deviceNames[DEVICE_COUNT];

void generateDeviceNames() {
    for (int i = 0; i < DEVICE_COUNT; i++) {
        deviceNames[i] = DEVICE_PREFIX + String(START_NUMBER + i);
    }
}
