/**
 * @file Ex7.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 5 - Ex7
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @enum fan_level 
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
enum fan_level{
	Level1,
	Level2,
	Level3
};

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
	enum fan_level fan1 = Level1;

	printf("Level1 = %d\n",fan1);

	if(fan1 == Level1)
	{
		fan1 = Level2;
	}

	printf("Level2 = %d\n",fan1);

	if(fan1 == Level2)
	{
		fan1 = Level3;
	}

	printf("Level3 = %d\n",fan1);

	return 0;
}