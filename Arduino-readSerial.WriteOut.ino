/*
 *  * teensy 2++ 2.0
 * 
 * JASAVM 
 */
#include "config.h"


extern String stringSplit[];


void setup() {
    Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
    //Serial.setTimeout(200);
    while (!Serial);  // Wait for Arduino Serial Monitor to open
          delay(100);
    printMenu();
    for (int i = 0; i <= 45; i++) {
        pinMode(i, OUTPUT);
        digitalWrite(i,LOW);
    }
    //inicializamos valores
    address_mode("ADDR", "0");
    data_mode("DATA", "0");
    control_mode("READ");
    enableDisable_mem("ENABLE");
    selection_mem("M0");
    Serial.println();
}

void loop() {
      // reply only when you receive data:
      if (Serial.available() > 0) {
          // read the commands:
          readCommands();   

          if(stringSplit[0] == "MENU")
              printMenu();
          
          if(stringSplit[0] == "CONFIG")
              configuration();
          
          if(stringSplit[0] == "RANDOM" ){
              random_mode();
              //SETDELAY = 300; 
          }else{
           
          convertStrToEnum(stringSplit[0]);
          address_mode(stringSplit[0], stringSplit[1]);
          data_mode(stringSplit[0], stringSplit[1]);
          control_mode(stringSplit[0]);
          enableDisable_mem(stringSplit[0]);
          selection_mem(stringSplit[0]);
          }
          limpiarComandos();
          Serial.println();
      }
}
