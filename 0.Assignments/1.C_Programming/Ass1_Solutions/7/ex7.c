/**
 * @file ex7.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 7
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main()
{
    int input1,input2,input3;
    int Min;
    printf("Please enter the three numbers : ");
    scanf("%d%d%d",&input1,&input2,&input3);
	
	/* Assume that the first number is the minimum number */
    Min=input1;
	/* Compare between the first number and second number to decide which one is the min between them */
    if(input2<=Min)
    {
        Min=input2;
    }
	
	/* Compare between the third number and previous min number to decide which one is the min between them */
    if(input3<=Min)
    {
        Min=input3;
    }
	
    printf("the min number is: %d",Min);
    return 0;
}
