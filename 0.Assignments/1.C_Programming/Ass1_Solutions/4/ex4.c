/**
 * @file ex4.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 4
 * @version 0.1
 * @date 2022-09-18 @ 14:09:15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#define PI 3.14 /* define the value of PI */

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
    float radious;
    float area;
    float circumference;
    printf("Enter the radious of the circle: ");
    scanf("%f",&radious);
	
	/* Calculate the circle area */
    area = PI * radious * radious;
	
	/* Calculate the circle circumference */
    circumference = 2 * PI * radious;

    printf("Circle Area=%f\nCircle Circumference=%f\n",area,circumference);
    return 0;
}
