/*
 * EX_interrupts.c
 *
 *  Created on: Mar 10, 2022
 *      Author: Mahmoud Mohamed Abd-Elqader
 */
#include <avr/io.h>
#include <avr/interrupt.h>

void INT0_enable(void){
	// Enable External interrupt #0 request.
	GICR |= (1<<INT0);

	// The low level of INT0 generates an interrupt request.
	MCUCR &= ~( (1<<ISC00) | (1<<ISC01) );

	// Enable global interrupts.
	sei();
}

void INT1_enable(void){
	// Enable External interrupt #1 request.
	GICR |= (1<<INT1);

	// The low level of INT1 generates an interrupt request.
	MCUCR &= ~( (1<<ISC10) | (1<<ISC11) );

	// Enable global interrupts.
	sei();
}
