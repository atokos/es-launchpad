#include "project.h"

#include "led.h"
#include "uart.h"

tLight_State TRAFFIC_state_G;
tWord TRAFFIC_time_in_state_G;
tWord gotoGreen;

/* Durations are supplied in seconds */
#define RED_DURATION ((5 * 1000) / TIMER_INTERVAL)
#define RED_GREEN_DURATION ((0.5 * 1000) / TIMER_INTERVAL)
#define GREEN_DURATION ((5 * 1000) / TIMER_INTERVAL)
#define GREEN_RED_DURATION ((0.5 * 1000) / TIMER_INTERVAL)
#define AMBER_DURATION ((5 * 1000) / TIMER_INTERVAL)


Traffic_Init(void) {
    TRAFFIC_state_G = AMBER;
    tWord TRAFFIC_time_in_state_G = 0;
    tWord gotoGreen = FALSE;
}

Traffic_Update(void) {

    /* Check if switch is pressed */
    if(isPressed() == TRUE){
      gotoGreen = TRUE;
    }

    TRAFFIC_time_in_state_G++;

    switch(TRAFFIC_state_G){
        case RED:
            /* Turn red led on, green off */
            Led_Set(RED, ON);
            Led_Set(GREEN, OFF);
            if((TRAFFIC_time_in_state_G > RED_DURATION ) || gotoGreen) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = RED_GREEN;
                gotoGreen = FALSE;
                UART_Write("Switching to RED_GREEN state ");
                break;
            }
            break;

        case RED_GREEN:
            /* Turn red led on, green on */
            Led_Set(RED, ON);
            Led_Set(GREEN, ON);
            if(TRAFFIC_time_in_state_G > RED_GREEN_DURATION) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = GREEN;
                UART_Write("Switchin to GREEN state ");
                break;
            }
            break;

        case GREEN:
            /* Turn red led off, green oon */
            Led_Set(RED, OFF);
            Led_Set(GREEN, ON);
            if(TRAFFIC_time_in_state_G > GREEN_DURATION) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = GREEN_RED;
                UART_Write("Switching to GREEN_RED state ");
                break;
            }
            break;

        case GREEN_RED:
            /* Turn red led on, green on */
            Led_Set(RED, ON);
            Led_Set(GREEN, ON);
            if(TRAFFIC_time_in_state_G > GREEN_RED_DURATION) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = RED;
                UART_Write("Switching to RED state ");
                break;
            }
            break;

        case AMBER:
            /* Turn red led on, green on */
            Led_Set(RED, ON);
            Led_Set(GREEN, ON);
            if(TRAFFIC_time_in_state_G > AMBER_DURATION) {
                TRAFFIC_time_in_state_G = 0;
                TRAFFIC_state_G = RED;
                UART_Write("Switching to RED state");
                break;
            }
            break;
    }
}