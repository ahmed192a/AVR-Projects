/**
 * @file ex9.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 9
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>


/**
 * @brief  Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main()
{
    float grade;        /* grade of the user */
    printf("Please enter the student grade : ");
    scanf("%f",&grade); /* read the grade from the user */
	
    if(grade>=85)    /* check if the grade is greater than or equal to 85 */
    {
        printf("Excellent");
    }
    else if(grade>=75)  /* check if the grade is greater than or equal to 75 */
    {
        printf("Very Good");
    }
    else if(grade>=65)  /* check if the grade is greater than or equal to 65 */
    {
        printf("Good");
    }
    else if(grade>=50)  /* check if the grade is greater than or equal to 50 */
    {
        printf("Pass");
    }
    else                /* if the grade is less than 50 */
    {
        printf("Fail");
    }
    
    return 0;
}
