#ifndef DEF_VALVE_TOR
#define DEF_VALVE_TOR

#include "Arduino.h"
#include "valve.h"

//Définition de l'objet "Pump"
class ValveTor : public Valve {
  public: //Disponible pour tout le monde (public)
    ValveTor(int pin_switchPos, bool initState = LOW);

    void askOpen();
    void askClose();

    bool isOpen();
    bool isOpening();
    bool isMoving();
    bool isClose();
    bool isClosing();
};

#endif
