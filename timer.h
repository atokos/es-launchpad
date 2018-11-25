#ifndef _TIMER_H
#define _TIMER_H

#include "project.h"

void Timer_Init();

void timer_run();

tWord getTick();

void delay_us(tWord delay);

void beep(tWord note, tWord duration);

#endif
