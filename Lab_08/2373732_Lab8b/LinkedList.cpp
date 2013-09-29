// The copy constructor and the method setEntry are left as exercises.
// ===================================================================

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include <cassert>
  
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(NULL), itemCount(0)
{
}  // end default constructor

//Copy Constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {
	//Copy data from parameter
	itemCount = aList.itemCount;
	//Create pointer to traverse original list
	Node<ItemType>* origChainPtr = aList.headPtr;
	
	//If list to copy is empty
	if(origChainPtr == NULL)
		headPtr = NULL;
	//Scan down list, copy
	else {
		//Create new head pointer and first node for copy list, give it first item of original
		headPtr = new Node<ItemType>();
		headPtr -> setItem(origChainPtr -> getItem());

		//Create pointer to build new list
		Node<ItemType>* newChainPtr = headPtr;
		//Traverse until last node
		while((origChainPtr -> getNext()) != NULL) {
			//Increment across old list
			origChainPtr = origChainPtr -> getNext();
			//Get item from old list, add it to a new node for new list
			ItemType nextItem = origChainPtr -> getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			//Add new node to new list
			newChainPtr -> setNext(newNodePtr);
			newChainPtr = newChainPtr -> getNext();
		}
		//Set last nodes nextPtr to NULL
		newChainPtr -> setNext(NULL);
	}	
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
void LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);  
      
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr); 
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
         
         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext()); 
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if
   else
	throw PrecondViolatedExcep("Unable to insert at given position");
}  // end insert

template<class ItemType>
void LinkedList<ItemType>::remove(int position) throw(PrecondViolatedExcep)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = NULL;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      // Return node to system
      curPtr->setNext(NULL);
      delete curPtr;
      curPtr = NULL;
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   else
	throw PrecondViolatedExcep("Unable to remove at the given index");
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

//Change entry of a position to a new entry
template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw (PrecondViolatedExcep) {
        //Check error condition
	bool ableToGet = (position >= 1) && (position <= itemCount);
        if(ableToGet) {
		//Perform change
                Node<ItemType>* nodePtr = getNodeAt(position);
                nodePtr -> setItem(newEntry);
        }
        else {
                string message = "setEntry() called with an empty list or ";
                message = message + "invalid position.";
                throw(PrecondViolatedExcep(message));
        }

} 

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}  // end getNodeAt
//  End of implementation file.
