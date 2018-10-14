#ifndef DEF_OUTPUT
#define DEF_OUTPUT

#include "Arduino.h"

class Output {
  public:
    Output(int pin, bool initState = LOW, bool reverse = true);
    bool get();
    bool getInitState();
    void set(bool state);
    void reset();
  private:
    int pin;
    bool initState;
    bool state;
    bool reverse;
};

#endif
