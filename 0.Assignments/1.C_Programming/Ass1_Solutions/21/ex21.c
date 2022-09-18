/**
 * @file ex21.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 21
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
int main()
{
    int i,j,rows;

    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("\n");

    for(i=0;i<rows;i++)
    {
        for(j=0;j<rows;j++)
        {
            if( (j==i) || (j==rows-i-1) )
            {
                printf(" *");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

