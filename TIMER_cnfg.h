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

typedef enum {timer0,timer1,timer2,NUM_OF_TIMERS}TIMER_t; // types

#define MAX_NUM_OF_TIMERS 3


//----------------------------------- TIIMER_PINS ------------------------------------//

//Define Output Compare Pin 1A and 1B and Input Capture Register for Timer 1:-

#define DDR_TIMER_1		DDRD
#define PORT_TIMER_1	PORTD
#define PIN_TIMER_1		PIND

#define OC1B	PD4
#define OC1A	PD5
#define ICP		PD6


#define DDR_ICU	 DDRD
#define PORT_ICU PORTD
#define PIN_ICU	 PIND

//Define Output Compare Pin for Timer 0:-

#define DDR_TIMER_0		DDRB
#define PORT_TIMER_0	PORTB
#define PIN_TIMER_0		PINB
#define OC0				PB3


//Define Output Compare Pin for Timer 2:-
#define DDR_TIMER_2		DDRD
#define PORT_TIMER_2	PORTD
#define PIN_TIMER_2		PIND
#define OC2				PD7



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

/* PRESCALER TIMER 2 */
#define PRESCALER32             7
#define PRESCALER128            8

/* WGM MODE */
#define NORMAL_MODE        0
#define CTC_MODE           1
#define FAST_PWM_MODE      2
#define PHASE_CORRECT_MODE 3

/* COM MODE */
#define NORMAL  0
#define TOGGLE  1
#define CLEAR   2
#define SET     3
/* PWM MODE */
#define INVERTING 	   4
#define NON_INVERTING  5

/* INTERRUPT */
#define INTERRUPT     1
#define NO_INTERRUPT  0

/* ICU */
#define ICU_USED     1
#define NO_ICU_USED  0

#define NA           0xff

/* INITIALIZATION	 */
#define INITIALIZED			1
#define NOT_INITIALIZED		0
#define POLLING				0

//Flag PWM
#define PWM_MODE		1
#define NON_PWM_MODE	0


/* Flag_mode */
#define PWM_MODE		1
#define NON_PWM_MODE	0

/* Enable Interrupt Overflow Flags */
#define ENABLE_OVERFLOW_INTERRUPT_TIMER0	TIMSK |= (1<<TOIE0)
#define ENABLE_OVERFLOW_INTERRUPT_TIMER1	TIMSK |= (1<<TOIE1)
#define ENABLE_OVERFLOW_INTERRUPT_TIMER2	TIMSK |= (1<<TOIE2)



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
