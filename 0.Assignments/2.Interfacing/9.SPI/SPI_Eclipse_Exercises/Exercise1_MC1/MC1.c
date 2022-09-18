/*
 * MC1.c
 *
 * Created: 4/11/2014 8:20:28 PM
 * Author: mohamed tarek
 */ 

#include "spi.h"

#define SWITCH_PRESSED 1
#define SWITCH_NOT_PRESSED 0

int main(void)
{
	SPI_initMaster();
	CLEAR_BIT(DDRA,PA0); //configure PA0 as input pin
    while(1)
    {
		if(BIT_IS_SET(PINA,PA0)) //if switch is pressed
		{
			SPI_sendByte(SWITCH_PRESSED);
		}
		else
		{
			SPI_sendByte(SWITCH_NOT_PRESSED);
		}						
    }
}
