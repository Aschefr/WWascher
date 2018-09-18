#ifndef DEF_VALVE_TRI
#define DEF_VALVE_TRI

#include "Arduino.h"
#include "valve.h"

//Définition de l'objet "Pump"
class ValveTri : public Valve {
  public: //Disponible pour tout le monde (public)
    ValveTri(int pin_switchPos, bool initState = LOW, bool reverse = false);

    void askPos12();
    void askPos13();

    bool isPos12();
    bool isMoving();
    bool isPos13();
};

#endif
