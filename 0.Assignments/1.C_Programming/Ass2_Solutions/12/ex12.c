/**
 * @file ex12.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex12
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief CalcualteHeatingTime function
 * 
 * @param WaterTemperature         the water temperature
 * @return unsigned int            the heating time
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
unsigned int CalcualteHeatingTime(unsigned int WaterTemperature)
{
    int result;
    if(WaterTemperature > 100)
         result = 0;
    else if(WaterTemperature > 90)
         result = 1;
    else if((WaterTemperature <= 90) && (WaterTemperature > 60))
         result = 3;
    else if((WaterTemperature <= 60) && (WaterTemperature > 30))
         result = 5;
    else if((WaterTemperature <= 30) && (WaterTemperature >= 0))
         result = 7;
    return result;
}

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main(void)
{
	printf("%d",CalcualteHeatingTime(10));
	printf("\n%d",CalcualteHeatingTime(35));
	return 0;
}