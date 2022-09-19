/**
 * @file main.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-19 @ 13:09:82
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <avr/io.h>
#include <util/delay.h>
void Dio_Init(void);

/**
 * @brief Main function
 * 
 * @return int 
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main(void)
{
    uint8_t counter = 0;
    Dio_Init();
    while (1)
    {
        if( PIND & (1<<PD4) )
        {
            counter++;  // Increment counter
            counter = counter == 10? 0 : counter;   // Reset counter if it reaches 10 (overflow)
            PORTC = counter;            // Display counter value on PORTC
            while( PIND & (1<<PD4) );   // Wait until the button is released
        }
    }
}


/**
 * @brief DIO initialization function
 * 
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Dio_Init(){
    // Port D pin 4 as input
    DDRD &= ~(1<<PD4);

    // port C first 4 pins as output
    DDRC |= 0x0F;

}