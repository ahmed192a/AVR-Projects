/**
 * @file main.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17 @ 20:09:02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <avr/io.h>
#include <util/delay.h>

void DIO_init();

/**
 * @brief main function
 * 
 * @return int 
 * @version 0.1
 * 
 * @date 2022-09-17 @ 20:09:90
 * @author Ahmed Mohamed 
 */
int main(){
	DIO_init();

	while(1){
		_delay_ms(1000);
		PORTD ^= (1<<6);
	}
	return 0;
}


/**
 * @brief Dio init function
 * 
 * @version 0.1
 * 
 * @date 2022-09-17 @ 20:09:37
 * @author Ahmed Mohamed 
 */
void DIO_init(){
    DDRD |= (1<<6);	    // PORTD Pin 6 Output
    PORTD &= ~(1<<6);   // PORTD Pin 6 Low initially
}

