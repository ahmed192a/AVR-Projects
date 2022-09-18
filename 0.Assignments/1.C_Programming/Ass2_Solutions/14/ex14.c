/**
 * @file ex14.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex14
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

long fibonacci( long n ); /* function prototype */

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
	long result;
	long number;

	/* obtain integer from user */
	printf( "Enter an integer: " );
	scanf( "%ld", &number );

	/* calculate fibonacci value for number input by user */
	result = fibonacci( number );

	printf( "Fibonacci( %ld ) = %ld\n", number, result );
	return 0;
}

/**
 * @brief fibonacci function to calculate the fibonacci of a number recursively
 * 
 * @param n 				the number to be calculated
 * @return long 			the fibonacci of the number
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
long fibonacci( long n )
{
	if ( n == 0 || n == 1 )
	{
		/* base case */
		return n;
	}
	else
	{ /* recursive step */
		return fibonacci( n - 1 ) + fibonacci( n - 2 );
	}
}