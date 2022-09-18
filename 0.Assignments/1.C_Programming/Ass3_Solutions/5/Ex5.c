/**
 * @file Ex5.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex5
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief Linear Search Function to find the first occurance of an element in an array
 * 
 * @param Array_size    the size of the array
 * @param Array         the array
 * @param Item          the element to be searched for
 * @return int           the index of the first occurance of the element
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int Linear_Search_Find_First(int Array_size,int *Array,int Item)
{
    int i;
    for(i=0;i<Array_size;i++)
	{
        if(Item==Array[i])
		{
			/* Element is found return the array index */
			return (i);
		}
    }
    return -1; /* element not found */
}

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main( void )
{
    const int size = 5;
    int i;
    int array[size];
    int location;
    int element;

    printf("Enter the required array: \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }

    printf("Enter element for search: ");
    scanf("%d",&element);

	/* pass the array to the function */
    location = Linear_Search_Find_First(size,array,element);

    if(location == -1)
    {
        printf("\nElement not found\n");
    }
    else
    {
        printf("\nThe element at the location: %d",location);
    }
    return 0;

}