#include "Arduino.h"
#include "config.h"
extern int SETDELAY;

void printMenu(){
    Serial.println("\n________________________");
    Serial.println("\nSerial OUT 2 test SET...");
    Serial.println("Iniciando...");  
    Serial.print("\nMAX_ADDR: ");     Serial.print(MAX_ADDR);
    Serial.print("\nDELAY = "); Serial.print(SETDELAY);   Serial.println(" ms (default)");
    
    Serial.println("\nCOMANDOS...");  
    Serial.println("\tADDR ########           (# en DECIMAL)");  
    Serial.println("\tADDR ALL                (Realiza secuencia completa)"); 
    Serial.println("\t STOP                   (Detiene secuencia) "); 
    Serial.println("\tDATA ####               (# en DECIMAL)"); 
    Serial.println("\tDATA ALL                (Realiza secuencia completa)"); 
    Serial.println("\tM0 M1 M2 M3 M4 M5 M6 M7 (Selecciona Memoria 138)");  
    Serial.println("\tREAD WRITE OUTDIS       (Realiza Operacion en Memoria)"); 
    Serial.println("\tENABLE DISABLEN         (Habilita o Deshabilita MEMORY 138)");
    Serial.println("\tRANDOM                  (genera valores aleatorios)");  
    Serial.println("\tRANDOM ALL              (Realiza secuencia de valores aleatorios)"); 
    Serial.println("\t STOP                   (Detiene secuencia) "); 
    Serial.println("\tMENU");  
    Serial.println("\tCONFIG\n"); 


    

}

void SubMenu(){

      Serial.println("\nSubMenu Config\n...");  
      Serial.println("\tPRINT   ON/OFF    (Para monstrar u ocultar en los cmds ALL)");  
      Serial.println("\tSETDELAY  ####    (Configurar el delay entre cada cambio en cmd ALL)\n"); 
      Serial.println("\tEXIT              (salir del MENU CONFIG)\n"); 


}
