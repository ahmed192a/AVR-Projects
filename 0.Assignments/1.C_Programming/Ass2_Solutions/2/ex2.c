/**
 * @file ex2.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 2
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
#include <stdio.h>

/**
 * @brief check_alphabet function
 * 
 * @param ch_in 		input character
 * @version 0.1	
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void check_alphabet(char ch_in)
{
	if( ((ch_in >= 'A') && (ch_in <= 'Z')) || ((ch_in >= 'a') && (ch_in <= 'z')) )	// Check if the input character is an alphabet
	{
		printf("\n%c is an alphabet.", ch_in);
	}
	else
	{
		printf("\n%c is not an alphabet.", ch_in);
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
int main(void) {
	char ch;
	printf("Please enter a character : ");
	scanf("%c",&ch);
	check_alphabet(ch);
	return 0;
}