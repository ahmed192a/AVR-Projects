/*
 * temp_sensor.c
 *
 *  Created on: Sep 5, 2015
 *  Author: Mohamed Tarek
 */

#include "adc.h"
#include "lcd.h"

int main(void)
{
	uint32 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "Temp =    " only once at LCD */
	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,10);
	/* display character 'C' on the screen "Temp =   C" */
	LCD_displayCharacter('C');
    while(1)
    {
		LCD_goToRowColumn(0,7); /* display the number every time at this position */
		temp = ADC_readChannel(2); /* read channel two where the temp sensor is connect */
		temp = (temp*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
		LCD_intgerToString(temp); /* display the temp on LCD screen */
    }
}
