/**
 * @file ex3.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 3
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
/**
 * @brief Main function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main()
{
    float temp_cel; /* temperature in celsius */
    float temp_fah; /* temperature in fahrenheit */
    printf("Please enter the temperature value in Celsius : ");
    scanf("%f",&temp_cel);
	
	/* Calculate the temp in Fahrenheit */
    temp_fah = ( ( temp_cel * 9 ) / 5 ) + 32;
	
    printf("\nThe temperature in Fahrenheit is : %f",temp_fah);
    return 0;
}
