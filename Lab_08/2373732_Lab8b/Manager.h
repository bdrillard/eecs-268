/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File: Manager.h
 * Date: 3/25/13
 * Modified: 4/6/13
 * Description: This file contains the definition of the Manager class, that
 * will validate and evaluate postfix expressions
 */
#include "LinkedStack.h"
#include "LinkedList.h"
#include "PrecondViolatedExcep.h"
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>

class Manager {
	private: 
		//Data types to be used
		LinkedStack<double> doubleStack;
		LinkedList<std::string> valueList;
		//File reading and validate/evaluation
		void parse(std::ifstream& input);
		double convert(std::string input) throw(PrecondViolatedExcep);
	public: 
		Manager();
		void start(std::ifstream& input);
};
