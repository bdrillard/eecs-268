// main.c++ - test out a Stack

#include <iostream>
#include <string>
#include "Manager.h"

#ifdef USE_ARRAY_BASED
#include "ArrayStack.h"
#define Stack ArrayStack
#else
#include "LinkedStack.h"
#define Stack LinkedStack
#endif

int main(int argc, char* argv[]) {
	if(argc != 2)
		std::cout << "Incorrect number of arguments, usage is <main> <input>" << std::endl;
	else {
		//Create manager, input stream, run
		Manager mgr;
		std::ifstream input;
		input.open(argv[1]);
		mgr.start(input);
		input.close();
	}
	return 0;
}
