/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 7, Stacks and Inheritance
Stack Function File
*/

#include "Stack.h"

/***********************************************************
Member Function: push()
Inputs: string of new value
Outputs: Returns nothing
General Description: 

This function inserts a node at front of top of the stack,
and the new value is the value that the top of teh stack
will hold. 
***********************************************************/
void Stack::push(string newValue) {
	insertAtFront(newValue);
}

/***********************************************************
Member Function: pop()
Inputs: Nothing
Outputs: Returns string
General Description: 

This function will return the node that is delete. Will 
delete node at the front, hence that is how the stack works
***********************************************************/
string Stack::pop(void) {
	return LinkedList::deleteAtFront();
}

/***********************************************************
Member Function: isEmpty()
Inputs: Nothing
Outputs: Returns bool
General Description: 

This function will return the value stored at the top of the
stack
***********************************************************/
string Stack::peek(void) {
	if(head) {
		return head->value;
	}
	
	// If first condition fails, there is nothing in the list
	return ""; 
}

/***********************************************************
Member Function: isEmpty()
Inputs: Nothing
Outputs: Returns bool
General Description: 

This function willl check if the stack is empty, by looking
at the head. 
***********************************************************/
bool Stack::isEmpty(void) {
	// Implies that there is something in the list
	if(head) {
		return false;
	}
	
	// If the head == NULL, then this will return
	return true; 
}