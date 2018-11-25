#include "project.h"
#include "ports.h"

#include "led.h"
#include "timer.h"

/* DELAY in ms */
void Led_Init() {
  /* Turn off both leds */
  //Led_Set(RED, ON);
  //Led_Set(GREEN, OFF);
  LED_PORT_DIRECTION |= RED_LED_PIN;
  LED_PORT |= RED_LED_PIN;
}
/*
void Led_Set(tByte LED, tByte STATE) {
  switch(LED) {
    case RED:
      if(STATE == ON){
        LED_PORT_DIRECTION |= RED_LED_PIN;
        LED_PORT |= RED_LED_PIN;
      }
      else{
        LED_PORT_DIRECTION &= ~(RED_LED_PIN);
      }
    case GREEN:
    if(STATE == ON){
        LED_PORT_DIRECTION |= GREEN_LED_PIN;
        LED_PORT |= GREEN_LED_PIN;
      }
      else{
        LED_PORT_DIRECTION &= ~(GREEN_LED_PIN);
      }
  }
}
*/

void Led_OFF() {
  LED_PORT &= ~(RED_LED_PIN);
}

void Led_ON() {
  LED_PORT |= RED_LED_PIN;
}

void Led_Switch() {
  LED_PORT ^= RED_LED_PIN;
}