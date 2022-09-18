/**
 * @file Ex1.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Assignment 4 - Ex1
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
/**
 * @struct student
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
struct student
{
    char name[50];
    int roll;
    float marks;
} s;

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
    printf("Enter information:\n");

    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    printf("Enter marks: ");
    scanf("%f", &s.marks);


    printf("Displaying Information:\n");

    printf("Name: ");
    puts(s.name);

    printf("Roll number: %d\n",s.roll);

    printf("Marks: %.1f\n", s.marks);

    return 0;
}
