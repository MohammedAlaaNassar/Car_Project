
#include"Timer_Draft_Ehab.h"
#include"TIMER_cnfg.h"

ACK timer_init (void)
{

    ACK STATE = AK ;
        uint8 loop_index=0 ;
			if (NUM_OF_TIMERS > MAX_NUM_OF_TIMERS ){  STATE = NAK ; }

    else
    {
            for (loop_index=0 ; loop_index < NUM_OF_TIMERS ; loop_index++)
            {
			        TIMER_cnfg_arr[loop_index].IS_init=INITIALIZED;

                    switch(TIMER_cnfg_arr[loop_index].timer)

                    {
                        /*
                      case TIMER0:
                        {
                            switch (TIMER_cnfg_arr[loop_index].prescalar)
                            {
                                case PRESCALER0
                                {

                                    break;
                                }

                                default:
                                {
                                    TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
                                    STATE=NAK;
                                    break;
                                }

                            }

                            switch (TIMER_cnfg_arr[loop_index].WGM_mode)
                            {
                                case NORMAL_MODE:
                                    {
                                        switch (TIMER_cnfg_arr[loop_index].COM_mode)
                                        {
                                            case NORMAL:
                                                {

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
                                 case INTERRUPT:
                                     {

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
                        */
                        case TIMER1:
                        {


                            switch (TIMER_cnfg_arr[loop_index].WGM_mode)
                            {

                                case NORMAL_MODE:
                                    {
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

                                    case CTC_MODE:
                                    {
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
                                                    COM_1A_PWM_NON_INVERTED()
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
                                 ENABLE_GLOBAL_INTERRUPT       //Enable_Global_Interrupt
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

                        }

                    }

                    default
                    {

                        TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
                        STATE=NAK;
                        break;
                    }
				}


    }
    return STATE;
}



void Timer_Delay ( float Required_Delay)
{


	Time_Delay ( Prescalar_Factor , Required_Delay  );

	Prescalar_Factor_config(Prescalar_Factor);

	    switch(TIMER_cnfg_arr[loop_index].timer)
           {

             case TIMER0: //need to be modified
                 {
                     	DDR_TIMER_0 |= ( 1<< OC);
                     	break;
                 }

            case TIMER1:
                 {
                     	DDR_TIMER_1 |= ( 1<< OC1A);
                     	break;
                 }

            case TIMER2://need to be modified
                 {
                     	DDR_TIMER_2 |= ( 1<< OC1A);
                     	break;
                 }

            default:
                {
                    // Should not be here
                    break;

                }

           }


}


void Time_Delay ( TIMER_t Timer_Select , float Required_Delay  )
{
	unsigned long Frequency_of_Timer_1;

	Required_Delay = (Required_Delay) * (10000000);  //seven zeros

	Frequency_of_Timer_1 =  (unsigned long) (F_CPU / TIMER_cnfg_arr[Timer_Select].prescalar) ;

	if(TIMER_cnfg_arr[Timer_Select].timer == CTC_MODE)
    {
    unsigned long OCR_Value ;

	OCR_Value =  Required_Delay * Frequency_of_Timer_1 ;

	OCR_Value = OCR_Value/10000000;					//seven zeros

     switch(TIMER_cnfg_arr[Timer_Select].timer)
           {
             case TIMER0:   //need to be modified
                 {
                     	OCR0 = (unsigned char) OCR_Value;
                     	break;
                 }

            case TIMER1:
                 {
                     	OCR1A = (unsigned short) OCR_Value;
                     	break;
                 }

            case TIMER2:  //need to be modified
                 {
                      	OCR2 = (unsigned char) OCR_Value;
                     	break;
                 }

            default:
                {
                    // Should not be here
                    break;

                }

           }
    }

    else if (TIMER_cnfg_arr[Timer_Select].timer == NORMAL_MODE)

        {
             unsigned long Preloaded_Value ;

	Preloaded_Value =  Required_Delay * Frequency_of_Timer_1 ;

	Preloaded_Value = Preloaded_Value/10000000;					//seven zeros

     switch(TIMER_cnfg_arr[Timer_Select].timer)
        {
             case TIMER0:   //need to be modified
                 {
                     	TCNT0 = (unsigned char) Preloaded_Value;
                     	break;
                 }

            case TIMER1:
                 {
                     	OCR1A = (unsigned short) Preloaded_Value;
                     	break;
                 }

            case TIMER2:  //need to be modified
                 {
                      	OCR2 = (unsigned char) Preloaded_Value;
                     	break;
                 }

            default:
                {
                    // Should not be here
                    break;

                }

           }

        }


        else
        {

        }
    }
    Timer_Start ( Timer_Select );
}



ACK Timer_Start ( TIMER_t Timer_Select )
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
		if ( (TIMER_cnfg_arr[loop_index].timer == Timer_Select) && (TIMER_cnfg_arr[loop_index].IS_init==INITIALIZED) )
        {


            switch (Timer_Select)
           {
              case TIMER0:
             {
                switch(TIMER_cnfg_arr[loop_index].prescalar)

                case PRESCALER0:
                {

                    break;
                }

                 case PRESCALER8:
                {

                    break;
                }

                 case PRESCALER64:
                {

                    break;
                }

                 case PRESCALER256:
                {

                    break;
                }

                 case PRESCALER1024:
                {
                    break;
                }

                  case EXTERNAL_CLK_RISING:
                {

                    break;
                }

                  case EXTERNAL_CLK_FALLING:
                {

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


            case TIMER1:
             {
                TIMER1_CLEAR_PRESCALAR_BITS;

                switch(TIMER_cnfg_arr[loop_index].prescalar)

                case PRESCALER0:
                {
                    TIMER1_NO_PRESCALAR();
                    break;
                }

                 case PRESCALER8
                {
                    TIMER1_PRESCALAR_8();
                    break;
                }

                 case PRESCALER64
                {
                    TIMER1_PRESCALAR_64();
                    break;
                }

                 case PRESCALER256
                {
                    TIMER1_PRESCALAR_256();
                    break;
                }

                 case PRESCALER1024
                {
                    TIMER1_PRESCALAR_1024();
                    break;
                }

                  case EXTERNAL_CLK_RISING
                {
                    EXT_TIMER_RISING();
                    break;
                }

                  case EXTERNAL_CLK_FALLING
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



            case TIMER2:
             {

                switch(TIMER_cnfg_arr[loop_index].prescalar)

                case PRESCALER0:
                {

                    break;
                }

                 case PRESCALER8:
                {

                    break;
                }

                 case PRESCALER64:
                {

                    break;
                }

                 case PRESCALER256:
                {

                    break;
                }

                 case PRESCALER1024:
                {

                    break;
                }

                  case EXTERNAL_CLK_RISING:
                {

                    break;
                }

                  case EXTERNAL_CLK_FALLING:
                {

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

