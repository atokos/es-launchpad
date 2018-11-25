#include "project.h"
#include "ports.h"

#include "timer.h"
#include "switch.h"

#define DIVIDER 8
#define TMRC (DCO_FREQ / DIVIDER / 1000 * TIMER_INTERVAL)

static tWord tickCount = 0;         // Counts the timers ticks, increments each interrupt
static tWord tickAtLastPress = 0;   // Tick count at the last button press
static tWord ledInterval = 0;    // Number of ticks between led blinks
static tWord ledTimer = 0;          // Used to count down from the ledInterval to 0

void Timer_Init() {

        BCSCTL1 = CALBC1_16MHZ;
        DCOCTL = CALDCO_16MHZ;
        BCSCTL2 = 0x0 ; // MCLK clock source DCOCLK, MCLK divider 1, SMCLK source DCOCLK, SMCLK divider 1

        // Set up interrupts and timer 0

        // Enable interrupts on timer
        CCTL0 = CCIE;

        // Use clock SMCLK, UP counting, divided of 8
        TACTL = TASSEL_2 + MC_1 + ID_3;

        // Set compare value
        CCR0 = TMRC;

        P1DIR |= BIT4;
}

tWord getTick() {return tickCount;}

/* Runs approx. every 10 ms */
void timer_run() {
	tickCount++;

  if (ledInterval){
    if(ledTimer){
      ledTimer--;
    }
    else{
      ledTimer = ledInterval + 1;
      Led_Switch();
      beep(HIGH_TONE, 100);
      beep(LOW_TONE, 100);
    }
  }
}

__attribute__((interrupt(PORT1_VECTOR))) void Port_1(void) {
    
  /* Check if switch is pressed */
  if(isPressed) {
    /* First press */
    if(tickAtLastPress == 0){
      tickAtLastPress = tickCount;
    }
    /* Second Press */
    else{
      ledInterval = tickCount - tickAtLastPress;
      ledTimer = ledInterval;
      tickAtLastPress = 0;
    }
  }
  P1IFG &= ~SWITCH_PIN; // Clear interrupt flag
}

__attribute__((interrupt(TIMER0_A0_VECTOR))) void Timer_A(void) {
  timer_run();
}

void delay_us(tWord us)
{
    tWord i;
    for (i = 0; i<= us/2; i++)
       __delay_cycles(1);
}
 
/* This function generates the square wave that makes the piezo speaker sound at a determinated frequency. */
void beep(tWord note, tWord duration)
{
    int i;
    long delay = (long)(10000/note);  //This is the semiperiod of each note.
    long time = (long)((duration*100)/(delay*2));  //This is how much time we need to spend on the note.
    for (i=0;i<time;i++)
    {
        P1OUT |= BIT4;     //Set P1.2...
        delay_us(delay);   //...for a semiperiod...
        P1OUT &= ~BIT4;    //...then reset it...
        delay_us(delay);   //...for the other semiperiod.
    }
}
