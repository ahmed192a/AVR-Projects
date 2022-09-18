/**
 * @file Ex4.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex4
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

#define ARR_SIZE 10

/**
 * @brief findSmallestElement Function
 * 
 * @param ptr 
 * @param size 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int findSmallestElement(int *ptr,int size)
{
	int i = 0;
	// assume that the minimum number is the first element
	int min = ptr[0];

	// start compare from the second array element
	for(i=1;i<size;i++)
	{
		if(ptr[i] < min)
		{
			min = ptr[i];
		}
	}
	return min;
}

/****************************** Another Solution ********************************
int findSmallestElement(int *ptr,int size)
{
	int i = 0;
	// assume that the minimum number is the first element
	int min = *ptr;
	// start compare from the second array element
	ptr++;
	for(i=1;i<size;i++)
	{
		if(*ptr < min)
		{
			min = *ptr;
		}
		ptr++; //increment pointer to get the next array element
	}
	return min;
}
*******************************************************************************/

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
   int i, arr[ARR_SIZE];
   int num;
   printf("\nEnter integers into array: ");

   for (i = 0; i < ARR_SIZE; i++)
   {
      scanf("%d", arr+i); // take each array element from user
   }

   num = findSmallestElement(arr,ARR_SIZE);

   printf("\nThe smallest array element is : %d",num);

   return 0;
}
