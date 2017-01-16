//Singly Linked List Program
//By: Joe Grazewski

#include "stdafx.h"
#include <iostream>

struct node
{
	int data; 
	node *next;
};

bool isEmpty(node *&);
void insertElement(node *&, node*&, int, int);
void printList(node*);
void removeElement(node*&, node*&, int);

int main()
{
	//Since there is nothing in the list we initialize both to NULL. 
	//Head node is 1st node in list. Last node is the node we were pointing to previously as we traverse through the list.
	node *head = NULL;	
	node *last = NULL;

	char choice;
	int position;
	int number;

	do
	{
		std::cout << "**Enter: 1 to add new number\n"; 
		std::cout << "2 to remove a number\n"; 
		std::cout << "3 to print the list\n"; 
		std::cout << "4 to exit**" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case '1':
			std::cout << "Enter a number: " << std::endl;
			std::cin >> number;
			std::cout << "Enter the position: " << std::endl;
			std::cin >> position;
			insertElement(head, last, number, position);
			break;

		case '2':
			std::cout << "At what position would you like to remove a number: " << std::endl;
			std::cin >> position;
			removeElement(head, last, position);
			break;

		case '3':
			printList(head);
			break;

		case '4':
			std::cout << "Thank you for using the Singly Linked List program!" << std::endl;
			break;

		}


	} while (choice != '4');


	return 0;
}

//Function to check if our list is empty.
bool isEmpty(node *&head)
{
	if (head == NULL)
		return true;
	else
		return false;
}

void insertElement(node *&head, node *&last, int number, int position)
{
	int k = 1;
	node *temp = new node;

	//if empty this will be the first and only number in the list
	if (isEmpty(head))
	{
		temp->data = number;
		temp->next = NULL;
		head = temp;
		last = temp;
	}

	//inserting at the beginning of list. Temp number is new head therefore its next pointer points to old head.
	else if (position == 1)
	{
		temp->data = number;
		temp->next = head;
		head = temp;
		last = temp;
	}

	else
	{
		temp->data = number;
		//following node is node that will follow the node we insert					 
		node *following = head;

		//traverse list until the position we want to insert- if we want to add at position 3 then we stop @ 2
		while (last != NULL && k < position)
		{
			k++;
			last = following;
			following = following->next;
		}
		//if our last node points to NULL we will be inserting node into the tail position
		if (last->next == NULL)
		{
			temp->data = number;
			temp->next = NULL;
			//last node (our 'previous' node) should now point to inserted node
			last->next = temp;
			last = temp;

		}
		//if we are inserting somewhere in the middle- really helps understand what last node and following node is
		else
		{
			last->next = temp;
			temp->next = following;
		}

	}
}

//traverse and print list- current is actually head but will call current
void printList(node *current) 
{
	if (isEmpty(current))
		std::cout << "The list is empty" << std::endl;
	else
		std::cout << "The list contains: " << std::endl;
	while (current != NULL)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}

void removeElement(node *&head, node *&last, int position)
{
	int k = 1;
	
	//before removing check if list is empty.
	if (isEmpty(head))
		std::cout << "The list is already empty." << std::endl;

	//if there is only one number in the list
	else if (head->next == NULL)
	{
		delete head;
		head = NULL;
		last = NULL;
	}

	//from the beginning
	else if (position == 1)
	{
		node *temp = head;
		head = head->next;

		delete temp;
	}

	else
	{
		node *following = head;

		//Traverse list until arriving at the position from which we want to delete
		while ((last != NULL) && (k < position))
		{
			k++;
			last = following;
			following = following->next;

		}
		//If following equals to NULL the position does not exist
		if (following == NULL)
			std::cout << "The position does not exist." << std::endl;
		//from the middle
		else
		{
			last->next = following->next;
			delete following;
		}
	}

}
