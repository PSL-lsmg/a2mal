/*
 *	List.cpp
 *	
 *	Class Description: List data collection ADT.
 *	Class Invariant: Data collection witht he following characteristics:
 *					- Each element is unique.
 *					- The elements are always ordered in the ascending order based on the care card number
 *					  even when a new element is added.
 *
 *
 *	Last odified on: May 2017
 *	Author: Jun Wei(Jason) Li
 */
/*
#include <iostream>
#include "List.h"
#include <string>


// Default Constructor
// Description: Create a list with zero element.
List::List()
{
	elementCount = 0;
	capacity = MAX_ELEMENTS;
}

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const
{
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.  
bool List::insert(const Patient& newElement)	//COMPLETED
{
	//check if already existed based on the care card of the patient
	for(int i = 0; i < elementCount; i++)
	{
		if(elements[i] == newElement || elementCount >= MAX_ELEMENTS)
		{
			return false;
		}
	}
	//find the optimal place to put the patient
	int position = elementCount;
	for(int j = 0; j < elementCount; j++)
	{
		if(elements[j] > newElement)
		{
			position = j;
			break;
		}
	}
	//shift the remaining elements to the right
	for(int k = elementCount; k > position; k--)
	{
		elements[k] = elements[k-1];
	}
	elements[position] = newElement;
	elementCount++;
	return true;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient& toBeRemoved)	//COMPLETED
{
	int position;
	bool removed = false;
	//Search for the Patient
	for(int i = 0 ; i < capacity; i++)
	{
		if(elements[i] == toBeRemoved)
		{
			position = i;
			removed = true;
		}
	}
	//Shift the other patients to the left of the list
	if(removed)
	{
		for(int j = position; j < elementCount - 1; j++)
		{
			elements[j] = elements[j+1];
		}
		elementCount--;
	}
	return removed;
}

// Description: Remove all elements.
void List::removeAll()	//COMPLETED
{
	elementCount = 0;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target)
{
	for(int i = 0; i < elementCount; i++)
	{
		if(elements[i] == target)
		{
			return &elements[i];
		}
	}
	return NULL;
}

// Description: Prints all elements stored in List.
void List::printList()
{
	//print the list
	for(int f = 0; f < elementCount; f++)
	{
		elements[f].printPatient();
	}
}
*/

