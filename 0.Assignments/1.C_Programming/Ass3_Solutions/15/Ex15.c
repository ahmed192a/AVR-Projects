/**
 * @file Ex15.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex15
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief string_cat Function
 * 
 * @param str1 		the first string
 * @param str2 		the second string
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void string_cat(char str1[],char str2[])
{
	int i, j;
	/* This loop is to store the length of str1 in i
	 * It just counts the number of characters in str1
	 * You can also use strlen instead of this.
	 */
	for(i=0; str1[i]!='\0'; ++i);

	/* This loop would concatenate the string str2 at
	 * the end of str1
	 */
	for(j=0; str2[j]!='\0'; ++j, ++i)
	{
		str1[i]=str2[j];
	}
	/* \0 represents end of string */
	str1[i]='\0';
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
   char s1[100], s2[50];
   printf("\nEnter first string: ");
   gets(s1);
   printf("\nEnter second string: ");
   gets(s2);

   string_cat(s1,s2);
   printf("\nOutput: %s",s1);

   return 0;
}
