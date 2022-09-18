/**
 * @file Ex13.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex13
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>

/**
 * @brief remove_all_except_alphabet
 * 
 * @param str   the string
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void remove_all_except_alphabet(char str[])
{
	int i, j;
	for(i = 0; str[i] != '\0'; ++i)
    {
        while ( !((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) &&  (str[i] != '\0') )
        {
        	/* Enter here in case the element is not alphabet and it is not equals to null */
            for(j = i; str[j] != '\0'; ++j)
            {
				/* remove this not alphabet character by making each element equals to the value of the next element */
                str[j] = str[j+1];
            }
        }
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
    char line[1000];

    printf("Enter a string: ");
    gets(line);

    remove_all_except_alphabet(line);

    printf("Output String: ");
    puts(line);
    return 0;
}
