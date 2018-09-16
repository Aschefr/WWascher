#ifndef DEF_NEXTION
#define DEF_NEXTION

#include "Arduino.h"

class Nextion {
  public:
    Nextion(int baudrate);
    void print(String message);
    bool available();
    String getCommand();
  private:
};

#endif
