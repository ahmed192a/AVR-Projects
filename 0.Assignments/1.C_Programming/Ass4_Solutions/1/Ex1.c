/**
 * @file Ex1.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex1
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

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
   int numArray[10];
   int i, sum = 0;
   int *ptr;

   printf("\nEnter 10 elements : ");

   for (i = 0; i < 10; i++)
      scanf("%d", &numArray[i]);

   ptr = numArray; /* point to the first array element */

   for (i = 0; i < 10; i++)
   {
      sum = sum + *ptr;
      ptr++; // increment pointer to the next array element
   }

   printf("The sum of array elements : %d", sum);

   return 0;
}
