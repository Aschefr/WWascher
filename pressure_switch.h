#ifndef DEF_PSWITCH
#define DEF_PSWITCH

#include "Arduino.h"
//Définition de l'objet "Pump"
class Pswitch {
  public: //Disponible pour tout le monde (public)
    Pswitch(int pin_pressureSwitch);

  private: //Information par pompes
    int pin //Pin de sortie pour marche

    bool PressureTooHigh;
};

#endif
