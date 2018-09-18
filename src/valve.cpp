#include "valve.h"

Valve::Valve(int pin_temp, bool initState = LOW, bool reverse = false) : out(pin_temp, initState, reverse) {
  this->reset();
}

/**
 * this->state correspond to state of the valve
 * state = 0 => close
 * state = 1 => closing
 * state = 2 => opening
 * state = 3 => open
 */
int Valve::get() {
  return this->state;
}

void Valve::loop(unsigned long time) {
  if (this->lastCommand == 0) {
    return;
  }

  if (time - this->lastCommand > VALVE_OPEN_TIME) {
    if (this->state == VALVE_OPENING) {
      this->state = VALVE_OPEN;
    } else if (this->state == VALVE_CLOSING) {
      this->state = VALVE_CLOSE;
    }
    this->lastCommand = 0;
  }
}

void Valve::reset() {
  if (this->out.getInitState()) {
    this->set(true);
  } else {
    this->set(false);
  }
}

void Valve::set(bool state) {
  this->out.set(state);
  if (state && this->state != VALVE_OPEN ) {
    this->lastCommand = millis();
    this->state = VALVE_OPENING;
  } else if (state == false && this->state != VALVE_CLOSE ) {
    this->lastCommand = millis();
    this->state = VALVE_CLOSING;
  }
}
