/**
 * @file dio.h
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Dio Driver for Atmega16 Microcontroller with internal frequency of 1MHz
 * @version 0.1
 * @date 2022-09-19 @ 13:09:10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DIO_H_
#define DIO_H_
#include <avr/io.h>
#include "dio_cfg.h"


typedef enum 
{
    Dio_PortA,
    Dio_PortB,
    Dio_PortC,
    Dio_PortD
} Dio_PortType;

typedef enum 
{
    Dio_Pin0,
    Dio_Pin1,
    Dio_Pin2,
    Dio_Pin3,
    Dio_Pin4,
    Dio_Pin5,
    Dio_Pin6,
    Dio_Pin7
}Dio_PinType;

typedef enum 
{
    Dio_PinLevelLow,
    Dio_PinLevelHigh
}Dio_PinLevelType;

typedef enum 
{
    Dio_InternalPullUpDisable,
    Dio_InternalPullUpEnable
}Dio_InternalPullUpType; 
typedef enum 
{
    Dio_PinDirectionInput,
    Dio_PinDirectionOutput
}Dio_PinDirectionType;


typedef struct 
{
    Dio_PortType Port;
    Dio_PinType Pin;
    Dio_PinDirectionType PinDirection;
    Dio_PinLevelType PinLevel;
    Dio_InternalPullUpType InternalPullUp;
}DioConfig;

void Dio_Init(const DioConfig * ConfigPtr);
void Dio_WriteChannel(Dio_PortType Port, Dio_PinType Pin, Dio_PinLevelType PinLevel);
Dio_PinLevelType Dio_ReadChannel(Dio_PortType Port, Dio_PinType Pin);
void Dio_FlipChannel(Dio_PortType Port, Dio_PinType Pin);
void Dio_WritePort(Dio_PortType Port, uint8_t PortLevel);
uint8_t Dio_ReadPort(Dio_PortType Port);
void Dio_FlipPort(Dio_PortType Port);



#endif /* DIO_H_ */