#include "pump.h"

Pump::Pump(int pin_power1, int pin_power2) {
  this->pin_power1 = pin_power1;
  this->pin_power2 = pin_power2;

  pinMode(this->pin_power1, OUTPUT);
  pinMode(this->pin_power2, OUTPUT);

  this->turnOff();
}

void Pump::turnHalfPower() {
  digitalWrite(this->pin_power1, LOW);
  digitalWrite(this->pin_power2, HIGH);
  this->halfPower = true;
  this->fullPower = false;
}

void Pump::turnFullPower() {
  digitalWrite(this->pin_power1, LOW);
  digitalWrite(this->pin_power2, LOW);
  this->halfPower = true;
  this->fullPower = true;
}

void Pump::turnOff() {
  digitalWrite(this->pin_power1, HIGH);
  digitalWrite(this->pin_power2, HIGH);
  this->halfPower = false;
  this->fullPower = false;
}

bool Pump::isOn() {
  return this->halfPower || this->fullPower;
}

bool Pump::isOff() {
  return !this->halfPower && !this->fullPower;
}

bool Pump::isHalfPower() {
  return this->halfPower;
}

bool Pump::isFullPower() {
  return this->fullPower;
}
