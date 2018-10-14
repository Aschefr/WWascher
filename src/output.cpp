#include "output.h"

Output::Output(int pin, bool initState = LOW, bool reverse = true) {
  this->pin = pin;
  pinMode(this->pin, OUTPUT);
  this->initState = initState;
  this->reverse = reverse;
  this->reset();
}

bool Output::get() {
  return this->state;
}

void Output::reset() {
  this->set(this->initState);
}

void Output::set(bool state) {
  this->state = state;
  digitalWrite(this->pin, state != this->reverse);
}

bool Output::getInitState() {
  return this->initState;
}
