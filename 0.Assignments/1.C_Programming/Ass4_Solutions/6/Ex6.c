/**
 * @file Ex6.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex6
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define MAX_SIZE 10

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main () {

	int  arr[MAX_SIZE] = {10, 100, 200, -1, 1000, 500, 20, 60, -50, 26};
	int i, *ptr[MAX_SIZE];
	int MAX = 0;

	for ( i = 0; i < MAX_SIZE; i++)
	{
		// assign the address of each array element to a pointer element
		ptr[i] = &arr[i];
	}

	for ( i = 0; i < MAX_SIZE; i++)
	{
		// print all the array elements using array of pointers
		printf("Value of arr[%d] = %d\n", i, *ptr[i] );
	}

	MAX = *ptr[0]; // assume that the maximum number is the first array element

	for ( i = 1; i < MAX_SIZE; i++)
	{
		if(MAX < *ptr[i])
		{
			MAX = *ptr[i];
		}
	}

	printf("Maximum Number = %d\n", MAX );

	return 0;
}
