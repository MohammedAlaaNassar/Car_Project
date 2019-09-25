/*
 * reg_lib.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Mohammed
 */

#ifndef REG_LIB_H_
#define REG_LIB_H_



#include "std_types.h"


#define  F_CPU	1000000
#define MAX_NUMBER_OF_PINS (uint8)32

#include <avr/io.h>

#define MAPPING(REG)  ( *( volatile uint8*) REG )
#define MAPPING16(REG)  ( *( volatile uint16*) REG )

#define PIN0                0
#define PIN1                1
#define PIN2                2
#define PIN3                3
#define PIN4                4
#define PIN5                5
#define PIN6                6
#define PIN7                7

/*
// Status Register //

#define SREG     MAPPING(0x5F)

// Bit numbers
#define   I    7
#define   T    6
#define   H    5
#define   S    4
#define   V    3
#define   N    2
#define   Z    1
#define   C    0

// I/O registers //

///////////////////// PORTS ////////////////////

// Port D //
#define PIND     MAPPING(0x30)
#define DDRD     MAPPING(0x31)
#define PORTD    MAPPING(0x32)

// Bit numbers

//--------- Port C ------------/
#define PINC     MAPPING(0x33)
#define DDRC     MAPPING(0x34)
#define PORTC    MAPPING(0x35)

// Bit numbers

//--------- Port B ------------/
#define PINB     MAPPING(0x36)
#define DDRB     MAPPING(0x37)
#define PORTB    MAPPING(0x38)

// Bit numbers

//--------- Port A ------------/
#define PINA     MAPPING(0x39)
#define DDRA     MAPPING(0x3A)
#define PORTA    MAPPING(0x3B)


/-------------- Timers ------------/

//--------- TIMSK ------------/
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

//-------- TIFR ----------//
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

//----- Timer 0 ------//
#define TCNT0   MAPPING(0x52)
#define TCCR0   MAPPING(0x53)

#define MCUCSR  MAPPING(0x54)
#define MCUCR   MAPPING(0x55)

#define TWCR    MAPPING(0x56)

#define SPMCR   MAPPING(0x57)

#define TIFR    MAPPING(0x58)
#define TIMSK   MAPPING(0x59)

#define GIFR    MAPPING(0x5A)
#define GICR    MAPPING(0x5B)


#define OCR0    MAPPING(0x5C)

//------ TCCR0 -------- //
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0


//------- Timer 2 -------- //
#define OCR2    MAPPING(0x43)
#define TCNT2   MAPPING(0x44)
#define TCCR2   MAPPING(0x45)

//-------  TCCR2 -------- //
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0

//-------  Timer 1 -------- //
#define ICR1    MAPPING16(0x46)
#define ICR1L   MAPPING(0x46)
#define ICR1H   MAPPING(0x47)
#define OCR1B   MAPPING16(0x48)
#define OCR1BL  MAPPING(0x48)
#define OCR1BH  MAPPING(0x49)
#define OCR1A   MAPPING16(0x4A)
#define OCR1AL  MAPPING(0x4A)
#define OCR1AH  MAPPING(0x4B)
#define TCNT1   MAPPING16(0x4C)
#define TCNT1L  MAPPING(0x4C)
#define TCNT1H  MAPPING(0x4D)
#define TCCR1B  MAPPING(0x4E)
#define TCCR1A  MAPPING(0x4F)



//-------  TCCR1A -------- //
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

//-------  TCCR1B -------- //
#define ICNC1   7
#define ICES1   6
//-------  bit 5 reserved -------- //
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0
*/

#endif /* REG_LIB_H_ */
