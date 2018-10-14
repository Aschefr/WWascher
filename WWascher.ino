#include "src/pump.h"
#include "src/heater.h"
#include "src/valveTor.h"
#include "src/valveTri.h"
#include "src/nextion.h"

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

  // Serial.begin(9600);
  nextion = new Nextion(9600);
}

bool trans_001VK_0 = false;
bool trans_001VK_1 = false;
bool trans_001VK_2 = false;
bool trans_001VK_3 = false;

bool trans_002VK_0 = false;
bool trans_002VK_1 = false;
bool trans_002VK_2 = false;
bool trans_002VK_3 = false;

bool trans_003VK_0 = false;
bool trans_003VK_1 = false;
bool trans_003VK_2 = false;
bool trans_003VK_3 = false;

bool trans_004VK_0 = false;
bool trans_004VK_1 = false;
bool trans_004VK_2 = false;
bool trans_004VK_3 = false;

bool trans_005VK_0 = false;
bool trans_005VK_1 = false;
bool trans_005VK_2 = false;
bool trans_005VK_3 = false;

bool trans_006VK_0 = false;
bool trans_006VK_1 = false;
bool trans_006VK_2 = false;
bool trans_006VK_3 = false;

bool trans_007VK_0 = false;
bool trans_007VK_1 = false;
bool trans_007VK_2 = false;
bool trans_007VK_3 = false;

bool trans_001PO_0 = false;
bool trans_001PO_1 = false;
bool trans_001PO_2 = false;

bool trans_002PO_0 = false;
bool trans_002PO_1 = false;
bool trans_002PO_2 = false;

bool trans_003PO_0 = false;
bool trans_003PO_1 = false;
bool trans_003PO_2 = false;

bool alive = false;



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
  }
//AFFICHAGE IHM
  //001VK
  if (trans_001VK_0 == false && valve_001VK->get() == 0) {
    nextion->print("img001VK.pic=21");
    trans_001VK_0=true;
    trans_001VK_1=false;
    trans_001VK_2=false;
    trans_001VK_3=false;
  } else if (trans_001VK_1 == false && valve_001VK->get() == 1)
  {
    nextion->print("img001VK.pic=23");
    trans_001VK_0=false;
    trans_001VK_1=true;
    trans_001VK_2=false;
    trans_001VK_3=false;
  } else if (trans_001VK_2 == false && valve_001VK->get() == 2)
  {
    nextion->print("img001VK.pic=22");
    trans_001VK_0=false;
    trans_001VK_1=false;
    trans_001VK_2=true;
    trans_001VK_3=false;
  } else if (trans_001VK_3 == false && valve_001VK->get() == 3)
  {
    nextion->print("img001VK.pic=24");
    trans_001VK_0=false;
    trans_001VK_1=false;
    trans_001VK_2=false;
    trans_001VK_3=true;
  }

  //002VK
  if (trans_002VK_0 == false && valve_002VK->get() == 0) {
    nextion->print("img002VK.pic=21");
    trans_002VK_0=true;
    trans_002VK_1=false;
    trans_002VK_2=false;
    trans_002VK_3=false;
  } else if (trans_002VK_1 == false && valve_002VK->get() == 1)
  {
    nextion->print("img002VK.pic=23");
    trans_002VK_0=false;
    trans_002VK_1=true;
    trans_002VK_2=false;
    trans_002VK_3=false;
  } else if (trans_002VK_2 == false && valve_002VK->get() == 2)
  {
    nextion->print("img002VK.pic=22");
    trans_002VK_0=false;
    trans_002VK_1=false;
    trans_002VK_2=true;
    trans_002VK_3=false;
  } else if (trans_002VK_3 == false && valve_002VK->get() == 3)
  {
    nextion->print("img002VK.pic=24");
    trans_002VK_0=false;
    trans_002VK_1=false;
    trans_002VK_2=false;
    trans_002VK_3=true;
  }

  //003VK
  if (trans_003VK_0 == false && valve_003VK->get() == 0) {
    nextion->print("img003VK.pic=21");
    trans_003VK_0=true;
    trans_003VK_1=false;
    trans_003VK_2=false;
    trans_003VK_3=false;
  } else if (trans_003VK_1 == false && valve_003VK->get() == 1)
  {
    nextion->print("img003VK.pic=23");
    trans_003VK_0=false;
    trans_003VK_1=true;
    trans_003VK_2=false;
    trans_003VK_3=false;
  } else if (trans_003VK_2 == false && valve_003VK->get() == 2)
  {
    nextion->print("img003VK.pic=22");
    trans_003VK_0=false;
    trans_003VK_1=false;
    trans_003VK_2=true;
    trans_003VK_3=false;
  } else if (trans_003VK_3 == false && valve_003VK->get() == 3)
  {
    nextion->print("img003VK.pic=24");
    trans_003VK_0=false;
    trans_003VK_1=false;
    trans_003VK_2=false;
    trans_003VK_3=true;
  }

  //004VK
  if (trans_004VK_0 == false && valve_004VK->get() == 0) {
    nextion->print("img004VK.pic=21");
    trans_004VK_0=true;
    trans_004VK_1=false;
    trans_004VK_2=false;
    trans_004VK_3=false;
  } else if (trans_004VK_1 == false && valve_004VK->get() == 1)
  {
    nextion->print("img004VK.pic=23");
    trans_004VK_0=false;
    trans_004VK_1=true;
    trans_004VK_2=false;
    trans_004VK_3=false;
  } else if (trans_004VK_2 == false && valve_004VK->get() == 2)
  {
    nextion->print("img004VK.pic=22");
    trans_004VK_0=false;
    trans_004VK_1=false;
    trans_004VK_2=true;
    trans_004VK_3=false;
  } else if (trans_004VK_3 == false && valve_004VK->get() == 3)
  {
    nextion->print("img004VK.pic=24");
    trans_004VK_0=false;
    trans_004VK_1=false;
    trans_004VK_2=false;
    trans_004VK_3=true;
  }

  //005VK
  if (trans_005VK_0 == false && valve_005VK->get() == 0) {
    nextion->print("img005VK.pic=28");
    trans_005VK_0=true;
    trans_005VK_1=false;
    trans_005VK_2=false;
    trans_005VK_3=false;
  } else if (trans_005VK_1 == false && valve_005VK->get() == 1)
  {
    nextion->print("img005VK.pic=26");
    trans_005VK_0=false;
    trans_005VK_1=true;
    trans_005VK_2=false;
    trans_005VK_3=false;
  } else if (trans_005VK_2 == false && valve_005VK->get() == 2)
  {
    nextion->print("img005VK.pic=27");
    trans_005VK_0=false;
    trans_005VK_1=false;
    trans_005VK_2=true;
    trans_005VK_3=false;
  } else if (trans_005VK_3 == false && valve_005VK->get() == 3)
  {
    nextion->print("img005VK.pic=25");
    trans_005VK_0=false;
    trans_005VK_1=false;
    trans_005VK_2=false;
    trans_005VK_3=true;
  }

  //006VK
  if (trans_006VK_0 == false && valve_006VK->get() == 0) {
    nextion->print("img006VK.pic=6");
    trans_006VK_0=true;
    trans_006VK_1=false;
    trans_006VK_2=false;
    trans_006VK_3=false;
  } else if (trans_006VK_1 == false && valve_006VK->get() == 1)
  {
    nextion->print("img006VK.pic=4");
    trans_006VK_0=false;
    trans_006VK_1=true;
    trans_006VK_2=false;
    trans_006VK_3=false;
  } else if (trans_006VK_2 == false && valve_006VK->get() == 2)
  {
    nextion->print("img006VK.pic=5");
    trans_006VK_0=false;
    trans_006VK_1=false;
    trans_006VK_2=true;
    trans_006VK_3=false;
  } else if (trans_006VK_3 == false && valve_006VK->get() == 3)
  {
    nextion->print("img006VK.pic=3");
    trans_006VK_0=false;
    trans_006VK_1=false;
    trans_006VK_2=false;
    trans_006VK_3=true;
  }

  //007VK
  if (trans_007VK_0 == false && valve_007VK->get() == 0) {
    nextion->print("img007VK.pic=6");
    trans_007VK_0=true;
    trans_007VK_1=false;
    trans_007VK_2=false;
    trans_007VK_3=false;
  } else if (trans_007VK_1 == false && valve_007VK->get() == 1)
  {
    nextion->print("img007VK.pic=4");
    trans_007VK_0=false;
    trans_007VK_1=true;
    trans_007VK_2=false;
    trans_007VK_3=false;
  } else if (trans_007VK_2 == false && valve_007VK->get() == 2)
  {
    nextion->print("img007VK.pic=5");
    trans_007VK_0=false;
    trans_007VK_1=false;
    trans_007VK_2=true;
    trans_007VK_3=false;
  } else if (trans_007VK_3 == false && valve_007VK->get() == 3)
  {
    nextion->print("img007VK.pic=3");
    trans_007VK_0=false;
    trans_007VK_1=false;
    trans_007VK_2=false;
    trans_007VK_3=true;
  }

  //001PO
  if (trans_001PO_0 == false && pump_001PO->get() == 0) {
    nextion->print("img001PO.pic=29");
    trans_001PO_0=true;
    trans_001PO_1=false;
    trans_001PO_2=false;
  } else if (trans_001PO_1 == false && pump_001PO->get() == 1)
  {
    nextion->print("img001PO.pic=30");
    trans_001PO_0=false;
    trans_001PO_1=true;
    trans_001PO_2=false;
  } else if (trans_001PO_2 == false && pump_001PO->get() > 1)
  {
    nextion->print("img001PO.pic=31");
    trans_001PO_0=false;
    trans_001PO_1=false;
    trans_001PO_2=true;
  }

  //002PO
  if (trans_002PO_0 == false && pump_002PO->get() == 0) {
    nextion->print("img002PO.pic=29");
    trans_002PO_0=true;
    trans_002PO_1=false;
    trans_002PO_2=false;
  } else if (trans_002PO_1 == false && pump_002PO->get() == 1)
  {
    nextion->print("img002PO.pic=30");
    trans_002PO_0=false;
    trans_002PO_1=true;
    trans_002PO_2=false;
  } else if (trans_002PO_2 == false && pump_002PO->get() > 1)
  {
    nextion->print("img002PO.pic=31");
    trans_002PO_0=false;
    trans_002PO_1=false;
    trans_002PO_2=true;
  }

  //003PO
  if (trans_003PO_0 == false && pump_003PO->get() == 0) {
    nextion->print("img003PO.pic=9");
    trans_003PO_0=true;
    trans_003PO_1=false;
    trans_003PO_2=false;
  } else if (trans_003PO_1 == false && pump_003PO->get() == 1)
  {
    nextion->print("img003PO.pic=10");
    trans_003PO_0=false;
    trans_003PO_1=true;
    trans_003PO_2=false;
  } else if (trans_003PO_2 == false && pump_003PO->get() > 1)
  {
    nextion->print("img003PO.pic=11");
    trans_003PO_0=false;
    trans_003PO_1=false;
    trans_003PO_2=true;
  }

//delay(1000);
//COMMANDE MODE MANUEL
  if (nextion->available()) {
    String data = nextion->getCommand();
    if (data == "Manu_001VK_Open") {
      valve_001VK->askOpen();
    }
    if (data == "Manu_001VK_Close") {
      valve_001VK->askClose();
    }
    if (data == "Manu_002VK_Open") {
      valve_002VK->askOpen();
    }
    if (data == "Manu_002VK_Close") {
      valve_002VK->askClose();
    }
    if (data == "Manu_003VK_Open") {
      valve_003VK->askOpen();
    }
    if (data == "Manu_003VK_Close") {
      valve_003VK->askClose();
    }
    if (data == "Manu_004VK_Open") {
      valve_004VK->askOpen();
    }
    if (data == "Manu_004VK_Close") {
      valve_004VK->askClose();
    }
    if (data == "Manu_005VK_Open") {
      valve_005VK->askPos12();
    }
    if (data == "Manu_005VK_Close") {
      valve_005VK->askPos13();
    }
    if (data == "Manu_006VK_Open") {
      valve_006VK->askPos12();
    }
    if (data == "Manu_006VK_Close") {
      valve_006VK->askPos13();
    }
    if (data == "Manu_007VK_Open") {
      valve_007VK->askPos12();
    }
    if (data == "Manu_007VK_Close") {
      valve_007VK->askPos13();
    }

    if (data == "Manu_001PO_Low") {
      pump_001PO->turnHalfPower();
    }
    if (data == "Manu_001PO_High") {
      pump_001PO->turnFullPower();
    }
    if (data == "Manu_001PO_Off") {
      pump_001PO->turnOff();
    }

    if (data == "Manu_002PO_Low") {
      pump_002PO->turnHalfPower();
    }
    if (data == "Manu_002PO_High") {
      pump_002PO->turnFullPower();
    }
    if (data == "Manu_002PO_Off") {
      pump_002PO->turnOff();
    }

    if (data == "Manu_003PO_Low") {
      pump_003PO->turnHalfPower();
    }
    if (data == "Manu_003PO_High") {
      pump_003PO->turnFullPower();
    }
    if (data == "Manu_003PO_Off") {
      pump_003PO->turnOff();
    }


    if (data == "question_alive") {
      nextion->print("page Menu");
      alive=true;
    }

  }
  //nextion->print(" end IF ");
}

// NexTouch *nex_listen_list[] =
// {
//     &p0,
//     NULL
// };
