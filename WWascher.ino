#include "src/pump.h"
#include "src/heater.h"
#include "src/valveTor.h"
#include "src/valveTri.h"
#include "src/nextion.h"

//Holblin Stuff
Pump* pump_001PO;
Pump* pump_002PO;
Pump* pump_003PO;
Heater* heater_0001CH;
Nextion* nextion;
 ValveTor* valve_001VK;
ValveTor* valve_002VK;
ValveTor* valve_003VK;
ValveTor* valve_004VK;
ValveTri* valve_005VK;
ValveTri* valve_006VK;
ValveTri* valve_007VK;

int in001SN = 4;
int in002SN = 5;
int in001SP = 6;

bool alive = false;

void setup() {
  pump_001PO = new Pump(29, 27);
  pump_002PO = new Pump(25, 23);
  pump_003PO = new Pump(10, 11);
  heater_0001CH = new Heater(22);

  valve_001VK = new ValveTor(36);
  valve_002VK = new ValveTor(34);
  valve_003VK = new ValveTor(32);
  valve_004VK = new ValveTor(30);
  valve_005VK = new ValveTri(28);
  valve_006VK = new ValveTri(26);
  valve_007VK = new ValveTri(24);

  //Test de lecture des entrées
  pinMode(in001SN, INPUT);
  pinMode(in002SN, INPUT);
  pinMode(in001SP, INPUT);

  // Serial.begin(9600);
  nextion = new Nextion(9600);
}


void loop() {

//TESTING NEW COM :// nexLoop(nextion_touch_events);  // Check for any touch event and run the associated function

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

  unsigned long time = millis();
  valve_001VK->loop(time);

  if (nextion->available()) {
    String data = nextion->getCommand();
    if (data == "btn_init") {
      valve_001VK->askOpen();

      if (heater_0001CH->get()) {
        heater_0001CH->turnOff();
        if (!heater_0001CH->get()) {
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
      if (!heater_0001CH->get() && pump_001PO->isOff() && pump_002PO->isOff() && pump_003PO->isOff()){
        nextion->print("vis btn_retour,1");
        nextion->print("vis imgRuning,0");
      }
    }

    else if (data == "Manu_001VK_Open") {
      valve_001VK->askOpen();
    }
    else if (data == "Manu_001VK_Close") {
      valve_001VK->askClose();
    }
    else if (data == "Manu_002VK_Open") {
      valve_002VK->askOpen();
    }
    else if (data == "Manu_002VK_Close") {
      valve_002VK->askClose();
    }
    else if (data == "Manu_003VK_Open") {
      valve_003VK->askOpen();
    }
    else if (data == "Manu_003VK_Close") {
      valve_003VK->askClose();
    }
    else if (data == "Manu_004VK_Open") {
      valve_004VK->askOpen();
    }
    else if (data == "Manu_004VK_Close") {
      valve_004VK->askClose();
    }
    else if (data == "Manu_005VK_Open") {
      valve_005VK->askPos12();
    }
    else if (data == "Manu_005VK_Close") {
      valve_005VK->askPos13();
    }
    else if (data == "Manu_006VK_Open") {
      valve_006VK->askPos12();
    }
    else if (data == "Manu_006VK_Close") {
      valve_006VK->askPos13();
    }
    else if (data == "Manu_007VK_Open") {
      valve_007VK->askPos12();
    }
    else if (data == "Manu_007VK_Close") {
      valve_007VK->askPos13();
    }

    else if (data == "Manu_001PO_Low") {
      pump_001PO->turnHalfPower();
    }
    else if (data == "Manu_001PO_High") {
      pump_001PO->turnFullPower();
    }
    else if (data == "Manu_001PO_Off") {
      pump_001PO->turnOff();
    }

    else if (data == "Manu_002PO_Low") {
      pump_002PO->turnHalfPower();
    }
    else if (data == "Manu_002PO_High") {
      pump_002PO->turnFullPower();
    }
    else if (data == "Manu_002PO_Off") {
      pump_002PO->turnOff();
    }

    else if (data == "Manu_003PO_Low") {
      pump_003PO->turnHalfPower();
    }
    else if (data == "Manu_003PO_High") {
      pump_003PO->turnFullPower();
    }
    else if (data == "Manu_003PO_Off") {
      pump_003PO->turnOff();
    }
    else if (data == "question_alive") {
      nextion->print("page Menu");
      alive = true;
    }
    else {
      // If you fall here, you need to implement it
    }
  }
}
