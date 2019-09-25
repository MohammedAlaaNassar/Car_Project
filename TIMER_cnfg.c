/*
 * TIMER_cnfg.c
 *
 *  Created on: Sep 24, 2019
 *      Author: Mohammed
 */

#include "TIMER_cnfg.h"



TIMER_cnfg_t TIMER_cnfg_arr[NUM_OF_TIMERS] =
{
		{TIMER0,CTC_MODE,NORMAL,INTERRUPT,NA,PRESCALER1024 ,INITIALIZED}
};
