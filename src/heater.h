#ifndef DEF_HEATER
#define DEF_HEATER

#include "Arduino.h"
#include "output.h"

class Heater : public Output {
  public: //Disponible pour tout le monde (public)
    Heater(int pin_heater);

    void turnOn();
    void turnOff();

    bool isOn();
    bool isOff();
};

#endif
