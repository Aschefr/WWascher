#include "valve.h"
/*
    void askOpen_12();
    void askClose_13();

    void execTimer(int setTimer);
    void initValve(bool posInit);

    bool isOpen_12();
    bool isClose_13();
*/

unsigned long last_time = millis();
int last_status = 0;

Valve::Valve(int pin_temp) {
  this->pin = pin_temp;

  pinMode(this->pin, OUTPUT);

  this->turnOff();
}

void Valve::askOpen_12() {
  digitalWrite(this->pin, LOW);
    if(last_status == 0) {
        last_time = millis();
        last_status = 1;
      } else if (millis() - last_time > setTimer) {
          this->valveOpen_12 = true;
          this->valveClose_13 = false;
        last_status = 0;
      }
}

void Valve::askClose_13() {
  digitalWrite(this->pin, HIGH);
  this->valveOpen_12 = false;
  this->valveClose_13 = true;
}

bool Valve::isOn() {
  return this->halfPower || this->fullPower;
}

bool Valve::isOff() {
  return !this->halfPower && !this->fullPower;
}

bool Valve::isHalfPower() {
  return this->halfPower;
}

bool Valve::isFullPower() {
  return this->fullPower;
}
