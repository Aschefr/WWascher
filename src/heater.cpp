#include "heater.h"

Heater::Heater(int pin_temp) : Output(pin_temp) {
  // no-op
}

void Heater::turnOn() {
  this->set(true);
}

void Heater::turnOff() {
  this->set(false);
}

bool Heater::isOn() {
  return this->get();
}

bool Heater::isOff() {
  return !this->get();
}
