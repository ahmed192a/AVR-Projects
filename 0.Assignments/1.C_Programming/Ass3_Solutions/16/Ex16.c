/**
 * @file Ex16.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex16
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief Reverse Array Function
 * 
 * @param Array_size 		the size of the array
 * @param Array 			the array
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Reverse_Array(int Array_size, int* Array)
{
	int i = 0, temp;
	while(i <  (Array_size / 2))
	{
		temp = Array[i];
		Array[i] = Array[Array_size - 1 - i];
		Array[Array_size - 1 - i] = temp;
		i++;
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
	int i;
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	/* Print the array before call the reverse function */
	for(i=0;i<10;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");

	Reverse_Array(10,array);

	/* Print the array after call the reverse function */
	for(i=0;i<10;i++)
	{
		printf("%d ",array[i]);
	}
	return 0;
}