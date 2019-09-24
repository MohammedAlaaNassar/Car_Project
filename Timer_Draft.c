

ACK timer_init (void)
{

    ACK STATE = AK;
        uint8 loop_index=0 ;
			if (NUM_OF_PINS>MAX_NUMBER_OF_PINS)
			    {  STATE = NAK; }

    else
    {
				for (loop_index=0 ; loop_index < NUM_OF_PINS ; loop_index++)
				{
			        TIMER_cnfg_arr[loop_index].IS_init=INITIALIZED;

                    switch(TIMER_cnfg_arr[loop_index].timer)

                    {

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
                    }

                    default
                    {

                        TIMER_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
                        STATE=NAK;
                        break;
                    }
				}


    }
}
