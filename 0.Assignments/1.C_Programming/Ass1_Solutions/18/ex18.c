/**
 * @file ex18.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 18
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
    int i, j, rows;

    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("\n");

	/* Loop for each row */
    for(i=1; i<=rows; ++i)
    {
		/* loop to display the stars in each row, number of stars in each row is same as number of rows */
        for(j=1; j<=i; ++j)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
