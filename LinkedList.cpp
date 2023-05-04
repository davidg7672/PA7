/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 7, Stacks and Inheritance
Linked List Function File
*/

#include "LinkedList.h"

// DVC
LinkedList::LinkedList() {
	head = NULL;
}

// Destructor
LinkedList::~LinkedList() {
	// free each Node's memory in the list
	destroyList();
}

/***********************************************************
Member Function: destoryList()
Inputs: Nothing
Outputs: Returns nothing
General Description: 

This function willl walk through each node in the list and
deallocate memory, but also assign the pointers to nothing.

***********************************************************/
void LinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL; // for good practice
}

void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

/***********************************************************
Member Function: insertAtFront()
Inputs: string of the new value that the node wil hold
Outputs: Returns nothing
General Description: 

This function willl insert a node at the front of the list
***********************************************************/
void LinkedList::insertAtFront(string newValue) {
	Node *newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
	
	if(head == NULL) {
		head = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
}

/***********************************************************
Member Function: deleteAtFront()
Inputs: Nothign
Outputs: Returns string of what's deleted
General Description: 

This function willl delete the node at the front of the list
***********************************************************/
string LinkedList::deleteAtFront() {
	string value = "";

	// Checks if there is thing in head
	if(head) {
		Node *nodeToDelete = head;
		head = head->next;
		value = nodeToDelete->value;
		
		delete nodeToDelete;
		nodeToDelete = NULL;
	}
	
	return value; 
}