/*
 * 7_SEG.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Mohammed
 */


#include "reg_lib.h"



#define SEG_PORT PORTB
#define SEG_PINS ( (0xF0)&(PORTB) )



ACK SEG_write(uint8 NUM){


	SEG_PORT = SEG_PINS | (NUM & 0x0F);

return AK ;
 }
