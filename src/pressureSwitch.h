#ifndef DEF_PRESSURE_SWITCH
#define DEF_PRESSURE_SWITCH

#include "Arduino.h"
#include "input.h"
#include "nextion.h"

//Définition de l'objet "Pump"
class PressureSwitch : public Input {
  public: //Disponible pour tout le monde (public)
    PressureSwitch(int pin, unsigned int intervalUpdate = 200, bool reverse = true);
};

#endif
