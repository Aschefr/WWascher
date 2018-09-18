#ifndef DEF_PUMP
#define DEF_PUMP

#include "Arduino.h"
#include "output.h"

//Définition de l'objet "Pump"
class Pump {
  public: //Disponible pour tout le monde (public)
    Pump(int pin_power1, int pin_power2);

    int get();
    void set(int state);
    void reset();

    void turnOff();
    void turnHalfPower();
    void turnFullPower();

    bool isOn();
    bool isOff();
    bool isHalfPower();
    bool isFullPower();

  private: //Information par pompes
    Output out1; //Pin de sortie pour marche 50%
    Output out2; //Pin de sortie pour marche 100%
};

#endif
