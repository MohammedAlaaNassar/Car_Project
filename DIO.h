/*
 * DIO.h
 *
 *  Created on: Sep 22, 2019
 *      Author: Mohammed
 */

#ifndef DIO_H_
#define DIO_H_


#include "DIO_cnfg.h"





ACK DIO_init(void);
ACK DIO_read(uint8 PORT ,uint8 PIN,uint8 *VALUE);
ACK DIO_write(uint8 PORT ,uint8 PIN,uint8 VALUE);
ACK DIO_init_PIN(uint8 PORT ,uint8 PIN,uint8 DIRECTION );





#endif /* DIO_H_ */
