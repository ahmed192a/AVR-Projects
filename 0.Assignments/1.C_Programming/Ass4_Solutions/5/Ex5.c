/**
 * @file Ex5.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex5
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

#define ARR_SIZE 10

/**
 * @brief copyArray Function
 * 
 * @param ptr1 
 * @param ptr2 
 * @param size 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void copyArray(int *ptr1,int *ptr2,int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		// copy each element in array2 to array1
		*ptr2 = *ptr1;
		// increment both pointers to get the next array element
		ptr1++;
		ptr2++;
	}
}

/****************************** Another Solution ********************************
void copyArray(int *ptr1,int *ptr2,int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		// copy each element in array2 to array1
		ptr2[i] = ptr1[i];
	}
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
   int i;
   int array1[ARR_SIZE],array2[ARR_SIZE];
   printf("\nEnter integers into array: ");

   for (i = 0; i < ARR_SIZE; i++)
   {
      scanf("%d", array1+i); // take each array1 element from user
   }

   copyArray(array1,array2,ARR_SIZE); // pass the two arrays to the function

   for(i=0; i<ARR_SIZE; i++)
   {
	   printf("\narray1[%d] = %d \t array2[%d] = %d",i,array1[i],i,array2[i]);
   }
   return 0;
}
