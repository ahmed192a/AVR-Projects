/**
 * @file Ex11.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex11
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief count_character function
 * 
 * @param s           the string
 * @param character   the character to count
 * @return int 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int count_character(char s[],char character)
{
	int i,frequency = 0;
	for(i = 0; s[i] != '\0'; i++) /* loop untill the end of the string */
    {
		if(character == s[i])
		{
			/* increment the frequency in match case */
			++frequency; 
		}
    }
	return frequency;
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
   char str[1000];
   char ch;
   int count;

   printf("Enter a string: ");
   gets(str);

   printf("Enter a character to find the frequency: ");
   scanf("%c",&ch);

   count = count_character(str,ch);

   printf("Frequency of %c = %d", ch, count);

   return 0;
}
