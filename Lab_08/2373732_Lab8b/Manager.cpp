/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File: Manager.cpp
 * Date: 3/18/13
 * Modified: 4/6/13
 * Description: This program contains the implementation for the Manager object
 * that provides methods for validating and evaluating postfix expressions that
 * are given numerical values from a file of variable names and value pairs.
 */
#include "Manager.h"

//Default constructor
Manager::Manager() {
}

/*
 * Precond: Manager object has been created, ifstream for @param input exists
 * Postcond: User will be asked for input of postfix expressions to evaluate until
 * sentinel value is given. Prints the expression as evaluated against a parsed
 * table of values gathered from @param input if all input is valid. Handles error
 * in case that input is invalid.
 */
void Manager::start(std::ifstream& input) {
	//Parse file of values into list
	parse(input);

	std::string userExpression;
	double candidate;
	//Collect expressions from user until sentinel is passed
	do {
		std::cout << "Enter a string: ";
		std::cin >> userExpression;
		if(userExpression != "#") {	
			try {
				//Validate and evaluate
				candidate = convert(userExpression);
			//Catch all error instances, display more information, get a new string
			} catch(PrecondViolatedExcep pe) {
				std::cout << "This string is invalid: " << pe.what() << std::endl;
				continue;
			}
			//Display evaluated string
			std::cout << "This is a valid string that evaluates to: " << candidate << std::endl;
		}
	} while(userExpression != "#");
}

/*
 * Precond: Manager object has been created, ifstream for @param input exists, @var valueList
 * has been declared
 * Postcond: a list will be filled with space delimeted variable_value pairs ordered by ASCII value
 * of the variable letter
 */
void Manager::parse(std::ifstream& input) {
	std::string letter;
	std::string number;
	std::string insertion;

	//Create head to list
	input >> letter;
	input >> number;
	insertion = letter + " " + number;
	valueList.insert(1, insertion);
	//Continue reading, add relative to current head
	input >> letter;
	input >> number;
	while(!input.eof()) {
		insertion = letter + " " + number;
		//Search for index to add at, when added, move to next variable_value pair
		for(int i = 1; i <= valueList.getLength(); i++) {
			if(insertion < valueList.getEntry(i)) {
				valueList.insert(i, insertion);
				break;
			}
			//If not less than anything, add to end
			if(i == valueList.getLength()) {
				valueList.insert(i + 1, insertion);
				break;
			}
		}
		//Collect next line
		input >> letter;
		input >> number;
		
	}
	//Display variable_value pairs
	for(int i = 1; i <= valueList.getLength(); i++) {
		std::cout << valueList.getEntry(i) << std::endl;
	}
}

/*
 * Precond: Manager object has been created, @param input gathered from caller, @var doubleStack
 * has been declared, @var valueList has been declared and populated.
 * Postcond: Validates and evaluates a given prefix expression by parsing expression and matching
 * variables in the expression against the list of variable_value pairs. Throws @excep 
 * PrecondViolatedExcep if the expression and its variables are ever in fault 
 */
double Manager::convert(std::string input) throw(PrecondViolatedExcep) {
	//Holder vars for expression and output
	double operand1;
	double operand2;
	double output;

	//Traverse the length of the expression
	for(int i = 0; i < input.length(); i++) {
		//If operator is encountered
		if(input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '*' || input.at(i) == '/') {
			//Double stack check to ensure correct number of operands exist
			if(doubleStack.isEmpty())
				throw PrecondViolatedExcep("Missing operands");
			//Assign operands to holder vars in correct order for evaluation
			operand2 = doubleStack.peek();
			doubleStack.pop();
			if(doubleStack.isEmpty())
				throw PrecondViolatedExcep("Missing operands");
			operand1 = doubleStack.peek();
			doubleStack.pop();
			
			//Apply correct operation, push value
			switch(input.at(i)) {
				case '+':
					doubleStack.push(operand1 + operand2);
					break;
				case '-':
					doubleStack.push(operand1 - operand2);
					break;
				case '*':
					doubleStack.push(operand1 * operand2);
					break;
				case '/':
					//Catch division by zero
					if(operand2 == 0)
						throw PrecondViolatedExcep("Division by zero");
					doubleStack.push(operand1 / operand2);
					break;	
			}
		}
		//Add value to stack
		else if(isalpha(input.at(i))) {
			//Helper var to ensure we throw error only when necessary
			bool notFound = true;
			//Match operand of expression with variable name in list
			for(int j = 1; j <= valueList.getLength(); j++) {
				//If corresponding variable is found, push its accompanying value onto stack
				//Set boolean to false so that error is not thrown on loop conclusion
				if(input.at(i) == (valueList.getEntry(j)).at(0)) {
					doubleStack.push(atof(((valueList.getEntry(j)).substr(2)).c_str()));
					notFound = false;
					break;
				}
			}
			//If whole expression was scanned, and corresonding variable was not found, throw error
			if(notFound)
				throw PrecondViolatedExcep("Undefined variable: " + input.substr(i, 1));
		}
		//Character other than alpha or operand was used
		else
			throw PrecondViolatedExcep("Illegal character: " + input.substr(i, 1));
				
	}
	//Gather top value remaining after parsing
	output = doubleStack.peek();
	doubleStack.pop();
	//If values remain, not enough operations were performed, throw error, clear whole
	//stack, and abort to caller for next expression
	if(!doubleStack.isEmpty()) {
		while(!doubleStack.isEmpty())
			doubleStack.pop();
		throw PrecondViolatedExcep("Missing one or more operators");
	}
	return output;
}
/*
std::string Manager::convert(std::string input) throw(PrecondViolatedExcep) {
	//Holder variables for parsing and output
	std::string builder = "";
	std::string output;

	//Parse over length of string, convert suffix string to infix string
	for(int i = 0; i < input.length(); i++) {
		//Parse operands
		if(input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '*' || input.at(i) == '/') {
			//Double error checks to make sure a binary operator has two operands on the stack
			//If in error, reset stack, abort instance
			if(charStack.isEmpty()) {
				throw PrecondViolatedExcep("Missing operands");
			}
			//Construct expression in correct order
			builder = input.substr(i, 1) + charStack.peek();
			charStack.pop();
			if(charStack.isEmpty()) {
				throw PrecondViolatedExcep("Missing operands");
			}
			builder = charStack.peek() + builder;
			charStack.pop();
			//Encase in parens, push to stack, reset builder to push-parse next expression
			builder = "(" + builder + ")";
			charStack.push(builder);
			builder = "";
		}
		//Push letters
		else if(isalpha(input.at(i)))  
			charStack.push(input.substr(i, 1));
		//Reject all other characters
		else
			throw PrecondViolatedExcep("Illegal character: " + input.substr(i, 1));
	}

	//Gather output, check that no other operand expressions remain
	output = charStack.peek();
	charStack.pop();
	if(!charStack.isEmpty()) {
		//Reset stack, abort instance
		while(!charStack.isEmpty()) 
			charStack.pop();
		throw PrecondViolatedExcep("Missing one or more operators");
	}
	//Return substring with redundant outermost parens removed
	return output.substr(1, output.length() - 2);
}*/
