/**
 * @file Ex21.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex21
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/* Global array is empty and will be filled by PrintReverseInclusive function */
int OutputArray[256];

/**
 * @brief PrintReverseInclusive Function
 * 
 * @param LowerNumber 		the lower number
 * @param UpperNumber 		the upper number
 * @param result_size 		the size of the result array
 * @return int* 			the result array
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int * PrintReverseInclusive(int LowerNumber,int UpperNumber,int * result_size)
{
	int i;
	*result_size = 0;
	/* check the exit conditions */
	if(LowerNumber > UpperNumber)
	{
		OutputArray[0] = 0xFF;
		OutputArray[1] = 0xFF;
		*result_size = 2;
	}
	else
	{
		/* start looping from UpperNumber until LowerNumber to fill the array */
		for(i=UpperNumber;i>=LowerNumber;i--)
		{
			OutputArray[*result_size] = i;
			(*result_size)++;
		}
	}
	return OutputArray;
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
	int count;
    int n1 = 5,n2=10;
    int *ptr;
	int arr_size_used = 0;
	
	ptr = PrintReverseInclusive(n1,n2,&arr_size_used);

	printf("Output Array = ");
	
	/* start looping from 0 to the last used element in the array */
	for(count=0;count<arr_size_used;count++)
	{
		/* access the global array using the ptr */
		printf("%d ",ptr[count]);
	}
	printf("\nOutput Array Size = %d",arr_size_used);
	return 0;
}