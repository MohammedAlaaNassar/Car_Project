/*
 * DIO_cnfg.c
 *
 *  Created on: Sep 22, 2019
 *      Author: Mohammed
 */


#include "DIO_cnfg.h"




DIO_cnfg_t DIO_cnfg_arr[NUM_OF_PINS] =
{
		{PORT_A,PIN0,OUTPUT,HIGH,NA,INITIALIZED},
		{PORT_B,PIN0,OUTPUT,HIGH,NA,INITIALIZED},
        {PORT_C,PIN0,INPUT,NA,PULLUP,INITIALIZED}

};

