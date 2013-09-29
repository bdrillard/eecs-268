/*
 * Name: Aleksander Eskilson, aeskilson@ku.edu
 * File: Manager.h
 * Created: 4/23/13
 * Modified: 5/8/13
 * Description: Definition of the Manager template class. Written as
 * template so that Manager may match data types of its privately
 * stack allocated BST. Incudes global definitions of the visit functions.
 */
#ifndef _MNGR
#define _MNGR

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
#include "Event.h"
using namespace std;

template<typename KeyType, typename ItemType>
class Manager {
    private:
        BinarySearchTree<KeyType, ItemType> binTree;
    public:
        Manager();
        ~Manager();
        //Parsing and printing method for text files
        void process(const char* fileName);
};

//Globally exposed visit functions
void visit(string& item);
void visit(Event& ev);

#include "Manager.cpp"
#endif
