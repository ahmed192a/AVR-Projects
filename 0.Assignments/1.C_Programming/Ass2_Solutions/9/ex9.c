/**
 * @file ex9.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 9
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief swap two numbers
 * 
 * @param ptr1 		pointer to the first number
 * @param ptr2 			pointer to the second number
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void swap(int *ptr1, int *ptr2)
{
	int temp;
	temp  = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

/********************************************************** 
 ***** Another Method without using the Temp variable *****
 
void swap(int *ptr1, int *ptr2)
{
	*ptr1 = *ptr1 + *ptr2;
	*ptr2 = *ptr1 - *ptr2;
	*ptr1 = *ptr1 - *ptr2;
}

************************************************************/

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @date 2022-09-18 @ 14:09:62
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main(void)
{
	int a = 3, b = 2;
	printf ("Number before swapping : a=%d b=%d\n",a,b);
	swap(&a,&b);
	printf ("Number after swapping : a=%d b=%d\n",a,b);
	return 0;
}


