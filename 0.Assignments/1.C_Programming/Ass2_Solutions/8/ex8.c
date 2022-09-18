/**
 * @file ex8.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 8
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief print_primes function to print all prime numbers from num1 to num2
 * 
 * @param num1 
 * @param num2 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void print_primes(int num1,int num2)
{
	int i,j;
	int not_prime = 0; // flag to indicate that the number is prime or not
	for(i=num1;i<=num2;i++)
	{
		for(j=2;j<=(i/2);j++)
		{
			if(i%j == 0) // in case the reminder equals zero
			{
				not_prime = 1; // this number is not a prime number
				break;
			}
		}
		if(not_prime == 0)
		{
			printf("%d\t",i); // print in case the number is a prime number
		}
		else
		{
			not_prime = 0;
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
	int num1,num2;
	printf("Please enter the two numbers : ");
	scanf("%d %d",&num1,&num2);
	printf("\n");
	print_primes(num1,num2);
	return 0;
}


