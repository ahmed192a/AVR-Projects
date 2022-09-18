/*
 * Challenge.c
 *
 * Created: 4/2/2014 7:42:04 PM
 *  Author: Mohamed T6arek
 */ 

#include "lcd.h"
#include "keypad.h"

int main(void)
{
	unsigned char key;
	LCD_init();
	LCD_displayStringRowColumn(0,0,"Challenge");
	LCD_displayStringRowColumn(1,0,"Keypad 4x4");
	LCD_displayStringRowColumn(2,0,"LCD");
	LCD_goToRowColumn(3,0);
    while(1)
    {
		/* if any switch pressed for more than 500 ms it counts more than one press */  
		key = KeyPad_getPressedKey(); /* get the pressed key number */
		if((key <= 9) && (key >= 0))
		{
			LCD_intgerToString(key); /* display the pressed keypad switch */
		}
		else
		{
			LCD_displayCharacter(key); /* display the pressed keypad switch */ 
		}
		_delay_ms(500); /* Press time */
    }
}
