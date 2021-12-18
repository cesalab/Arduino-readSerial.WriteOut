#ifndef LIBOUT_H
#define LIBOUT_H

#include "Arduino.h"

void writeAddr(uint32_t var, uint8_t pinStart, uint8_t pinFinal) ;
void convertStrToEnum();
void control_mode(String);
void control_mode(long);
void selection_mem(String);
void selection_mem(long);
void enableDisable_mem(String);
void enableDisable_mem(long);
void convertStrToEnum(String);
void address_mode(String, String);
void data_mode(String, String);
void random_mode();

#endif
