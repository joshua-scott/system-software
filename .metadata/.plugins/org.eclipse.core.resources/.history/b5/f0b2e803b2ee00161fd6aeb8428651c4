/*
 Name: 			Exercise4Advanced, Assignment1.c
 Author: 		Joshua Scott
 Task description:
Code a doubly linked list of structs. Each struct is an element in the periodic table.
Each struct contains the element's name (e.g. Hydrogen), chemical symbol (e.g. H), atomic number (e.g. 1) and state (liquid, solid, gas, unknown)
Each struct shall also contain a pointer to the next element and a pointer to the previous element
You shall be able to add new elements to the list (either read user input or from a file)
New elements shall go to correct place in the list based on their atomic number
You shall be able to find an element by using the chemical symbol as a key
You shall be able to print out the element's information
You shall be able to print out the elements that currently exist periodic table
You shall be able to empty the whole list and free the memory
Use pointers and functions and allocate memory dynamically for each element
 */

#define NAME_LENGTH 20

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char* name[NAME_LENGTH];    // e.g. Hydrogen
    char* chemicalSymbol[2];    // e.g. H or Ag
	short int atomicNumber;     // e.g. 1
	char state;                 // s, l, g or u (unknown)

	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(char* name[NAME_LENGTH], char* chemicalSymbol[2],
                        short int atomicNumber, char state)
{
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->name = name;
	newNode->chemicalSymbol = chemicalSymbol;
	newNode->atomicNumber = atomicNumber;
	newNode->state = state;

	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x)
{
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x)
{
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void Print()
{
	struct Node* temp = head;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{

	/*Driver code to test the implementation*/
	head = NULL; // empty list. set head as NULL.

	// Calling an Insert and printing list both in forward as well as reverse direction.


}
