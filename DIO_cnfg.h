/*
 * DIO_cnfg.h
 *
 *  Created on: Sep 22, 2019
 *      Author: Mohammed
 */

#ifndef DIO_CNFG_H_
#define DIO_CNFG_H_


#include "reg_lib.h"




#define _PWM_OUTPUT
//#define TEST_LEDS
#define _7SEG 
//#define TEST_LEDS_PORTD	


		// LEDs of sprints kit PORT_B
#define led0  PIN7
#define led1  PIN5
#define led2  PIN6
#define led3  PIN7
#define LEDs_TESTING_PORT PORT_B

    // PIN FOR PWM OUTPUT
#define PWM_PORT PORT_B
#define PWM_PIN  PIN4




typedef enum {SWITCH=2,led=6,NUM_OF_PINS=30}PINS_t; // types



#define PORT_A              'A'
#define PORT_B              'B'
#define PORT_C              'C'
#define PORT_D              'D'


#define OUTPUT  	        1
#define INPUT		        0

#define HIGH                1
#define LOW                 0

#define PULLUP	            1
#define PULLDOWN            0


#define INITIALIZED			1
#define NOT_INITIALIZED		0


#define NA			        0xff


typedef struct
{
	uint8 PORT;
	uint8 PIN;
	uint8 DIR;
	uint8 VALUE;
	uint8 PULL;
	uint8 IS_init;
}DIO_cnfg_t;



extern DIO_cnfg_t DIO_cnfg_arr[NUM_OF_PINS];


#endif /* DIO_CNFG_H_ */
