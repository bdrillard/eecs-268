/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Manager.h
 * Date Created: 03/11/13
 * Last Modified: 03/20/13
 * Description: This file contains the class definition for the Manager wrapper object that 
 * provides access to the String Stack. Its methods parse a given string of characters and
 * digits into a string of characters separated by commas and parens.
 */
#include "ArrayStack.h"
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Manager {
	private:
		//Stack of strings
		ArrayStack<string> charStack;
		//Private helper method to parse string
		string parser(string input, int choice) throw(overflow_error, underflow_error);
	public:
		Manager();
		//Interface method
		void start(string input);
};
