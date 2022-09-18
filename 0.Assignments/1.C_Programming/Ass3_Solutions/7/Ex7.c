/**
 * @file Ex7.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex7
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define ARR_SIZE 100

/**
 * @brief   Main Function
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
    for(i=1;i<ARR_SIZE;i++) /* fill the 100 array elements */
    {
    	arr[i]=arr[i-1]+2; /* each element equals to the previous one + 2 */
    }
    printf("\nThe %dth term is:%d",num_index,arr[num_index-1]);
    return 0;
}

