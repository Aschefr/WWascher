#include "nextion.h"

Nextion::Nextion(int baudRate) {
  Serial.begin(9600);
}

void Nextion::print(String message) {
  Serial.print(message);
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
}

bool Nextion::available() {
  return Serial.available();
}

String Nextion::getCommand() {
  return Serial.readStringUntil('\n');
}
