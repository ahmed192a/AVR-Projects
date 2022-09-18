/**
 * @file Ex10.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex10
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief Swap_two_pointers
 * 
 * @param p1 
 * @param p2 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void Swap_two_pointers(int **p1,int **p2)
{
	int *temp = *p1;
	*p1 = *p2;
	*p2 = temp;
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
	int num1=5,num2=7;
	int *ptr1 = &num1;
	int *ptr2 = &num2;

	printf("*prt1 = %d\n",*ptr1); /* It should be the value of num1 */
	printf("*prt2 = %d\n",*ptr2); /* It should be the value of num2 */

	Swap_two_pointers(&ptr1,&ptr2);

	printf("*prt1 = %d\n",*ptr1); /* It should be the value of num2 */
	printf("*prt2 = %d\n",*ptr2); /* It should be the value of num1 */

	return 0;
}


	