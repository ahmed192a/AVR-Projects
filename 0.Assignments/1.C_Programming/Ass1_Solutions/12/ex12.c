/**
 * @file ex12.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 12
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
    int input;
    long long fact = 1;
    int i;
    printf("Please enter the required number : ");
    scanf("%d",&input);
	
	/* Loop to calcuate the factorial for example (5! = 5 * 4 * 3 * 2 * 1) */
    for(i=1;i<=input;i++)
    {
        fact = fact * i;
    }
    printf("\nfactorial of %d is: %ld",input,fact);
    return 0;
}
