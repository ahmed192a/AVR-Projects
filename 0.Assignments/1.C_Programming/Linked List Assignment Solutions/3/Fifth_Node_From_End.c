/**
 * @file Fifth_Node_From_End.c
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 * @brief Function that return the data of the 5th node from the end of linked list.
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
 * @brief sizeOfList function
 * 
 * @return int 
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
 * @brief fifthElmentFromEnd function 
 * 
 * @param fifth 
 * @version 0.1
 * 
 * @author Ahmed Mohamed (ahmed.mohamed.eng.25@gmail.com)
 */
void fifthElmentFromEnd(int *fifth)
{
	struct node *ptr = head;
	// check if the list is empty
	if(head==NULL)
	{
		printf("Empty Linked List \n");
		return;
	}
	// check if the list has only one node
	if(head->next == NULL)
	{
		*fifth = head->data;
		return;
	}
	//check if the array size is greater than or equal 5
	if(sizeOfList() >= 5)
	{
		while(ptr->next->next->next->next->next != NULL)
		{
			//increment step by step until reached the 5th element from the end
			ptr = ptr->next;
		}
		*fifth = ptr->data;
	}
	else
	{
		printf("Linked List Size is smaller than 5\n");
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
	int fifthElement;
	insertAtLast(10);
	insertAtLast(20);
	insertAtLast(30);
	insertAtLast(1);
	insertAtLast(40);
	insertAtLast(56);
	insertAtLast(44);

	// print the list
	printList();

	// get the 5th element from the end
	fifthElmentFromEnd(&fifthElement);

	// print data of the 5th node from the end
	printf("The data of the 5th node from the end : %d\n",fifthElement);
	return 0;
}
