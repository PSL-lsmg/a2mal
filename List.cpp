/*
 * List.cpp
 * 
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accommodate 
 *                     new insertion. This is done unbeknown to the client code.
 *
 * Last modified on: May 2017
 * Author: AL
 */

#pragma once
#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

using namespace std;


// We must add at least 1 constructor and a destructor
	
// Default constructor
List::List()
{
	//initialize Patient arrays
	for(int i = 0; i <= 9; i++ )
	{
		mainArray[i] = new Patient[initialSize];
		elementTracker[i] = initialSize;
	}

	// Patient a;
	// mainArray[0][0] = a;
	// cout << mainArray[0][0].getName() << endl;

}

List::List(const List& lst)
{

}

List::~List()
{

}

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const
{
	return 0;
}

// Description: Insert an element.
//              When "this" List is full, its data structure is expanded to accommodate 
//              a new element. This is done unbeknown to the client code.
//              If the insertion is successful, true is returned otherwise, false is returned.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.	
bool List::insert(const Patient& newElement)
{

	return false;
}

// Description: Remove an element. 
//              If the removal is successful, true is returned otherwise, false is returned.
// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved)
{
	return false;
}
	
// Description: Remove all elements.
void List::removeAll()
{

}
   
// Description: Search for target element and returns a pointer to it if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target)
{
	return NULL;
}
   
// Description: Prints all n elements stored in List in sort order and does so in O(n).
void List::printList()
{

}
	
// *** End of Public Interface ***