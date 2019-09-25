/*
 * TIMER_cnfg.h
 *
 *  Created on: Sep 24, 2019
 *      Author: Mohammed
 */

#ifndef TIMER_CNFG_H_
#define TIMER_CNFG_H_



#include "reg_lib.h"
#include "TIMER1_cnfg.h"

typedef enum {timer0=0,timer1,timer2,NUM_OF_TIMERS}TIMER_t; // types

#define MAX_NUM_OF_TIMERS 3

/* TIMER # */
#define TIMER0    0
#define TIMER1    1
#define TIMER2    2

/* PRESCALER */
/*
typedef enum
{
    // PRESCALER //
 PRESCALER0 =  1,
 PRESCALER8 =  8,
 PRESCALER64 = 64,
 PRESCALER256 = 256,
 PRESCALER1024 = 1024,
 EXTERNAL_CLK_RISING = 5,
 EXTERNAL_CLK_FALLING = 6
}prescalar_factor_t;
*/

/*
#define PRESCALER0             1u
#define PRESCALER8             8u
#define PRESCALER64            64u
#define PRESCALER256           256u
#define PRESCALER1024         1024
#define EXTERNAL_CLK_RISING    5u
#define EXTERNAL_CLK_FALLING   6u 
*/

#define PRESCALER0             0
#define PRESCALER8             1
#define PRESCALER64            2
#define PRESCALER256           3
#define PRESCALER1024          4
#define EXTERNAL_CLK_RISING	   5
#define EXTERNAL_CLK_FALLING   6

/* WGM MODE */
#define NORMAL_MODE        1
#define CTC_MODE           2
#define FAST_PWM_MODE      3
#define PHASE_CORRECT_MODE 4

/* COM MODE */
#define NORMAL  1
#define TOGGLE  2
#define CLEAR   3
#define SET     4
/* PWM MODE */
#define INVERTING 	   5
#define NON_INVERTING  6

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
  uint8 WGM_mode;
  uint8 COM_mode;
  uint8 interrupt;
  uint8 ICU;
  uint8 prescalar;
  uint8 IS_init;
 
  
} TIMER_cnfg_t ;



extern TIMER_cnfg_t TIMER_cnfg_arr[NUM_OF_TIMERS];

#endif /* TIMER_CNFG_H_ */

