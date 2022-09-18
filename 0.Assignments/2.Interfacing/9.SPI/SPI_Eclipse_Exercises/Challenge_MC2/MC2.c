/*
 * MC2.c
 *
 *  Created on: Sep 18, 2015
 *  Author: Mohamed Tarek
 */

#include "spi.h"
#include "lcd.h"

int main(void)
{
	uint8 key;
	LCD_init();
	SPI_initSlave(); //initialize salve MC
    while(1)
    {
		key = SPI_recieveByte();  //receive the pressed key from spi
		if((key>=0) && (key<=9))
		{
			LCD_intgerToString(key); //display the pressed key
		}
		else
		{
			LCD_displayCharacter(key);
		}
    }
}


