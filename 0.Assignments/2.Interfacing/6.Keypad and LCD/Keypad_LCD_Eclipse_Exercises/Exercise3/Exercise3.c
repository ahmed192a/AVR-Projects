/*
 * Exercise3.c
 *
 * Created: 4/14/2015 3:17:07 PM
 *  Author: Mohamed Tarek
 */ 

#include "lcd.h"

int main(void)
{
	LCD_init(); /* initialize LCD */
	LCD_displayString("Welcome To LCD");
	LCD_displayStringRowColumn(1,0,"4 Bits Data Mode");
	
    while(1)
    {
		/* Note: we write the code before while(1) because we want to execute it only once */
    }
	
}
