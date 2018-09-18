#ifndef DEF_PUMP
#define DEF_PUMP

#include "Arduino.h"
//Définition de l'objet "Pump"
class Pump {
  public: //Disponible pour tout le monde (public)
    Pump(int pin_power1, int pin_power2);

    void turnHalfPower();
    void turnFullPower();
    void turnOff();

    bool isOn();
    bool isOff();
    bool isHalfPower();
    bool isFullPower();

  private: //Information par pompes
    int pin_power1; //Pin de sortie pour marche 50%
    int pin_power2; //Pin de sortie pour marche 100%

    bool halfPower;
    bool fullPower;
};

#endif
