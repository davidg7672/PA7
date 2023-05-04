/*
David Sosa Vidal
CPSC 122
Professor Jacob Shea
Programming Assignment 7, Stacks and Inheritance
PA7 Function File
*/

#include "PA7.h"

/***********************************************************
Function: execution
Inputs: Nothing
Outputs: Returns nothing
General Description: 

This function comptues everything, acts as the driver funciton, 
it read,comptues and does everything.
***********************************************************/
void execution(void) {
    ifstream inputFile;
    string fileName = "input.txt", expression, trash, newExpression, postfixResult;
    char value;
    int numberValue;
    vector<int> numberValueVector;
    vector<char> valueVector;
    vector<string> expressionVector;
    Calculator cal;

    // Opening files and checking to see if they are open
    inputFile.open(fileName);
    inputFileOpen(inputFile);

    while(!inputFile.eof()) {
        inputFile >> value;

        if(value != '#') {
            inputFile >> numberValue;
            valueVector.push_back(value);
            numberValueVector.push_back(numberValue);

            continue;
        }

        getline(inputFile, trash); // clears the buffer

        while(true) {
            getline(inputFile, expression);

            if(expression != "#") {
                expressionVector.push_back(expression);
                continue;
            }
            break;
        }
    }

    // Closing the inputFile
    inputFile.close();


    for(int i = 0; i < expressionVector.size(); i++) {
        newExpression = cal.convertInfixToPostfix(expressionVector.at(i));
        postfixResult = cal.evaluatePostfix(newExpression, valueVector, numberValueVector);

        cout << endl << "Infix Expression: " << expressionVector.at(i) << endl;
		cout << "Postfix Expression Equivalent: " << newExpression << endl;
		cout << "Expression Value After Postfix Evaluation: " << stoi(postfixResult) << endl;
    }
}

/***********************************************************
Function: inputFileOpen()
Inputs: Ifstream variable
Outputs: Returns nothing
General Description: 

This function will check to see if there is a file to use, 
if not, then it will exit, because there is not point to,
running a program with no proper input
***********************************************************/
void inputFileOpen(ifstream& inputFile) {
    if(!inputFile.is_open()) {
        printf("Couldn't find file\n");
        exit(-1);
    }
}