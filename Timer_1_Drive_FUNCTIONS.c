/*
 * Timer_1_Drive.c
 * Author : HOBA
 */

//-------------------------------------------------------------------------------------------------//

#include "STD_MACROS_HEADER.h"
#include "STD_TYPES_HEADER.h"

//-------------------------------------------------------------------------------------------------//

//NOTE you should only use one mode in Timer 1 at a time

//-------------------------------------------------------------------------------------------------//

//Define Output Compare Register 1A and 1B and Input Capture Register for Timer 1:-

#define DDR_TIMER_1		DDRD
#define PORT_TIMER_1	PORTD
#define PIN_TIMER_1		PIND

#define OC1B	PD4
#define OC1A	PD5
#define ICP		PD6

//-------------------------------------------------------------------------------------------------//

//Configure Prescalar Factor for Timer 1 :-

/*prescalar_index = 0*/
#define STOP_TIMER_1     TCCR1B &= ( ~(1<<CS12) & ~(1<<CS11) & ~(1<<CS10))

/*prescalar_index = 1*/
#define NO_PRESCALAR()  do{\
						 TCCR1B |= (1<<CS10);\
						 TCCR1B &= (~(1<<CS11));\
						 TCCR1B &= (~(1<<CS12));\
						 }while(0)

/*prescalar_index = 2*/
#define PRESCALAR_8()   do{TCCR1B |= (1<<CS11);\
					   	   TCCR1B &= (~(1<<CS10) & ~(1<<CS12));}while(0)

/*prescalar_index = 3*/
#define PRESCALAR_64()  do{\
						 TCCR1B |= (1<<CS11) | (1<<CS10);\
						 TCCR1B &= (~(1<<CS12)); \
						} while(0)


/*prescalar_index = 4*/
#define PRESCALAR_256() do{\
						 TCCR1B |= ((1<<CS12));\
						 TCCR1B &= (~(1<<CS11) & ~(1<<CS10));\
						} while(0)

/*prescalar_index = 5*/
#define PRESCALAR_1024() do{\
						  TCCR1B |= (1<<CS12) | (1<<CS10);\
						  TCCR1B &= (~(1<<CS11));\
						 }while(0)

//-------------------------------------------------------------------------------------------------//

/*CHOOSE ONLY ONE MODE FOR TIMER 1 AT A TIME*/

//-------------------------------------------------------------------------------------------------//

// 1-Configure (Normal Mode) for Timer 1 :-

#define NORMAL_MODE()  do{\
						TCCR1A &= (~(1<<WGM10) & ~(1<<WGM11));\
					    TCCR1B &= (~(1<<WGM13) & ~(1<<WGM12));\
						}while(0)

//-------------------------------------------------------------------------------------------------//

// 2-Configure the Clear on Timer Compare ( CTC mode ) for Timer 1 :-

/* mode_no = 8 */
#define CTC_OCR1A_MODE() do{\
						  (TCCR1A) &= (~(1<<WGM10) & ~(1<<WGM11));\
					       TCCR1B |= (1<<WGM12);\
				           TCCR1B &= (~(1<<WGM13));\
						  }while(0)

/* mode_no = 12 */
#define CTC_ICR1_MODE()  do{\
						  TCCR1A &= (~(1<<WGM10) & ~(1<<WGM11));\
					      TCCR1B |= (1<<WGM12) | (1<<WGM13);\
						 }while(0)

//-------------------------------------------------------------------------------------------------//

//3-Configure (Phase Correct PWM) for Timer 1 :-

/* mode_no = 1 */
#define PWM_PHASE_CORRECT_8_BIT()   do{\
									   TCCR1A |= (1<<WGM10);\
									   TCCR1A &= (~(1<<WGM11));\
									   TCCR1B &= (~(1<<WGM13) & ~(1<<WGM12));\
									   }while(0)

/* mode_no = 2 */
#define PWM_PHASE_CORRECT_9_BIT()  do{\
									 TCCR1A &= (~(1<<WGM10));\
									 TCCR1A |= (1<<WGM11);\
									 TCCR1B &= (~(1<<WGM13) & ~(1<<WGM12));\
									 }while(0)

/* mode_no = 3 */
#define PWM_PHASE_CORRECT_10_BIT() do{\
									 TCCR1A |= (1<<WGM10) | (1<<WGM11); \
									 TCCR1B &= (~(1<<WGM13) & ~(1<<WGM12));\
									}while(0)

/* mode_no = 10 */
#define PWM_PHASE_CORRECT_ICR1()   do{\
									 TCCR1A &= (~(1<<WGM10);\
									 TCCR1A |= (1<<WGM11));\
									 TCCR1B &= (~(1<<WGM12));\
									 TCCR1B |= (1<<WGM13);\
									 }while(0)

/* mode_no = 11 */
#define PWM_PHASE_CORRECT_OCR1A()  do{\
									 TCCR1A |= (1<<WGM10) | (1<<WGM11); \
								     TCCR1B &= (~(1<<WGM12));\
								     TCCR1B |= (1<<WGM13);\
									 }while(0)

//-------------------------------------------------------------------------------------------------//

//4- Configure (FAST PWM) for Timer 1 :-

/* mode_no = 5 */
#define FAST_PWM_8_BIT()	do{\
							   TCCR1A |= (1<<WGM10);\
							   TCCR1A &= (~(1<<WGM11));\
							   TCCR1B |= (1<<WGM12);\
							   TCCR1B &= (~(1<<WGM13));\
							   }while(0)

/* mode_no = 6 */
#define FAST_PWM_9_BIT()	do{\
							   TCCR1A &= (~(1<<WGM10))\
							   TCCR1A |= (1<<WGM11);\
							   TCCR1B |= (1<<WGM12);\
							   TCCR1B &= (~(1<<WGM13));\
							   }while(0)

/* mode_no = 7 */
#define FAST_PWM_10_BIT()	do{\
							   TCCR1A |= (1<<WGM11) | (1<<WGM10);\
							   TCCR1B |= (1<<WGM12);\
							   TCCR1B &= (~(1<<WGM13));\
							   }while(0)

/* mode_no = 14 */
#define FAST_PWM_ICR1()		do{\
							   TCCR1A &= (~(1<<WGM10));\
							   TCCR1A |= (1<<WGM11);\
							   TCCR1B |= (1<<WGM13) | (1<<WGM12);\
							   }while(0)

 /* mode_no = 15 */
#define	FAST_PWM_OCR1A()	do{\
							   TCCR1A |= (1<<WGM10) | (1<<WGM11);\
							   TCCR1B |= (1<<WGM13) | (1<<WGM12);\
							  }while(0)


//-------------------------------------------------------------------------------------------------//


//5- Configure (ICU mode) for Timer 1 using ICR Register :-

#define DDR_ICU	 DDRD
#define PORT_ICU PORTD
#define PIN_ICU	 PIND

/* Rising edge and no noise cancellation */
#define ICU_RISING_EDGE()  do\
							{\
							TCCR1A = 0;\
							TCCR1B |= (1<<ICES1);\
							TCCR1B &= (~(1<<ICNC1));\
							} while(0)

/* Falling edge and no noise cancellation */
#define ICU_FALLING_EDGE() do{\
							TCCR1A = 0;\
							TCCR1B &= (~(1<<ICNC1) & ~(1<<ICES1));\
							}while(0)


//-------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------//

// These are the types of Operation for Normal and CTC mode using OCR1A Register:-

/* COM_Mode_no = 0*/
#define COM_1A_NORMAL	  TCCR1A &= (~(1<<COM1A1) & ~(1<<COM1A0))


/* COM_Mode_no = 1*/
#define COM_1A_TOGGLE()	do{\
						   TCCR1A &= (~(1<<COM1A0));\
						   TCCR1A |= (1<<COM1A1);\
						  }while(0)

/* COM_Mode_no = 2*/
#define COM_1A_CLEAR()	do{\
						   TCCR1A |= (1<<COM1A0);\
						   TCCR1A &= (~(1<<COM1A1));\
						  }while(0)

/* COM_Mode_no = 3*/
#define COM_1A_SET		TCCR1A |= (1<<COM1A1) | (1<<COM1A0)



//-------------------------------------------------------------------------------------------------//

// These are the types of Operation for Fast and Phase Correct PWM mode using OCR1A Register:-

/* COM_Mode_no = 0*/
#define COM_1A_PWM_DISCONNECT		TCCR1A &= (~(1<<COM1A1) & ~(1<<COM1A0))  //Disconnect the PWM, Normal Mode Operation

/* COM_Mode_no = 1*/
/*
#define COM_1A_DISCONNECT	 do{TCCR1A &= (~(1<<COM1A0));\ 			         //Disconnect the PWM, Normal Mode Operation
  COM_Mode_no = 1  			    TCCR1A |= (1<<COM1A1);}while(0)
*/

/* COM_Mode_no = 2*/
#define COM_1A_PWM_NON_INVERTED() do{\
									TCCR1A |= (1<<COM1A0);\
								    TCCR1A &= (~(1<<COM1A1));\
								   }while(0)

/* COM_Mode_no = 3*/
#define COM_1A_PWM_INVERTED			TCCR1A |= (1<<COM1A1) | (1<<COM1A0)



//-------------------------------------------------------------------------------------------------//

//Configure TIMSK for interrupt for Timer 1 :-

#define ENABLE_TOIE1	TIMSK|= (1<<TOIE1)						//Timer Overflow Interrupt Enable for timer 1.

#define ENABLE_OCIE1A   TIMSK |= (1<<OCIE1A)					//Output Compare Interrupt Enable for timer 1A.

#define ENABLE_OCIE1B	TIMSK|= (1<<OCIE1B)						//Output Compare Interrupt Enable for timer 1B.

#define ENABLE_TICIE1	TIMSK|= (1<<TICIE1)						//Timer (1) Input Capture Interrupt Enable for timer 1.



//-------------------------------------------------------------------------------------------------//

//Configure TIFR for Timer 1 for Polling on Flags :-

#define POLL_ON_TOV1()   while ( (TIFR & (1<<TOV1)) == 0)	 // Polling on the Timer Overflow Flag for timer 1.
#define POLL_ON_OCF1A()  while ( (TIFR & (1<<OCF1A)) == 0)	 // Polling on Output Compare Flag for timer 1A.
#define POLL_ON_OCF1B()  while ( (TIFR & (1<<OCF1B)) == 0)	 // Polling on Output Compare Flag for timer 1B.
#define POLL_ON_ICF1()   while ( (TIFR & (1<<ICF1)) == 0)	 // Polling on the input capture flag.

#define CLEAR_TOV1	  TIFR = ( 1<< TOV1)					 //Clear TOV1 Flag
#define CLEAR_OCF1A	  TIFR = ( 1<< OCF1A)					 //Clear OCF1A Flag
#define CLEAR_OCF1B   TIFR = ( 1<< OCF1B)					 //Clear OCF1B Flag
#define CLEAR_ICF1	  TIFR = ( 1<< ICF1)					 //Clear ICF1 Flag

//-------------------------------------------------------------------------------------------------//

//Define Prototype of Functions :

void Prescalar_Factor_config ( unsigned short);
void Duty_cycle ( unsigned short  , unsigned char );
void Time_Delay (unsigned short ,  float );

void Timer_1_Normal_mode (void);
void Timer1_CTC_OCR1A  ( unsigned short  , float );

void Timer1_Fast_PWM_OCR1A ( unsigned short  , unsigned short  , unsigned char );
void Timer1_Phase_Correct_PWM_OCR1A ( unsigned short  , unsigned short  , unsigned char );
unsigned short* ICU ( void );

//-------------------------------------------------------------------------------------------------//

//define Constants Macro :-

#define INVERTING_PWM	  1
#define NON_INVERTING_PWM 0
#define ms /1000
#define us /1000000

//-------------------------------------------------------------------------------------------------//


void Prescalar_Factor_config ( unsigned short factor)
{
	if(factor == 0)
	{
		STOP_TIMER_1 ;
	}

	else if(factor == 1)
	{
		NO_PRESCALAR();
	}

	else if( factor == 8)
	{
		PRESCALAR_8();
	}

	else if (factor == 64)
	{
		PRESCALAR_64();
	}

	else if (factor == 256)
	{
		PRESCALAR_256();
	}

	else if (factor == 1024)
	{
		PRESCALAR_1024();
	}

	else
	{
		NO_PRESCALAR();
	}
}


void Duty_cycle ( unsigned short Required_Duty_Cycle , unsigned char Type)
{
	unsigned short Top = 0;
	Top = ~0;			// 2 to the power 16 - 1 "as short is two byte"
	if( Type == INVERTING_PWM  )
	{
		OCR1A = (unsigned short) ( (Top+1) - (unsigned short) ( (Required_Duty_Cycle * (Top+1)) /100 ) ) ; //inverting PWM
	}

	else if ( Type == NON_INVERTING_PWM )
	{
		OCR1A = (unsigned short) ( ( ( Required_Duty_Cycle * (Top+1) ) /100 ) -1 );						   // non_inverting PWM
	}
}

void Time_Delay (unsigned short Prescalar_Factor ,  float Required_Delay  )
{
	unsigned long Frequency_of_Timer_1;

	Required_Delay = (Required_Delay) * (10000000);  //seven zeros

	Frequency_of_Timer_1 =  (unsigned long) (F_CPU / Prescalar_Factor) ;

	unsigned long OCR_Value ;

	OCR_Value =  Required_Delay * Frequency_of_Timer_1 ;

	OCR_Value = OCR_Value/10000000;					//seven zeros

	OCR1A = (unsigned short) OCR_Value;

}

void Timer_1_Normal_mode (void)
{
	NORMAL_MODE();
}

void Timer1_CTC_OCR1A ( unsigned short Prescalar_Factor , float Required_Delay)
{
	DDR_TIMER_1 |= ( 1<< OC1A);

	Time_Delay ( Prescalar_Factor , Required_Delay  );

	Prescalar_Factor_config(Prescalar_Factor);

	CTC_OCR1A_MODE() ;
	COM_1A_TOGGLE() ;
}




void Timer1_Fast_PWM_OCR1A ( unsigned short Prescalar_Factor , unsigned short Required_Duty_cycle , unsigned char Type )
{
	Duty_cycle(Required_Duty_cycle , Type);
	Prescalar_Factor_config( Prescalar_Factor );
	FAST_PWM_OCR1A();

	if( Type == INVERTING_PWM  )
	{
		COM_1A_PWM_INVERTED;
	}

	else if ( Type == NON_INVERTING_PWM )
	{
		COM_1A_PWM_NON_INVERTED();
	}

}


void Timer1_Phase_Correct_PWM_OCR1A ( unsigned short Prescalar_Factor , unsigned short Required_Duty_cycle , unsigned char Type )
{
	Duty_cycle(Required_Duty_cycle , Type);
	Prescalar_Factor_config( Prescalar_Factor );

	PWM_PHASE_CORRECT_OCR1A();

	if( Type == INVERTING_PWM  )
	{
		COM_1A_PWM_INVERTED;
	}

	else if ( Type == NON_INVERTING_PWM )
	{
		COM_1A_PWM_NON_INVERTED();
	}
}


unsigned short* ICU ( void )
{
		static unsigned short arr_time[3];  //arr_time[0] = 1st_rising_edge , arr_time[1] = 1st_falling_edge , arr_time[2] = 2nd_rising_edge

		DDR_ICU &= ~( 1<< ICP); // make PD6 which is responsible for ICP as an input pin
		PORT_ICU |= ( 1<< ICP);  //Activate pull-up Resistor

		unsigned short Prescalar_factor;
		Prescalar_factor = 256;
		Prescalar_Factor_config( Prescalar_factor );

		ICU_RISING_EDGE();
		POLL_ON_ICF1();

		arr_time[0]=ICR1;

		CLEAR_ICF1;

		ICU_FALLING_EDGE( );

		POLL_ON_ICF1( );

		arr_time[1]=ICR1;

		CLEAR_ICF1;

		ICU_RISING_EDGE();
		POLL_ON_ICF1();

		arr_time[2]=ICR1;

		CLEAR_ICF1;


		return arr_time;
}



int main ()
{
	Timer1_Fast_PWM_OCR1A ( 256 , 70 , INVERTING_PWM );

	return 0;
}
