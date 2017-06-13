/*
 * WICPS.cpp
 *
 * Class Description: A walk-in clinic patient system that allows the receptionlist
 *					  add a new patient, remove a/all patient, search for a patient,
 *					  modify the information of a patient, and print the informations,
 *					  of all patients in ascending order.
 *
 * Last modified on: June 2017
 * Author: Jun Wei(Jason) Li, Priscilla (Fae Yein) Lee
 */

#include <string>
#include <iostream>
#include "Patient.h"
#include "List.h"
#include <stdlib.h>
using namespace std;

// Function prototypes
void addPatient(List&);
void removePatient(List&);
void searchPatient(List&);
void modifyPatient(List&);
void printAllPatients(List&);
void removeAllPatient(List&);
string successOrFail(bool);


// Description: A walk-in clinic patient system that allows the user to add/remove/search/modify/print patients
int main()
{
	cout << "Started" << endl;
	int select;
	bool done = false;
	List patientList;
	while(!done)
	{
		cout << "*****WICPS Main Menu*****" << endl;
		cout << "1)Add patient 2)Remove a patient 3)Search for a patient 4)Modify patient's record 5)Print all 6)Remove all 7)Quit : ";
		cin >> select;
		switch (select)
		{
			case 1: addPatient(patientList);
				break;
			case 2:	removePatient(patientList);
				break;
			case 3: searchPatient(patientList);
				break;
			case 4:	modifyPatient(patientList);
				break;
			case 5:	printAllPatients(patientList);
				break;
			case 6: removeAllPatient(patientList);
				break;
			default: done = true;
		}
		cin.ignore();
	}
	cout << "Ended" << endl;
	return 0;
}

// Description: Add the patient into the system based on the given care card number.
//				User needs to input valid care card number (must be numerical).
void addPatient(List& patientList)
{
	cout << "*****Adding*****" << endl;
	string careCardNum;
	bool valid = false;
	while(!valid)
	{
		cout << "Enter care card number: ";
		cin >> careCardNum;

		//Check for non-digits
		for(unsigned int i = 0; i < careCardNum.length(); i++)
		{
			if(!isdigit(careCardNum[i]))
			{
				cout << "Error: Numbers only" << endl;
				break;
			}
			if(i == careCardNum.length() - 1 )
			{
				valid = true;
			}
		}

		//Check for correct number of digits
		if(careCardNum.length() != 10)
		{
			valid = false;
			cout << "Error: care card must be 10 digits" << endl;
		}
	}
	Patient newPatient(careCardNum);
	bool check = patientList.insert(newPatient);
	cout << "Patient added: " << successOrFail(check) << endl;
}

// Description: Remove the patient from the system based on the given care card number.
//				User needs to input the care card number.
void removePatient(List& patientList)
{
	cout << "*****Removing a patient*****" << endl;
	string careCardNum;
	cout << "Enter care card number: ";
	cin >> careCardNum;
	Patient tempPatient(careCardNum);
	bool check = patientList.remove(tempPatient);
	cout << "Patient removed: " << successOrFail(check) << endl;
}

// Description: Search for the patient in the system based on the given care card number.
//				User needs to input the care card number.
//				If the user input an invalid care card number, it will search for the invalid care
//				card number in the system. E.g. user input "asd", it will search "0000000000".
void searchPatient(List& patientList)
{
	//Search for patient with care card num
	cout << "*****Searching*****" << endl;
	string careCardNum;
    bool valid = false;
    while(!valid)
    {
        cout << "Enter care card number: ";
        cin >> careCardNum;
        
        //Check for non-digits
        for(unsigned int i = 0; i < careCardNum.length(); i++)
        {
            if(!isdigit(careCardNum[i]))
            {
                cout << "Error: Numbers only" << endl;
                break;
            }
            if(i == careCardNum.length() - 1 )
            {
                valid = true;
            }
        }
        
        //Check for correct number of digits
        if(careCardNum.length() != 10)
        {
            valid = false;
            cout << "Error: care card must be 10 digits" << endl;
        }
    }

	Patient tempPatient(careCardNum);
	Patient* foundPatient = patientList.search(tempPatient);
	//check if patient found
	if(foundPatient != NULL)
	{
		cout << "Patient found: ";
		foundPatient->printPatient();
	}
	else
	{
		cout << "Error: Patient not found" << endl;
	}
}

// Description: Modify the patient in the system.
//				User needs to input the care card number and informations that need to be modified.
//				If the user input an invalid care card number, it will search for the invalid care
//				card number in the system. E.g. user input "asd", it will search "0000000000".
void modifyPatient(List& patientList)
{
	//search for patient with care card num
	cout << "*****Modifying*****" << endl;
	string careCardNum;
    bool valid = false;
    while(!valid)
    {
        cout << "Enter care card number: ";
        cin >> careCardNum;
        
        //Check for non-digits
        for(unsigned int i = 0; i < careCardNum.length(); i++)
        {
            if(!isdigit(careCardNum[i]))
            {
                cout << "Error: Numbers only" << endl;
                break;
            }
            if(i == careCardNum.length() - 1 )
            {
                valid = true;
            }
        }
        
        //Check for correct number of digits
        if(careCardNum.length() != 10)
        {
            valid = false;
            cout << "Error: care card must be 10 digits" << endl;
        }
    }
	Patient tempPatient(careCardNum);
	Patient* foundPatient = patientList.search(tempPatient);
	//if found, prompt to change information
	if(foundPatient != NULL)
	{
		cout << "Patient found: ";
		foundPatient->printPatient();
		bool done = false;
		int select;
		while(!done)
		{
			cout << "1)Name 2)Address 3)Phone 4)Email 5)Back to main menu : ";
			cin >> select;
			string info;
			switch(select)
			{
				case 1: cout << "New name: ";
						cin.ignore();
						getline(cin, info);
						foundPatient->setName(info);
						break;
				case 2:	cout << "New address: ";
						cin.ignore();
						getline(cin, info);
						foundPatient->setAddress(info);
						break;
				case 3:	cout << "New phone: ";
						cin.ignore();
						getline(cin, info);
						foundPatient->setPhone(info);
						break;
				case 4:	cout << "New email: ";
						cin.ignore();
						getline(cin, info);
						foundPatient->setEmail(info);
						break;
				case 5: done = true;
			}
		}
	}
	else
	{
		cout << "Error: Patient not found" << endl;
	}
}

// Description: Print all of the patient in ascending order
void printAllPatients(List& patientList)
{
	cout << "*****Printing*****" << endl;
	patientList.printList();
}

// Description: Remove all of the patient in the system
void removeAllPatient(List& patientList)
{
	cout << "*****Removing all*****" << endl;
	patientList.removeAll();
}

// Description: Return "SUCCESS" or "FAILED" based on the bool.
string successOrFail(bool success)
{
	if(success)
	{
		return "SUCCESS!";
	}
	return "FAILED!";
}
