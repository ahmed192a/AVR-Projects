/**
 * @file ex18.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 2 - Ex18
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <math.h>

/**
 * @brief superPower	function to calculate the super power of a number
 * 
 * @param z 			the number to be calculated
 * @return int 			the super power of the number
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int superPower(int z)
{
	int result;
	result = (int)sqrt(z);
	if(z == (result * result))
	{
		return 1;
	}
	else
	{
		return 0;
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
int main(void)
{
	int num,res;
	scanf("%d",&num);
	res = superPower(num);
	if(res == 1)
	{
		printf("The input number %d is super square \n",num);
	}
	else
	{
		printf("The input number %d is not super square \n",num);
	}
	return 0;
}