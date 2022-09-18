/**
 * @file Ex12.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex12
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define ARRAY_SIZE 15

/**
 * @brief OddRepetitionNumberInArray
 * 
 * @param arr 
 * @param arr_size 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int OddRepetitionNumberInArray(int *arr,int arr_size)
{
	int i,j;
	int count = 0;
	int index = 0;
	for(i=0;i<arr_size;i++)
	{
		for(j = 0; j < arr_size;j++)
		{
			/* Count the number of times that this element value exist in the array */
			if(arr[i] == arr[j])
			{
				index = i;
				count++;
			}
		}
		/* check if the count is odd number then we found number */
		if(count%2 != 0)
		{
			break;
		}
		/* reset the count value before check for the next array element */
		count = 0;
	}
	return arr[index];
}

/**
 * @brief 		Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main(void)
{
	int arr[ARRAY_SIZE] = {1,2,3,1,2,3,1,1,1,1,3,3,3};

	int num = OddRepetitionNumberInArray(arr,ARRAY_SIZE);

	printf("number is : %d",num); /* It should be 3 */

	return 0;
}