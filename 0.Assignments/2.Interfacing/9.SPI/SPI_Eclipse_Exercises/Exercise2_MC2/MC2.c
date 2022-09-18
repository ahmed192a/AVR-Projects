/*
 * MC2.c
 *
 *  Created on: Sep 18, 2015
 *      Author: mtarek
 */

#include "spi.h"
#include "lcd.h"

int main(void)
{
	uint8 str[20];
	LCD_init();
	/* Initialize Salve SPI */
	SPI_initSlave();
	/* Receive String from MC1 */
	SPI_ReceiveString(str);
	/* Display the received string on the LCD display */
	LCD_displayString(str);
    while(1)
    {

    }
}

