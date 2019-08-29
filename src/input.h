#ifndef DEF_INTPUT
#define DEF_INTPUT

#include "Arduino.h"

class Input {
  public:
    Input(int pin, unsigned int intervalUpdate = 200, bool reverse = false);
    bool get();
    void loop(unsigned long time);
  private:
    unsigned long lastUpdate;
    unsigned int intervalUpdate;
    int pin;
    bool state;
    bool reverse;
};

#endif
