#include "valveTri.h"

ValveTri::ValveTri(int pin_switchPos, bool initState = LOW, bool reverse = false) : Valve(pin_switchPos, initState, reverse) {
  // no-op
}

void ValveTri::askPos13() {
  this->set(true);
}

void ValveTri::askPos12() {
  this->set(false);
}

bool ValveTri::isPos13() {
  return this->get() == VALVE_OPEN;
}

bool ValveTri::isMoving() {
  return this->get() == VALVE_OPENING || this->get() == VALVE_CLOSING;
}

bool ValveTri::isPos12() {
  return this->get() == VALVE_CLOSE;
}
