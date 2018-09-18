#include "valveTor.h"

ValveTor::ValveTor(int pin_switchPos, bool initState = LOW) : Valve(pin_switchPos, initState) {
  // no-op
}

void ValveTor::askOpen() {
  this->set(true);
}

void ValveTor::askClose() {
  this->set(false);
}

bool ValveTor::isOpen() {
  return this->get() == VALVE_OPEN;
}

bool ValveTor::isMoving() {
  return this->get() == VALVE_OPENING || this->get() == VALVE_CLOSING;
}

bool ValveTor::isClose() {
  return this->get() == VALVE_CLOSE;
}
