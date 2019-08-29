#include "pressureSwitch.h"

PressureSwitch::PressureSwitch(int pin, unsigned int intervalUpdate = 200, bool reverse = false) : Input(pin, intervalUpdate, reverse) {
  // no-op
}
