/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Manager.cpp
 * Date Created: 2/24/13
 * Last Modified: 2/24/13
 * Description: This file contains the implementation for 
 * the Manager wrapper class
 */
#include "Manager.h"

//Generic constructor
Manager::Manager() {
}

//Parametrized constructor - populates string bag from file
Manager::Manager(std::istream& input) {
	testBag = new LinkedBag<std::string>; 
	
	//Read file, populated bag with strings
	std::string line;
	input >> line;
	while(!input.eof()) {
		testBag -> add(line);
		input >> line;
	}
}

//Destructor - deletes bag, invokes other destructors
Manager::~Manager() {
	delete testBag;
	testBag = NULL;
}

/*
 * Precondition: a string bag has been declared and populated
 * Postcondition: a user will be given the choice of items to
 * gather, those items will be frontloaded to the bag and then
 * retrieved
 */
void Manager::start() {
	std::string choice;
	std::string item;	

	//Gather choice
	std::cout << "What item would you like to gather? ";
	std::cin >> choice;
	testBag -> gather(choice);
	//Output items
	while(testBag -> retrieve(item)) 
		std::cout << item << std::endl;
}
