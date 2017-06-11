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
	mainArray = new Patient*[TEN];

	//initialize Patient arrays
	for(int i = 0; i < TEN; i++ )
	{
		mainArray[i] = new Patient[INITIALSIZE];
		elementTracker[i] = 0;
		capacityTracker[i] = INITIALSIZE;
	}

	// Patient a;
	// mainArray[0][1] = a;
	// cout << mainArray[0][1].getName() << endl;
	// cout << sizeof(mainArray[0]) << endl;
}

List::List(const List& lst)
{
	mainArray = new Patient*[TEN];

}

List::~List()
{
    for (int x = 0; x< TEN; x++)
    {
        delete[] mainArray[x];
    }
    delete[] mainArray;
    std::cout<< "Destructor called." << std::endl;
}

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const
{
	int total = 0;
	for(int i = 0; i < TEN; i++)
	{
		total += elementTracker[i];
	}
	return total;
}

// Description: Insert an element.
//              When "this" List is full, its data structure is expanded to accommodate 
//              a new element. This is done unbeknown to the client code.
//              If the insertion is successful, true is returned otherwise, false is returned.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.	
bool List::insert(const Patient& newElement)
{
	int digit = newElement.getCareCard().at(0) - '0';
	//check if the patient already exist in the system
	for(int j = 0; j < elementTracker[digit]; j++)
	{
		if(mainArray[digit][j] == newElement)
		{
			return false;
		}
	}
	//Check if expansion needed
	if(elementTracker[digit] >= capacityTracker[digit])
	{
		cout << "[DEBUGGING]---new array created..." ;
		Patient* expandedList = new Patient[capacityTracker[digit]*2];
		capacityTracker[digit] = capacityTracker[digit] * 2;
		for(int i = 0; i < elementTracker[digit]; i++)
		{
			expandedList[i] = mainArray[digit][i];
		}
		//delete the old array
		delete [] mainArray[digit];
		cout << "old array deleted... new capacity = " << capacityTracker[digit] << endl;
		mainArray[digit] = expandedList;
	}
	//find the optimal place to insert the patient
	int position = elementTracker[digit];
	for(int k = 0; k < elementTracker[digit]; k++)
	{
		if(mainArray[digit][k] > newElement)
		{
			position = k;
			break;
		}
	}
	//insert and shift the patient to the right
	for(int l = elementTracker[digit]; l > position; l--)
	{
		mainArray[digit][l] = mainArray[digit][l-1];
	}
	mainArray[digit][elementTracker[digit]] = newElement;
	elementTracker[digit]++;
	return true;
}

// Description: Remove an element. 
//              If the removal is successful, true is returned otherwise, false is returned.
// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved)
{
	int position;
	bool removed = false;
	int digit = toBeRemoved.getCareCard().at(0) - '0';
	for(int i = 0; i < elementTracker[digit]; i++)
	{
		if(mainArray[digit][i] == toBeRemoved)
		{
			position = i;
			removed = true;
		}
	}

	//Shift the other patients to the left of the list
	if(removed)
	{
		for(int j = position; j < elementTracker[digit] - 1; j++)
		{
			mainArray[digit][j] = mainArray[digit][j+1];
		}
		elementTracker[digit]--;
	}
	return removed;
}
	
// Description: Remove all elements.
void List::removeAll()
{
	for(int i = 0; i < TEN; i++)
	{
		elementTracker[i] = 0;
	}
}
   
// Description: Search for target element and returns a pointer to it if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target)
{
	int digit = target.getCareCard().at(0) - '0';
	for(int i = 0; i < elementTracker[digit]; i++)
	{
		if(mainArray[digit][i] == target)
		{
			return &mainArray[digit][i];
		}

	}
	return NULL;
}
   
// Description: Prints all n elements stored in List in sort order and does so in O(n).
void List::printList()
{
	for(int i = 0; i < TEN; i++)
	{
		for(int j = 0; j < elementTracker[i]; j++)
		{
			mainArray[i][j].printPatient();
		}
	}
}
	
// *** End of Public Interface ***
