/**
 * @file ex13.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex13
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief addNumbers function to add two numbers
 * 
 * @param a 				the first number
 * @param b 				the second number
 * @return int 				the sum of the two numbers
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int addNumbers(float a,float b)
{
	/* return the integer value for the addition between two float numbers */
	return (int)(a+b);
}

/**
 * @brief Main Function
 * 
 * @return int 		
 * @version 0.1		
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main( void )
{
	float f1 = 3.5, f2 = 2.3;
	int res;
	res = addNumbers(f1,f2);
	printf("res = %d",res);
	return 0;
}