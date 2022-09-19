/**
 * @file main.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-19 @ 11:09:55
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU   (1000000UL)
#define TRUE    (1U)
#define FALSE   (0U)
typedef uint8_t bool_t;

void Dio_Init(void);

/**
 * @brief Main function
 * 
 * @return int 
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main(){
    bool_t flag = FALSE;
    Dio_Init();     // Initialize the DIO
    while(1){
        if (! (PINB & (1<<PINB0))){
            if(!flag){
                _delay_ms(30);
                if (! (PINB & (1<<PINB0))){
                    PORTC ^= (1<<PORTC0);
                    flag   = TRUE;
                }
            }
        }
        else{
            flag = FALSE;
        }
    }
}


/**
 * @brief Dio_Init
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Dio_Init(void)
{
    DDRB  &= ~(1<<DDB0);       // Define portB pin0 as input
    PORTB |=  (1<<PB0);        // Enable internal pull-up resistor

    DDRC  |=  (1<<DDC0);       // Define PORTC pin0 as output
}