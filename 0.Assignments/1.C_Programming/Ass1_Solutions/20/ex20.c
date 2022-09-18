/**
 * @file ex20.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 20
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
int main(void)
{
	int i, j, rows;
	
	printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("\n");
	
	/* Loop for each row */
	for(i=0;i<rows;i++)
	{
		/* print the left spaces */
		for(j=i;j<rows-1;j++) printf(" ");

		/* print the stars number of stars in each row = ((2 * Row Number) + 1) */
		for(j=0;j<((2*i)+1);j++) printf("*");

		printf("\n");
	}
	return 0;
}

