/*
 * DIO.h
 *
 *  Created on: Sep 22, 2019
 *      Author: Mohammed
 */

#ifndef DIO_H_
#define DIO_H_


#include "DIO_cnfg.h"



typedef enum {AK,NAK} ACK;

ACK DIO_init(void);
ACK DIO_read(uint8 PORT ,uint8 PIN,uint8 *VALUE);
ACK DIO_write(uint8 PORT ,uint8 PIN,uint8 VALUE);






#endif /* DIO_H_ */
