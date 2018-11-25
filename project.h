#ifndef _MAIN_H
#define _MAIN_H

#include "msp430.h"

#define DCO_FREQ 16*1e6
/* interval in ms */
#define TIMER_INTERVAL 200
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0
#define RED_LED 0
#define GREEN_LED 1
#define HIGH_TONE 900
#define LOW_TONE 200

typedef unsigned char tByte;
typedef unsigned int tWord;
typedef unsigned long tLong;

#endif
