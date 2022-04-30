/*
 * seven_seg.h
 *
 *  Created on: Apr 30, 2022
 *      Author: Mahmoud Mohamed Abd-Elqader
 */

#ifndef SEVEN_SEGMENT_SEVEN_SEG_H_
#define SEVEN_SEGMENT_SEVEN_SEG_H_
/* includes */
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

//================= Common Cathode 7-seg structure =================
typedef struct seven_segment_common_cathode{
	// Data bus
	volatile uint8_t* data_DDR;		// Data direction register.
	volatile uint8_t* data_PRT;		// output register.
	uint8_t a, b, c, d;

	// Control bus
	volatile uint8_t* control_DDR;
	volatile uint8_t* control_PRT;
	uint8_t s1, s2, s3, s4, s5, s6, DP;
}_7_seg_CC;

//============================== 7 segment data array ==================================
//uint8_t array_data[10]={0x77, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};

//============= Initialization function =============
void seven_segment_init(_7_seg_CC *ps);

void display(_7_seg_CC *ps);
#endif /* SEVEN_SEGMENT_SEVEN_SEG_H_ */
