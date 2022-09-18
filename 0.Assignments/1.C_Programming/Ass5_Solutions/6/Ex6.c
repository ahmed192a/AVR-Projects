/**
 * @file Ex6.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 5 - Ex6
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>


/**
 * @union family_name 
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
union family_name
{
	char first_name[30];	/* first name */
	char last_name[30];		/* last name */
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
	union family_name member;

	// store "Mohamed Tarek" --> first_name
	strcpy(member.first_name,"Mohamed Tarek");

	// last_name share the same memory area with first_name
	printf("Last Name : %s \n",member.last_name);

	// union allocate memory equals to the size of its largest member
	printf("Size of Union family_name is : %d \n",sizeof(union family_name));

    return 0;
}

