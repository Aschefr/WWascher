#include "heater.h"

Heater::Heater(int pin_temp) {
  this->pin = pin_temp;

  pinMode(this->pin, OUTPUT);

  this->turnOff();
}

void Heater::turnOn() {
  digitalWrite(this->pin, LOW);
  this->heaterStatus = true;
}

void Heater::turnOff() {
  digitalWrite(this->pin, HIGH);
  this->heaterStatus = false;
}

bool Heater::getStatus() {
  return this->heaterStatus;
}
