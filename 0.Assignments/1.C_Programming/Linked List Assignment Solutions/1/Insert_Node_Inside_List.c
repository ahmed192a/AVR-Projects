/**
 * @file Insert_Node_Inside_List.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Example to demonstrate how to insert a node in Linked List at any position.
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

struct node *head = NULL;		// Head of the list
struct node *current = NULL;	// Current node of the list
struct node *prev = NULL;		// Previous node of the list

/**
 * @brief printList Function
 * 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */void printList(void)
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
 * @brief sizeOfList Function calculate the list size
 * 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
int sizeOfList(void)
{
   int size = 0;

   // check if the linked list is empty
   if(head==NULL)
   {
      printf("List size : %d ", size);
      return -1;
   }

   current = head;
   size = 1;
   while(current->next != NULL)
   {
      current = current->next;
      size++;
   }
   return size;
}

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
 * @brief insertNodeInsideList function
 * 
 * @param data 
 * @param position 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void insertNodeInsideList(int data,int position)
{
	// Allocate memory for new node;
	struct node *link = (struct node*) malloc(sizeof(struct node));
	int pos = 0;
	// If head is empty, create new list
	if(head==NULL)
	{
		link->data = data;
		link->next = NULL;
		head = link;
		return;
	}
	//check if the array size smaller than in the input position
	if(position > sizeOfList())
	{
		printf("Invalid Index Number\n");
		return;
	}
	//check the first node in the linked list
	if(position == 0)
	{
		link->next = head;
		link->data = data;
		head = link;
		return;
	}
	current = head;
	while(pos < position)
	{
		prev = current;
		current = current->next;
		pos++;
	}
	link->data = data;
	link->next = current;
	prev->next = link;

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
	insertAtLast(10);
	insertAtLast(20);
	insertAtLast(30);
	insertAtLast(1);
	insertAtLast(40);
	insertAtLast(56);

	// print the list
	printList();

	//add node at the head
	insertNodeInsideList(72,0);

	// print the list
	printList();

	//add node in position 5
	insertNodeInsideList(60,5);

	// print the list
	printList();

	//add node at the tail
	insertNodeInsideList(100,8);

	// print the list
	printList();

	return 0;
}

