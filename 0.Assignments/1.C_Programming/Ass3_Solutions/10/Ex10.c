/**
 * @file Ex10.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 3 - Ex10
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief upper_to_lower
 * 
 * @param s 		the string
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void upper_to_lower(char s[])
{
	int i=0;
	while(s[i] != '\0') /* loop until the end of the string */
	{
		if((s[i]>='A') && (s[i]<='Z'))
		{
			/* the difference between any small letter and captial letter is 32 according to the ASCII table
			   so in case the character is captial letter increment it by 32 to be small letter */
			s[i] = s[i] + 32;
		}
		i++; // increment to fet the next array element
	}
}

/**
 * @brief Main Function
 * 
 * @return int 
 * @version 0.1
 * 
 * @date 2022-09-18 @ 15:09:94
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int main(void)
{
	char str[20];
	printf("Please enter ther required sting message : ");
	gets(str);
	printf("\n");
	upper_to_lower(str);
	printf("Message after converting : %s\n",str);
	return 0;
}


