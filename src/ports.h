#ifndef _PORTS_H
#define _PORTS_H

#include "project.h"

#define LED_PORT_DIRECTION P1DIR
#define LED_PORT P1OUT

#define RED_LED_PIN (0x01)
#define GREEN_LED_PIN (0x40)

#define SWITCH_PORT_DIRECTION P1DIR
#define SWITCH_INPUT P1IN
#define SWITCH_PORT P1OUT
#define SWITCH_PIN (0x08)

#endif
