/**
 * @file dio_Lcfg.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Dio Linker Configuration Source File 
 * @version 0.1
 * @date 2022-09-19 @ 14:09:98
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "dio.h"



DioConfig dioconf [DIO_CONFIGURED_PINS] ={
    {Dio_PortA,Dio_Pin0,Dio_PinDirectionOutput,Dio_PinLevelLow,Dio_InternalPullUpDisable},
    {Dio_PortA,Dio_Pin1,Dio_PinDirectionOutput,Dio_PinLevelLow,Dio_InternalPullUpDisable},
    {Dio_PortA,Dio_Pin2,Dio_PinDirectionOutput,Dio_PinLevelLow,Dio_InternalPullUpDisable},
    {Dio_PortA,Dio_Pin3,Dio_PinDirectionOutput,Dio_PinLevelLow,Dio_InternalPullUpDisable}
};

