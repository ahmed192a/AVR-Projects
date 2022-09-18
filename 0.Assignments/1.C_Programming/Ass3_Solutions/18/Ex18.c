/**
 * @file Ex18.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex18
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define ARR_SIZE 15

/**
 * @brief FindLongestConsecutive
 * 
 * @param Array_size 		the size of the array
 * @param Array 			the array
 * @param Number 			the number to be searched for
 * @return int 				the length of the longest consecutive sequence
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int FindLongestConsecutive(int Array_size,int * Array,int Number)
{
	int i;
	int occur_count = 0;
	int longest_count = 0;
	for(i=0;i<Array_size;i++)
	{
		if(Number == Array[i])
		{
			/* Increment the current consecutive count (occur_count) each time the Number is found */
			occur_count++;
			
			/* Compare the current consecutive count (occur_count) with the logest consecutive count (longest_count) */
			if(occur_count > longest_count)
			{
				longest_count = occur_count;
			}
		}
		else
		{
			/* Clear the occur_count as the consecutive count is failed */
			occur_count = 0;
		}
	}
	return longest_count;
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
	int arr[ARR_SIZE] = {1,1,2,2,3,3,3,3,4,4,4,4,3,3,3};
	int res = 0;
	
	/* find the maximum consecutive occurance of 3 */
	res = FindLongestConsecutive(ARR_SIZE,arr,3);
	
	printf("The maximum occurance of Number 3 is : %d",res);
}
