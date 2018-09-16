#include "pump.h"
#include "heater.h"
#include "nextion.h"

Pump* pump_001PO;
Pump* pump_002PO;
Pump* pump_003PO;
Heater* heater_0001CH;
Nextion* nextion;


void setup() {
  pump_001PO = new Pump(22, 24);
  pump_002PO = new Pump(26, 28);
  pump_003PO = new Pump(30, 32);
  heater_0001CH = new Heater(22);

  // Serial.begin(9600);
  nextion = new Nextion(9600);
}

void loop() {
  /*pump1->turnFullPower();
  delay(500);
  if (pump1->isOn()) {
  	pump1->turnOff();
	  delay(500);
  }
  pump1->turnHalfPower();
  delay(500); */

  // heater_0001CH->turnOn();
  // delay(500);
  // if (heater_0001CH->getStatus()) {
  //   heater_0001CH->turnOff();
  //   delay(500);
  // }

  if (nextion->available()) {
    String data = nextion->getCommand();
    if (data == "btn_init") {
      if (heater_0001CH->getStatus()) {
        heater_0001CH->turnOff();
        if (!heater_0001CH->getStatus()) {
          nextion->print("vis iniOK001CH,1");
        }
      }
      if (pump_001PO->isOn()) {
        pump_001PO->turnOff();
        if (pump_001PO->isOff()) {
          nextion->print("vis iniOK001PO,1");
        }
      }
      if (pump_002PO->isOn()) {
        pump_002PO->turnOff();
        if (pump_002PO->isOff()) {
          nextion->print("vis iniOK002PO,1");
        }
      }
      if (pump_003PO->isOn()) {
        pump_003PO->turnOff();
        if (pump_003PO->isOff()) {
          nextion->print("vis iniOK003PO,1");
        }
      }
      if (!heater_0001CH->getStatus() && pump_001PO->isOff() && pump_002PO->isOff() && pump_003PO->isOff()){
        nextion->print("vis btn_retour,1");
        nextion->print("vis imgRuning,0");
      }
    }
  }
}

// NexTouch *nex_listen_list[] =
// {
//     &p0,
//     NULL
// };
