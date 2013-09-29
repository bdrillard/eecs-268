//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */
 
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "NotFoundException.h"

template<typename KeyType, typename ItemType>
class BinarySearchTree : public BinaryTreeInterface<ItemType>
{
private:
   BinaryNode<ItemType>* rootPtr;
   
protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Helper methods for public methods.
   //------------------------------------------------------------
   int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
   int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
   BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const KeyType target, bool& success);
   BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodeToDeletePtr);
   BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodeToDeletePtr, ItemType& inorderSucessor);
   bool isLeaf(BinaryNode<ItemType>* nodeToDeletePtr);
   void destroyTree(BinaryNode<ItemType>* subTreePtr);
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, const KeyType& target) const;
   BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
   void inorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const;
   void preorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const;
   void postorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const;
   BinaryNode<ItemType>* inorderInsertion(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree(); // creates an empty BST
   BinarySearchTree(const BinarySearchTree<KeyType,ItemType>& tree);
   virtual ~BinarySearchTree();
   
   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const;
   int getHeight() const;
   int getNumberOfNodes() const;
   void add(const ItemType& newEntry);
   void remove(const KeyType& aKey) throw(NotFoundException);
   ItemType getEntry(const KeyType& aKey) const throw(NotFoundException);
   bool contains(const KeyType& aKey) const;
   
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse(void visit(ItemType&)) const;
   void inorderTraverse(void visit(ItemType&)) const;
   void postorderTraverse(void visit(ItemType&)) const;
   
   //------------------------------------------------------------   
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif
