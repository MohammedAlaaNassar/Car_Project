/*
 * DIO_cnfg.c
 *
 *  Created on: Sep 22, 2019
 *      Author: Mohammed
 */


#include "DIO_cnfg.h"




DIO_cnfg_t DIO_cnfg_arr[NUM_OF_PINS] =
{
		/*
		{PORT_A,PIN2,INPUT,NA,PULLDOWN,INITIALIZED},
		{PORT_A,PIN4,INPUT,NA,PULLUP,INITIALIZED},
		{PORT_A,PIN6,OUTPUT,LOW,NA,INITIALIZED},

#ifdef _PWM_OUTPUT

		{LEDs_TESTING_PORT,led0,OUTPUT,LOW,NA,INITIALIZED},

#endif

#ifdef TEST_LEDS_PORTB
		//test LEDs for debugging//
		{LEDs_TESTING_PORT,led0,OUTPUT,LOW,NA,INITIALIZED},
		{LEDs_TESTING_PORT,led1,OUTPUT,LOW,NA,INITIALIZED},
		{LEDs_TESTING_PORT,led2,OUTPUT,LOW,NA,INITIALIZED},
		{LEDs_TESTING_PORT,led3,OUTPUT,LOW,NA,INITIALIZED},

#endif

		
#ifdef TEST_LEDS_PORTD	
		//test LEDs for debugging//
		{PORT_D,PIN3,OUTPUT,LOW,NA,INITIALIZED},
		{PORT_D,PIN4,OUTPUT,LOW,NA,INITIALIZED},
		{PORT_D,PIN5,OUTPUT,LOW,NA,INITIALIZED},
		{PORT_D,PIN6,OUTPUT,LOW,NA,INITIALIZED},
		{PORT_D,PIN7,OUTPUT,LOW,NA,INITIALIZED},
#endif
		

#ifdef _7SEG
			//  7-SEG 4 Data_PINS //
			        {PORT_B,PIN0,OUTPUT,LOW,NA,INITIALIZED},
					{PORT_B,PIN1,OUTPUT,LOW,NA,INITIALIZED},
					{PORT_B,PIN2,OUTPUT,LOW,NA,INITIALIZED},
					{PORT_B,PIN3,OUTPUT,LOW,NA,INITIALIZED},

			//  7-SEG 4 Enable_PINS //
					 {PORT_D,PIN2,OUTPUT,HIGH,NA,INITIALIZED},
			         {PORT_D,PIN3,OUTPUT,HIGH,NA,INITIALIZED},

#endif

			// Enable Timer Pins
					 {PORT_B,PIN3,OUTPUT,LOW,NA,INITIALIZED},	//OC0  timer0 it's common with Seven segment Data pin 4
		   	         {PORT_D,PIN4,OUTPUT,LOW,NA,INITIALIZED},	//OC1B timer1 channel B
					 {PORT_D,PIN5,OUTPUT,LOW,NA,INITIALIZED},	//OC1A timer1 channel A
				     {PORT_D,PIN6,OUTPUT,LOW,NA,INITIALIZED},	//ICP timer1
					 {PORT_D,PIN7,OUTPUT,LOW,NA,INITIALIZED}	//OC2  timer2

};
