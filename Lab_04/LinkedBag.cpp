//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <iostream>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(NULL), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
   itemCount = aBag->itemCount;
   Node<ItemType>* origChainPtr = aBag->headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == NULL)
      headPtr = NULL;  // Original bag is empty; so is copy
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr; // Last-node pointer
      while (origChainPtr != NULL)
      {
         origChainPtr = origChainPtr ->getNext(); // Advance pointer
         
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
      } // end while
      
      newChainPtr->setNext(NULL); // Flag end of new chain
   } // end if
} // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(headPtr);  // New node points to chain
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

   headPtr = nextNodePtr;          // New node is now first node
   itemCount++;
   
   return true;
}  // end add

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != NULL) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != NULL);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(NULL);
      delete nodeToDeletePtr;
      nodeToDeletePtr = NULL;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != NULL)
   {
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(NULL);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is NULL; nodeToDeletePtr is NULL
   
	itemCount = 0;
}  // end clear


template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != NULL) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != NULL);
}  // end contains

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != NULL))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

/*
 * Precondition: a bag has been initialized and populated with values
 * Postcondition: an item will have its value passed to the manager,
 * and its entry will be removed from the bag
 */
template<class ItemType>
bool LinkedBag<ItemType>::retrieve(ItemType& item) {
	//If the bag is already empty
	if(isEmpty()) 
		return false;
	//If there are items to remove
	else {
		//Set item value to a copy of the first entry's value
		item = (headPtr -> getItem());
		remove(item);
		return true;
	}
}

/*
 * Precondition: a bag has been initialized and populated with values
 * Postcondition: all entries of an @param item will be loaded to the front
 * of the bag
 */
template<class ItemType>
void LinkedBag<ItemType>::gather(const ItemType& item) {
	//Temporary variables to travel accross bag and swap entries
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* tempPtr = curPtr -> getNext();
	//If the bag has our item
	if(contains(item)) {	
		//Pass across bag until end
		while(curPtr -> getNext() != NULL) {
			if((curPtr -> getNext()) -> getItem() == item) {
				//Set @var curPtr to entry immediately after @param item
				curPtr -> setNext(tempPtr -> getNext());
				//Have @param item point to the first entry of the bag
				tempPtr -> setNext(headPtr);
				//Set @var headPtr to item, item becomes first entry
				headPtr = tempPtr;				
				curPtr = curPtr -> getNext();
				tempPtr = curPtr -> getNext();
		
			} else {
				//Move pointers to next entry of the bag
				curPtr = curPtr -> getNext();
				tempPtr = curPtr -> getNext();
			}
		}

	} else 
		std::cout << "The item is not in the bag." << std::endl;	
}

