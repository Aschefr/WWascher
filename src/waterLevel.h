#ifndef DEF_WATER_LEVEL
#define DEF_WATER_LEVEL

#include "Arduino.h"
#include "input.h"
#include "nextion.h"

//Définition de l'objet "Pump"
class WaterLevel : public Input {
  public: //Disponible pour tout le monde (public)
    WaterLevel(int pin, unsigned int intervalUpdate = 200, bool reverse = false);
};

#endif
