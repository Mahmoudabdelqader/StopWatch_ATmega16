/*
 * seven_seg.c
 *
 *  Created on: Mar 10, 2022
 *      Author: Mahmoud Mohamed Abd-Elqader
 */
/* includes */
#include "seven_seg.h"

extern volatile uint16_t min, sec, msec;

//============= Initialization function =============
void seven_segment_init(_7_seg_CC *ps){
	// Configure data pins as output pins.
	*ps->data_DDR |= (1<<ps->a) | (1<<ps->b) | (1<<ps->c) | (1<<ps->d);

	// Configure control pins as output pins and initially high.
	*ps->control_DDR |= (1<<ps->s1) | (1<<ps->s2) | (1<<ps->s3) | (1<<ps->s4) | (1<<ps->s5) | (1<<ps->s6) | (1<<ps->DP);

	// all control pins initially high.
	*ps->control_PRT |= (1<<ps->s1) | (1<<ps->s2) | (1<<ps->s3) | (1<<ps->s4) | (1<<ps->s5) | (1<<ps->s6);
}

void display(_7_seg_CC *ps){
	// ========================= mill seconds ====================================================

	uint16_t time = 10;
	// display mill seconds.
	// >> second digit for example: msec = 125 >> display 2.
	//disable all segments
	*ps->control_PRT |= 0x3F;
	// enable specific seven segment.
	*ps->control_PRT &= ~(1<<ps->s6);
	*ps->control_PRT |=  (1<<ps->DP);
	*ps->data_PRT = ( (msec/10) %10 );
	_delay_ms(time);

	// >> third digit for example: msec = 125 >> display 1.
	//disable all segments
	*ps->control_PRT |= 0x3F;
	// enable specific seven segment.
	*ps->control_PRT &= ~( (1<<ps->s5) | (1<<ps->DP) );
	*ps->data_PRT = (msec/100);
	_delay_ms(time);

	// ================================ seconds ==================================================

	// display sec seconds.
	// >> second digit for example: sec = 12 >> display 2.
	//disable all segments
	*ps->control_PRT |= 0x3F;
	// enable specific seven segment.
	*ps->control_PRT &= ~(1<<ps->s4);
	*ps->control_PRT |=  (1<<ps->DP);
	*ps->data_PRT = ( sec%10 );
	_delay_ms(time);

	// >> third digit for example: sec = 12 >> display 1.
	//disable all segments
	*ps->control_PRT |= 0x3F;
	// enable specific seven segment.
	*ps->control_PRT &= ~( (1<<ps->s3) | (1<<ps->DP) );
	*ps->data_PRT = (sec/10);
	_delay_ms(time);

	// ================================== minutes =================================================

	// display min seconds.
	// >> second digit for example: sec = 12 >> display 2.
	//disable all segments
	*ps->control_PRT |= 0x3F;
	// enable specific seven segment.
	*ps->control_PRT &= ~(1<<ps->s2);
	*ps->control_PRT |=  (1<<ps->DP);
	*ps->data_PRT = ( min%10 );
	_delay_ms(time);

	// >> third digit for example: min = 12 >> display 1.
	//disable all segments
	*ps->control_PRT |= 0x3F;
	// enable specific seven segment.
	*ps->control_PRT &= ~( (1<<ps->s1) | (1<<ps->DP) );
	*ps->data_PRT = (min/10);
	_delay_ms(time);
}



