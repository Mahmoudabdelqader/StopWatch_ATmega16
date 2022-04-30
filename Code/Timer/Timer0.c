/*
 * Timer0.c
 *
 *  Created on: Apr 30, 2022
 *      Author: Mahmoud Mohamed Abd-Elqader
 */
#include "Timer0.h"

void Timer0_run(void){
	/*
	 * =================================================================================
	 * To calculate OCR0 value to generate 1 mill second delay:-
	 * time(delay) = #of counts * time(timer).
	 * #of counts = ( Time(delay) / time(timer) );
	 *            = (f(timer) * time(delay);
	 * for example: clk(timer) = 8_MHZ/64 = 125_KHZ
	 * 				time(delay) = 0.001 seconds;
	 * 				#of counts = 125_KHZ * 0.001 = 125 counts
	 * 	So, OCR0 = 125 - 1 = 124.
	 *=================================================================================
	 */
	// CTC mode.
	TCCR0 &= ~(1<<WGM00);
	TCCR0 |= (1<<WGM01);

	// OC0 disconnected.
	TCCR0 &= ~(1<<COM00);
	TCCR0 &= ~(1<<COM01);

	// clk/64
	TCCR0 |=  (1<<CS00);
	TCCR0 |=  (1<<CS01);
	TCCR0 &= ~(1<<CS02);

	// Compare value.
	OCR0 = 124;

	// Enable Output compare interrupt.
	TIMSK |= (1<<OCIE0);

	// Enable global interrupts.
	sei();
}

void Timer0_stop(void){
	TCCR0 = 0x00;
}

