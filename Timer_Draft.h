/*
 * TIMER.h
 *
 *  Created on: Sep 24, 2019
 *      Author: Mohammed
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "TIMER_cnfg.h"




ACK TIMER_init(void);
ACK Time_Delay ( TIMER_t Timer_Select , float Required_Delay  );
ACK TIMER_Start ( TIMER_t Timer_Select );


#endif /* TIMER_H_ */
