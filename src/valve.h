#ifndef DEF_VALVE
#define DEF_VALVE

#include "Arduino.h"
#include "output.h"
#include "nextion.h"

#define VALVE_CLOSE 0
#define VALVE_CLOSING 1
#define VALVE_OPENING 2
#define VALVE_OPEN 3
#define VALVE_OPEN_TIME 3000

//Définition de l'objet
class Valve {
  public: //Disponible pour tout le monde (public)
    Valve(int pin_switchPos, bool initState = LOW, bool reverse = true);

    int get();
    void set(bool state);
    void reset();
    void loop(unsigned long time);
    //void image();

  private:
    unsigned long lastCommand;
    int state;
    Output out;
};

#endif
