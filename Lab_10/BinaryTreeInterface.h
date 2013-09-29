//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 15-1.
 @file BinaryTreeInterface.h */

#ifndef _BINARY_TREE_INTERFACE
#define _BINARY_TREE_INTERFACE

template<typename ItemType>
class BinaryTreeInterface
{
public:
   /** Tests whether this binary tree is empty.
    @return True if the binary tree is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Gets the height of this binary tree.
    @return The height of the binary tree. */
   virtual int getHeight() const = 0;
   
   /** Gets the number of nodes in this binary tree.
    @return The number of nodes in the binary tree. */
   virtual int getNumberOfNodes() const = 0;
   
   /** Traverses this binary tree in preorder (inorder, postorder) and
       calls the function visit once for each node.
    @param visit A client-defined function that performs an operation on
       or with the data in each visited node. */
   virtual void preorderTraverse(void visit(ItemType&)) const = 0;
   virtual void inorderTraverse(void visit(ItemType&)) const = 0;
   virtual void postorderTraverse(void visit(ItemType&)) const = 0;
}; // end BinaryTreeInterface
#endif
