/**
 * @file Ex9_Sol1.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex9
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define ARR_SIZE 100

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
    int arr[ARR_SIZE],i;
    int num_index;
    printf("Please enter the element index : ");
    scanf("%d",&num_index);
    arr[0] = 1;
    arr[1] = 1;
    for(i=2;i<ARR_SIZE;i++) /* fill the 100 array elements */
    {
    	arr[i]=arr[i-1] + arr[i-2]; /* each element equals to the sum of the previous two elements */
    }
    printf("\nThe %dth term is:%d",num_index,arr[num_index-1]);
    return 0;
}

