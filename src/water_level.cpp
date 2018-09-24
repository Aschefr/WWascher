#include "water_level.h"

WaterLevel::WaterLevel(int pin) {
  this->reset();
}

bool WaterLevel::isOn() {
  return this->get() > 0;
}
