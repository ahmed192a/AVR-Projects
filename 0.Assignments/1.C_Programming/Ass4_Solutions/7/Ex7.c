/**
 * @file Ex7.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex7
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define MAX_SIZE 10

/**
 * @brief SWAP Function
 * 
 * @param ptr1 
 * @param ptr2 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void SWAP(int *ptr1,int *ptr2)
{
	*ptr1 = *ptr1 ^ *ptr2;
	*ptr2 = *ptr1 ^ *ptr2;
	*ptr1 = *ptr1 ^ *ptr2;
}

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main () {

	void (*ptr_func)(int*,int*);
	int num1 = 10,num2 = 15;

	ptr_func = SWAP; //point to the SWAP function

	printf("Before SWAP Call : num1 = %d num2 = %d\n",num1,num2);

	// call SWAP API through the function pointer
	(*ptr_func)(&num1,&num2); // or ptr_func(&num1,&num2);

	printf("After SWAP Call : num1 = %d num2 = %d\n",num1,num2);

	return 0;
}
