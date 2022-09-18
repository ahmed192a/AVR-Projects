/**
 * @file ex10.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 10
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "stdio.h"

/**
 * @brief Main function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main() {

    char operator;
    float firstNumber,secondNumber;
    double result;

    printf("Enter an operator + or - or * or % ");
    scanf("%c", &operator);

    printf("\nEnter two operands: ");
    scanf("%f %f",&firstNumber, &secondNumber);
	
	/* Swicth case to perfrom the required operations */
    switch(operator)
    {
        case '+':
        	result = firstNumber + secondNumber;
            printf("\n%f + %f = %lf",firstNumber, secondNumber, result);
            break;

        case '-':
        	result = firstNumber - secondNumber;
            printf("\n%f - %f = %lf",firstNumber, secondNumber, result);
            break;

        case '*':
        	result = firstNumber * secondNumber;
            printf("\n%f * %f = %lf",firstNumber, secondNumber, result);
            break;

        case '/':
        	result = firstNumber / secondNumber;
            printf("\n%f / %f = %lf",firstNumber, secondNumber, result);
            break;

        /* operator doesn't match any case constant (+, -, *, /) */
        default:
            printf("Error! operator is not correct");
    }

    return 0;
}