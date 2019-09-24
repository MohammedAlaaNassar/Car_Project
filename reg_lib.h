/*
 * reg_lib.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Mohammed
 */

#ifndef REG_LIB_H_
#define REG_LIB_H_


#include "std_types.h"



#define MAX_NUMBER_OF_PINS (uint8)32

#define MAPPING(REG)  ( *( volatile uint8*) REG )


/* Status Register */

#define SREG     MAPPING(0x3F)

// Bit numbers
#define   I    7
#define   T    6
#define   H    5
#define   S    4
#define   V    3
#define   N    2
#define   Z    1
#define   C    0

/******************* PORTS *******************/

/* Port D */
#define PIND     MAPPING(0x10)
#define DDRD     MAPPING(0x11)
#define PORTD    MAPPING(0x12)

// Bit numbers

/* Port C */
#define PINC     MAPPING(0x13)
#define DDRC     MAPPING(0x14)
#define PORTC    MAPPING(0x15)

// Bit numbers

/* Port B */
#define PINB     MAPPING(0x16)
#define DDRB     MAPPING(0x17)
#define PORTB    MAPPING(0x18)

// Bit numbers

/* Port A */
#define PINA     MAPPING(0x19)
#define DDRA     MAPPING(0x1A)
#define PORTA    MAPPING(0x1B)


/******************* Timers *******************/

/* Timer 0 */
#define TCNT0   MAPPING(0x32)
#define TCCR0   MAPPING(0x33)

#define MCUCSR  MAPPING(0x34)
#define MCUCR   MAPPING(0x35)

#define TWCR    MAPPING(0x36)

#define SPMCR   MAPPING(0x37)

#define TIFR    MAPPING(0x38)
#define TIMSK   MAPPING(0x39)

#define GIFR    MAPPING(0x3A)
#define GICR    MAPPING(0x3B)


#define OCR0    MAPPING(0x3C)


#endif /* REG_LIB_H_ */
