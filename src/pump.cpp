#include "pump.h"

Pump::Pump(int pin_power1, int pin_power2) : out1(pin_power1), out2(pin_power2) {
  this->reset();
}

void Pump::turnOff() {
  this->set(0);
}

void Pump::turnHalfPower() {
  this->set(1);
}

void Pump::turnFullPower() {
  this->set(2);
}

void Pump::set(int state) {
  if (state <= 0) {
    this->out1.set(false);
    this->out2.set(false);
  } else if (state == 1) {
    this->out1.set(true);
    this->out2.set(false);
  } else {
    this->out1.set(true);
    this->out2.set(true);
  }
}

int Pump::get() {
  return this->out1.get() + this->out2.get();
}

void Pump::reset() {
  this->out1.reset();
  this->out2.reset();
}

bool Pump::isOn() {
  return this->get() > 0;
}

bool Pump::isOff() {
  return this->get() <= 0;
}

bool Pump::isHalfPower() {
  return this->get() == 1;
}

bool Pump::isFullPower() {
  return this->get() >= 2;
}
