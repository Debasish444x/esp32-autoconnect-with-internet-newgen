#ifndef RELAYCONTROL_H
#define RELAYCONTROL_H

#include <Arduino.h>
#include "StorageManager.h"
#include "Config.h"  // Include Config for dynamic relay handling

void setupRelays();
void relayControl(uint8_t relayIndex, uint8_t brightness);
void restoreRelayStates();
void saveRelayState(int relayIndex, bool state);
void saveInternetState(bool state);

#endif  // RELAYCONTROL_H
