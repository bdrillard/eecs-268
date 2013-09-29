#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

void print(int& item) {
    std::cout << item << endl;
}

int main(int argc, char** argv) {
    BinarySearchTree<int, int> intTree;
    
    intTree.add(40);
    intTree.add(5);
    intTree.add(10);
    intTree.add(30);
    intTree.add(20);
    intTree.add(35);
    intTree.add(25);
    intTree.add(15);

    cout << intTree.getHeight() << endl;
    cout << intTree.getNumberOfNodes() << endl;

    int item;

    cout << "Inorder\n";
    intTree.inorderTraverse(print);

    cout << "Get entry for 5 " << intTree.getEntry(5) << endl;
    cout << "Get entry for 25 " << intTree.getEntry(25) << endl;
    try {
        cout << "Get entry for 65 " << intTree.getEntry(65) << endl;
    } catch(NotFoundException e) {
        cout << "Error " << e.what() << endl;
    }

    cout << "Does it contain 5 " << intTree.contains(5) << endl;
    cout << "Does it contain 25 " << intTree.contains(25) << endl;
    cout << "Does it contain 65 " << intTree.contains(65) << endl;

    try {
        intTree.remove(45);
    } catch(NotFoundException e) {
        cout << "Error " << e.what() << endl;
    }
    intTree.inorderTraverse(print);
    cout << endl;
    intTree.remove(30);
    intTree.inorderTraverse(print);
    cout << endl;
    intTree.remove(5);
    intTree.inorderTraverse(print);
    cout << endl;
    intTree.remove(15);
    intTree.inorderTraverse(print);
    cout << endl;
    cout << intTree.getHeight() << endl;
    cout << intTree.getNumberOfNodes() << endl;
}
