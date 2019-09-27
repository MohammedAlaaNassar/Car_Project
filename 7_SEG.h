

#ifndef _7_SEG_H_
#define _7_SEG_H_


#include "reg_lib.h"



#define SEG_PORT PORTB
#define SEG_PINS ( (0xF0)&(SEG_PORT) )


//-------Prototypes------------//
void SEG_write(uint8 );

#endif // _7_SEG_H_
