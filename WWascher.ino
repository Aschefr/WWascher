#include "src/pump.h"  // OK
#include "src/heater.h" // KO
#include "src/valveTor.h" // OK
#include "src/valveTri.h" // OK

#include "src/waterLevel.h" // OK
#include "src/pressureSwitch.h" // OK

#include "src/nextion.h" // Mehhh

//Holblin Stuff
Pump* pump_001PO;
Pump* pump_002PO;
Pump* pump_003PO;
Heater* heater_001CH;
Nextion* nextion;
ValveTor* valve_001VK;
ValveTor* valve_002VK;
ValveTor* valve_003VK;
ValveTor* valve_004VK;
ValveTri* valve_005VK;
ValveTri* valve_006VK;
ValveTri* valve_007VK;
PressureSwitch* in001SP;
WaterLevel* in001SN;
WaterLevel* in002SN;

bool alive = false;

//Animation

bool trans_lignage_img87 = false;
bool trans_lignage_img88 = false;
bool trans_lignage_img89 = false;
bool trans_lignage_img90 = false;
bool trans_lignage_img91 = false;
bool trans_lignage_img92 = false;
bool trans_lignage_img93 = false;
bool trans_lignage_img94 = false;
bool trans_lignage_img95 = false;
bool trans_lignage_img96 = false;
bool trans_lignage_img97 = false;
bool trans_lignage_img98 = false;
bool trans_lignage_img99 = false;
bool trans_lignage_img100 = false;
bool trans_lignage_img101 = false;


void setup() {
  pump_001PO = new Pump(29, 27);
  pump_002PO = new Pump(25, 23);
  pump_003PO = new Pump(10, 11);
  heater_001CH = new Heater(22);

  valve_001VK = new ValveTor(36);
  valve_002VK = new ValveTor(34);
  valve_003VK = new ValveTor(32);
  valve_004VK = new ValveTor(30);
  valve_005VK = new ValveTri(28, 1);
  valve_006VK = new ValveTri(26, 1);
  valve_007VK = new ValveTri(24, 1, 1);

  //Test de lecture des entrées
  in001SP = new PressureSwitch(6);
  in001SN = new WaterLevel(5);
  in002SN = new WaterLevel(4);

  Serial.begin(9600);

  // Serial.begin(9600);
  nextion = new Nextion(9600);
}

unsigned long last_time_debug = 0;
void loop() {

  // heater_001CH->turnOn();
  // delay(500);
  // if (heater_001CH->getStatus()) {
  //   heater_001CH->turnOff();
  //   delay(500);
  // }

  unsigned long time = millis();

  Serial.print("Loop time: ");
  Serial.println(time - last_time_debug);
  last_time_debug = time;

  valve_001VK->loop(time);
  valve_002VK->loop(time);
  valve_003VK->loop(time);
  valve_004VK->loop(time);
  valve_005VK->loop(time);
  valve_006VK->loop(time);
  valve_007VK->loop(time);

  in001SP->loop(time);
  in001SN->loop(time);
  in002SN->loop(time);

  while (nextion->available()) {
    String data = nextion->getCommand();
    Serial.print("Nextion command: ");
    Serial.println(data);



    if (data == "btn_init") {
      valve_001VK->askClose();
      valve_002VK->askClose();
      valve_003VK->askClose();
      valve_004VK->askClose();
      valve_005VK->askPos13();
      valve_006VK->askPos13();
      valve_007VK->askPos13();

      if (heater_001CH->get()) {
        heater_001CH->turnOff();
        if (!heater_001CH->get()) {
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
      if (!heater_001CH->get() && pump_001PO->isOff() && pump_002PO->isOff() && pump_003PO->isOff() && valve_001VK->get() == 0 && valve_002VK->get() == 0 && valve_003VK->get() == 0 && valve_004VK->get() == 0 && valve_005VK->get() == 3 && valve_006VK->get() == 3 && valve_007VK->get() == 3) {
        nextion->print("vis btn_retour,1");
        nextion->print("vis imgRuning,0");
        nextion->print("vis iniOK001PO,1");
        nextion->print("vis iniOK002PO,1");
        nextion->print("vis iniOK003PO,1");
        nextion->print("vis iniOK001CH,1");
        nextion->print("vis iniOK001VK,1");
        nextion->print("vis iniOK002VK,1");
        nextion->print("vis iniOK003VK,1");
        nextion->print("vis iniOK004VK,1");
        nextion->print("vis iniOK005VK,1");
        nextion->print("vis iniOK006VK,1");
        nextion->print("vis iniOK007VK,1");
        nextion->print("vis iniOK001SN,1");
        nextion->print("vis iniOK002SN,1");
        nextion->print("vis iniOK001SP,1");
      }
    }

//ACTION EN MANUEL :

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
    if (data == "Manu_001PO_Off" || in001SP->get()) {
      pump_001PO->turnOff();
    }

    if (data == "Manu_002PO_Low") {
      pump_002PO->turnHalfPower();
    }
    if (data == "Manu_002PO_High") {
      pump_002PO->turnFullPower();
    }
    if (data == "Manu_002PO_Off" || in001SP->get()) {
      pump_002PO->turnOff();
    }

    if (data == "Manu_003PO_Low") {
      pump_003PO->turnHalfPower();
    }
    if (data == "Manu_003PO_High") {
      pump_003PO->turnFullPower();
    }
    if (data == "Manu_003PO_Off" || in001SP->get()) {
      pump_003PO->turnOff();
    }
    if (data == "question_alive") {
      nextion->print("page 1");
    }

//ETABLISSEMENT DIRECT DE LIGNAGES :

    if (data == "Lign_87") {
      valve_001VK->askOpen();
      valve_002VK->askClose();
      valve_003VK->askClose();
      valve_004VK->askOpen();
      valve_005VK->askPos13();
      valve_006VK->askPos13();
      valve_007VK->askPos12();
    }
    if (data == "Lign_88") {
      valve_001VK->askClose();
      valve_002VK->askOpen();
      valve_003VK->askOpen();
      valve_004VK->askClose();
      valve_005VK->askPos13();
      valve_006VK->askPos13();
      valve_007VK->askPos12();
    }
    if (data == "Lign_89") {
      valve_001VK->askOpen();
      valve_002VK->askClose();
      valve_003VK->askClose();
      valve_004VK->askOpen();
      valve_005VK->askPos12();
      valve_006VK->askPos12();
      valve_007VK->askPos13();
    }
    if (data == "Lign_90") {
      valve_001VK->askClose();
      valve_002VK->askOpen();
      valve_003VK->askOpen();
      valve_004VK->askClose();
      valve_005VK->askPos12();
      valve_006VK->askPos12();
      valve_007VK->askPos13();
    }
    if (data == "Lign_91") {
      valve_001VK->askOpen();
      valve_002VK->askClose();
      valve_003VK->askClose();
      valve_004VK->askOpen();
      valve_005VK->askPos13();
      valve_007VK->askPos13();
    }
    if (data == "Lign_93") {
      valve_001VK->askOpen();
      valve_002VK->askClose();
      valve_003VK->askClose();
      valve_004VK->askOpen();
      valve_005VK->askPos12();
      valve_006VK->askPos13();
      valve_007VK->askPos13();
    }
    if (data == "Lign_94") {
      valve_001VK->askClose();
      valve_002VK->askOpen();
      valve_003VK->askOpen();
      valve_004VK->askClose();
      valve_005VK->askPos12();
      valve_006VK->askPos13();
      valve_007VK->askPos13();
    }
    if (data == "Lign_95") {
      valve_001VK->askOpen();
      valve_002VK->askClose();
      valve_003VK->askClose();
      valve_004VK->askOpen();
      valve_005VK->askPos13();
      valve_007VK->askPos13();
    }



//BOUCLE DE RAFRAICHISSEMENT POUR L'ANIMATION SYNOPTIQUE DE L"IHM :
    if (data == "Synopt_refresh")
    {
      //AFFICHAGE IHM
      Synopt_refresh_lignage();
      Synopt_refresh_objects();
    }
  }
}
  //nextion->print(" end IF ");
//}
void Synopt_refresh_lignage() {

  //ANIMATION DES LIGNAGES
  //Lignage img87 (003PO sens 1 vers purge)
  if (valve_001VK->get() == 3 && valve_002VK->get() == 0 && valve_003VK->get() == 0 && valve_004VK->get() == 3 && valve_005VK->get() == 3 && valve_007VK->get() == 0)
  {
    if (!trans_lignage_img87)
    {
      nextion->print("lignage.pic=87");
      resetImages();
      trans_lignage_img87 = true;
    }
    //Lignage img88 (003PO sens 2 vers purge)
  }
  else if (valve_001VK->get() == 0 && valve_002VK->get() == 3 && valve_003VK->get() == 3 && valve_004VK->get() == 0 && valve_005VK->get() == 3 && valve_007VK->get() == 0)
  {
    if (!trans_lignage_img88) {
      nextion->print("lignage.pic=88");
      resetImages();
      trans_lignage_img88 = true;
    }
    //Lignage img89 (001PO sens 1 vers 001BA)
  }
  else if (pump_001PO->get() >= 1 && valve_001VK->get() == 3 && valve_002VK->get() == 0 && valve_003VK->get() == 0 && valve_004VK->get() == 3 && valve_005VK->get() == 0 && valve_006VK->get() == 0 && valve_007VK->get() == 3)
  {
    if (!trans_lignage_img89) {
      nextion->print("lignage.pic=89");
      resetImages();
      trans_lignage_img89 = true;
    }
    //Lignage img90 (001PO sens 2 vers 001BA)
  }
  else if (pump_001PO->get() >= 1 && valve_001VK->get() == 0 && valve_002VK->get() == 3 && valve_003VK->get() == 3 && valve_004VK->get() == 0 && valve_005VK->get() == 0 && valve_006VK->get() == 0 && valve_007VK->get() == 3)
  {
    if (!trans_lignage_img90) {
      nextion->print("lignage.pic=90");
      resetImages();
      trans_lignage_img90 = true;
    }
    //Lignage img91 (001PO sens 1 vers purge)
  }
  else if (pump_001PO->get() >= 1 && valve_001VK->get() == 3 && valve_002VK->get() == 0 && valve_003VK->get() == 0 && valve_004VK->get() == 3 && valve_005VK->get() == 3 && valve_007VK->get() == 3)
  {
    if (!trans_lignage_img91) {
      nextion->print("lignage.pic=91");
      resetImages();
      trans_lignage_img91 = true;
    }
    //Lignage img92 (001PO sens 2 vers purge)
  }
  else if (pump_001PO->get() >= 1 && valve_001VK->get() == 0 && valve_002VK->get() == 3 && valve_003VK->get() == 3 && valve_004VK->get() == 0 && valve_005VK->get() == 3 && valve_007VK->get() == 3)
  {
    if (!trans_lignage_img92) {
      nextion->print("lignage.pic=92");
      resetImages();
      trans_lignage_img92 = true;
    }
    //Lignage img93 (002PO sens 1 vers 002BA)
  }
  else if (pump_002PO->get() >= 1 && valve_001VK->get() == 3 && valve_002VK->get() == 0 && valve_003VK->get() == 0 && valve_004VK->get() == 3 && valve_005VK->get() == 0 && valve_006VK->get() == 3 && valve_007VK->get() == 3)
  {
   if (!trans_lignage_img93) {
      nextion->print("lignage.pic=93");
      resetImages();
      trans_lignage_img93 = true;
    }
    //Lignage img94 (002PO sens 2 vers 002BA)
  }
  else if (pump_002PO->get() >= 1 && valve_001VK->get() == 0 && valve_002VK->get() == 3 && valve_003VK->get() == 3 && valve_004VK->get() == 0 && valve_005VK->get() == 0 && valve_006VK->get() == 3 && valve_007VK->get() == 3)
  {
    if (!trans_lignage_img94) {
      nextion->print("lignage.pic=94");
      resetImages();
      trans_lignage_img94 = true;
    }
    //Lignage img95 (002PO sens 1 vers purge)
  }
  else if (pump_002PO->get() >= 1 && valve_001VK->get() == 3 && valve_002VK->get() == 0 && valve_003VK->get() == 0 && valve_004VK->get() == 3 && valve_005VK->get() == 3 && valve_007VK->get() == 3)
  {
    if (!trans_lignage_img95) {
      nextion->print("lignage.pic=95");
      resetImages();
      trans_lignage_img95 = true;
    }
    //Lignage img96 (002PO sens 2 vers purge)
  }
  else if (pump_002PO->get() >= 1 && valve_001VK->get() == 0 && valve_002VK->get() == 3 && valve_003VK->get() == 3 && valve_004VK->get() == 0 && valve_005VK->get() == 3 && valve_007VK->get() == 3)
  {
    if (!trans_lignage_img96) {
      nextion->print("lignage.pic=96");
      resetImages();
      trans_lignage_img96 = true;
    }
    //Lignage img97 (003PO sens 0 vers purge)
  }
  else if (valve_001VK->get() == 3 && valve_002VK->get() == 3 && valve_003VK->get() == 3 && valve_004VK->get() == 3 && valve_005VK->get() == 3 && valve_007VK->get() == 0)
  {
    if (!trans_lignage_img97) {
      nextion->print("lignage.pic=97");
      resetImages();
      trans_lignage_img97 = true;
    }
  }
  else
  {
    if (!trans_lignage_img101)
    {
      nextion->print("lignage.pic=101");
      resetImages();
      trans_lignage_img101 = true;
    }
  }
}

int Synopt_refresh_valve(Valve* valve, int lastStatus, String name, int pic1, int pic2, int pic3, int pic4) {
  int newStatus = valve->get();
  if (lastStatus == newStatus) {
    return newStatus;
  }
  switch (newStatus) {
    case VALVE_CLOSE:
      nextion->print(name + ".pic=" + String(pic1));
      break;
    case VALVE_CLOSING:
      nextion->print(name + ".pic=" + String(pic2));
      break;
    case VALVE_OPENING:
      nextion->print(name + ".pic=" + String(pic3));
      break;
    case VALVE_OPEN:
      nextion->print(name + ".pic=" + String(pic4));
      break;
  }
  return newStatus;
}

int Synopt_refresh_pump(Pump* pump, int lastStatus, String name, int pic1, int pic2, int pic3) {
  int newStatus = pump->get();
  if (lastStatus == newStatus) {
    return newStatus;
  }
  switch (newStatus) {
    case 0:
      nextion->print(name + ".pic=" + String(pic1));
      break;
    case 1:
      nextion->print(name + ".pic=" + String(pic2));
      break;
    case 2:
      nextion->print(name + ".pic=" + String(pic3));
      break;
  }
  return newStatus;
}

int cacheValve_001VK = -1;
int cacheValve_002VK = -1;
int cacheValve_003VK = -1;
int cacheValve_004VK = -1;
int cacheValve_005VK = -1;
int cacheValve_006VK = -1;
int cacheValve_007VK = -1;

int cachePump_001PO = -1;
int cachePump_002PO = -1;
int cachePump_003PO = -1;

void Synopt_refresh_objects() {

  //in001SN
  if (!in001SN->get()) {
    nextion->print("img001BA.pic=1");
  } else {
    nextion->print("img001BA.pic=2");
  }

  //in002SN
  if (!in002SN->get()) {
    nextion->print("img002BA.pic=1");
    nextion->print("vis img001CH,1");
  } else {
    nextion->print("img002BA.pic=2");
    nextion->print("vis img001CH,1");
  }

  //in001SP
  if (!in001SP->get()) {
    nextion->print("img001SP.pic=19");
  } else {
    nextion->print("img001SP.pic=20");
  }

  cacheValve_001VK = Synopt_refresh_valve(valve_001VK, cacheValve_001VK, "img001VK", 21, 23, 22, 24);
  cacheValve_002VK = Synopt_refresh_valve(valve_002VK, cacheValve_002VK, "img002VK", 21, 23, 22, 24);
  cacheValve_003VK = Synopt_refresh_valve(valve_003VK, cacheValve_003VK, "img003VK", 21, 23, 22, 24);
  cacheValve_004VK = Synopt_refresh_valve(valve_004VK, cacheValve_004VK, "img004VK", 21, 23, 22, 24);
  cacheValve_005VK = Synopt_refresh_valve(valve_005VK, cacheValve_005VK, "img005VK", 28, 26, 27, 25);
  cacheValve_006VK = Synopt_refresh_valve(valve_006VK, cacheValve_006VK, "img006VK", 6, 4, 5, 3);
  cacheValve_007VK = Synopt_refresh_valve(valve_007VK, cacheValve_007VK, "img007VK", 6, 4, 5, 3);

  cachePump_001PO = Synopt_refresh_pump(pump_001PO, cachePump_001PO, "img001PO", 29, 30, 31);
  cachePump_002PO = Synopt_refresh_pump(pump_002PO, cachePump_002PO, "img002PO", 29, 30, 31);
  cachePump_003PO = Synopt_refresh_pump(pump_003PO, cachePump_003PO, "img003PO", 9, 10, 11);
}

void resetImages() {
  trans_lignage_img87 = false;
  trans_lignage_img88 = false;
  trans_lignage_img89 = false;
  trans_lignage_img90 = false;
  trans_lignage_img91 = false;
  trans_lignage_img92 = false;
  trans_lignage_img93 = false;
  trans_lignage_img94 = false;
  trans_lignage_img95 = false;
  trans_lignage_img96 = false;
  trans_lignage_img97 = false;
  trans_lignage_img98 = false;
  trans_lignage_img99 = false;
  trans_lignage_img100 = false;
  trans_lignage_img101 = false;

  cacheValve_001VK = -1;
  cacheValve_002VK = -1;
  cacheValve_003VK = -1;
  cacheValve_004VK = -1;
  cacheValve_005VK = -1;
  cacheValve_006VK = -1;
  cacheValve_007VK = -1;

  cachePump_001PO = -1;
  cachePump_002PO = -1;
  cachePump_003PO = -1;
}
