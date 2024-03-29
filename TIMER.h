/*
 * TIMER.h
 *
 *  Created on: Sep 24, 2019
 *      Author: Mohammed
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "TIMER_cnfg.h"

//-------------------  Public_Functions-------------------------------//
ACK TIMER_init(void);
ACK Time_Delay ( TIMER_t Timer_Select , double Required_Delay  );
ACK TIMER_Start ( TIMER_t Timer_Select );
ACK PWM_generate( TIMER_t Timer_Select , float Required_duty_cycle ,uint8 );
	void interrupt_PWM ( TIMER_t TIMER_Select);
uint8 va;

#endif /* TIMER_H_ */
