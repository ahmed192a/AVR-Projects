/**
 * @file ex3.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 3
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief check_positive_negative function
 * 
 * @param in 		input number
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void check_positive_negative(int in)
{
	if( in > 0 )
	{
		printf("\nThe input number is Positive");
	}
	else if (in < 0)
	{
		printf("\nThe input number is Negative");
	}
	else
	{
		printf("\nThe input number is Zero");
	}
}

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main(void) {
	int num;
	printf("Please enter a number : ");
	scanf("%d",&num);
	check_positive_negative(num);
	return 0;
}