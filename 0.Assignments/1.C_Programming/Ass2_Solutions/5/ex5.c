/**
 * @file ex5.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 5
 * @version 0.1
 * @date 2022-09-18 @ 14:09:27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief checkEvenOrOdd function
 * 
 * @param Number 		the number to be checked
 * @return int 			0 if the number is even, 1 if the number is odd
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int CheckEvenOrOdd(unsigned int Number)
{
	if((Number % 2) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
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
	int number;
	printf("Please enter the number : ");
	scanf("%d",&number);
	if(CheckEvenOrOdd(number) == 0)
	{
		printf("%d is Even Number\n",number);
	}
	else
	{
		printf("%d is Odd Number\n",number);
	}
	return 0;
}
