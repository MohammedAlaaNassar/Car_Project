/*
 * Timer_Driver_Test.c
 *
 * Created: 9/25/2019 2:49:16 PM
 * Author : Ahmed Ehab
 */ 



#include "std_types.h"
#include "reg_lib.h"
#include "DIO.h"
#include "Timer_Draft.h"
#include "7_SEG.h"


int main(void)
{	
	DIO_init();	
	uint8 test;
	
	test= TIMER_init();
	
	DDRC=0xFF;
	DDRA=0xFF;
	DDRD=0xFF;
	DDRB=0xFF;
	
	uint8 value=1;
	
	// this code line below is used to check WGM_CTC_mode in TOGGLE_Com_mode in TIMER1 and it works
	test = Time_Delay(timer0, 0.2);
	

	
	// this code line below is used to check WGM_CTC_mode in TOGGLE_Com_mode in TIMER1 and it works
	test=Time_Delay(TIMER1, (0.2) );
	
	// We need to test  WGM_Normal_mode in TOGGLE_Com_mode in both timers 
	
	
	test = DIO_write(PORT_D , PIN5 , LOW);
	
	while (1)
	{
		/*
		// these code lines below is used to check WGM_Normal_mode in Normal_Com_mode in TIMER0 by polling on TOV0 flag and it needs testing
		
		test=Time_Delay(TIMER1, (0.2) );		
		while( (TIFR & (1<<TOV0)) == 0);
		{ TIFR |= 1<<TOV0 ;}		
		DIO_write(PORT_B , PIN3 , value);
		value ^=1;
		*/
		
					/*
		// these code lines below is used to check WGM_CTC_mode in Normal_Com_mode in TIMER0 by polling on OCF0 flag and it works
		
		test=Time_Delay(TIMER1, (0.2) );		
		while( (TIFR & (1<<OCF0)) == 0);
		{ TIFR |= 1<<OCF0 ;}		
		DIO_write(PORT_B, PIN3 , value);
		value ^=1;
		*/
		
		
		
		// these code lines below is used to check  WGM_CTC_mode in Normal_Com_mode channel 1A in TIMER1 by polling on OCF1A flag and it works
		/*
		while( (TIFR & (1<<OCF1A)) == 0);
		{ TIFR |= 1<<OCF1A ;}
		
		DIO_write(PORT_D , PIN6 , value);
		value ^=1;
		*/
		
		//----------------------------------------------------------------//
		
		/*
		// these code lines below is used to check WGM_Normal_mode in Normal_Com_mode in TIMER1 by polling on TOV1 flag and it works
		
		test=Time_Delay(TIMER1, (0.2) );		
		while( (TIFR & (1<<TOV1)) == 0);
		{ TIFR |= 1<<TOV1 ;}		
		DIO_write(PORT_D , PIN5 , value);
		value ^=1;
		*/
		
	}
	return (0);

}

