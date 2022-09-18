/**
 * @file ex6.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 6
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

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
    int integer1; /* first number to be input by user */
    int integer2; /* second number to be input by user */
    int result; /* variable in which result will be stored */
    printf( "Enter first integer:\n" ); /* prompt */
    scanf( "%d", &integer1 ); /* read an integer */
    printf( "Enter second integer:\n" ); /* prompt */
    scanf( "%d", &integer2 ); /* read an integer */
    if(integer1 > integer2)
	{
		printf("integer1 is greater than integer2\n");
	}
	else if(integer1 < integer2)
	{
		printf("integer2 is greater than integer1\n");
	}
	else
	{
		printf("both numbers are equal\n");
	}
    return 0;
}
