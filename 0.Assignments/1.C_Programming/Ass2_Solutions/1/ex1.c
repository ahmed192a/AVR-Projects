/**
 * @file ex1.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 1
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief cube function
 * 
 * @param x 	input number
 * @return int  x^3 the cube of x
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int cube(int x)
{
	return x * x * x;
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
	int result;
	printf("Please enter any number : ");
	scanf("%d",&num);
	result = cube(num);
	printf("\nThe cube value of %d is %d",num,result);
	return 0;
}