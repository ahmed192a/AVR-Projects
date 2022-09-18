/**
 * @file ex15.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex15
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief CountOnes function to count the number of ones in a binary number
 * 
 * @param Number 				the number to be checked
 * @return int 					the number of ones in the binary number
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int CountOnes(unsigned int Number)
{
	unsigned int mask=0x1;
	int ones_count=0;
	while (Number)
	{
		if(Number & mask)
		{
			ones_count++;
		}
		Number = Number >> 1;
	}
	
	return ones_count;
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
	unsigned int num1 = 0x00000FFF;
	int count; 
	count = CountOnes(num1);
	printf("%d",count);
}