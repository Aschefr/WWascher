#include "nextion.h"


Nextion::Nextion(int baudRate) {
  //Serial.begin(9600);
  Serial3.begin(9600);
}

void Nextion::print(String message) {
  //Serial.print(message);
  //Serial.write(0xFF);
  //Serial.write(0xFF);
  //Serial.write(0xFF);
  Serial3.print(message);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
  Serial3.write(0xFF);
}

bool Nextion::available() {
  //return Serial.available();
  return Serial3.available();
}

String Nextion::getCommand() {
  //return Serial.readStringUntil('\n');
  return Serial3.readStringUntil('\n');
}
