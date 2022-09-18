/**
 * @file ex6.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 6
 * @version 0.1
 * @date 2022-09-18 @ 14:09:65
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief convert_lower_to_upper function
 * 
 * @param ch  input character
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void convert_lower_to_upper(char ch)
{
	/* according to ASCII table charaters from A --> Z are from 97 --> 122 */
    if((ch >= 'a') && (ch <='z'))
    {
        printf("\nCapital letter character is : %c",ch-32);
    }
    else
    {
        printf("\nInvaild input character");
    }
}

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
    char ch;
    printf("please enter small letter character to convert it to capital letter:");
    scanf("%c",&ch);
    convert_lower_to_upper(ch);
    return 0;
}
