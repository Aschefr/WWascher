#ifndef DEF_HEATER
#define DEF_HEATER

#include "Arduino.h"

class Heater {
  public: //Disponible pour tout le monde (public)
    Heater(int pin_heater);

    void turnOn();
    void turnOff();

    bool getStatus();

  private: //Information par pompes
    int pin; //Pin de sortie pour marche

    bool heaterStatus;
};

#endif
