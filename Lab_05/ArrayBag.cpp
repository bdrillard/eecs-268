//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <cstddef>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY), step(0)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains


template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
   bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf
/*
 * Precondition: a bag has been initialized and populated with integer values
 * Postcondition: an integer from the bag will be assigned to the alias @param item
 * parameter for printing in the calling environment. The index, @var step, will be
 * incremented so that we may iterate through the bag in sequence.
 */
template<class ItemType>
bool ArrayBag<ItemType>::retrieve(ItemType& item) {
	bool isSuccessful;
	
	//Return if bag is empty
	if(isEmpty())
		isSuccessful = false;
	//Pass value of item, remember position in bag, return success
	else {
		item = items[step];
		remove(items[step]);
		isSuccessful =  true;
		step++;	
	}
	
	return isSuccessful;
}

/*
 * Precondition: a bag has been initialized and populated with integer values
 * Postcondition: the index positions of the maximum and minimum values will be
 * found recursively and returned to the calling environment via integer references
 */
template<class ItemType>
void ArrayBag<ItemType>::minMax(int firstIndex, int lastIndex, int& minI, int& maxI) {
	//Separate bag into halves
	int mid = (lastIndex + firstIndex) / 2;

	//Check if the value at the current index is less than the value held
	if(items[firstIndex] < items[minI]) { 
		minI = firstIndex;
	}

	//Check if the value at the current index is greater than the value held
	if(items[firstIndex] > items[maxI]) {
		maxI = firstIndex;
	}

	//Return when the size of the array sliver is 1
	if(firstIndex == lastIndex) 
		return;

	//Recurse on two halves of the array, divide it into continuously smaller portions
	minMax(firstIndex, mid, minI, maxI);
	minMax(mid + 1, lastIndex, minI, maxI);

}

/*
 * Precondition: a bag has been initialized and populated with integer values
 * Postcondition: the maximum and minimum values of the bag will be found and will
 * be placed at the end and front of the bag respectively. 
 */
template<class ItemType>
void ArrayBag<ItemType>::segregate() {
	//Starting indices for max and min
	int min = 0;
	int max = 0;
	
	//Invoke helper to find max and min
	minMax(0, DEFAULT_CAPACITY - 1, min, max);

	//Swap max and min to their correct positions in the array
	int temp;
	temp = items[0];
	items[0] = items[min];
	items[min] = temp;

	temp = items[DEFAULT_CAPACITY - 1];
	items[DEFAULT_CAPACITY - 1] = items[max];
	items[max] = temp;

}

