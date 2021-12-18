#ifndef CONFIG_H
#define CONFIG_H

#define MAX_CHAR 50
#define MAX_COMMANDS 10

//definimos cantidad de lineas de address y num maximo 2^20
#define ADDR_LINES 20      //definimos tamaño del bus
//uint32_t MAX_ADDR = pow(2, ADDR_LINES);   //calculamos el valor maximo del bus
#define MAX_ADDR (pow(2, ADDR_LINES))//calculamos el valor maximo del bus

#endif
