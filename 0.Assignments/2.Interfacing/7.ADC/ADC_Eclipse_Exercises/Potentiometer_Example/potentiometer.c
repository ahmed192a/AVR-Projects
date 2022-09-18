/*
 * potentiometer.c
 *
 *  Created on: Jun 18, 2017
 *  Author: Mohamed Tarek
 */

#include "adc.h"
#include "lcd.h"

int main(void)
{
	uint16 res_value;
	LCD_init(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("ADC Value = ");
    while(1)
    {
		LCD_goToRowColumn(0,12); /* display the number every time at this position */
		res_value = ADC_readChannel(0); /* read channel zero where the potentiometer is connect */
		LCD_intgerToString(res_value); /* display the ADC value on LCD screen */
    }
}


