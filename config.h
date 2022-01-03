#ifndef config_h
#define config_h

#define MAX_CHAR 50
#define MAX_COMMANDS 10

//definimos cantidad de lineas de address y num maximo 2^20
#define ADDR_LINES 20      //definimos tamaño del bus
//uint32_t MAX_ADDR = pow(2, ADDR_LINES);   //calculamos el valor maximo del bus
#define MAX_ADDR (pow(2, ADDR_LINES)) //calculamos el valor maximo del bus

typedef enum  {DP0, DP1, DP2, DP3, DP4, DP5, DP6, DP7, UNKNOWOP, READ = 9, WRITE = 10, OUTDIS = 11, STB12, STB13, STB14, STB15} OPERATIONS;
typedef enum  {M0, M1, M2, M3, M4, M5, M6, M7} SELECTION;
typedef enum  {DISABLE_MEM= 0, ENABLE_MEM = 1} ENABLEDIS;


//libout
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
void configuration();

//librsc
String readCommands();
void limpiarComandos();


//menu
void printMenu();
void SubMenu();

// Outputs
#define RPPin     38
#define OEPin     39
#define WEPin     40

#define A138Pin   28
#define B138Pin   29
#define C138Pin   30
#define G2APin    31
#define G2BPin    32
#define G1Pin     33

#define ADDR0     0
#define ADDR1     1
#define ADDR2     2
#define ADDR3     3
#define ADDR4     4
#define ADDR5     5
#define ADDR6     6
#define ADDR7     7
#define ADDR8     8
#define ADDR9     9
#define ADDR10    10
#define ADDR11    11
#define ADDR12    12
#define ADDR13    13
#define ADDR14    14
#define ADDR15    15
#define ADDR16    16
#define ADDR17    17
#define ADDR18    18
#define ADDR19    19
#define DATA0     20
#define DATA1     21
#define DATA2     22
#define DATA3     23
#define DATA4     24
#define DATA5     25
#define DATA6     26
#define DATA7     27

#endif
