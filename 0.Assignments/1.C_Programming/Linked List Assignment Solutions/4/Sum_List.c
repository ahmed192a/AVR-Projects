/**
 * @file Sum_List.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Function that return the sum of all nodes in linked list.
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
struct node {
   int data;               // Data
   struct node *next;      // Address of next node
};

struct node *head = NULL;     // Head of the list
struct node *current = NULL;  // Current node of the list


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

//display the list
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
 * @brief sum_List Function that return the sum of all nodes in linked list.
 * 
 * @param sum_ptr 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void sumList(int *sum_ptr)
{
	//check if the list is empty
	if(head==NULL)
	{
		return;
	}
	current = head;
	//loop until the end of the list
	while(current != NULL)
	{
		*sum_ptr += current->data;
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
	int sum = 0;
	insertAtLast(10);
	insertAtLast(20);
	insertAtLast(30);
	insertAtLast(1);
	insertAtLast(40);
	insertAtLast(56);

	// print the list
	printList();

	//get the sum of all node
	sumList(&sum);

	//print the sum of all node
	printf("sum = %d\n",sum);
	return 0;
}
