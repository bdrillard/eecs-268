/*
 * Name: Aleksander Eskilson, aeskilson@ku.edu
 * File: main2.cpp
 * Created: 4/29/13
 * Modified: 5/8/13
 * Description: Second driver program for BST ADT. Uses Manager template
 * class to implement different BSTs.
 */
#include <iostream>
#include <string>
#include "Manager.h"
#include "Event.h"
using namespace std;

int main(int argc, char** argv) {
    if(argc != 3)
        cout << "Incorrect number of arguments, provide two input file names" << endl;
    else {
        //History Manager
        Manager<int, Event> histMgr;
        cout << "Starting history manager:" << endl;
        histMgr.process(argv[1]);

        //String Manager
        Manager<string, string> stringMgr;
        cout << endl << "Starting string manager:" << endl;
        stringMgr.process(argv[2]);
    }
}
