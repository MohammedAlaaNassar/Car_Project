/*
 * TIMER_cnfg.h
 *
 *  Created on: Sep 24, 2019
 *      Author: Mohammed
 */

#ifndef TIMER_CNFG_H_
#define TIMER_CNFG_H_


#include "reg_lib.h"

typedef enum {timer0,timer1,timer2,NUM_OF_TIMER}TIMER_t; // types

/* TIMER # */
#define TIMER0    0
#define TIMER1    1
#define TIMER2    2

/* PRESCALER */
#define PRESCALER0             0
#define PRESCALER8             1
#define PRESCALER64            2
#define PRESCALER256           3
#define PRESCALER1024          4
#define EXTERNAL_CLK_RISING    5
#define EXTERNAL_CLK_FALLING   6

/* WGM MODE */
#define NORMAL_MODE        0
#define CTC_MODE           1
#define FAST_PWM_MODE      2
#define PHASE_CORRECT_MODE 3

/* COM MODE */
#define NORMAL  0
#define TOGGLE  1
#define SET     2
#define CLEAR   3
/* PWM MODE */
#define INVERTING 	   4
#define NON_INVERTING  5

/* INTERRUPT */
#define INTERRUPT     1
#define NO_INTERRUPT  0

/* ICU */
#define ICU_USED     1
#define ICU_NO_USED  0

#define NA           0xff

/* INITIALIZATION	 */
#define INITIALIZED			1
#define NOT_INITIALIZED		0



typedef struct
{
  uint8 timer;
  uint8 prescalar;
  uint8 WGM_mode;
  uint8 COM_mode;
  uint8 interrupt;
  uint8 ICU;
  uint8 IS_init;

} TIMER_cnfg_t ;


extern TIMER_cnfg_t TIMER_cnfg_arr[NUM_OF_TIMER];

#endif /* TIMER_CNFG_H_ */
