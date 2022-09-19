/**
 * @file dio.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief  Dio APIs implementations
 * @version 0.1
 * @date 2022-09-19 @ 14:09:35
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "dio.h"
#include "std_types.h"
#include "CommonMacros.h"


/**
 * @brief Dio Initialization Function
 * 
 * @param ConfigPtr     Pointer to Dio Configuration Structure array
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Dio_Init(const DioConfig * ConfigPtr){
    uint8_t _Pin = 0;
    // check if the pointer is not null
    if (ConfigPtr == NULL_PTR)
    {
        return;
    }
    for( _Pin = 0; _Pin < DIO_CONFIGURED_PINS; _Pin++){
       switch (ConfigPtr[_Pin].Port)
        {
        case Dio_PortA:
            if (ConfigPtr[_Pin].PinDirection == Dio_PinDirectionOutput)
            {
                SET_BIT(DDRA,ConfigPtr[_Pin].Pin);
                if (ConfigPtr[_Pin].PinLevel == Dio_PinLevelHigh)
                {
                    SET_BIT(PORTA,ConfigPtr[_Pin].Pin);
                }
                else
                {
                    CLEAR_BIT(PORTA,ConfigPtr[_Pin].Pin);
                }
            }
            else
            {
                CLEAR_BIT(DDRA,ConfigPtr[_Pin].Pin);
                if (ConfigPtr[_Pin].InternalPullUp == Dio_InternalPullUpEnable)
                {
                    SET_BIT(PORTA,ConfigPtr[_Pin].Pin);
                }
                else
                {
                    CLEAR_BIT(PORTA,ConfigPtr[_Pin].Pin);
                }
            }
            break;
        case Dio_PortB:
            if (ConfigPtr[_Pin].PinDirection == Dio_PinDirectionOutput)
            {
                SET_BIT(DDRB,ConfigPtr[_Pin].Pin);
                if (ConfigPtr[_Pin].PinLevel == Dio_PinLevelHigh)
                {
                    SET_BIT(PORTB,ConfigPtr[_Pin].Pin);
                }
                else
                {
                    CLEAR_BIT(PORTB,ConfigPtr[_Pin].Pin);
                }
            }
            else
            {
                CLEAR_BIT(DDRB,ConfigPtr[_Pin].Pin);
                if (ConfigPtr[_Pin].InternalPullUp == Dio_InternalPullUpEnable)
                {
                    SET_BIT(PORTB,ConfigPtr[_Pin].Pin);
                }
                else
                {
                    CLEAR_BIT(PORTB,ConfigPtr[_Pin].Pin);
                }
            }
            break;
        case Dio_PortC:
            if (ConfigPtr[_Pin].PinDirection == Dio_PinDirectionOutput)
            {
                SET_BIT(DDRC,ConfigPtr[_Pin].Pin);
                if (ConfigPtr[_Pin].PinLevel == Dio_PinLevelHigh)
                {
                    SET_BIT(PORTC,ConfigPtr[_Pin].Pin);
                }
                else
                {
                    CLEAR_BIT(PORTC,ConfigPtr[_Pin].Pin);
                }
            }
            else
            {
                CLEAR_BIT(DDRC,ConfigPtr[_Pin].Pin);
                if (ConfigPtr[_Pin].InternalPullUp == Dio_InternalPullUpEnable)
                {
                    SET_BIT(PORTC,ConfigPtr[_Pin].Pin);
                }
                else
                {
                    CLEAR_BIT(PORTC,ConfigPtr[_Pin].Pin);
                }
            }
            break;
        case Dio_PortD:
            if (ConfigPtr[_Pin].PinDirection == Dio_PinDirectionOutput)
            {
                SET_BIT(DDRD,ConfigPtr[_Pin].Pin);
                if (ConfigPtr[_Pin].PinLevel == Dio_PinLevelHigh)
                {
                    SET_BIT(PORTD,ConfigPtr[_Pin].Pin);
                }
                else
                {
                    CLEAR_BIT(PORTD,ConfigPtr[_Pin].Pin);
                }
            }
            else
            {
                CLEAR_BIT(DDRD,ConfigPtr[_Pin].Pin);
                if (ConfigPtr[_Pin].InternalPullUp == Dio_InternalPullUpEnable)
                {
                    SET_BIT(PORTD,ConfigPtr[_Pin].Pin);
                }
                else
                {
                    CLEAR_BIT(PORTD,ConfigPtr[_Pin].Pin);
                }
            }
            break;
        default:
            break;
        }
    } 
}

/**
 * @brief Dio Write channel Function
 * 
 * @param Port      Dio Port
 * @param Pin       Dio Pin
 * @param PinLevel  Dio Pin Level
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Dio_WriteChannel(Dio_PortType Port, Dio_PinType Pin, Dio_PinLevelType PinLevel){
    switch (Port)
    {
    case Dio_PortA:
        if (PinLevel == Dio_PinLevelHigh)
        {
            SET_BIT(PORTA,Pin);
        }
        else
        {
            CLEAR_BIT(PORTA,Pin);
        }
        break;
    case Dio_PortB:
        if (PinLevel == Dio_PinLevelHigh)
        {
            SET_BIT(PORTB,Pin);
        }
        else
        {
            CLEAR_BIT(PORTB,Pin);
        }
        break;
    case Dio_PortC:
        if (PinLevel == Dio_PinLevelHigh)
        {
            SET_BIT(PORTC,Pin);
        }
        else
        {
            CLEAR_BIT(PORTC,Pin);
        }
        break;
    case Dio_PortD:
        if (PinLevel == Dio_PinLevelHigh)
        {
            SET_BIT(PORTD,Pin);
        }
        else
        {
            CLEAR_BIT(PORTD,Pin);
        }
        break;
    default:
        break;
    }
}
/**
 * @brief Dio Read channel Function
 * 
 * @param Port      Dio Port
 * @param Pin       Dio Pin
 * @return Dio_PinLevelType     Dio Pin Level
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
Dio_PinLevelType Dio_ReadChannel(Dio_PortType Port, Dio_PinType Pin){
    Dio_PinLevelType _PinLevel = Dio_PinLevelLow;
    switch (Port)
    {
    case Dio_PortA:
        _PinLevel = GET_BIT(PINA,Pin);
        break;
    case Dio_PortB:
        _PinLevel = GET_BIT(PINB,Pin);
        break;
    case Dio_PortC:
        _PinLevel = GET_BIT(PINC,Pin);
        break;
    case Dio_PortD:
        _PinLevel = GET_BIT(PIND,Pin);
        break;
    default:
        break;
    }
    return _PinLevel;
}

/**
 * @brief Dio Flip channel Function
 * 
 * @param Port      Dio Port
 * @param Pin       Dio Pin
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Dio_FlipChannel(Dio_PortType Port, Dio_PinType Pin){
    switch (Port)
    {
    case Dio_PortA:
        TOGGLE_BIT(PORTA,Pin);
        break;
    case Dio_PortB:
        TOGGLE_BIT(PORTB,Pin);
        break;
    case Dio_PortC:
        TOGGLE_BIT(PORTC,Pin);
        break;
    case Dio_PortD:
        TOGGLE_BIT(PORTD,Pin);
        break;
    default:
        break;
    }
}

/**
 * @brief Dio Wrtie Port Function
 * 
 * @param Port          Dio Port
 * @param PortLevel     Dio Port Level
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Dio_WritePort(Dio_PortType Port, uint8_t PortLevel){
    switch (Port)
    {
    case Dio_PortA:
        PORTA = PortLevel;
        break;
    case Dio_PortB:
        PORTB = PortLevel;
        break;
    case Dio_PortC:
        PORTC = PortLevel;
        break;
    case Dio_PortD:
        PORTD = PortLevel;
        break;
    default:
        break;
    }
}

/**
 * @brief Dio Read Port Function
 * 
 * @param Port      Dio Port
 * @return uint8_t  Dio Port Level
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
uint8_t Dio_ReadPort(Dio_PortType Port){
    uint8_t _PortLevel = 0;
    switch (Port)
    {
    case Dio_PortA:
        _PortLevel = PINA;
        break;
    case Dio_PortB:
        _PortLevel = PINB;
        break;
    case Dio_PortC:
        _PortLevel = PINC;
        break;
    case Dio_PortD:
        _PortLevel = PIND;
        break;
    default:
        break;
    }
    return _PortLevel;
}

/**
 * @brief       Dio Flip Port Group Function
 * 
 * @param Port  Dio Port
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Dio_FlipPort(Dio_PortType Port){
    switch (Port)
    {
    case Dio_PortA:
        PORTA = ~PORTA;
        break;
    case Dio_PortB:
        PORTB = ~PORTB;
        break;
    case Dio_PortC:
        PORTC = ~PORTC;
        break;
    case Dio_PortD:
        PORTD = ~PORTD;
        break;
    default:
        break;
    }
}
