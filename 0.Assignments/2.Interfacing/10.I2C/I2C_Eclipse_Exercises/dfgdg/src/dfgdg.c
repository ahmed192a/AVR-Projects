/**************************************************************************************************
 Name        : ex10.c
 Author      : Mohamed Tarek
 Description : Assignment 2 - Ex 10
 **************************************************************************************************/

#include <stdio.h>

#define ONE_HOLES 1
#define TWO_HOLES 2

int countHoles(int num)
{
	int data = 0;
	int count = 0;
	if(num == 0)
	{
		count += ONE_HOLES;
	}
	else
	{
		while(num != 0)
		{
			/* get the first digit in the number from the right */
			data = num % 10;
			if((data == 0) || (data == 4) || (data == 6) || (data == 9))
			{
				count += ONE_HOLES;
			}
			else if(data == 8)
			{
				count += TWO_HOLES;
			}
			/* remove the digit in the right to get the next digit in the next loop iteration */
			num = num / 10;
		}
	}
	return count;
}

int main(void)
{
	int number  = 819;
	printf("%d",countHoles(number));
	return 0;
}
