/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Manager.cpp
 * Date Created: 03/11/13
 * Last Modified: 03/20/13
 * Description: This file contains the implementation for the Manager wrapper class that 
 * provides an interface for the string stack. Its methods parse a string of characters
 * and digits into a nested sequence of characters separated by commas and parens. 
 */
#include "Manager.h"

//Generic constructor
Manager::Manager() {
}

/*
 * Primary interface
 * Precondition: a Manager object has been declared and a string @param input has been passed
 * Postcondition: user choice of parsing order gathered and @param input string parsed by helper
 * @method Manager::parser. The result is printed to the screen. Method catches @excep
 * overflow_error in which additional strings remain on stack post-parsing. 
 */
void Manager::start(string input) {
	int choice;
	//Gather user choice, ensure correct input
	do {
		cout << "Parse the string in forward or reverse order?" << endl;
		cout << "Input '0' for forward\nInput '1' for reverse\nInput '-1' to quit:" << endl;
		cin >> choice;
	} while(choice != 0 && choice != 1 && choice != -1);
	//If you're a quitter, return
	if(choice == -1)
		return;
	//Begin parsing, print result to screen
	cout << parser(input, choice) << endl;
}

/*
 * Helper method, parses input into singular string
 * Precondition: a Manager object has been declared and the @method Manager::start method calls
 * this helper, passing both the input string and the user parsing choice
 * Postcondition: a string @var output will be returned that implements the correct parsing rules by a given
 * choice. Throw errors @excep overflow_error if items remain on the stack post-parsing or @excep underflow_error
 * if the method attempts to remove more items from the stack than exist. In such a case, catch the exception and 
 * continue as though the correct number were called for removal.
 */
string Manager::parser(string input, int choice) throw(overflow_error, underflow_error) {
	//Helper string, used to gather a set of strings by a parsed number
	string builder = "";
	string output;
	//Scan across the entirety of the string, distinguish digits from nondigits
	for(int i = 0; i < input.length(); i++) {
		//If character is a digit, gather items from the stack, apply correct commas and parens
		if(isdigit(input.at(i))) {
			string temp = input.substr(i, 1);
			//Case in which characters are followed by 0
			if(atoi(temp.c_str()) == 0) {
				//Pop the whole stack, push a parenthesized empty builder at the end
				while(!charStack.isEmpty()) 
					charStack.pop();
			} else {
				for(int j = 0; j < atoi(temp.c_str()); j++) {
					//Attempt to pop items from the stack
					try {
						if(charStack.isEmpty())
							throw underflow_error("Stack Underflow - Too many items were attempted to be removed from stack");
						//Forward parsing
						if(choice == 0) {
							if(j == 0)
								builder = charStack.peek() + builder;
							else
								builder = charStack.peek() + "," + builder;
						//Reverse parsing
						} else {	
							if(j == atoi(temp.c_str()) - 1)
								builder = builder + charStack.peek();
							else
								builder = builder + charStack.peek() + ",";
						}
						//Remove item from stack that was added to builder 
						charStack.pop();
					//Catch underflow_error immediately, report, continue parsing
					} catch(underflow_error ue) {
						cout << "Caught exception in Manager::parser: " << ue.what() << endl;
						break;
					}
				}
			}
			//Enclose builder in correct parens
			builder = "(" + builder + ")";
			charStack.push(builder);
			//Reset builder
			builder = "";
		//When not putting characters together, simply put them on the stack
		} else 
			charStack.push(input.substr(i, 1));			
	}
	//Gather output from stack
	try {
		output = charStack.peek();
		charStack.pop();
		//Error case
		if(!charStack.isEmpty())
			throw overflow_error("Items remain on the stack");
		
	//Error, items remain on the stack post-parsing
	} catch(overflow_error oe) {
		cout << "Caught exception in Manager::start: " << oe.what() << endl;
	}
	
	return output;
}
