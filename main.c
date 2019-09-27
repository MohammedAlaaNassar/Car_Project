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

//define constants
#define ANTICLOCKWISE 1
#define CLOCKWISE	  0
#define ENABLE		  1
#define UNABLE	      0

#define M1_IN1 PD0				// IN1 is supplied by logic 1
#define M1_IN2 PD1				// IN2 is supplied by logic 0
#define M1_EN1 PD5
#define DDR_MOTOR_IN1   DDRD
#define PORT_MOTOR_IN1  PORTD
#define DDR_MOTOR_IN2   DDRD
#define PORT_MOTOR_IN2  PORTD
#define DDR_MOTOR_EN1   DDRD
#define PORT_MOTOR_EN1  PORTD

ISR(TIMER0_COMP_vect)
{
	PORTC |= (1<<5);
	/*
	OVF_Counter_Loop--;
	
	if(OVF_Counter_Loop == 0)
	{
		Running_Flag[TIMER0]=1;
	}*/
	DIO_write(PWM_PORT,PWM_PIN,va);
	va^=1;
		TIMSK &= ~(1<<OCIE0);
}

ISR(TIMER0_OVF_vect)
{
	PORTC |= (1<<6);
	/*
	OVF_Counter_Loop--;
	
	if(OVF_Counter_Loop == 0)
	{
		Running_Flag[TIMER0]=1;
	}*/
	
	DIO_write(PWM_PORT,PWM_PIN,va);
	va^=1;
		TIMSK |= (1<<OCIE0);
	
}


void MOTORS_Initialization (void)
{
	DDR_MOTOR_IN1 |= (1<<M1_IN1) ;  // enable the IN1 of the Half Bridge as an output
	DDR_MOTOR_IN2 |= (1<<M1_IN2) ;  // enable the IN2 of the Half Bridge as an output
	
	DDR_MOTOR_EN1 |= (1<<M1_EN1) ;  // enable the EN1 of the Half Bridge as an output
	
	
}

void MOTORS_ENABLE ( unsigned char Status)
{
	
	if (Status == ENABLE)
	{
		PORT_MOTOR_EN1 |= (1<<M1_EN1) ; // Put logic one to the EN1 of the Half Bridge
	}
	
	else if (Status == UNABLE)
	{
		PORT_MOTOR_EN1 &= ~(1<<M1_EN1) ; // Put logic zero to the EN1 of the Half Bridge
	}

	
}


void MOTOR_Direction ( unsigned char Set_Direction)
{
	if( Set_Direction == ANTICLOCKWISE)  // Default Direction
	{
		
		PORT_MOTOR_IN2 &= ~(1<<M1_IN2) ; // Put logic zero on the IN2 to the half bridge (L298)
		PORT_MOTOR_IN1 |= (1<<M1_IN1) ;  // Put logic one on the IN1 to the half bridge (L298)

	}
	
	else if( Set_Direction == CLOCKWISE)
	{
		PORT_MOTOR_IN1 &= ~ (1<<M1_IN1) ;  // Put logic one on the IN1 to the half bridge (L298)
		PORT_MOTOR_IN2 |= (1<<M1_IN2) ; // Put logic zero on the IN2 to the half bridge (L298)

	}
	
}



int main(void)
{	
	DIO_init();	
	uint8 test;
	
	test= TIMER_init();
	
	
	
	// this code line below is used to check WGM_CTC_mode in TOGGLE_Com_mode in TIMER1 and it works
	//test = Time_Delay(timer0, 0.2);
	

	
	// this code line below is used to check WGM_CTC_mode in TOGGLE_Com_mode in TIMER1 and it works
	//test=Time_Delay(TIMER1, (0.2) );
	
	// We need to test  WGM_Normal_mode in TOGGLE_Com_mode in both timers 
	
	
	DIO_write(PWM_PORT,PWM_PIN,va);

	PWM_generate(TIMER0,50,NON_INVERTING);
	
	DDRD=0xFF;
	
	PORTD |= (1<<4);
	MOTORS_Initialization ();
	MOTORS_ENABLE(ENABLE);
	MOTOR_Direction(CLOCKWISE);
	for(int i=0;i<10;i++)
	{	
	 SEG_write(i);
		Time_Delay(timer1,1);
			while( (TIFR & (1<<OCF1A)) == 0);
			{ TIFR |= 1<<OCF1A ;}
	}	
		MOTOR_Direction(ANTICLOCKWISE);	
		for(int i=0;i<10;i++){
			SEG_write(i);
			Time_Delay(timer1,1);
			while( (TIFR & (1<<OCF1A)) == 0);
			{ TIFR |= 1<<OCF1A ;}
		}
		MOTORS_ENABLE(UNABLE);
		
			
	while (1)
	{
		// these code lines below is used to check WGM_Normal_mode in Normal_Com_mode in TIMER0 by polling on TOV0 flag and it needs testing	
	/*	test=Time_Delay(TIMER1, (0.2) );		
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
		
		DIO_write(PORT_D , PIN5 , value);
		value ^=1;
		*/
		
	}
	return (0);

}

