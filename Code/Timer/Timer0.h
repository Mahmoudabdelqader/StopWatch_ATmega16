/*
 * Timer0.h
 *
 *  Created on: Apr 30, 2022
 *      Author: Mahmoud Mohamed Abd-Elqader
 */

#ifndef TIMER_TIMER0_H_
#define TIMER_TIMER0_H_

#include <avr/io.h>
#include <avr/interrupt.h>

void Timer0_run(void);

void Timer0_stop(void);

#endif /* TIMER_TIMER0_H_ */
