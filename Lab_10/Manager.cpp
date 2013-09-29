/*
 * Name: Aleksander Eskilson, aeskilson@ku.edu
 * File: Manager.cpp
 * Created: 4/23/13
 * Modified: 4/8/13
 * Description: Implementation for the Manager template class.
 * Implementation for global visit methods included at the bottom.
 */

//Default constructor
template<typename KeyType, typename ItemType>
Manager<KeyType, ItemType>::Manager() {
}

//Memory stack allocated, empty descructor
template<typename KeyType, typename ItemType>
Manager<KeyType, ItemType>::~Manager() {
}

/*
 * Precondition: Caller provides c string filename. Binary Search Tree
 * allocated as member variable with KeyType and ItemType specified at
 * instantiation of Manager object in caller. 
 * Postcondition: File contents parsed and commands executed. Pertinent
 * information printed. 
 */
template<typename KeyType, typename ItemType>
void Manager<KeyType, ItemType>::process(const char* fileName) {
    //Open file
    ifstream in;
    in.open(fileName);
    //Holder variable for keys appearing in file
    KeyType key;

    //Parse commands and contents
    string line;
    while(in >> line) {
        //Add - adds entry to BST
        if(line == "add") {
            ItemType item;
            in >> item;
            cout << "Performing operation: " << line << " " << item << endl;
            binTree.add(item);
        //Contains - boolean check for entry associated with key
        } else if(line == "contains") {
            cout << "Performing operation: " << line << endl;
            in >> key;
            if(binTree.contains(key))
                cout << "Tree does contain " << key << endl;
            else
                cout << "Tree does not contain " << key << endl;
        //getEntry - print entry associated with key
        } else if(line == "getEntry") {
            in >> key;
            cout << "Performing operation: " << line << " for " << key << endl;
            try {
                cout << binTree.getEntry(key) << endl;
            } catch(NotFoundException e) {
                cout << "Error " << e.what() << endl;
            }
        //getHeight - integer for BST's height
        } else if(line == "getHeight") {
            cout << "Performing operation: " << line << endl;
            cout << "The height is " << binTree.getHeight() << endl;
        //getNumberOfNodes - integer for node number in BST
        } else if(line == "getNumberOfNodes") {
            cout << "Performing operation: " << line << endl;
            cout << "The number of nodes is " << binTree.getNumberOfNodes() << endl;
        //isEmpty - boolean check for any number of nodes
        } else if(line == "isEmpty") {
            cout << "Performing operation: " << line << endl;
            if(binTree.isEmpty())
                cout << "The tree is empty" << endl;
            else
                cout << "The tree is not empty" << endl;
        //remove - delete node associated with key
        } else if(line == "remove") {
            in >> key;
            cout << "Performing operation: " << line << " " << key << endl;
            try {
                binTree.remove(key);
            } catch(NotFoundException e) {
                cout << "Error " << e.what() << endl;
            }
        //inorder - perform Inorder Traverse, print contents
        } else if(line == "inorder") {
            cout << "Performing operation: " << line << endl;
            binTree.inorderTraverse(visit);
        //preorder - perform Preorder Traverse, print contents
        } else if(line == "preorder") {
            cout << "Performing operation: " << line << endl;
            binTree.preorderTraverse(visit);
        //postorder - perform Postorder Traverse, print contents
        } else if(line == "postorder") {
            cout << "Performing operation: " << line << endl;
            binTree.postorderTraverse(visit);
        } else 
            cout << "Command not recognized" << endl;
    }
}

//Globally defined visit functions
//Print string type
void visit(string& item) {
    cout << item << endl;
}

//Print Event type
void visit(Event& ev) {
    cout << ev << endl;
}
