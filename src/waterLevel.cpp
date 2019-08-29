#include "waterLevel.h"

WaterLevel::WaterLevel(int pin, unsigned int intervalUpdate = 200, bool reverse = false) : Input(pin, intervalUpdate, reverse) {
  // no-op
}
