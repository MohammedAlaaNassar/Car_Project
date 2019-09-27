/*
 * 7_SEG.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Mohammed
 */


 #include"7_SEG.h"



void SEG_write(uint8 NUM)
{

	SEG_PORT = (SEG_PINS | (NUM & 0x0F));

 }
