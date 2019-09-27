/*
 * reg_lib.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Mohammed
 */

#ifndef REG_LIB_H_
#define REG_LIB_H_



#include "std_types.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#define MAX_NUMBER_OF_PINS (uint8)32

#ifndef F_CPU
#define F_CPU 1000000ul
#endif

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
//
///* Status Register */
//
#ifndef SREG
#define SREG     MAPPING(0x5F)
#endif
//
//// Bit numbers
//#define   I    7
//#define   T    6
//#define   H    5
//#define   S    4
//#define   V    3
//#define   N    2
//#define   Z    1
//#define   C    0
//
///* I/O registers */
//
///******************* PORTS *******************/
//
///* Port D */
//#define PIND     MAPPING(0x30)
//#define DDRD     MAPPING(0x31)
//#define PORTD    MAPPING(0x32)
//
//// Bit numbers
//
///* Port C */
//#define PINC     MAPPING(0x33)
//#define DDRC     MAPPING(0x34)
//#define PORTC    MAPPING(0x35)
//
//// Bit numbers
//
///* Port B */
//#define PINB     MAPPING(0x36)
//#define DDRB     MAPPING(0x37)
//#define PORTB    MAPPING(0x38)
//
//// Bit numbers
//
///* Port A */
//#define PINA     MAPPING(0x39)
//#define DDRA     MAPPING(0x3A)
//#define PORTA    MAPPING(0x3B)
//
//
////* Interrupt vectors */

//#  define __INTR_ATTRS used, externally_visible
/*#  define ISR(vector, ...)            \    */
/*    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \  */
//    void vector (void)

///* External Interrupt Request 0 */
//#define INT0_vect_num		1
//#define INT0_vect			_VECTOR(1)
//#define SIG_INTERRUPT0			_VECTOR(1)
//
///* External Interrupt Request 1 */
//#define INT1_vect_num		2
//#define INT1_vect			_VECTOR(2)
//#define SIG_INTERRUPT1			_VECTOR(2)
//
///* External Interrupt Request 2 */
//#define INT2_vect_num		3
//#define INT2_vect			_VECTOR(3)
//#define SIG_INTERRUPT2			_VECTOR(3)
//
///* Timer/Counter2 Compare Match */
//#define TIMER2_COMP_vect_num	4
//#define TIMER2_COMP_vect		_VECTOR(4)
//#define SIG_OUTPUT_COMPARE2		_VECTOR(4)
//
///* Timer/Counter2 Overflow */
//#define TIMER2_OVF_vect_num		5
//#define TIMER2_OVF_vect			_VECTOR(5)
//#define SIG_OVERFLOW2			_VECTOR(5)
//
///* Timer/Counter1 Capture Event */
//#define TIMER1_CAPT_vect_num	6
//#define TIMER1_CAPT_vect		_VECTOR(6)
//#define SIG_INPUT_CAPTURE1		_VECTOR(6)
//
///* Timer/Counter1 Compare Match A */
//#define TIMER1_COMPA_vect_num	7
//#define TIMER1_COMPA_vect		_VECTOR(7)
//#define SIG_OUTPUT_COMPARE1A		_VECTOR(7)
//
///* Timer/Counter1 Compare Match B */
//#define TIMER1_COMPB_vect_num	8
//#define TIMER1_COMPB_vect		_VECTOR(8)
//#define SIG_OUTPUT_COMPARE1B		_VECTOR(8)
//
///* Timer/Counter1 Overflow */
//#define TIMER1_OVF_vect_num		9
//#define TIMER1_OVF_vect			_VECTOR(9)
//#define SIG_OVERFLOW1			_VECTOR(9)
//
///* Timer/Counter0 Compare Match */
//#define TIMER0_COMP_vect_num	10
//#define TIMER0_COMP_vect		_VECTOR(10)
//#define SIG_OUTPUT_COMPARE0		_VECTOR(10)
//
///* Timer/Counter0 Overflow */
//#define TIMER0_OVF_vect_num		11
//#define TIMER0_OVF_vect			_VECTOR(11)
//#define SIG_OVERFLOW0			_VECTOR(11)
//
///* Serial Transfer Complete */
//#define SPI_STC_vect_num		12
//#define SPI_STC_vect			_VECTOR(12)
//#define SIG_SPI				_VECTOR(12)
//
///* USART, Rx Complete */
//#define USART_RXC_vect_num		13
//#define USART_RXC_vect			_VECTOR(13)
//#define SIG_USART_RECV			_VECTOR(13)
//#define SIG_UART_RECV			_VECTOR(13)
//
///* USART Data Register Empty */
//#define USART_UDRE_vect_num		14
//#define USART_UDRE_vect			_VECTOR(14)
//#define SIG_USART_DATA			_VECTOR(14)
//#define SIG_UART_DATA			_VECTOR(14)
//
///* USART, Tx Complete */
//#define USART_TXC_vect_num		15
//#define USART_TXC_vect			_VECTOR(15)
//#define SIG_USART_TRANS			_VECTOR(15)
//#define SIG_UART_TRANS			_VECTOR(15)
//
///* ADC Conversion Complete */
//#define ADC_vect_num		16
//#define ADC_vect			_VECTOR(16)
//#define SIG_ADC				_VECTOR(16)
//
///* EEPROM Ready */
//#define EE_RDY_vect_num		17
//#define EE_RDY_vect			_VECTOR(17)
//#define SIG_EEPROM_READY		_VECTOR(17)
//
///* Analog Comparator */
//#define ANA_COMP_vect_num		18
//#define ANA_COMP_vect			_VECTOR(18)
//#define SIG_COMPARATOR			_VECTOR(18)
//
///* 2-wire Serial Interface */
//#define TWI_vect_num		19
//#define TWI_vect			_VECTOR(19)
//#define SIG_2WIRE_SERIAL		_VECTOR(19)
//
///* Store Program Memory Ready */
//#define SPM_RDY_vect_num		20
//#define SPM_RDY_vect			_VECTOR(20)
//#define SIG_SPM_READY			_VECTOR(20)
//
//#define _VECTORS_SIZE 84


#endif /* REG_LIB_H_ */
