/**
 * @file ex15.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 15
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
    int num, power;

    long long result = 1;

    printf("Enter a num number: ");
    scanf("%d", &num);

    printf("\nEnter an power: ");
    scanf("%d", &power);

    /* Multiply the number by its value for number of times equals to the input power */
    while (power != 0)
    {
        result *= num;
        --power;
    }

    printf("\nAnswer = %lld", result);

    return 0;
}
