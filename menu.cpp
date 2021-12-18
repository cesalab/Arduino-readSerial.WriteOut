#include "Arduino.h"
#include "config.h"

void printMenu(){
    Serial.println("Serial OUT 2 test ...");
    Serial.println("Iniciando...");  
    Serial.println("\nCOMANDOS...");  
    Serial.println("\tADDR ########\t(# en DECIMAL)");  
    Serial.println("\tADDR ALL\t(Realiza secuencia completa)"); 
    Serial.println("\tDATA ####\t(# en DECIMAL)"); 
    Serial.println("\tDATA ALL\t(Realiza secuencia completa)"); 
    Serial.println("\tM0 M1 M2 M3 M4 M5 M6 M7\t(Selecciona Memoria 138)");  
    Serial.println("\tREAD WRITE OUTDIS\t(Realiza Operacion en Memoria)"); 
    Serial.println("\tENABLE DISABLE\t(Habilita o Deshabilita MEMORY 138)");
    Serial.print("\nMAX_ADDR: ");     Serial.println(MAX_ADDR);
    Serial.println("\tRANDOM"); 
    Serial.println("\tRANDOM ALL"); 
}
