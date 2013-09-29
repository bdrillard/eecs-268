/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: main.cpp
 * Date Created: 2/24/13
 * Last Modified: 2/24/13
 * Description: This file contains the implementation of
 * a string bag. It invokes the manager class to input and
 * access data from the bag
 */
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
	if(argc == 2) {
		//Open file
		std::ifstream input;
		input.open(argv[1]);
		
		//Pass file for reading, begin dialogue
		Manager mgr(input);
		mgr.start();

		input.close();
	} else
		std::cout << "Incorrect number of arguments given, please provide the name of an input file." << std::endl;
	return 0;
}
