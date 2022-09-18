/**
 * @file ex11.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex11
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief Is power of 2 function to check if a number is a power of 2
 * 
 * @param number 				the number to be checked
 * @return int 					1 if the number is a power of 2, 0 otherwise
 * @version 0.1
 * 
 * @date 2022-09-18 @ 15:09:97
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int isPowerOf2(int number)
{
	int i;

	if(number == 0 || number == 2)
	{
		return 1;
	}
	else if(number == 1)
	{
		return 0;
	}
	else
	{
		while(1)
		{
			/* Check if the number can be divided by 2 */
			if((number % 2) == 0)
			{
				/*
				 * Divide the number by 2 every time in case the number is power three
				 * after multiple division it will be equals to 3 then return 1 as the
				 * number is power 2
				 */
				number = number / 2;
				if(number == 2)
				{
					return 1;
				}
			}
			else
			{
				return 0;
			}
		}
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
int main(void)
{
	int num,res;
	scanf("%d",&num);
	res = isPowerOf2(num);
	if(res == 1)
	{
		printf("%d is power of 2\n",num);
	}
	else
	{
		printf("%d is not power of 2\n",num);
	}
	return 0;
}
