/*
 * Name: Aleksander Eskilson, aeskilson@ku.edu
 * File: BinaryNode.cpp
 * Created: 4/23/13
 * Modified: 5/8/13
 * Description: Implementation of BinaryNode template class used as wrappers
 * for Binary Search Tree. 
 */
//Default constructor, set params to null
template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(): leftChildPtr(NULL), rightChildPtr(NULL) {
}

//Constructor with data
template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem): leftChildPtr(NULL), rightChildPtr(NULL) {
    setItem(anItem);
}

//Full constructor, data and child pointers
template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr) {
    setItem(anItem);
    setLeftChildPtr(leftPtr);
    setRightChildPtr(rightPtr);
}

//Setter for item
template<typename ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

//Getter for item
template<typename ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
    return item;
}

//Check if node is leaf (has no children)
template<typename ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
    return (getLeftChildPtr() == NULL && getRightChildPtr() == NULL);
}

//Getter for left child pointer
template<typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}

//Getter for right child pointer
template<typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}

//Setter for left child pointer
template<typename ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr) {
    leftChildPtr = leftPtr;
}

//Setter for right child pointer
template<typename ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr) {
    rightChildPtr = rightPtr;
}
