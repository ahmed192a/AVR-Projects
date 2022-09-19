/**
 * @file main.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Main Source File to test Dio Driver
 * @version 0.1
 * @date 2022-09-19 @ 15:09:84
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "dio.h"
#include <avr/delay.h>

extern DioConfig dioconf [DIO_CONFIGURED_PINS];

int main(void)
{
    uint8_t data = 1;
    Dio_Init(dioconf);
    while (1) 
    {

        _delay_ms(500);
        data = data & 0x08? 1 : data << 1;
        Dio_WritePort(Dio_PortA,data);
    }
}