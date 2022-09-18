/**
 * @file ex4.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 4
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
#include <stdio.h>

#define NO_ERROR_VALID_OPERATION 		(0U)
#define ERROR_INVALID_OPERATION 		(1U)

/**
 * @brief operation function
 * 
 * @param op 		the operation to be performed
 * @param n1 			the first number
 * @param n2 			the second number	
 * @param error_ptr 	pointer to the error variable
 * @return float 		the result of the operation
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
float operation(char op,float n1, float n2,int * error_ptr)
{
	float result;
	switch(op)
	{
		case '+' :
			result = n1 + n2;
			*error_ptr = NO_ERROR_VALID_OPERATION;
			break;
		case '-' :
			result = n1 - n2;
			*error_ptr = NO_ERROR_VALID_OPERATION;
			break;
		case '*' :
			result = n1 * n2;
			*error_ptr = NO_ERROR_VALID_OPERATION;
			break;
		case '/' :
			result = n1 / n2;
			*error_ptr = NO_ERROR_VALID_OPERATION;
			break;
		default  :
			printf("\nError Invalid Input Operation");
			*error_ptr = ERROR_INVALID_OPERATION;
			break;
	}
	return result;
}

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main(void) {
	char op;
	float num1,num2;
	float result;
	int error = NO_ERROR_VALID_OPERATION; // used to check if the input operation is valid or not
	printf("Please enter the required operation : ");
	scanf("%c",&op);
	printf("\nPlease enter the two numbers : ");
	scanf("%f %f",&num1,&num2);
	result = operation(op,num1,num2,&error);
	if(error == NO_ERROR_VALID_OPERATION)
	{
		printf("\nresult = %f",result);
	}
	else if(error == ERROR_INVALID_OPERATION)
	{
		printf("\nNo Results");
	}

	return 0;
}
