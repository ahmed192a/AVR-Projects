/**
 * @file main.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17 @ 18:09:37
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <avr/io.h>

void DIO_init();

/**
 * @brief main function
 * 
 * @return int 
 * @version 0.1
 * 
 * @date 2022-09-17 @ 18:09:51
 * @author Ahmed Mohamed
 */
int main(){
	DIO_init();

	while(1){
        // if button is pressed
        if(PINA & (1<<3)){
            PORTC |= (1<<5);    // PORTC Pin 5 High
        }
        else{
            PORTC &= ~(1<<5);   // PORTC Pin 5 Low
        }

	}
	return 0;
}

/**
 * @brief DIO_init function
 */
void DIO_init(){
    DDRA &= ~(1<<3);    // PORTA Pin 3 Input
    PORTA &= ~(1<<3);   // PORTA Pin 3 Pull down

    DDRC |= (1<<5);	    // PORTC Pin 5 Output
    PORTC &= ~(1<<5);   // PORTC Pin 5 Low initially
}
