/*
 * TIMER.c
 *
 *  Created on: Sep 24, 2019
 *      Author: Mohammed
 */

#include "TIMER_Draft.h"
#include "DIO.h"
static uint16 Prescalar_Factor[7]={1,8,64,256,1024,5,6};


/**************************** TIMER DRIVER ****************************/


ACK TIMER_init(void) 
{

	ACK STATE = AK;
	
	uint8 loop_index = 0;
	if (NUM_OF_TIMERS > MAX_NUM_OF_TIMERS) 
	{
		STATE = NAK;
	}
	else 
	{
		for (loop_index = 0; loop_index < NUM_OF_TIMERS; loop_index++) 
		{
			TIMER_cnfg_arr[loop_index].IS_init = INITIALIZED;

			switch (TIMER_cnfg_arr[loop_index].timer) 
		{

			case TIMER0: 
			{
				
				/**************************** TIMER 0 ****************************/
				TCNT0 = 0; //timer initial value
				switch (TIMER_cnfg_arr[loop_index].WGM_mode) 
				{

				/**************************** WGM MODE ****************************/

				case NORMAL_MODE:
				{
					/*********** NORMAL_MODE *********/
					TCCR0 &=  ~ ( (1u<<WGM01) | (1u<<WGM00) );	// NORMAL_MODE WGM01=0 & WGM00=0
					TCCR0 = (1<<FOC0); //Non PWM mode

					switch (TIMER_cnfg_arr[loop_index].COM_mode) 
					{

					/*********** COM_MODE *********/

					// NORMAL
					case NORMAL: 
					{
						TCCR0 &=  ~( (1u<<COM01) | (1u<<COM00) );	// NORMAL COM01=0 & COM00=0
						break;
					}
					// TOGGLE
					case TOGGLE: 
					{
						TCCR0 &= ( ~(1u<<COM01) ); // TOGGLE COM01=0
						TCCR0 |=  (1u<<COM00);  // TOGGLE  COM00=1
						break;
					}
					// CLEAR
					case CLEAR: 
					{
						TCCR0 |= (1u<<COM01) ; // CLEAR COM01=1
						TCCR0 &= ( ~ (1u<<COM00) );  // CLEAR  COM00=0
						break;
					}
					// SET
					case SET: 
					{
						TCCR0 |= ( (1u<<COM01) | (1u<<COM00) ) ; // SET COM01=1 & COM00=1
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
					// END OF NORMAL_MODE
					break;
				}

				case CTC_MODE: 
				{
					
					/*********** CTC MODE *********/
					TCCR0 |= (1u<<WGM01) ; // CTC WGM01=1
				    TCCR0 &= ( ~ (1u<<WGM00) );  // CTC  WGM00=0
				    TCCR0 = (1<<FOC0); //Non PWM mode
					
					
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
					// END OF CTC_MODE
					break;
				}

				case FAST_PWM_MODE:
				 {
					/*********** FAST PWM MODE *********/
					TCCR0 |= ((1u << WGM01) | (1u << WGM00)); // FAST PWM MODE WGM01=1 & WGM00=1
					 DDRB |= (1u<<PIN3); // OCO PIN OUTPUT
					switch (TIMER_cnfg_arr[loop_index].COM_mode) 
					{

					/*********** COM_MODE *********/

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

					// END OF FAST_PWM_MODE
					break;
				}

				case PHASE_CORRECT_MODE: 
				{
					/*********** PHASE CORRECT MODE *********/
					TCCR0 &= (~(1u << WGM01)); // PHASE CORRECT MODE  WGM01=0
					TCCR0 |= (1u << WGM00);  // PHASE CORRECT MODE  WGM00=1
                    DDRB |= (1u<<PIN3);  // OCO PIN OUTPUT
					switch (TIMER_cnfg_arr[loop_index].COM_mode) 
					{

					/*********** COM_MODE *********/

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

					// END OF FAST_PWM_MODE
					break;
				}

					// INCORRECT INPUT IN  WGM MODE
				default: {
					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;
					break;
			          	}

				/**************************** END OF WGM MODE ****************************/
			}


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
					default: {
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

				default: {

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
				{break;}
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



                        case TIMER1:
                        {
                  /**************************** TIMER 1 ****************************/

                            switch (TIMER_cnfg_arr[loop_index].WGM_mode)
                            {

                                case NORMAL_MODE:
                                    {
                                        TCNT1H=0;
                                        TCNT1L=0;
                                        //TCNT1=0;
                                        NORMAL_MODE_TIMER1();
										
                                        switch (TIMER_cnfg_arr[loop_index].COM_mode)
                                        {
                                            case NORMAL:
                                                {
                                                    COM_1A_NORMAL();
                                                    break;
                                                }

                                            case TOGGLE:
                                                {
                                                  COM_1A_TOGGLE();
                                                    break;
                                                }

                                            case CLEAR:
                                                {
                                                    COM_1A_CLEAR();
                                                    break;
                                                }

                                            case SET:
                                                {
                                                    COM_1A_SET;
                                                    break;
                                                }



                                            default:
                                                {

                                                    TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
                                                    STATE=NAK;
                                                    break;
                                                }

                                        }
                                    }

                                    case CTC_MODE:
                                    {
                                        TCNT1H=0;
                                        TCNT1L=0;
                                        //TCNT1=0;
                                        CTC_OCR1A_MODE_TIMER1();
										
                                        switch (TIMER_cnfg_arr[loop_index].COM_mode)
                                        {
                                             case NORMAL:
                                                {
                                                    COM_1A_NORMAL();
                                                    break;
                                                }

                                            case TOGGLE:
                                                {
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
                                    }

                                    case FAST_PWM_MODE:
                                    {
                                        PWM_PHASE_CORRECT_OCR1A();

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
                                    }

                                    case PHASE_CORRECT_MODE:
                                    {
                                        PWM_PHASE_CORRECT_OCR1A();

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
                                    }

                                 default:
                                    {
                                        STATE=NAK;
                                        break;
                                    }
                            }

                            switch (TIMER_cnfg_arr[loop_index].interrupt)
                            {
                                 ENABLE_GLOBAL_INTERRUPT;      //Enable_Global_Interrupt
                                 case INTERRUPT:
                                     {
                                        switch(TIMER_cnfg_arr[loop_index].WGM_mode)
                                        {
                                            case NORMAL:
                                                {
                                                    ENABLE_TOIE1;
                                                }

                                            case CTC_MODE:
                                                {
                                                    ENABLE_OCIE1A;
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

                                default:
                                {

                                    TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
                                    STATE=NAK;
                                    break;
                                }

                            }
                            /**************************** END OF TIMER 1 ****************************/
                        }



			case TIMER2: {

				/**************************** TIMER 2 ****************************/
				TCNT2 = 0; //timer initial value
				switch (TIMER_cnfg_arr[loop_index].WGM_mode) {

				/**************************** WGM MODE ****************************/

				case NORMAL_MODE:
				{
					/*********** NORMAL_MODE *********/
					TCCR2 &=  ~ ( (1u<<WGM21) | (1u<<WGM20) );	// NORMAL_MODE WGM21=0 & WGM20=0
					TCCR2 = (1<<FOC2); //Non PWM mode

					switch (TIMER_cnfg_arr[loop_index].COM_mode) {

					/*********** COM_MODE *********/

					// NORMAL
					case NORMAL: {
						TCCR2 &=  ~ ( (1u<<COM21) | (1u<<COM20) );	// NORMAL COM21=0 & COM20=0
						break;
					}
					// TOGGLE
					case TOGGLE: {
						TCCR2 &= ( ~(1u<<COM21) ); // TOGGLE COM21=0
						TCCR2 |=  (1u<<COM20);  // TOGGLE  COM20=1
						break;
					}
					// CLEAR
					case CLEAR: {
						TCCR2 |= (1u<<COM21) ; // CLEAR COM21=1
						TCCR2 &= ( ~ (1u<<COM20) );  // CLEAR  COM20=0
						break;
					}
					// SET
					case SET: {
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
					// END OF NORMAL_MODE
				}

				case CTC_MODE: {
					/*********** CTC MODE *********/
					TCCR2 |= (1u<<WGM21) ; // CTC WGM21=1
					TCCR2 &= ( ~ (1u<<WGM20) );  // CTC  WGM20=0
					TCCR2 = (1<<FOC2); //Non PWM mode

					switch (TIMER_cnfg_arr[loop_index].COM_mode) {

					/*********** COM_MODE *********/

					// NORMAL
					case NORMAL: {
						TCCR2 &= ~((1u << COM21) | (1u << COM20));// NORMAL COM21=0 & COM20=0
						break;
					}
					// TOGGLE
					case TOGGLE: {
						TCCR2 &= (~(1u << COM21)); // TOGGLE COM21=0
						TCCR2 |= (1u << COM20);  // TOGGLE  COM20=1
						break;
					}
					// CLEAR
					case CLEAR: {
						TCCR2 |= (1u << COM21); // CLEAR COM21=1
						TCCR2 &= (~(1u << COM20));  // CLEAR  COM20=0
						break;
					}
					// SET
					case SET: {
						TCCR2 |= ((1u << COM21) | (1u << COM20)); // SET COM21=1 & COM20=1
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
					// END OF CTC_MODE
				}

				case FAST_PWM_MODE: {
					/*********** FAST PWM MODE *********/
					TCCR2 |= ((1u << WGM21) | (1u << WGM20)); // FAST PWM MODE WGM21=1 & WGM20=1
					DDRD |= (1u<<PIN7); // OC2 PIN OUTPUT
					switch (TIMER_cnfg_arr[loop_index].COM_mode) {

					/*********** COM_MODE *********/

					// INVERTING
					case INVERTING: {
						TCCR2 |= (1u << COM21); // INVERTING COM21=1
						TCCR2 &= (~(1u << COM20));  // INVERTING COM20=0
						break;
					}
					// NON_INVERTING
					case SET: {
						TCCR2 |= ((1u << COM21) | (1u << COM20)); // NON_INVERTING COM21=1 & COM20=1
						break;
					}
					// INCORRECT INPUT IN COM MODE
					default: {

						TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
						STATE = NAK;
						break;
					}
					// END OF COM_MODE
					}

					// END OF FAST_PWM_MODE
				}

				case PHASE_CORRECT_MODE: {
					/*********** PHASE CORRECT MODE *********/
					TCCR2 &= (~(1u << WGM21)); // PHASE CORRECT MODE  WGM21=0
					TCCR2 |= (1u << WGM20);  // PHASE CORRECT MODE  WGM20=1
					DDRD |= (1u<<PIN7);  // OC2 PIN OUTPUT
					switch (TIMER_cnfg_arr[loop_index].COM_mode) {

					/*********** COM_MODE *********/

					// INVERTING
					case INVERTING: {
						TCCR2 |= (1u << COM21); // INVERTING COM21=1
						TCCR2 &= (~(1u << COM20));  // INVERTING COM20=0
						break;
					}
					// NON_INVERTING
					case SET: {
						TCCR2 |= ((1u << COM21) | (1u << COM20)); // NON_INVERTING COM21=1 & COM20=1
						break;
					}
					// INCORRECT INPUT IN COM MODE
					default: {

						TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
						STATE = NAK;
						break;
					}
					// END OF COM_MODE
					}

					// END OF FAST_PWM_MODE
				}

				// INCORRECT INPUT IN  WGM MODE
				default: {
					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;
					break;
				}

				/**************************** END OF WGM MODE ****************************/
				}


				switch (TIMER_cnfg_arr[loop_index].interrupt) {

				/*********** INTERRUPT MODE *********/
				// INTERRUPT
				case INTERRUPT: {
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
					default: {
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
				case NO_INTERRUPT: {
					TIMSK &= (~ ( (1u<<OCIE0) |(1u<<TOIE0) ) );  //Overflow Interrupt & Output Compare Match Interrupt disable
					break;
				}

				default: {

					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;
					break;
				}


				/*********** END OF INTERRUPT MODE *********/
				}


				switch (TIMER_cnfg_arr[loop_index].ICU) {
				/*********** ICU MODE *********/
				case NA:
					break;
				default: {
					TIMER_cnfg_arr[loop_index].IS_init = NOT_INITIALIZED;
					STATE = NAK;
					break;
				}
				/*********** END OF ICU MODE *********/
				}

				break;

				/**************************** END OF TIMER 2 ****************************/
			}

			// INCORRECT INPUT IN  TIMER
			default: {
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







ACK Time_Delay ( TIMER_t TIMER_Select , float Required_Delay  )
{
	
    ACK STATE =AK;
	
	uint16 Frequency_of_Timer;


	Required_Delay = (Required_Delay) * (10000000);  //seven zeros

	Frequency_of_Timer =  (uint32) (F_CPU / Prescalar_Factor[TIMER_cnfg_arr[TIMER_Select].prescalar]) ;


	if(TIMER_cnfg_arr[TIMER_Select].WGM_mode == CTC_MODE)
  {
    uint32 OCR_Value ;

	OCR_Value =  Required_Delay * Frequency_of_Timer ;
	
	OCR_Value = OCR_Value/10000000;					//seven zeros

     switch(TIMER_cnfg_arr[TIMER_Select].timer)
           {
             case TIMER0:   //need to be modified ok
                 {
					 DIO_write(PORT_D,PIN3,HIGH);
                     	OCR0 = (uint8) OCR_Value;
                     	break;
                 }

            case TIMER1:
                 {
                     	OCR1AH =  OCR_Value/256;
                     	OCR1AL =  OCR_Value%256;
                     	//OCR1A = (uint16) OCR_Value;
                     	break;
                 }

            case TIMER2:  //need to be modified ok
                 {
                      	OCR2 = (uint8) OCR_Value;
                     	break;
                 }

            default:
                {
                    // Should not be here
                    break;
                    STATE = NAK;
                }

           }
    }

    else if (TIMER_cnfg_arr[TIMER_Select].WGM_mode == NORMAL_MODE)

        {
            uint16 Top=0;
            uint16 Preloaded_Value=0 ;

       switch(TIMER_cnfg_arr[TIMER_Select].timer)
        {
             case TIMER0:   //need to be modified
                 {
                        Top=255;
                     	Preloaded_Value = (Top - (Required_Delay * Frequency_of_Timer)) ;
	                    Preloaded_Value = Preloaded_Value/10000000;					//seven zeros
                     	TCNT0 = (uint8) Preloaded_Value;
                     	break;
                 }

            case TIMER1:
                 {
                        Top=65535;
                        Preloaded_Value =  (Top - (Required_Delay * Frequency_of_Timer)) ;
	                    Preloaded_Value = Preloaded_Value/10000000;					//seven zeros
                     	TCNT1H =  Preloaded_Value/256;
                     	TCNT1L =  Preloaded_Value%256;
                     	//TCNT1 = (uint16) Preloaded_Value;
                     	break;
                 }

            case TIMER2:  //need to be modified
                 {
                        Top=255;
                     	Preloaded_Value = (Top - (Required_Delay * Frequency_of_Timer));
	                    Preloaded_Value = Preloaded_Value/10000000;					//seven zeros
                      	TCNT2 = (uint8) Preloaded_Value;
                     	break;
                 }

            default:
                {
                    // Should not be here
                    break;
                    STATE=NAK;

                }

           }

        }

        else
        {
             // Should not be here
            STATE=NAK;
            return STATE;
        }

	OCR0=195;
    
     TCCR0 |= (0b00000101);
	
    //STATE = TIMER_Start(TIMER_Select );

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
          STATE=AK;
		if ( (TIMER_cnfg_arr[loop_index].timer == TIMER_Select) && (TIMER_cnfg_arr[loop_index].IS_init==INITIALIZED) )
        {


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
					DIO_write(PORT_D,PIN4,HIGH);
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
                break;
            }
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

                 case PRESCALER64:
                {
					TCCR2 |= (0b00000011);
                    break;
                }

                 case PRESCALER256:
                {
					TCCR2 |= (0b00000100);
                    break;
                }

                 case PRESCALER1024:
                {
					TCCR2 |= (0b00000101);
                    break;
                }

                  case EXTERNAL_CLK_RISING:
                {
					TCCR2 |= (0b00000110);
                    break;
                }

                  case EXTERNAL_CLK_FALLING:
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

