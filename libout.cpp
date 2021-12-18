#include "Arduino.h"
#include "enums.h"
#include "gpio.h"
#include "config.h"
#include "librsc.h"

uint32_t numberADDR = 0;
uint8_t numberDATA = 0;
extern String stringSplit[];

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
    
}


void control_mode(long xin){
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
    
}


void selection_mem(String xin){

  switch (MEMORY){
      case M0:
            Serial.println("M0 ");
            writeAddr(M0, A138Pin, C138Pin);
            break;
      case M1:
            Serial.println("M1 ");
            writeAddr(M1, A138Pin, C138Pin);
            break;
      case M2:
            Serial.println("M2 ");
            writeAddr(M2, A138Pin, C138Pin);
            break;
      case M3:
            Serial.println("M3 ");
            writeAddr(M3, A138Pin, C138Pin);
            break;
      case M4:
            Serial.println("M4 ");
            writeAddr(M4, A138Pin, C138Pin);
            break;
      case M5:
            Serial.println("M5 ");
            writeAddr(M5, A138Pin, C138Pin);
            break;
      case M6:
            Serial.println("M6 ");
            writeAddr(M6, A138Pin, C138Pin);
            break;
      case M7:
            Serial.println("M7 ");
            writeAddr(M7, A138Pin, C138Pin);
            break;
      default:
            //Serial.println("NO select memory... ");  
            break;     
            
    }
    
}


void selection_mem(long xin){
  MEMORY = xin;
  switch (MEMORY){
      case M0:
            Serial.println("M0 ");
            writeAddr(M0, A138Pin, C138Pin);
            break;
      case M1:
            Serial.println("M1 ");
            writeAddr(M1, A138Pin, C138Pin);
            break;
      case M2:
            Serial.println("M2 ");
            writeAddr(M2, A138Pin, C138Pin);
            break;
      case M3:
            Serial.println("M3 ");
            writeAddr(M3, A138Pin, C138Pin);
            break;
      case M4:
            Serial.println("M4 ");
            writeAddr(M4, A138Pin, C138Pin);
            break;
      case M5:
            Serial.println("M5 ");
            writeAddr(M5, A138Pin, C138Pin);
            break;
      case M6:
            Serial.println("M6 ");
            writeAddr(M6, A138Pin, C138Pin);
            break;
      case M7:
            Serial.println("M7 ");
            writeAddr(M7, A138Pin, C138Pin);
            break;
      default:
            //Serial.println("NO select memory... ");  
            break;     
            
    }
    
}


void enableDisable_mem(String xin){

  switch (ED_MEM){
      case ENABLE_MEM:
            Serial.print("ENABLE__138\t");
            writeAddr(ENABLE_MEM, G2APin, G1Pin);
            break;
      case DISABLE_MEM:
            Serial.print("DISABLE_138\t");
            writeAddr(DISABLE_MEM, G2APin, G1Pin);
            break;
      default:
            //Serial.println("comando NO RECONOCIDO enable/disable... ");  
            break;     
            
    }
}


void enableDisable_mem(long xin){
  ED_MEM = xin;
  switch (ED_MEM){
      case ENABLE_MEM:
            Serial.print("ENABLE__138\t");
            writeAddr(ENABLE_MEM, G2APin, G1Pin);
            break;
      case DISABLE_MEM:
            Serial.print("DISABLE_138\t");
            writeAddr(DISABLE_MEM, G2APin, G1Pin);
            break;
      default:
            //Serial.println("comando NO RECONOCIDO enable/disable... ");  
            break;     
            
    }
}


void address_mode(String xin0, String xin1){
      if (xin0 == "ADDR"){
          if(xin1 == "ALL"){
            unsigned long currentMillis = millis(); 
              for(uint16_t k = 0; k < MAX_ADDR; k++){
                  writeAddr(k, ADDR0, ADDR0 + ADDR_LINES);
                  //Serial.print("ADDR: ");  Serial.println(k); 
                  //delayMicroseconds(10);
                  if (Serial.available() > 0) {
                        // read the commands:
                        String x = sendCommands(); 
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
            unsigned long currentMillis = micros(); 
              for(uint16_t k = 0; k < 256; k++){
                  writeAddr(k, DATA0, DATA7);
                  //Serial.print("DATA: ");   Serial.println(k); 
                  //delayMicroseconds(10);
                  if (Serial.available() > 0) {
                              // read the commands:
                              String x = sendCommands(); 
                              if(x == "STOP")
                                  break;
                  }  
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
                if (Serial.available() > 0) {
                    // read the commands:
                    String x = sendCommands(); 
                    if(x == "STOP")
                    activeflag = false;
                }  
                delay(200);
          }
      }
      else {
            randomSeed(millis());
            convertStrToEnum(stringSplit[0]);
            address_mode("ADDR", random(0xFFFFF));
            data_mode("DATA", random(0xFF));
            control_mode(String(random(9, 12)));
            enableDisable_mem(String(random(2)));
            selection_mem(String(random(8)));
      }
}
