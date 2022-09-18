/**
 * @file Ex3.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex3
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

#define ARR_SIZE 10

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
   int *ptr;

   ptr = &arr[0]; //point to the first array element

   printf("\nEnter integers into array: ");

   for (i = 0; i < ARR_SIZE; i++)
   {
      scanf("%d", ptr); // take array element from user
      ptr++; // increment pointer to get the next array element
   }

   ptr = &arr[ARR_SIZE - 1]; //point to the last array element

   printf("\nElements of array in reverse order are :");

   for (i = ARR_SIZE - 1; i >= 0; i--)
   {
      printf("\nElement%d is %d : ", i, *ptr);
      ptr--;
   }

   return 0;
}
