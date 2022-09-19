/**
 * @file main.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-19 @ 13:09:53
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
        if(PINA & (1<<PINA0))
        {
            _delay_ms(30);
            counter = counter == 9? counter: counter + 1;
            PORTD = counter;
            while (PINA & (1<<PINA0));
        }
        if(PINA & (1<<PINA1))
        {
            _delay_ms(30);
            counter = counter == 0? counter: counter - 1;
            PORTD = counter;
            while (PINA & (1<<PINA1));
        }
    }
}


/**
 * @brief Dio_Init function
 * 
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Dio_Init(void)
{
    // PortA pin 0,1 as input
    DDRA &= ~((1 << DDA0) | (1 << DDA1));
    // PortD 4 pins as output
    DDRD |= (1 << DDD0) | (1 << DDD1) | (1 << DDD2) | (1 << DDD3);

}