/*
 * TIMER.c
 *
 *  Created on: Sep 24, 2019
 *      Author: Mohammed
 */

#include "TIMER.h"
#include "DIO.h"
static uint16 Prescalar_Factor[]={1,8,64,256,1024,0,0,32,128};
static uint8 Flag_mode = NA ;

/**************************** TIMER DRIVER ****************************/


/**************************** TIMER DRIVER ****************************/

//-------------------  Public_Global_Varibles -------------------------------//
 uint16 OVF_Counter_Loop=0 ;
 uint8 Running_Flag = 0;

//-------------------  Private_Function --------------------------------------//
static ACK Polling_Delay (TIMER_t );


ACK TIMER_init(void)
{

	ACK STATE = AK;
	uint8 Flag_mode = NA ;


	uint8 loop_index = 0;
	if (NUM_OF_TIMERS > MAX_NUM_OF_TIMERS)
	{
		STATE = NAK;
	}
	else
	{
		for (loop_index = 0; loop_index < NUM_OF_TIMERS; loop_index++)
		{

			if(TIMER_cnfg_arr[loop_index].IS_init == NOT_INITIALIZED)
			{
				continue;
			}

			TIMER_cnfg_arr[loop_index].IS_init = INITIALIZED;

			switch (TIMER_cnfg_arr[loop_index].timer)
		{

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//			
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//						
						/**************************** START OF TIMER0 ****************************/
		case TIMER0:
		{
			
			TCNT0 = 0; //timer initial value
			
			

			/**************************** WGM MODE TIMER0 ****************************/
			switch (TIMER_cnfg_arr[loop_index].WGM_mode)
			{
				case NORMAL_MODE:
				{

					Flag_mode= NON_PWM_MODE;
					/*********** NORMAL_MODE TIMER0 ********/
					TCCR0 &=  ~ ( (1u<<WGM01) | (1u<<WGM00) );	// NORMAL_MODE WGM01=0 & WGM00=0
					TCCR0 = (1<<FOC0); //Non PWM mode
					// END OF NORMAL_MODE
					break;
				}

				case CTC_MODE:
				{

					Flag_mode=NON_PWM_MODE;
					/*********** CTC MODE *********/
					TCCR0 |= (1u<<WGM01) ; // CTC WGM01=1
					TCCR0 &= ( ~ (1u<<WGM00) );  // CTC  WGM00=0
					TCCR0 = (1<<FOC0); //Non PWM mode
					// END OF CTC_MODE
					break;
				}

				case FAST_PWM_MODE:
				{
					Flag_mode = PWM_MODE;
					/*********** FAST PWM MODE *********/
					TCCR0 |= ((1u << WGM01) | (1u << WGM00)); // FAST PWM MODE WGM01=1 & WGM00=1
					DDRB |= (1u<<PIN3); // OCO PIN OUTPUT
					// END OF FAST_PWM_MODE
					break;
				}

				case PHASE_CORRECT_MODE:
				{
					Flag_mode = PWM_MODE;
					/*********** PHASE CORRECT MODE *********/
					TCCR0 &= (~(1u << WGM01)); // PHASE CORRECT MODE  WGM01=0
					TCCR0 |= (1u << WGM00);  // PHASE CORRECT MODE  WGM00=1
					DDRB |= (1u<<PIN3);  // OCO PIN OUTPUT
					// END OF FAST_PWM_MODE

					break;
				}

				// INCORRECT INPUT IN  WGM MODE
				default:
				{
					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;
					break;
				}
			}
			/**************************** END OF WGM MODE ****************************/

			switch(Flag_mode)
			{
				case NON_PWM_MODE:
				{

					switch (TIMER_cnfg_arr[loop_index].COM_mode)
					{
						/*********** COM_MODE *********/
						// NORMAL
						case NORMAL:
						{

							TCCR0 &= ~((1u << COM01) | (1u << COM00));// NORMAL COM01=0 & COM00=0
							break;
						}
						// TOGGLE
						case TOGGLE:
						{

							TCCR0 &= (~(1u << COM01)); // TOGGLE COM01=0
							TCCR0 |= (1u << COM00);  // TOGGLE  COM00=1
							break;
						}
						// CLEAR
						case CLEAR:
						{
							TCCR0 |= (1u << COM01); // CLEAR COM01=1
							TCCR0 &= (~(1u << COM00));  // CLEAR  COM00=0
							break;
						}
						// SET
						case SET:
						{
							TCCR0 |= ((1u << COM01) | (1u << COM00)); // SET COM01=1 & COM00=1
							break;
						}
						// INCORRECT INPUT IN  COM MODE
						default:
						{

							TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
							STATE = NAK;
							break;
						}
						// END OF COM_MODE
					}
					// END OF NON_PWM_MODE
					break;
				}

				case PWM_MODE:
				{
					switch (TIMER_cnfg_arr[loop_index].COM_mode)
					{
						// INVERTING
						case INVERTING:
						{
							TCCR0 |= (1u << COM01); // INVERTING COM01=1
							TCCR0 &= (~(1u << COM00));  // INVERTING COM00=0
							break;
						}
						// NON_INVERTING
						case NON_INVERTING:
						{
							TCCR0 |= ((1u << COM01) | (1u << COM00)); // NON_INVERTING COM01=1 & COM00=1
							break;
						}
						// INCORRECT INPUT IN COM MODE
						default:
						{
							TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
							STATE = NAK;
							break;
						}
						// END OF COM_MODE
					}
					// END OF PWM_MODE

					break;
				}

				// INCORRECT INPUT IN  WGM MODE
				default:
				{
					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;

					break;
				}
			}
			/**************************** END OF WGM MODE ****************************/
			
			switch(Flag_mode)
			{
				case NON_PWM_MODE:
				{
					
					switch (TIMER_cnfg_arr[loop_index].COM_mode)
					{
						/*********** COM_MODE *********/
						// NORMAL
						case NORMAL:
						{
							
							TCCR0 &= ~((1u << COM01) | (1u << COM00));// NORMAL COM01=0 & COM00=0
							break;
						}
						// TOGGLE
						case TOGGLE:
						{
							
							TCCR0 &= (~(1u << COM01)); // TOGGLE COM01=0
							TCCR0 |= (1u << COM00);  // TOGGLE  COM00=1
							break;
						}
						// CLEAR
						case CLEAR:
						{
							TCCR0 |= (1u << COM01); // CLEAR COM01=1
							TCCR0 &= (~(1u << COM00));  // CLEAR  COM00=0
							break;
						}
						// SET
						case SET:
						{
							TCCR0 |= ((1u << COM01) | (1u << COM00)); // SET COM01=1 & COM00=1
							break;
						}
						// INCORRECT INPUT IN  COM MODE
						default:
						{


			/**************************** END OF COM MODE ****************************/


							TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
							STATE = NAK;
							break;
						}
						// END OF COM_MODE
					}
					// END OF NON_PWM_MODE
					break;
				}
				
				case PWM_MODE:
				{
					switch (TIMER_cnfg_arr[loop_index].COM_mode)
					{
						// INVERTING
						case INVERTING:
						{
							TCCR0 |= (1u << COM01); // INVERTING COM01=1
							TCCR0 &= (~(1u << COM00));  // INVERTING COM00=0
							break;
						}
						// NON_INVERTING
						case NON_INVERTING:
						{
							TCCR0 |= ((1u << COM01) | (1u << COM00)); // NON_INVERTING COM01=1 & COM00=1
							break;
						}
						// INCORRECT INPUT IN COM MODE
						default:
						{
							TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
							STATE = NAK;
							break;
						}
						// END OF COM_MODE
					}
					// END OF PWM_MODE
					break;
				}
			}

			/**************************** END OF COM MODE ****************************/
			

			switch (TIMER_cnfg_arr[loop_index].interrupt)
			{

				/*********** INTERRUPT MODE *********/
				// INTERRUPT
				case INTERRUPT:
				{
					SREG |= (1u<< 7 ) ; // ENABLE GLOBAL INTERRUPT
					switch (TIMER_cnfg_arr[loop_index].WGM_mode)
					{

						case NORMAL_MODE:
						{
							TIMSK |= (1u<<TOIE0); //Overflow Interrupt Enable
							break;

						}
						case CTC_MODE:
						{
							TIMSK |= (1u<<OCIE0); // Output Compare Match Interrupt Enable
							break;
						}

						// INCORRECT INPUT IN  WGM MODE
						default:
						{
							TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
							STATE = NAK;
							break;
						}

					}
					// END OF WGM MODE
					break;
					// END OF INTERRUPT
				}

				// NO INTERRUPT
				case NO_INTERRUPT:
				{

					TIMSK &= (~ ( (1u<<OCIE0) |(1u<<TOIE0) ) );  //Overflow Interrupt & Output Compare Match Interrupt disable
					break;
				}

				default:
				{
					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;
					break;
				}
				/*********** END OF INTERRUPT MODE *********/

			}


			switch (TIMER_cnfg_arr[loop_index].ICU)
			{


				/*********** ICU MODE *********/
				case NA:
				{

					break;
				}
				default:
				{
					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;
					break;
				}
				/*********** END OF ICU MODE *********/
			}

			break;
			/**************************** END OF TIMER 0 ****************************/
		}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

			/**************************** START OF TIMER 1 ****************************/
			case TIMER1:
			{
				PORTC |= (1<<PC0) ;
				/**************************** WGM MODE ****************************/
				switch (TIMER_cnfg_arr[loop_index].WGM_mode)

				{
					case NORMAL_MODE:
					{
						PORTC |= (1<<PC1) ;
						Flag_mode = NON_PWM_MODE;
						TCNT1H=0;
						TCNT1L=0;
						//TCNT1=0;
						NORMAL_MODE_TIMER1();
						break;
					}

					case CTC_MODE:
					{

						Flag_mode=NON_PWM_MODE;
						TCNT1H=0;
						TCNT1L=0;
						//TCNT1=0;
						CTC_OCR1A_MODE_TIMER1();
						break;
					}

					case FAST_PWM_MODE:
					{
						Flag_mode=PWM_MODE;
						PWM_PHASE_CORRECT_OCR1A();
						break;
					}

					case PHASE_CORRECT_MODE:
					{
						Flag_mode=PWM_MODE;
						PWM_PHASE_CORRECT_OCR1A();
						break;
					}

					default:
					{
						TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
						STATE=NAK;
						break;
					}
				}
				/**************************** END OF WGM MODE ****************************/

				/**************************** COM MODE ****************************/
				switch(Flag_mode)
				{
					/**************************** END OF NON PWM MODE ****************************/
					case NON_PWM_MODE:
					{

						switch (TIMER_cnfg_arr[loop_index].COM_mode)
						{
							case NORMAL:
							{

								COM_1A_NORMAL();
								break;
							}

							case TOGGLE:
							{
								PORTC |= (1<<PC2) ;
								COM_1A_TOGGLE();
								break;
							}

							case SET:
							{
								COM_1A_SET;
								break;
							}

							case CLEAR:
							{
								COM_1A_CLEAR();
								break;
							}

							default:
							{

								TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
								STATE=NAK;
								break;
							}

						}
						/**************************** END OF NON PWM MODE ****************************/
						break;
					}

					/**************************** PWM MODE ****************************/
					case PWM_MODE:
					{
						switch (TIMER_cnfg_arr[loop_index].COM_mode)
						{
							case INVERTING:
							{
								COM_1A_PWM_INVERTED();
								break;
							}

							case NON_INVERTING:
							{
								COM_1A_PWM_NON_INVERTED();
								break;
							}


							default:
							{
								TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
								STATE=NAK;
								break;
							}

						}

						break;
					}

					default:
					{
						TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
						STATE=NAK;
						break;
					}
				}
				/**************************** END OF PWM MODE ****************************/


				/**************************** INTERRUPT MODE ****************************/
				switch (TIMER_cnfg_arr[loop_index].interrupt)
				{

					case INTERRUPT:
					{
						ENABLE_GLOBAL_INTERRUPT;      //Enable_Global_Interrupt
						switch(TIMER_cnfg_arr[loop_index].WGM_mode)		//check what's WGM
						{
							case NORMAL:
							{
								ENABLE_TOIE1;
								break;
							}

							case CTC_MODE:
							{
								ENABLE_OCIE1A;
								break;
							}

							default:
							{
								TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
								STATE=NAK;
								break;
							}

						}
						break;
					}

					case NO_INTERRUPT:
					{

						PORTC |= (1<<PC3) ;
						TIMSK &= ~(1<<TOIE1) ;
						TIMSK &= ~(1<<TICIE1) ;
						TIMSK &= ~(1<<TOV1) ;
						break;
					}

					default:
					{
						TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
						STATE=NAK;
						break;
					}

					break;
				}

				/*********** END OF INTERRUPT MODE *********/

				/*********** ICU MODE *********/
				switch (TIMER_cnfg_arr[loop_index].ICU)
				{
					case ICU_USED:
					{
						if(TIMER_cnfg_arr[loop_index].interrupt == 1 )
						{
							ENABLE_TICIE1;
						}

						break;
					}

					case NO_ICU_USED:
					{

						PORTC |= (1<<PC4) ;

				{
					case NORMAL_MODE:
					{
						PORTC |= (1<<PC1) ;
						Flag_mode = NON_PWM_MODE;
						TCNT1H=0;
						TCNT1L=0;
						//TCNT1=0;
						NORMAL_MODE_TIMER1();
						break;
					}

					case CTC_MODE:
					{
						
						Flag_mode=NON_PWM_MODE;
						TCNT1H=0;
						TCNT1L=0;
						//TCNT1=0;
						CTC_OCR1A_MODE_TIMER1();
						break;
					}

					case FAST_PWM_MODE:
					{
						Flag_mode=PWM_MODE;
						PWM_PHASE_CORRECT_OCR1A();
						break;
					}

					case PHASE_CORRECT_MODE:
					{
						Flag_mode=PWM_MODE;
						PWM_PHASE_CORRECT_OCR1A();

						break;
					}

					default:
					{

						TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
						STATE=NAK;
						break;
					}
					/*********** END OF ICU MODE *********/
				}
				break;
				/**************************** END OF TIMER 1 ****************************/
			}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//




			/**************************** START OF TIMER 2 ****************************/
		case TIMER2:
			{

			TCNT2 = 0; //timer initial value
			switch (TIMER_cnfg_arr[loop_index].WGM_mode)
			{

				/**************************** WGM MODE ****************************/

				case NORMAL_MODE:
				{
					Flag_mode = NON_PWM_MODE;
					/*********** NORMAL_MODE *********/
					TCCR2 &=  ~ ( (1u<<WGM21) | (1u<<WGM20) );	// NORMAL_MODE WGM21=0 & WGM20=0
					TCCR2 = (1<<FOC2); //Non PWM mode
					// END OF NORMAL_MODE

						TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
						STATE=NAK;
						break;
					}

				}
				/**************************** END OF WGM MODE ****************************/
				
				/**************************** COM MODE ****************************/
				switch(Flag_mode)
				{
					/**************************** END OF NON PWM MODE ****************************/
					case NON_PWM_MODE:
					{
						
						switch (TIMER_cnfg_arr[loop_index].COM_mode)
						{
							case NORMAL:
							{
								
								COM_1A_NORMAL();
								break;
							}

							case TOGGLE:
							{
								PORTC |= (1<<PC2) ;
								COM_1A_TOGGLE();
								break;
							}

							case SET:
							{
								COM_1A_SET;
								break;
							}

							case CLEAR:
							{
								COM_1A_CLEAR();
								break;
							}

							default:
							{

								TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
								STATE=NAK;
								break;
							}


				case CTC_MODE:
				{
					Flag_mode = NON_PWM_MODE;
					/*********** CTC MODE *********/
					TCCR2 |= (1u<<WGM21) ; // CTC WGM21=1
					TCCR2 &= ( ~ (1u<<WGM20) );  // CTC  WGM20=0
					TCCR2 = (1<<FOC2); //Non PWM mode
					// END OF CTC_MODE

						}
						/**************************** END OF NON PWM MODE ****************************/
						break;
					}
					
					/**************************** PWM MODE ****************************/
					case PWM_MODE:
					{
						switch (TIMER_cnfg_arr[loop_index].COM_mode)
						{
							case INVERTING:
							{
								COM_1A_PWM_INVERTED();
								break;
							}

							case NON_INVERTING:
							{
								COM_1A_PWM_NON_INVERTED();
								break;
							}


							default:
							{
								TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
								STATE=NAK;
								break;
							}
							
						}
						
						break;
					}
					
					default:
					{
						TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
						STATE=NAK;
						break;
					}
				}
				/**************************** END OF PWM MODE ****************************/
				
				
				/**************************** INTERRUPT MODE ****************************/
				switch (TIMER_cnfg_arr[loop_index].interrupt)
				{
				
					case INTERRUPT:
					{
						ENABLE_GLOBAL_INTERRUPT;      //Enable_Global_Interrupt
						switch(TIMER_cnfg_arr[loop_index].WGM_mode)		//check what's WGM
						{
							case NORMAL:
							{
								ENABLE_TOIE1;
								break;
							}

							case CTC_MODE:
							{
								ENABLE_OCIE1A;
								break;
							}
							
							default:
							{
								TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
								STATE=NAK;
								break;
							}

						}
						break;
					}
					
					case NO_INTERRUPT:
					{
						
						PORTC |= (1<<PC3) ;
						TIMSK &= ~(1<<TOIE1) ;
						TIMSK &= ~(1<<TICIE1) ;
						TIMSK &= ~(1<<TOV1) ;
						break;
					}

					default:
					{
						TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
						STATE=NAK;
						break;
					}
					

					break;
				}
				
				/*********** END OF INTERRUPT MODE *********/


				case FAST_PWM_MODE:
				{
					Flag_mode = PWM_MODE;
					/*********** FAST PWM MODE *********/
					TCCR2 |= ((1u << WGM21) | (1u << WGM20)); // FAST PWM MODE WGM21=1 & WGM20=1
					DDRD |= (1u<<PIN7); // OC2 PIN OUTPUT
				break;
				}

				/**************************** END OF WGM MODE ****************************/
				}

				switch(Flag_mode)
				{
					case NON_PWM_MODE:
					{

						switch (TIMER_cnfg_arr[loop_index].COM_mode)
						{

							/*********** COM_MODE *********/

							// NORMAL
							case NORMAL:
							{
								TCCR2 &=  ~ ( (1u<<COM21) | (1u<<COM20) );	// NORMAL COM21=0 & COM20=0
								break;
							}

							// TOGGLE
							case TOGGLE:
							{
								TCCR2 &= ( ~(1u<<COM21) ); // TOGGLE COM21=0
								TCCR2 |=  (1u<<COM20);  // TOGGLE  COM20=1
								break;
							}
							// CLEAR
							case CLEAR:
							{
								TCCR2 |= (1u<<COM21) ; // CLEAR COM21=1
								TCCR2 &= ( ~ (1u<<COM20) );  // CLEAR  COM20=0
								break;
							}
							// SET
							case SET:
							{
								TCCR2 |= ( (1u<<COM21) | (1u<<COM20) ) ; // SET COM21=1 & COM20=1
								break;
							}
							// INCORRECT INPUT IN  COM MODE
							default: {

								TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
								STATE = NAK;
								break;
							}
							// END OF COM_MODE
						}

						break;
					}


				/*********** ICU MODE *********/
				switch (TIMER_cnfg_arr[loop_index].ICU)
				{
					case ICU_USED:
					{
						if(TIMER_cnfg_arr[loop_index].interrupt == 1 )
						{
							ENABLE_TICIE1;
						}

						break;
					}
					
					case ICU_NO_USED:
					{
						
						PORTC |= (1<<PC4) ;
						break;
					}

					default:
					{
						TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
						STATE=NAK;
						break;
					}
					/*********** END OF ICU MODE *********/
				}
				break;
				/**************************** END OF TIMER 1 ****************************/
			}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	
		


			/**************************** START OF TIMER 2 ****************************/
		case TIMER2: 
			{
				
			TCNT2 = 0; //timer initial value
			switch (TIMER_cnfg_arr[loop_index].WGM_mode)
			{

				/**************************** WGM MODE ****************************/

				case NORMAL_MODE:
				{
					Flag_mode = NON_PWM_MODE;
					/*********** NORMAL_MODE *********/
					TCCR2 &=  ~ ( (1u<<WGM21) | (1u<<WGM20) );	// NORMAL_MODE WGM21=0 & WGM20=0
					TCCR2 = (1<<FOC2); //Non PWM mode
					// END OF NORMAL_MODE
				}


				case CTC_MODE: 
				{
					Flag_mode = NON_PWM_MODE;
					/*********** CTC MODE *********/
					TCCR2 |= (1u<<WGM21) ; // CTC WGM21=1
					TCCR2 &= ( ~ (1u<<WGM20) );  // CTC  WGM20=0
					TCCR2 = (1<<FOC2); //Non PWM mode
					// END OF CTC_MODE
					break;
				}

				case FAST_PWM_MODE: 
				{
					Flag_mode = PWM_MODE;
					/*********** FAST PWM MODE *********/
					TCCR2 |= ((1u << WGM21) | (1u << WGM20)); // FAST PWM MODE WGM21=1 & WGM20=1
					DDRD |= (1u<<PIN7); // OC2 PIN OUTPUT
				break;
				}

				/**************************** END OF WGM MODE ****************************/
				}

				switch(Flag_mode)
				{
					case NON_PWM_MODE:
					{
						
						switch (TIMER_cnfg_arr[loop_index].COM_mode)
						{

							/*********** COM_MODE *********/

							// NORMAL
							case NORMAL:
							{
								TCCR2 &=  ~ ( (1u<<COM21) | (1u<<COM20) );	// NORMAL COM21=0 & COM20=0
								break;
							}
							
							// TOGGLE
							case TOGGLE:
							{
								TCCR2 &= ( ~(1u<<COM21) ); // TOGGLE COM21=0
								TCCR2 |=  (1u<<COM20);  // TOGGLE  COM20=1
								break;
							}
							// CLEAR
							case CLEAR:
							{
								TCCR2 |= (1u<<COM21) ; // CLEAR COM21=1
								TCCR2 &= ( ~ (1u<<COM20) );  // CLEAR  COM20=0
								break;
							}
							// SET
							case SET:
							{
								TCCR2 |= ( (1u<<COM21) | (1u<<COM20) ) ; // SET COM21=1 & COM20=1
								break;
							}
							// INCORRECT INPUT IN  COM MODE
							default: {

								TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
								STATE = NAK;
								break;
							}
							// END OF COM_MODE
						}
						
						break;
					}
					

					case PWM_MODE:
					{
						switch (TIMER_cnfg_arr[loop_index].COM_mode)
						{

							/*********** COM_MODE *********/

							// INVERTING
							case INVERTING:
							{
								TCCR2 |= (1u << COM21); // INVERTING COM21=1
								TCCR2 &= (~(1u << COM20));  // INVERTING COM20=0
								break;
							}
							// NON_INVERTING
							case SET:
							{
								TCCR2 |= ((1u << COM21) | (1u << COM20)); // NON_INVERTING COM21=1 & COM20=1
								break;
							}
							// INCORRECT INPUT IN COM MODE
							default:
							{
								TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
								STATE = NAK;
								break;
							}
							// END OF COM_MODE
						}

						
						break;
					}
					

					default:
					{
						TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
						STATE = NAK;
						break;
					}
				}





				switch (TIMER_cnfg_arr[loop_index].interrupt) 

				{

				/*********** INTERRUPT MODE *********/
				// INTERRUPT

				case INTERRUPT:

				{
					SREG |= (1u<< 7 ) ; // ENABLE GLOBAL INTERRUPT
					switch (TIMER_cnfg_arr[loop_index].WGM_mode) {

					case NORMAL_MODE:
					{
						TIMSK |= (1u<<TOIE2); //Overflow Interrupt Enable
						break;

					}
					case CTC_MODE:
					{
						TIMSK |= (1u<<OCIE2); // Output Compare Match Interrupt Enable
						break;
					}

					// INCORRECT INPUT IN  WGM MODE

					default:

					{
						TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
						STATE = NAK;
						break;
					}

					}
					// END OF WGM MODE
					break;
					// END OF INTERRUPT
				}

				// NO INTERRUPT
				case NO_INTERRUPT:
				 {
					TIMSK &= (~ ( (1u<<OCIE2) |(1u<<TOIE2) ) );  //Overflow Interrupt & Output Compare Match Interrupt disable
					break;
				 }

				default:

				{

					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;
					break;
				}


				/*********** END OF INTERRUPT MODE *********/
				}



				switch (TIMER_cnfg_arr[loop_index].ICU)

				{
				/*********** ICU MODE *********/
                    case NA {
					break;
                    }
                    default:

				{
					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;
					break;
				}
				/*********** END OF ICU MODE *********/
				}

				break;

				/**************************** END OF TIMER 2 ****************************/
			}

			// INCORRECT INPUT IN TIMER

			default:
			{
				TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
				STATE = NAK;
				break;
			}

			/**************************** END OF SWITCH TIMERS  ****************************/
			}

			/**************************** END OF FOTIMER_cnfg_arr  ****************************/
}

	//END OF ELSE
	}

return STATE;
}







ACK Time_Delay ( TIMER_t TIMER_Select , double Required_Delay  )
{
    ACK STATE =AK;
	double Frequency_of_Timer;
	double OCR_Value ;
	uint16 Top=0;

	uint16 Preloaded_Value=0 ;
	uint16 OVF_Counter_Loop ;

	Required_Delay = (Required_Delay) * (10000000);  //seven zeros
	Frequency_of_Timer =   (F_CPU / Prescalar_Factor[TIMER_cnfg_arr[TIMER_Select].prescalar]) ;

	OCR_Value =  Required_Delay * Frequency_of_Timer ;
	OCR_Value = OCR_Value/10000000;					//seven zeros


	uint16 Preloaded_Value=0;
	uint8 test;
	
	
	Required_Delay = (Required_Delay) * (10000000);  //seven zeros
	Frequency_of_Timer =   (F_CPU / Prescalar_Factor[TIMER_cnfg_arr[TIMER_Select].prescalar]) ;
	 
	OCR_Value =  Required_Delay * Frequency_of_Timer ;
	OCR_Value = OCR_Value/10000000;					//seven zeros
	

	if ((TIMER_cnfg_arr[TIMER_Select].WGM_mode == CTC_MODE) && (TIMER_cnfg_arr[TIMER_Select].IS_init == INITIALIZED))
  {
			  /*
			OCR_Value =  Required_Delay * Frequency_of_Timer ;
			OCR_Value = OCR_Value/10000000;					//seven zeros
				*/

			if( (TIMER_cnfg_arr[TIMER_Select].timer == TIMER0) || (TIMER_cnfg_arr[TIMER_Select].timer == TIMER2) )

			{
				if(OCR_Value > 255)
				{
					OVF_Counter_Loop = OCR_Value/255;

					// we can use the polling on Overflow Flag till the OVF_Counter_loop is finished
					//or we can use the interrupt on Overflow Flag by the number of OVF_Counter_loop till is finished
				}
			}

					
					// we can use the interrupt on Overflow Flag by the number of OVF_Counter_loop till is finished
					if(TIMER_cnfg_arr[TIMER_Select].interrupt == INTERRUPT)
					{
						switch(TIMER_Select)
						{
							case TIMER0:
							{
								ENABLE_GLOBAL_INTERRUPT;
								ENABLE_OVERFLOW_INTERRUPT_TIMER0;
								break;	
							}
							case TIMER2:
							{
								ENABLE_GLOBAL_INTERRUPT;
								ENABLE_OVERFLOW_INTERRUPT_TIMER2;
								break;
							}
							default:
							{
								STATE = NAK;
								break;
							}
						}
					}
					
					// we can use the polling on Overflow Flag till the OVF_Counter_loop is finished
					else if(TIMER_cnfg_arr[TIMER_Select].interrupt == NO_INTERRUPT)
					{
						test = Polling_Delay (TIMER_Select );	
					}
					
					else
					{
						STATE =NAK;
					}
						return STATE ;
				}
			}
			
			else if ( (TIMER_cnfg_arr[TIMER_Select].timer == TIMER1) )
			{
					if(OCR_Value > 65535)
					{
							OVF_Counter_Loop = OCR_Value/65535;
							
						// we can use the interrupt on Overflow Flag by the number of OVF_Counter_loop till is finished
							if(TIMER_cnfg_arr[TIMER_Select].interrupt == INTERRUPT)
							{
								ENABLE_GLOBAL_INTERRUPT;
								ENABLE_OVERFLOW_INTERRUPT_TIMER1 ;
							}
												
						// we can use the interrupt on Overflow Flag by the number of OVF_Counter_loop till is finished
							else if(TIMER_cnfg_arr[TIMER_Select].interrupt == NO_INTERRUPT)
							{
								test = Polling_Delay (TIMER_Select );	
							}
							
							else
							{
								STATE=NAK;
							}
							
						return STATE ;	
					}
			}
	

     switch(TIMER_cnfg_arr[TIMER_Select].timer)
           {
             case TIMER0:   
                 {

                     	OCR0 = (uint8) OCR_Value;
                     	break;
                 }

            case TIMER1:
                 {
					 //PORTA |= (1<<PA0);
                     //	OCR1AH =  OCR_Value/256;
					//	OCR1AL =  OCR_Value%256;
                     	OCR1A = (uint16) OCR_Value;
                     	break;
                 }


            case TIMER2:  //need to be modified

                 {
                      	OCR2 = (uint8) OCR_Value;
                     	break;
                 }

            default:
                {
                    // Should not be here
                    STATE = NAK;
					 break;
                }

           }

    }

    else if ( (TIMER_cnfg_arr[TIMER_Select].WGM_mode == NORMAL_MODE)  && (TIMER_cnfg_arr[TIMER_Select].IS_init == INITIALIZED))

        {

       switch(TIMER_cnfg_arr[TIMER_Select].timer)
        {
             case TIMER0:  
                 {
                        Top=255;
                     	//Preloaded_Value = (Top - (Required_Delay * Frequency_of_Timer)) ;

						// Preloaded_Value = Preloaded_Value/10000000;					//seven zeros
						Preloaded_Value = (Top - OCR_Value) ;

                     	TCNT0 = (uint8) Preloaded_Value;
                     	break;
                 }

            case TIMER1:
                 {
						PORTA |= (1<<PA0);
                        Top=65535;
                        //Preloaded_Value =  (Top - (Required_Delay * Frequency_of_Timer)) ;
						// Preloaded_Value = Preloaded_Value/10000000;					//seven zeros
						Preloaded_Value = (Top - OCR_Value) ;

                     	//TCNT1H =  Preloaded_Value/256;
                     	//TCNT1L =  Preloaded_Value%256;
                     	TCNT1 = (uint16) Preloaded_Value;
                     	break;
                 }

            case TIMER2: 
                 {
                        Top=255;
                     	//Preloaded_Value = (Top - (Required_Delay * Frequency_of_Timer));
						 // Preloaded_Value = Preloaded_Value/10000000;					//seven zeros
						Preloaded_Value = (Top - OCR_Value) ;
                      	TCNT2 = (uint8) Preloaded_Value;
                     	break;
                 }

            default:
                {
                    // Should not be here
                    STATE=NAK;
					  break;
                }

           }

       }

        else
        {
             // Should not be here
            STATE=NAK;
            return STATE;
        }


	DDRA=0xFF;
	PORTA= Preloaded_Value ;


    STATE = TIMER_Start(TIMER_Select );

    return STATE;
}





ACK TIMER_Start ( TIMER_t TIMER_Select )
{
	
       ACK STATE = AK ;
       uint8 loop_index=0 ;

    if (NUM_OF_TIMERS > MAX_NUM_OF_TIMERS )
        {
          STATE = NAK ;
        }

    else
    {
        for (loop_index=0 ; loop_index < NUM_OF_TIMERS ; loop_index++)
      {
		   //PORTA |= (1<<PA2);
          STATE=AK;
		if ( (TIMER_cnfg_arr[loop_index].timer == TIMER_Select) && (TIMER_cnfg_arr[loop_index].IS_init==INITIALIZED) )
        {
			//PORTA |= (1<<PA3);
            switch (TIMER_Select)
           {
              case TIMER0:
             {

                 TCCR0 &= (0b11111000);

                switch(TIMER_cnfg_arr[TIMER_Select].prescalar)
			  {
                case PRESCALER0:
                {
                  TCCR0 |= (0b00000001);
                    break;
                }

                 case PRESCALER8:
                {
                  TCCR0 |= (0b00000010);
                    break;
                }

                 case PRESCALER64:
                {
					TCCR0 |= (0b00000011);
                    break;
                }

                 case PRESCALER256:
                {
					TCCR0 |= (0b00000100);
                    break;
                }

                 case PRESCALER1024:
                {

					TCCR0 |= (0b00000101);
                    break;
                }

                  case EXTERNAL_CLK_RISING:
                {
					TCCR0 |= (0b00000110);
                    break;
                }

                  case EXTERNAL_CLK_FALLING:
                {
					TCCR0 |= (0b00000111);
                    break;
                }

                default:
                {
                    TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
                    STATE=NAK;
                    break;
                }
			  }

                break;
            }



            case TIMER1:
             {

                TIMER1_CLEAR_PRESCALAR_BITS;

	               switch(TIMER_cnfg_arr[loop_index].prescalar)
				{

                case PRESCALER0:
                {
                    TIMER1_NO_PRESCALAR();
                    break;
                }

                 case PRESCALER8:
                {
                    TIMER1_PRESCALAR_8();
                    break;
                }

                 case PRESCALER64:
                {
                    TIMER1_PRESCALAR_64();
                    break;
                }

                 case PRESCALER256:
                {
                    TIMER1_PRESCALAR_256();
                    break;
                }

                 case PRESCALER1024:
                {
				//	 PORTA |= (1<<PA4);
                    TIMER1_PRESCALAR_1024();
                    break;
                }

                  case EXTERNAL_CLK_RISING:
                {
                    EXT_TIMER_RISING();
                    break;
                }

                  case EXTERNAL_CLK_FALLING:
                {
                    EXT_TIMER_FALLING();
                    break;
                }

                default:
                {
                    TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
                    STATE=NAK;
                    break;
                }

              }
	               break;
             }



            case TIMER2:
             {
                TCCR2 &= (0b11111000);

                switch(TIMER_cnfg_arr[loop_index].prescalar)
			  {
                case PRESCALER0:
                {
					TCCR2 |= (0b00000001);
                    break;
                }

                 case PRESCALER8:
                {
					TCCR2 |= (0b00000010);
                    break;
                }

                 case PRESCALER32:
                {
					TCCR2 |= (0b00000011);
                    break;
                }

                 case PRESCALER64:
                {
					TCCR2 |= (0b00000100);
                    break;
                }

                 case PRESCALER128:
                {
					TCCR2 |= (0b00000101);
                    break;
                }

                  case PRESCALER256:
                {
					TCCR2 |= (0b00000110);
                    break;
                }

                  case PRESCALER1024:
                {
					TCCR2 |= (0b00000111);
                    break;
                }

                default:
                {
                    TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
                    STATE=NAK;
                    break;
                }
			  }
                break;
            }


            default:
                {
                    TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
                    STATE=NAK;
                    break;
                }

           }

           loop_index=NUM_OF_TIMERS+1;
        }

        else
            {
                     STATE=NAK;
            }
    }
  }
  return STATE;
}






ACK PWM_generate( TIMER_t TIMER_Select , uint8 Required_duty_cycle , uint8 type )
{

	ACK STATE = AK ;
	uint8 loop_index=0 ;
	double TIMER_CLK =0 ;
	double duty_on=0;
	double duty_off=0;
	uint8 value;
	for (loop_index=0 ; loop_index < NUM_OF_TIMERS ; loop_index++)
	{
		//PORTA |= (1<<PA2);
		STATE=AK;
		if ( (TIMER_cnfg_arr[loop_index].timer == TIMER_Select) && (TIMER_cnfg_arr[loop_index].IS_init==INITIALIZED) && (Flag_mode == NON_PWM_MODE) )
		{

			TIMER_CLK= ( TIMER_cnfg_arr[loop_index].prescalar / F_CPU );
			duty_on= (TIMER_CLK*Required_duty_cycle)/100;
			duty_off=TIMER_CLK-duty_on;

			//END IF
		}

		// END FOR
	}

	if (type == INVERTING ){

		value=0;
		DIO_write(PWM_PORT, PWM_PIN, value);
		value^=1;
		Time_Delay ( TIMER_Select , duty_off  );
		DIO_write(PWM_PORT, PWM_PIN, value);
		Time_Delay (TIMER_Select , duty_on );


	}
	else if (type == NON_INVERTING ){

		value=1;
		DIO_write(PWM_PORT, PWM_PIN, value);
		Time_Delay (TIMER_Select , duty_on );
		DIO_write(PWM_PORT, PWM_PIN, value);
		Time_Delay ( TIMER_Select , duty_off  );

	}

	return STATE ;
}
=======
 ACK Polling_Delay (TIMER_t TIMER_Select)
 {
		uint8 i=0; 	
		ACK STATE= AK;	
	

	switch(TIMER_Select)
	{
		case TIMER0:
		{
			for(i=OVF_Counter_Loop; i>0;i--)
			{
				while( (TIFR & (1<<TOV0)) == 0);
				{ TIFR |= 1<<TOV0 ;}
			}			
			break;
		}
		
		case TIMER1:
		{
			for(i=OVF_Counter_Loop; i>0;i--)
			{
				while( (TIFR & (1<<TOV1)) == 0);
				{ TIFR |= 1<<TOV1 ;}
			}
			break;
		}
		
		case TIMER2:
		{
			for(i=OVF_Counter_Loop; i>0;i--)
			{
				while( (TIFR & (1<<TOV2)) == 0);
				{ TIFR |= 1<<TOV2 ;}
			}

			break;
		}
		
		
		default:
		{
			TIMER_cnfg_arr[TIMER_Select].IS_init = NOT_INITIALIZED;
		    STATE=NAK;
			break;
		}
		
	}
	return STATE; 
 }


	ISR(TIMER0_OVF_vect)
	{
		OVF_Counter_Loop--;
		
		if(OVF_Counter_Loop == 0)
		{
			Running_Flag=1;
		}
		
		
	}
	
	
	ISR(TIMER1_OVF_vect)
	{
		OVF_Counter_Loop--;
			
		if(OVF_Counter_Loop == 0)
		{
			Running_Flag=1;
		}
			
			
	}
	
	ISR(TIMER2_OVF_vect)
	{
		OVF_Counter_Loop--;
		
		if(OVF_Counter_Loop == 0)
		{
			Running_Flag=1;
		}
		
		
	}

