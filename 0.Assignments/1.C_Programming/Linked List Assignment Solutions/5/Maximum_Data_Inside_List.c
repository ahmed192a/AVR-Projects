/**
 * @file Maximum_Data_Inside_List.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Example to demonstrate how to get the maximum data inside the Linked List.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct node 
 * 
 * @version 0.1
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
struct node
{
   int data;            // Data
   struct node *next;   // Address of next node
};

struct node *head = NULL;        // Head of the list
struct node *current = NULL;     // Current node of the list

/**
 * @brief insertAtLast Function
 * 
 * @param data 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void insertAtLast(int data)
{
   // Allocate memory for new node
   struct node *link = (struct node*) malloc(sizeof(struct node));

   // insert the data to the new node and make the next point to null
   link->data = data;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL)
   {
      head = link;
      return;
   }

   current = head;

   // loop until reach the last node in the old list
   while(current->next != NULL)
   {
	   current = current->next;
   }

   // Make the last node in the old list point to new node
   current->next = link;
}

/**
 * @brief printList Function
 * 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void printList(void)
{
   struct node *ptr = head;

   printf("[head] =>");

   //start looping from the head until the last node
   while(ptr != NULL)
   {
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

/**
 * @brief findMaximumDataInTheList function
 * 
 * @param max_ptr 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void findMaximumDataInTheList(int *max_ptr)
{
   if(head==NULL)
   {
      printf("Linked List is empty");
      return;
   }
   //assume that the head is the maximum value
   *max_ptr = head->data;

   // start checking from the second node
   current = head->next;

   while(current != NULL)
   {
      if(current->data > *max_ptr)
      {
    	  *max_ptr = current->data;
      }
      current = current->next;
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
	int max;
	insertAtLast(10);
	insertAtLast(20);
	insertAtLast(30);
	insertAtLast(1);
	insertAtLast(40);
	insertAtLast(56);

	// print the list
	printList();

	// get the maximum value inside the list
	findMaximumDataInTheList(&max); // max will be passed by address

	//max now contain the maximum value
	printf("Maximum Value Inside The List : %d",max);

	return 0;
}
