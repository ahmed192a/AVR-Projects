/**
 * @file Ex12.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex12
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief string_length Function
 * 
 * @param str   the string
 * @return int  the length of the string
 * @version 0.1 
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int string_length(char str[])
{
	int i;
	/* count the string start from element 0 until the element before the NULL terminator */
	for(i = 0; str[i] != '\0'; ++i);
	return i;
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
    char s[1000], length;

    printf("Enter a string: ");
    gets(s);

	length = string_length(s);
	
    printf("Length of string: %d", length);
    return 0;
}
