/*
 * MC2.c
 *
 * Created: 4/10/2014 11:23:48 PM
 * Author: mohamed tarek
 */ 

#include "uart.h"
#include "lcd.h"

#define M2_READY 0x10

int main(void)
{
	uint8 Str[20];
	UART_init(); // initialize UART driver
	LCD_init(); // initialize LCD driver
	UART_sendByte(M2_READY); // MC2 is ready
	UART_receiveString(Str); // receive the string 
	LCD_displayString(Str); // display the string on LCD
    while(1)
    {
		
    }
}
