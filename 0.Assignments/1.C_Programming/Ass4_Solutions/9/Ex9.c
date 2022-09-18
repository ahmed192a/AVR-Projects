/**
 * @file Ex9.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex9
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

char arr[4];

/**
 * @brief lastLetter Function
 * 
 * @param word 
 * @return char* 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
char* lastLetters(char* word)
{
	char *ptr = word;

	/* loop until the pointer ptr reaches the NULL terminator */
	while(*ptr != '\0')
	{
		ptr++;
	}
	/* get the last character in the string word */
	arr[0] = *(--ptr);
	arr[1] = ' ';
	/* get the second last character in the string word */
	arr[2] = *(--ptr);
	
	/* Add the null terminator */
	arr[3] = '\0';
	
	return arr;
}

/**
 * @brief 		Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main(void)
{
	char str[10] = "Embedded";
	printf("%s",lastLetters(str));
	return 0;
}

	