/*
 * reg_lib.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Mohammed
 */

#ifndef REG_LIB_H_
#define REG_LIB_H_


#include "std_types.h"





#define MAPPING(REG)  ( *( volatile uint8*) (REG) )


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
#define PIND     MAPPING(0x30)
#define DDRD     MAPPING(0x31)
#define PORTD    MAPPING(0x32)

// Bit numbers

/* Port C */
#define PINC     MAPPING(0x33)
#define DDRC     MAPPING(0x34)
#define PORTC    MAPPING(0x35)

// Bit numbers

/* Port B */
#define PINB     MAPPING(0x36)
#define DDRB     MAPPING(0x37)
#define PORTB    MAPPING(0x38)

// Bit numbers

/* Port A */
#define PINA     MAPPING(0x39)
#define DDRA     MAPPING(0x3A)
#define PORTA    MAPPING(0x3B)


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
