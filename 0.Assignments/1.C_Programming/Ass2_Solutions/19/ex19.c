/**
 * @file ex19.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex 19
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

/**
 * @brief IsPowerOfThree function
 * 
 * @param Number 		the number to be checked
 * @return int 		    0 if the number is power of three, 1 otherwise
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int IsPowerOfThree(unsigned int Number)
{
	if (Number == 0) 		return 1;
	if (Number % 3 == 0)	return IsPowerOfThree(Number / 3);
    if (Number == 1)		return 1;

    return 0;
}

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
	int num;
	int res;
	scanf("%d",&num);
	res = IsPowerOfThree(num);
	if(res == 0)
	{
		printf("%d is power of 3\n",num);
	}
	else
	{
		printf("%d is not power of 3\n",num);
	}
	return 0;
}
