/**
 * @file Ex9_Sol2.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex9
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief fibanacci function
 * 
 * @param n 					the number to be checked
 * @return long 			the fibonacci of the number
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
long fibanacci(long n)
{
	if(n==0 || n==1)
	{
		/* the base value */
		return n;
	}
	else
	{ /* each element equals to the sum of the previous two elements */
		return fibanacci(n-1) + fibanacci(n-2);
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
	long num_index,num;
	printf("Please enter the element index : ");
	scanf("%ld",&num_index);
	num = fibanacci(num_index);
	printf("\nThe %ldth term is:%ld",num_index,num);
	return 0;
}


