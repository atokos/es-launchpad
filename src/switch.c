#include "project.h"
#include "ports.h"

#include "switch.h"

void Switch_Init(void) {
    SWITCH_PORT_DIRECTION &= ~SWITCH_PIN;
    SWITCH_PORT |= SWITCH_PIN;
    P1REN |= SWITCH_PIN; // Enable pullup resistor for switch
    P1IE |= SWITCH_PIN; // Make P1.3 interrupt pin
}

int isPressed() {
    if((SWITCH_INPUT & SWITCH_PIN) == SWITCH_PIN){
        return FALSE;
    }
    else{
        return TRUE;
    }
}