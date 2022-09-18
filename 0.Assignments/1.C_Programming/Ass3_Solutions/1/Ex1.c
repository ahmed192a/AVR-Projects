/**
 * @file Ex1.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex1
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define ARR_SIZE 	(5U) 	/* Array size */

/**
 * @brief summation function to calculate the summation of an array
 * 
 * @param numbers_size 		the size of the array
 * @param numbers 			the array
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int summation(int numbers_size, int* numbers)
{
	int sum = 0,i;
	for(i=0;i<numbers_size;i++)
	{
		sum += numbers[i];
	}
	return sum;
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
	int arr[ARR_SIZE];
	int i;
	int res = 0;
	printf("Please enter the arrat elements : \n");

	/* loop for all the array elements to fill the array elements */
	for(i=0;i<ARR_SIZE;i++)
	{
		/* take array element by element */
		scanf("%d",&arr[i]);
	}

	res = summation(ARR_SIZE,arr);

	printf("The Sum of the array elements : %d",res);

	return 0;
}