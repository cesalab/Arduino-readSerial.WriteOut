#include "Arduino.h"
#include "enums.h"
#include "gpio.h"
#include "config.h"
#include "librsc.h"

uint32_t numberADDR = 0;
uint8_t numberDATA = 0;
extern String stringSplit[];
int SETDELAY = 200;     //200 ms time default 
bool flagprint = true; //default

void writeAddr(uint32_t var, uint8_t pinStart, uint8_t pinFinal) {
  uint32_t mask = 0x01;
  for (int i = pinStart; i <= pinFinal; i++) {
    if ((mask & var) != 0) {
      digitalWrite(i, HIGH);
    } else { 
      digitalWrite(i, LOW);
    }
    mask = mask << 1;
  }
}


void convertStrToEnum(String xin){

    if (xin == "READ")
        OP_MODE = READ;
    else if (xin == "WRITE")
        OP_MODE = WRITE;
    else if (xin == "OUTDIS")
        OP_MODE = OUTDIS;
    
    else if (xin == "M0")
        MEMORY = M0;
    else if (xin == "M1")
        MEMORY = M1;
    else if (xin == "M2")
        MEMORY = M2;
    else if (xin == "M3")
        MEMORY = M3;
    else if (xin == "M4")
        MEMORY = M4;
    else if (xin == "M5")
        MEMORY = M5;
    else if (xin == "M6")
        MEMORY = M6;
    else if (xin == "M7")
        MEMORY = M7;
        
    else if (xin == "ENABLE")
        ED_MEM = ENABLE_MEM;
    else if (xin == "DISABLE")
        ED_MEM = DISABLE_MEM;
}


void control_mode(String xin){
    String tempStr = "";

  switch (OP_MODE){
      case READ:
            Serial.print("READ\t\t");
            writeAddr(READ, RPPin, WEPin);
            SETDELAY = 400; 
            break;
      case WRITE:
            Serial.print("WRITE\t\t");
            writeAddr(WRITE, RPPin, WEPin);
            break;
      case OUTDIS:
            Serial.print("OUTPUT DISABLE\t");
            writeAddr(OUTDIS, RPPin, WEPin);
            break;
      default:
            //Serial.println("comando NO RECONOCIDO OP_MODE... ");
            break;            
    }
   //if (flagprint)
      Serial.print(tempStr);
}


void control_mode(long xin){
    String tempStr = "";
  OP_MODE = xin;
  switch (OP_MODE){
      case READ:
            Serial.print("READ\t\t");
            writeAddr(READ, RPPin, WEPin);
            break;
      case WRITE:
            Serial.print("WRITE\t\t");
            writeAddr(WRITE, RPPin, WEPin);
            break;
      case OUTDIS:
            Serial.print("OUTPUT DISABLE\t");
            writeAddr(OUTDIS, RPPin, WEPin);
            break;
      default:
            //Serial.println("comando NO RECONOCIDO OP_MODE... ");
            break;     
            
    }
   //if (flagprint)
      Serial.print(tempStr);
}


void selection_mem(String xin){
  String tempStr = "";

  switch (MEMORY){
      case M0:
            tempStr = "M0 ";
            writeAddr(M0, A138Pin, C138Pin);
            break;
      case M1:
            tempStr = "M1 ";
            writeAddr(M1, A138Pin, C138Pin);
            break;
      case M2:
            tempStr = "M2 ";
            writeAddr(M2, A138Pin, C138Pin);
            break;
      case M3:
            tempStr = "M3 ";
            writeAddr(M3, A138Pin, C138Pin);
            break;
      case M4:
            tempStr = "M4 ";
            writeAddr(M4, A138Pin, C138Pin);
            break;
      case M5:
            tempStr = "M5 ";
            writeAddr(M5, A138Pin, C138Pin);
            break;
      case M6:
            tempStr = "M6 ";
            writeAddr(M6, A138Pin, C138Pin);
            break;
      case M7:
            tempStr = "M7 ";
            writeAddr(M7, A138Pin, C138Pin);
            break;
      default:
            //Serial.println("NO select memory... ");  
            break;     
            
    }
   //if (flagprint)
      Serial.print(tempStr);
}


void selection_mem(long xin){
  String tempStr = "";
  MEMORY = xin;
  switch (MEMORY){
      case M0:
            tempStr = "M0 ";
            writeAddr(M0, A138Pin, C138Pin);
            break;
      case M1:
            tempStr = "M1 ";
            writeAddr(M1, A138Pin, C138Pin);
            break;
      case M2:
            tempStr = "M2 ";
            writeAddr(M2, A138Pin, C138Pin);
            break;
      case M3:
            tempStr = "M3 ";
            writeAddr(M3, A138Pin, C138Pin);
            break;
      case M4:
            tempStr = "M4 ";
            writeAddr(M4, A138Pin, C138Pin);
            break;
      case M5:
            tempStr = "M5 ";
            writeAddr(M5, A138Pin, C138Pin);
            break;
      case M6:
            tempStr = "M6 ";
            writeAddr(M6, A138Pin, C138Pin);
            break;
      case M7:
            tempStr = "M7 ";
            writeAddr(M7, A138Pin, C138Pin);
            break;
      default:
            //Serial.println("NO select memory... ");  
            break;     
            
    }
   //if (flagprint)
      Serial.print(tempStr);
}


void enableDisable_mem(String xin){
  String tempStr = "";

  switch (ED_MEM){
      case ENABLE_MEM:
            tempStr = "ENABLE__138\t";
            writeAddr(ENABLE_MEM, G2APin, G1Pin);
            break;
      case DISABLE_MEM:
            tempStr = "DISABLE_138\t";
            writeAddr(DISABLE_MEM, G2APin, G1Pin);
            break;
      default:
            //Serial.println("comando NO RECONOCIDO enable/disable... ");  
            break;     
            
    }
   //if (flagprint)
      Serial.print(tempStr);
}


void enableDisable_mem(long xin){
  String tempStr = "";
  ED_MEM = xin;
  switch (ED_MEM){
      case ENABLE_MEM:
            tempStr = "ENABLE__138\t";
            writeAddr(ENABLE_MEM, G2APin, G1Pin);
            break;
      case DISABLE_MEM:
            tempStr = "DISABLE_138\t";
            writeAddr(DISABLE_MEM, G2APin, G1Pin);
            break;
      default:
            //Serial.println("comando NO RECONOCIDO enable/disable... ");  
            break;     
            
    }
   //if (flagprint)
      Serial.print(tempStr);
}


void address_mode(String xin0, String xin1){
      if (xin0 == "ADDR"){
          if(xin1 == "ALL"){
            unsigned long currentMillis = millis(); 
              for(uint16_t k = 0; k < MAX_ADDR; k++){
                  writeAddr(k, ADDR0, ADDR0 + ADDR_LINES);
                  if ( flagprint){
                      Serial.print("ADDR: ");  Serial.println(k); 
                  }

                  //delayMicroseconds(10);

                  if (Serial.available() > 0) {
                        // read the commands:
                        String x = readCommands(); 
                        if(x == "STOP")
                            break;
                  }  
                  
              }
              long durationTime = millis() - currentMillis;
              Serial.print("TIME ADDR ALL EXEC = "); Serial.print(durationTime); Serial.println(" ms");
              xin0 = "FINISH";
              numberADDR = MAX_ADDR - 1;
          }
          else{
              numberADDR = xin1.toInt();
              writeAddr(numberADDR, ADDR0, ADDR0 + ADDR_LINES);
          }
      }
      Serial.print("ADDR: ");
      if (numberADDR < 16)      
          Serial.print("0");
      Serial.print(numberADDR, HEX);    Serial.print("\t");
}


void data_mode(String xin0, String xin1){
      if (xin0 == "DATA"){
          if(xin1 == "ALL"){
            bool activeflag = true;
            unsigned long currentMillis = micros(); 
              for(uint16_t k = 0; k < 256; k++){
                  writeAddr(k, DATA0, DATA7);
                   if ( flagprint){
                      Serial.print("DATA: ");  Serial.println(k); 
                   }

                  //delayMicroseconds(10);
                  //delayMicroseconds(10);
                  if (Serial.available() > 0) {
                      // read the commands:
                      String x = readCommands(); 
                      if(x == "STOP")
                          break;
                      activeflag = false;
                  }  
                  if (SETDELAY)
                    delay(SETDELAY); 
              }
              long durationTime = micros() - currentMillis;
              Serial.print("TIME DATA ALL EXEC = "); Serial.print(durationTime); Serial.println(" us");
              xin0 = "finished";
              numberDATA = 255;
          }
          else{
              numberDATA = xin1.toInt();
              writeAddr(numberDATA, DATA0, DATA7);
          }
      }
      Serial.print("DATA: ");
      if (numberDATA < 16)      
          Serial.print("0");
      Serial.print(numberDATA, HEX);   Serial.print("\t");
}


 void random_mode(){
      if(stringSplit[0] == "RANDOM" && stringSplit[1] == "ALL"){
          bool activeflag = true;

          while(activeflag){
                randomSeed(millis());
                convertStrToEnum(stringSplit[0]);
                address_mode("ADDR", random(0xFFFFF));
                data_mode("DATA", random(0xFF));
                control_mode(random(9, 12));
                enableDisable_mem(random(2));
                selection_mem(random(8));
                Serial.println();
                if (Serial.available() > 0) {
                    // read the commands:
                    String x = readCommands(); 
                    if(x == "STOP")
                    activeflag = false;
                }  
                if (SETDELAY)
                  delay(SETDELAY);
          }
      }
      else {
            randomSeed(millis());
            convertStrToEnum(stringSplit[0]);
            address_mode("ADDR", random(0xFFFFF));
            data_mode("DATA", random(0xFF));
            control_mode(random(9, 12));
            enableDisable_mem(random(2));
            selection_mem(random(8));
      }
}


void configuration(){
  
      SubMenu();

      Serial.print("\tPREVIO DELAY = "); Serial.print(SETDELAY);   Serial.println(" ms");
      Serial.print("\tPRINT MENSAJES = "); if (flagprint)  Serial.println("ACTIVE");  else  Serial.println("DISABLE");

      while(1){

            readCommands();   
      
            if(stringSplit[0] == "PRINT"){
                    if (stringSplit[1] == "ON")
                          flagprint = true;
                    if (stringSplit[1] == "OFF")
                          flagprint = false;
      
              Serial.print("NOW PRINT MENSAJES = "); if (flagprint)  Serial.println("ACTIVE");  else  Serial.println("DISABLE");
            
            }
      
             if(stringSplit[0] == "SETDELAY"){
      
             int number = stringSplit[1].toInt();
             
             
                if (number > 0)
                    SETDELAY = number;
                else if (number == 0)
                    SETDELAY = number;
                else
                    Serial.print("error en configurar DELAY");
      
               Serial.print("NEW DELAY = "); Serial.print(SETDELAY);   Serial.println(" ms");
      
             }  

             if(stringSplit[0] == "EXIT"){
                break;
             }
      }  
}
