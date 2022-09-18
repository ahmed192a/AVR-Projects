/**
 * @file ex7.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 7
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief Multiply function
 * 
 * @param num1  input number 1
 * @param num2  input number 2
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void multiply(int num1,int num2)
{
	if(num1%num2==0)
    {
        printf("\n%d is multiply of %d\n",num1,num2);
    }
    else
    {
        printf("\n%d is not multiply of %d\n",num1,num2);
    }
}

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
    int input1,input2;
    printf("Please enter the two numbers : ");
    scanf("%d %d",&input1,&input2);
    multiply(input1,input2);
    return 0;
}
