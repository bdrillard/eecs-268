// main.cpp
// Simple test program to illustrate List usage.

// 1. After you have implemented "LinkedList::setEntry",
//    compile and run this program, making sure you
//    understand the output.
// 2. Then implement the copy constructor, uncomment
//    "fakeModifyList" as well as the call to it from
//    main. Then compile and run the program, making
//    sure you understand the new output.

#include <iostream>

#include "LinkedList.h"

void buildList(LinkedList<std::string>& strList)
{
	strList.insert(1, "xyz");
	strList.insert(1, "qrstuv");
	strList.insert(3, "abc");
	strList.insert(2, "qwerty");
}

void fakeModifyList(LinkedList<std::string> modList)
{
	modList.setEntry(3, "This-was-replaced");
	modList.remove(1);
	modList.remove(1);
}

void modifyList(LinkedList<std::string>& modList)
{
	modList.setEntry(3, "This-was-replaced");
	modList.remove(1);
	modList.remove(1);
}

void printList(const LinkedList<std::string>& printList)
{
	for (int i=1 ; i<=printList.getLength() ; i++)
		std::cout << printList.getEntry(i) << std::endl;
}

int main()
{
	LinkedList<std::string> mainList;
	buildList(mainList);
	printList(mainList);
	fakeModifyList(mainList);
	printList(mainList);
	modifyList(mainList);
	printList(mainList);
	return 0;
}
