/*
 * WatchDog_Exercise.c
 *
 *  Created on: Jun 20, 2017
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>
#include <util/delay.h>

//	function to enable Watchdog timer.
void WDT_ON(void)
{
	// Watchdog timer enables with timeout period 2.1 second.
	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
}

// 	function to disable Watchdog timer.
void WDT_OFF(void)
{
	// Set the WDTOE & WDE bits in the same operation
	WDTCR = (1<<WDTOE)|(1<<WDE);
	// Wait 4 cycles before clear the WDE bit
	_delay_us(4);
	WDTCR = 0x00;
}

int main(void)
{
	// Enable the Watchdog timer
	WDT_ON();

	// Configure PD6 as output pin
	DDRD |= (1<<PD6);

	// Toggle the led every reset
	PORTD |= (1<<PD6);
	_delay_ms(1000);
	PORTD &= ~(1<<PD6);

	// Wait until the system reset itself
    while(1);
}
