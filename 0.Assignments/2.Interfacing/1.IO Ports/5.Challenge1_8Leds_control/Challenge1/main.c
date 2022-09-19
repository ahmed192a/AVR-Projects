/**
 * @file main.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-19 @ 13:09:46
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
    uint8_t Leds = 1;
    Dio_Init();
    while (1) 
    {
        PORTC = Leds;
        _delay_ms(500);
        Leds = Leds << 1;
        Leds = Leds == 0? 1 : Leds;
    }
}


void Dio_Init(void)
{
    // PORTC all as output
    DDRC = 0xFF;
    // initialize PORTC with 0
    PORTC = 0x00;
}