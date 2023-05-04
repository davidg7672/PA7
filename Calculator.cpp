/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 7, Stacks and Inheritance
Calculator Function File
*/

#include "Calculator.h"
#include "PA7.h"

/***********************************************************
Member Function: setSymbolTable()
Inputs: Array of symbol table
Outputs: Returns nothing
General Description: 

This function assigns one array manually to another array
***********************************************************/
void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		symbolTable[i] = newSymbolTable[i];
	}
}	

/***********************************************************
Function: checkOperatorOnStackPrecedence()
Inputs: Strings, current operator and operator on the stack
Outputs: Returns bool
General Description: 

This funciton campes two operators that were passed in. 
This is done in order to figure what the order of operations 
were taken in order to place the prescedence
***********************************************************/
bool checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator) {
	if(prescednece(operatorOnStack) > prescednece(currentOperator)) {
		return true;
	}

	return false;
}

/***********************************************************
Member Function: convertInfixToPostfix()
Inputs: String of infix value
Outputs: Returns a string of postfix
General Description: 

This member function iterates through the string until,
the funciton is fully converted to postfix.
***********************************************************/
string Calculator::convertInfixToPostfix(string infix) {
	string result, c;

	for(int i = 0; i < infix.length(); i++) {
		if(isOperand(infix[i])) {
			result += infix[i];
		}
		else if (infix[i] == '(') {
			c = infix[i];
			stack.push(c);
		}
		else if(infix[i] == ')') {
			while(stack.peek()[0] != '(') {
	 			result += stack.pop();
	 		}
			stack.pop();
	 	}
		else {
			c = infix[i];
			while(!stack.isEmpty() && checkOperatorOnStackPrecedence(stack.peek(), c)) {
				result += stack.pop();
			}
			stack.push(c);
		}
	}

	while(!stack.isEmpty()) {
		result += stack.pop();
	}
	return result;
}

/***********************************************************
Member Function: evaulatePostfix()
Inputs: Postfix string, value vector, and variable vector
Outputs: Returns the result of the computation via string
General Description: 

This function uses the stack in order to make computations.
During iterations, it will pop and push things on to the stack
to get the final result
***********************************************************/
string Calculator::evaluatePostfix(string postfix, vector<char> valueVector, vector<int> variableVector) {
	long operand1, operand2;
	string evalutedString;

	while(!stack.isEmpty()) {
		stack.pop();
	}

	for(int i = 0; i < postfix.length(); i++) {
		if(isOperand(postfix[i])) {
			for(int j = 0; j < variableVector.size(); j++) {
				if(postfix[i] == valueVector[j]) {
					stack.push(to_string(variableVector.at(j)));
				}
			}
		}
		else {
			operand1 = stol(stack.pop());
			operand2 = stol(stack.pop());

			switch (postfix[i])
			{
			case '+':
				stack.push(to_string(operand1 + operand2));
				break;
			case '-':
				stack.push(to_string(operand1 - operand2));
				break;
			case '*':
				stack.push(to_string(operand1 * operand2));
				break;
			case '/':
				stack.push(to_string(operand1 / operand2));
				break;
			case '^':
				stack.push(to_string(pow(operand1, operand2)));
				break;
			}
		}
	}

	evalutedString = stack.pop();

	return evalutedString;
}

/***********************************************************
Function: prescedence()
Inputs: String value character
Outputs: Int of prescedence
General Description: 

This function will compare c to different types of operators,
different operators have different presecedences, in which
they will be executed
***********************************************************/
int prescednece(string c) {
	if(c == "^") {
		return 3;
	}
	else if(c == "*"|| c == "/") {
		return 2;
	}
	else if(c == "+"|| c == "-") {
		return 1;
	}
	else {
		return -1;
	}
}

/***********************************************************
Function: isOperator()
Inputs: Char c
Outputs: Returns bool
General Description: 

This function check to see if the character passed in is an
operator, returns true is it is. False if not
***********************************************************/
bool isOperator(char c) {
	if(c == '+'|| c == '-'|| c == '*' || c == '/' || c == '^') {
		return true; // is an operator
	}
	return false; // not an operator
}

/***********************************************************
Function: isOperand
Inputs: Char c
Outputs: Returns bool
General Description: 

This function checks to see if the character passed in is
between 'A' and 'Z', no lowercase valeus, returns true it is,
false if not. 
***********************************************************/
bool isOperand(char c) {
	if(c >= 'A'&& c <= 'Z') {
		return true;
	}
	return false;
}