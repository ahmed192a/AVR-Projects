/*
 * MC2.c
 *
 * Created: 4/11/2014 8:32:25 PM
 *  Author: mohamed tarek
 */ 

#include "spi.h"

#define SWITCH_PRESSED 1
#define SWITCH_NOT_PRESSED 0

int main(void)
{
	uint8 data_received;
	SPI_initSlave();
	SET_BIT(DDRC,PC3); //configure PC3 as output pin
    while(1)
    {
		data_received = SPI_recieveByte(); //receive data from the master Micro-controller
		if(data_received == SWITCH_PRESSED)
		{
			SET_BIT(PORTC,PC3); //Led on
		}
		else if(data_received == SWITCH_NOT_PRESSED)
		{
			CLEAR_BIT(PORTC,PC3); //Led off
		}						
    }
}
