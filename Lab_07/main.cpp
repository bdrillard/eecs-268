/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File name: main.cpp
 * Date Created: 03/11/13
 * Last Modified: 03/20/13
 * Description: This file implements the Manager wrapper for the stack ADT.
 */
#include <iostream>
#include <string>
#include "Manager.h"
/*
void tryStack()
{
	ArrayStack<std::string> stk;
	stk.push("fall");
	stk.push("had a great ");
	stk.push("Humpty Dumpty ");
	while (!stk.isEmpty())
	{
		std::string x = stk.peek();
		std::cout << x;
		stk.pop();
	}
	std::cout << '\n';
}
*/
int main(int argc, char* argv[])
{
	//tryStack();
	//Ensure correct args
	if(argc != 2 )
		cout << "Incorrect number of arguments. Usage is './main <string>'" << endl;
	else {
		Manager mgr;
		mgr.start(argv[1]);
	}
	return 0;
}
