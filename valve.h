#ifndef DEF_VALVE
#define DEF_VALVE

#include "Arduino.h"
//Définition de l'objet "Pump"
class Valve {
  public: //Disponible pour tout le monde (public)
    Valve(int pin_switchPos);

    void askOpen_12();
    void askClose_13();

    void execTimer(int setTimer);
    void initValve(bool posInit);

    bool isOpen_12();
    bool isClose_13();

  private: //Information par pompes
    int pin_switchPos; //Pin de sortie pour basculement vanne

    bool valveOpen_12;
};

#endif
