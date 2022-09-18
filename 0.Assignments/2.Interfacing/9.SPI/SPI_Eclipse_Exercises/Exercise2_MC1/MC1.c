/*
 * MC1.c
 *
 *  Created on: Sep 18, 2015
 *  Author: Mohamed Tarek
 */

#include "spi.h"

int main(void)
{
	SPI_initMaster(); /* Master Initialization */
	_delay_ms(50); /* delay until MC2 finish its initialization task */
	SPI_SendString("I am Micro1#");
    while(1)
    {

    }
}


