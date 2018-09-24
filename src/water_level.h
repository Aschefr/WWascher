#ifndef DEF_WATERLEVEL
#define DEF_WATERLEVE

#include "Arduino.h"
//Définition de l'objet "Pump"
class WaterLevel {
  public: //Disponible pour tout le monde (public)
    WaterLevel(int pin_waterLevelSwitch);

    bool isOn();
    bool isOff();

  private: //Information par pompes
    int pin //Pin de sortie pour marche

    bool bucketStatus;
};

#endif
