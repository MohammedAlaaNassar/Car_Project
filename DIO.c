/*
 * DIO.c
 *
 *  Created on: Sep 22, 2019
 *      Author: Mohammed
 */


#include "DIO.h"

ACK DIO_init_PIN(uint8 PORT ,uint8 PIN,uint8 DIRECTION){
	ACK STATE = AK;
	 switch (PORT)
		  				{
		                case PORT_A:
							if (DIRECTION == OUTPUT)
							{
								DDRA |=(1u<<PIN);
							}
							else if (DIRECTION == INPUT)
							{
								DDRA &=~(1u<<PIN);
							}
						break;
						case PORT_B:
							if (DIRECTION == OUTPUT)
							{
								DDRB |=(1u<<PIN);
							}
							else if (DIRECTION == INPUT)
							{
								DDRB &=~(1u<<PIN);
							}
						break;
						case PORT_C:
							if (DIRECTION == OUTPUT)
							{
								DDRC |=(1u<<PIN);
							}
							else if (DIRECTION == INPUT)
							{
								DDRC &=~(1u<<PIN);
							}
						break;
						case PORT_D:
							if (DIRECTION == OUTPUT)
							{
								DDRD |=(1u<<PIN);
							}
							else if ( DIRECTION == INPUT)
							{
								DDRD &=~(1u<<PIN);
							}
						break;

						default:
							STATE=NAK;
							break;
		  				}

	return STATE ;
}



ACK DIO_init(void){
	ACK STATE = AK;
			uint8 loop_index ;
			if (NUM_OF_PINS>MAX_NUMBER_OF_PINS){  STATE = NAK; }
			else {
				for (loop_index=0 ; loop_index < NUM_OF_PINS ; loop_index++)
				{
			DIO_cnfg_arr[loop_index].IS_init=INITIALIZED;
					switch(DIO_cnfg_arr[loop_index].PORT)
					{

					case PORT_A:
						if (DIO_cnfg_arr[loop_index].DIR==OUTPUT)
					{
						DDRA |=(1u<<DIO_cnfg_arr[loop_index].PIN);
						if (DIO_cnfg_arr[loop_index].VALUE==HIGH)
						{
							PORTA |=(1u<<DIO_cnfg_arr[loop_index].PIN);
						}
						else if (DIO_cnfg_arr[loop_index].VALUE==LOW)
						{
							PORTA &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
						}
						else
						{
							DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
							STATE=NAK;
						}
					}
					else if (DIO_cnfg_arr[loop_index].DIR==INPUT)
					{
						DDRA &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
						if (DIO_cnfg_arr[loop_index].PULL==PULLUP)
						{
							PORTA |=(1u<<DIO_cnfg_arr[loop_index].PIN);

						}
						else if (DIO_cnfg_arr[loop_index].PULL==PULLDOWN)
						{
							PORTA &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
						}
						else
						{
							DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
													STATE=NAK;
						}
					}
					else
					{
						DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
						STATE=NAK;
					}
					break;

					case PORT_B:
								if (DIO_cnfg_arr[loop_index].DIR==OUTPUT)
							{
								DDRB |=(1u<<DIO_cnfg_arr[loop_index].PIN);
								if (DIO_cnfg_arr[loop_index].VALUE==HIGH)
								{
									PORTB |=(1u<<DIO_cnfg_arr[loop_index].PIN);
								}
								else if (DIO_cnfg_arr[loop_index].VALUE==LOW)
								{
									PORTB &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
								}
								else
								{
									DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
									STATE=NAK;
								}
							}
							else if (DIO_cnfg_arr[loop_index].DIR==INPUT)
							{
								DDRB &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
								if (DIO_cnfg_arr[loop_index].PULL==PULLUP)
								{
									PORTB |=(1u<<DIO_cnfg_arr[loop_index].PIN);

								}
								else if (DIO_cnfg_arr[loop_index].PULL==PULLDOWN)
								{
									PORTB &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
								}
								else
								{
									DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
															STATE=NAK;
								}
							}
							else
							{
								DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
								STATE=NAK;
							}
							break;

					case PORT_C:
								if (DIO_cnfg_arr[loop_index].DIR==OUTPUT)
							{
								DDRC |=(1u<<DIO_cnfg_arr[loop_index].PIN);
								if (DIO_cnfg_arr[loop_index].VALUE==HIGH)
								{
									PORTC |=(1u<<DIO_cnfg_arr[loop_index].PIN);
								}
								else if (DIO_cnfg_arr[loop_index].VALUE==LOW)
								{
									PORTC &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
								}
								else
								{
									DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
									STATE=NAK;
								}
							}
							else if (DIO_cnfg_arr[loop_index].DIR==INPUT)
							{
								DDRC &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
								if (DIO_cnfg_arr[loop_index].PULL==PULLUP)
								{
									PORTC |=(1u<<DIO_cnfg_arr[loop_index].PIN);

								}
								else if (DIO_cnfg_arr[loop_index].PULL==PULLDOWN)
								{
									PORTC &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
								}
								else
								{
									DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
															STATE=NAK;
								}
							}
							else
							{
								DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
								STATE=NAK;
							}
							break;

					case PORT_D:
								if (DIO_cnfg_arr[loop_index].DIR==OUTPUT)
							{
								DDRD |=(1u<<DIO_cnfg_arr[loop_index].PIN);
								if (DIO_cnfg_arr[loop_index].VALUE==HIGH)
								{
									PORTD |=(1u<<DIO_cnfg_arr[loop_index].PIN);
								}
								else if (DIO_cnfg_arr[loop_index].VALUE==LOW)
								{
									PORTD &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
								}
								else
								{
									DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
									STATE=NAK;
								}
							}
							else if (DIO_cnfg_arr[loop_index].DIR==INPUT)
							{
								DDRD &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
								if (DIO_cnfg_arr[loop_index].PULL==PULLUP)
								{
									PORTD |=(1u<<DIO_cnfg_arr[loop_index].PIN);

								}
								else if (DIO_cnfg_arr[loop_index].PULL==PULLDOWN)
								{
									PORTD &= ~(1u<<DIO_cnfg_arr[loop_index].PIN);
								}
								else
								{
									DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
															STATE=NAK;
								}
							}
							else
							{
								DIO_cnfg_arr[loop_index].IS_init=NOT_INITIALIZED;
								STATE=NAK;
							}
							break;

					}

				}

    }
return STATE ;
}




ACK DIO_read(uint8 PORT ,uint8 PIN,uint8 *VALUE){
	ACK STATE = AK;
		uint8 loop_index ;
		if (NUM_OF_PINS>MAX_NUMBER_OF_PINS){  STATE = NAK; }
		else {
			for (loop_index=0 ; loop_index < NUM_OF_PINS ; loop_index++)
			{
				STATE = AK;
				 if( (DIO_cnfg_arr[loop_index].PORT==PORT) && (DIO_cnfg_arr[loop_index].PIN==PIN) && (DIO_cnfg_arr[loop_index].IS_init==INITIALIZED ) && (DIO_cnfg_arr[loop_index].DIR==INPUT) )
				  {
					 switch (PORT)
					 				{
					 					case PORT_A:
					 						*VALUE = (1u&(PINA>>PIN));
					 					break;
					 					case PORT_B:
					 					    *VALUE = (1u&(PINB>>PIN));
					 					break;
					 					case PORT_C:
					 						*VALUE = (1u&(PINC>>PIN));
					 					break;
					 					case PORT_D:
					 						*VALUE = (1u&(PIND>>PIN));
					 					break;
					 				}

				  }
				  else
				  {
					  STATE = NAK;
				  }
			}
	loop_index = MAX_NUMBER_OF_PINS+1;
		}



		return STATE ;
}











ACK DIO_write(uint8 PORT ,uint8 PIN,uint8 VALUE){

	ACK STATE = AK;
	uint8 loop_index ;
	if (NUM_OF_PINS>MAX_NUMBER_OF_PINS){  STATE = NAK; }
	else {
	for (loop_index=0 ; loop_index < NUM_OF_PINS ; loop_index++){
		STATE = AK;
		if( (DIO_cnfg_arr[loop_index].PORT==PORT) && (DIO_cnfg_arr[loop_index].PIN==PIN) && (DIO_cnfg_arr[loop_index].IS_init==INITIALIZED ) && (DIO_cnfg_arr[loop_index].DIR==OUTPUT) && ((DIO_cnfg_arr[loop_index].VALUE==HIGH ) || (DIO_cnfg_arr[loop_index].VALUE==LOW ) ) )
  {
	  switch (PORT)
	  				{
	                case PORT_A:
						if (VALUE == HIGH)
						{
							PORTA |=(1u<<PIN);
						}
						else
						{
							PORTA &=~(1u<<PIN);
						}
					break;
					case PORT_B:
						if (VALUE == HIGH)
						{
							PORTB |=(1u<<PIN);
						}
						else
						{
							PORTB &=~(1u<<PIN);
						}
					break;
					case PORT_C:
						if (VALUE == HIGH)
						{
							PORTC |=(1u<<PIN);
						}
						else
						{
							PORTC &=~(1u<<PIN);
						}
					break;
					case PORT_D:
						if (VALUE == HIGH)
						{
							PORTD |=(1u<<PIN);
						}
						else
						{
							PORTD &=~(1u<<PIN);
						}
					break;
				}
	  loop_index = MAX_NUMBER_OF_PINS+1;
  }
  else
  {

	  STATE = NAK;
  }

	}

	}
return STATE ;
}
