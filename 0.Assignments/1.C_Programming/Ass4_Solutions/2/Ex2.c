/**
 * @file Ex2.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex2
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

int string_ln(char*); // function prototype

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
	char str[20];
	int length;

	printf("\nEnter your string : ");
	gets(str);

	length = string_ln(str);
	printf("The length of the given string \"%s\" is : %d", str, length);
	return 0;
}

/**
 * @brief string_ln Function
 * 
 * @param ptr 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int string_ln(char *ptr) /* ptr = &str[0] */
{
	int str_count = 0;
	while (*ptr != '\0') // loop until the end of the string
	{
		str_count++;
		ptr++; // increment the pointer to get the next character
	}
	return str_count;
}
