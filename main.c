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



void main(void)
{	
	DIO_init();	
	uint8 test;
	
	
	test= TIMER_init();
	

	uint8 value=1;
	
	while (1)
	{

			 test = Time_Delay(timer0, 0.2);
			
			 while( ( TIFR & (1<<OCF0) ) == 0);
			 
			
			DIO_write(PORT_A,6,value);
			value^=1;
	}

}

/*
TIMER0_COMP_vect_num ()
{
	
}
*/