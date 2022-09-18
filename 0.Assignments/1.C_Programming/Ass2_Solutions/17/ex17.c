/**
 * @file ex17.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 17
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

/**
 * @brief maximum_XOR function to calculate the maximum XOR between two numbers
 * 
 * @param a 				the first number
 * @param b 				the second number
 * @return int 				the maximum XOR between the two numbers
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int maximum_XOR(int a,int b)
{
	int max_xor = 0;
	int temp = 0;
	int i,j;
	for(i=a;i<=b;i++)
	{
		for(j=i;j<=b;j++)
		{
			temp = i ^ j;
			if(temp > max_xor)
			{
				max_xor = temp;
			}
		}
	}
	return max_xor;
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
	printf("Maximum XOR : %d",maximum_XOR(10,15));
	return 0;
}