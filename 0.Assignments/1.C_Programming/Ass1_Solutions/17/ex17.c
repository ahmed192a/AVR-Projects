/**
 * @file ex17.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 17
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main()
{
    int num;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while(num != 0)
    {
		/* Divide number by 10 to get the next digit to right before the next loop iteration */
    	num /= 10;
		
		/* Increment the number of digits */
        ++count;
    }
	
    printf("Number of digits: %d", count);
    return 0;
}
