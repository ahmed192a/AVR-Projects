/**
 * @file ex5.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 1 - Ex 5
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
    char c;
    printf("Enter a character: ");

    /* Reads character input from the user */
    scanf("%c", &c);

    /*
       %d displays the integer value of a character
       %c displays the actual character
    */
    printf("ASCII value of %c = %d", c, c);
    return 0;
}
