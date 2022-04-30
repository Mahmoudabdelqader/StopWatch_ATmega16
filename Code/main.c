/*
 * main.c
 *
 *  Created on: Mar 10, 2022
 *      Author: Mahmoud Mohamed Abd-Elqader
 */
/* includes */
#include <avr/io.h>
#include <util/delay.h>
#include "seven_segment/seven_seg.h"
#include "Timer/Timer0.h"
#include "External_interrupts/EX_interrupts.h"

// variables used to start and stop counting.
volatile uint8_t timer0_state = 0;

// Time variables.
volatile uint16_t min=0, sec=0, msec=0;

//======================== Main function =======================
int main(void){
	// create seven segment objects.
	_7_seg_CC S;

	// Hardware configuration of seven segment.
	S.data_DDR = &DDRC;
	S.data_PRT = &PORTC;
	S.control_DDR = &DDRA;
	S.control_PRT = &PORTA;
	S.a = PC0; S.b = PC1; S.c = PC2; S.d = PC3;
	S.s1 = PA0; S.s2 = PA1; S.s3 = PA2; S.s4 = PA3; S.s5 = PA4; S.s6 = PA5, S.DP = PA6;

	// init. seven segment.
	seven_segment_init(&S);

	// init. INT0 >> if INT0 becomes in the low-level Timer 0 will run and starts counting.
	INT0_enable();

	// init. INT1 >> if INT1 becomes in the low-level StopWatch will reset.
	INT1_enable();

	while(1){
		display(&S);
	}
	return 0;
}

ISR(TIMER0_COMP_vect){
	if(++msec==1000){
		if(++sec==60){
			if(++min==100){
				min=0;
			}
			sec=0;
		}
		msec=0;
	}
}

ISR(INT0_vect){
	// if timer stop >> run timer.
	if(timer0_state==0){
		Timer0_run();
		timer0_state=1;
	}
	// if timer run >> stop timer.
	else if(timer0_state==1){
		Timer0_stop();
		timer0_state=0;
	}
}

ISR(INT1_vect){
	min = 0;
	sec = 0;
	msec = 0;
}
