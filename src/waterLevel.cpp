#include "waterLevel.h"

WaterLevel::WaterLevel(int pin, unsigned int intervalUpdate = 200, bool reverse = true) : Input(pin, intervalUpdate, reverse) {
  // no-op
}
