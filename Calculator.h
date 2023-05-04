/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 7, Stacks and Inheritance
Calculator Header File
*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "Stack.h"
#include "LinkedList.h"
#include "PA7.h"

using namespace std;

bool checkOperatorOnStackPrecedence(string, string);
int prescednece(string c);
bool isOperator(char c);
bool isOperand(char c);

class Calculator {
	private:
		string symbolTable['Z' + 1];
		// example of composition
		// Calculator "has-a" Stack
		Stack stack; // for converting infix to postfix and for evaluating postfix
	public:
		void setSymbolTable(string[]);
		string convertInfixToPostfix(string);
		string evaluatePostfix(string postfix, vector<char> valueVector, vector<int> variableVector);

};

#endif