#ifndef RGB_H_INCLUDED
#define RGB_H_INCLUDED

#include "utilitaire.h"
#include <Arduino.h>
#include <Wire.h>

#define APDS9960_ADR  0x39
#define APDS9960_ID   0xAB

#ifndef VAR         // protect your global variables
#define VAR

static String        SERIAL_STRING;
static unsigned char DATA_U,DATA_D,DATA_L,DATA_R;
static unsigned char OLD_U,OLD_D,OLD_L,OLD_R;
static unsigned char work;
static unsigned char U_PEAK_END_FLAG,D_PEAK_END_FLAG,L_PEAK_END_FLAG,R_PEAK_END_FLAG;
static unsigned char STATUS_UD,STATUS_LR;
static unsigned char OLD_STATUS_UD,OLD_STATUS_LR;
static unsigned char DISP_FLAG;
static unsigned char NOISE_LEVEL = 2;
static unsigned char DECIDE_FLAG;
static unsigned int  PHASE_COUNTER;
static unsigned int  U_PEAK,D_PEAK,L_PEAK,R_PEAK;
static int distance=0;

#else

extern String        SERIAL_STRING;
extern unsigned char DATA_U,DATA_D,DATA_L,DATA_R;
extern unsigned char OLD_U,OLD_D,OLD_L,OLD_R;
extern unsigned char work;
extern unsigned char U_PEAK_END_FLAG,D_PEAK_END_FLAG,L_PEAK_END_FLAG,R_PEAK_END_FLAG;
extern unsigned char STATUS_UD,STATUS_LR;
extern unsigned char OLD_STATUS_UD,OLD_STATUS_LR;
extern unsigned char DISP_FLAG;
extern unsigned char NOISE_LEVEL = 2;
extern unsigned char DECIDE_FLAG;
extern unsigned int  PHASE_COUNTER;
extern unsigned int  U_PEAK,D_PEAK,L_PEAK,R_PEAK;
extern int distance=0;

#endif

void I2C_WRITE(unsigned char REG_ADR, unsigned char DATA);
char I2C_READ(unsigned char REG_ADR);
void RESET_VARIABLE(void);
void DATA_SYORI(void);

void start_rgb(void);             //void setup
String continued_rgb(void);      //  void loop
int get_Distance(void);
String DISP_DIR(void);
#endif
