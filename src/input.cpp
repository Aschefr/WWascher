#include "input.h"

Input::Input(int pin, unsigned int intervalUpdate = 200, bool reverse = true) {
  this->pin = pin;
  pinMode(this->pin, INPUT);
  this->reverse = reverse;
  this->intervalUpdate = intervalUpdate;
}

bool Input::get() {
  return this->state;
}

void Input::loop(unsigned long time) {
  if (time - this->lastUpdate > this->intervalUpdate) {
    this->state = digitalRead(this->pin) != this->reverse;
    this->lastUpdate = time;
  }
}
