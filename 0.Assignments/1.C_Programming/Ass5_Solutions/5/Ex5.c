/**
 * @file Ex5.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 5 - Ex5	
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define MAX_NUM_STUDENTS 10

/**
 * @struct student 
 * 
 * @version 0.1 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
struct student
{
  char name[30];	/* student name */
  int id;			/* student id */
  float grade;		/* student grade */
};

void fillStudentsInformation(struct student *st_ptr, int size);
void printStudentsInformation(struct student *st_ptr, int size);

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
	struct student students[MAX_NUM_STUDENTS];
	// Pass the array of structures to fill it
    fillStudentsInformation(students,MAX_NUM_STUDENTS);
    printStudentsInformation(students,MAX_NUM_STUDENTS);
    return 0;
}
/**
 * @brief fillStudentsInformation Function
 * 
 * @param st_ptr 
 * @param size 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void fillStudentsInformation(struct student *st_ptr, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
    	printf("Please Enter Name, Id and Grade for student number %d :",i+1);
    	// take inputs from user
    	scanf("%s %d %f",st_ptr->name,&(st_ptr->id),&(st_ptr->grade));
    	printf("\n");
    	st_ptr++; // increment the pointer to get the next structure in the array
    }
}
/**
 * @brief printStudentsInformation Function
 * 
 * @param st_ptr 
 * @param size 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void printStudentsInformation(struct student *st_ptr, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		// print student information
		printf("Student Number %d Information : \n",i+1);
		printf("Name : %s \n",st_ptr->name);
		printf("Id : %d \n",st_ptr->id);
		printf("Grade : %f \n",st_ptr->grade);
		st_ptr++; // increment the pointer to get the next structure in the array
	}
}

/*********************************** Another Method *****************************************
void printStudentsInformation(struct student *st_ptr, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("Student Number %d Information : \n",i+1);
		printf("Name : %s \n",st_ptr[i].name);
		printf("Id : %d \n",st_ptr[i].id);
		printf("Grade : %f \n",st_ptr[i].grade);
	}
}
********************************************************************************************/
