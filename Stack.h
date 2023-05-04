/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 7, Stacks and Inheritance
Stack Header File
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

// Stack inherits from LinkedList
class Stack : public LinkedList {
	public:
	   // common stack operations
	   void push(string);
	   string pop(void);
	   string peek(void);
	   bool isEmpty(void);
};

#endif