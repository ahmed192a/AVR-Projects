/*
 * main.c
 *
 *  Created on: Sep 17, 2022
 *      Author: Ahmed Mohamed
 */
#include <avr/io.h>

void DIO_init();


/**
 * @brief main function
 * @return int
 */
int main(){
	DIO_init();

	while(1){
        // if button is pressed
		switch(PINB & 0x3){
		case 0:
		    PORTC &= ~((1<<1) | (1<<0));
		    break;
		case 1:
			PORTC |=  (1<<0);
			PORTC &= ~(1<<1);
			break;
		case 2:
			PORTC |=  (1<<1);
			PORTC &= ~(1<<0);
			break;
		default:
			PORTC |= ((1<<1) | (1<<0));
			break;
		}


	}
	return 0;
}

/**
 * @brief DIO_init function
 */
void DIO_init(){
    DDRB  &= ~((1<<1) | (1<<0));    // PORTB Pin 0,1 Input
    PORTB &= ~((1<<1) | (1<<0));    // PORTB Pin 0,1 Pull down

    DDRC  |=  ((1<<1) | (1<<0));	// PORTC Pin 0,1 Output
    PORTC &= ~((1<<1) | (1<<0));    // PORTC Pin 0,1 Low initially
}
