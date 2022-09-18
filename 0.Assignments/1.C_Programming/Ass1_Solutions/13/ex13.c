/**
 * @file ex13.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 13
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define TRUE    (1U)    /* Define TRUE as 1 */
#define FALSE   (0U)    /* Define FALSE as 0 */

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
    int i;
    int prime_num = TRUE;
    printf("Please enter the required number : ");
    scanf("%d",&input);

    for(i=2;i<=(input/2);i++)
    {
		/* Check if the input number can be divided by i */
        if(input%i == 0)
        {
            prime_num = FALSE;
            printf("\n%d is not prime number\n",input);
            /* terminate the loop as no need to continue the loop iterations */
			break;
        }
    }
	
    /* in case the prime_num still equals TRUE which means that the number can not be divided
       by another number */
    if(prime_num == TRUE)
    {
        printf("\n%d is a prime number\n",input);
    }
    return 0;
}
