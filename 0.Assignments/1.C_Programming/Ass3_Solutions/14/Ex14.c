/**
 * @file Ex14.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex14
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<string.h>

/**
 * @brief reverse_string
 * 
 * @param s 		the string
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void reverse_string(char s[])
{
	int i = 0, j;
	char temp;
	j = strlen(s) - 1;
	
	/* null will remained in the same place just start swapping the array element */
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
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
int main() {
   char str[1000];
   printf("\nEnter the string :");
   gets(str);

   reverse_string(str);

   printf("\nReverse string is :%s", str);
   return (0);
}
