// Implementation file for the CityList class
#include <iostream>  // For cout  and NULL
#include <iomanip>
#include <string>
#include "CityList.h"
using namespace std;

/**************************************************
Constructor
This function allocates an empty node to act as a
sentinel node: it makes the code shorter and the
processing of the list faster.
**************************************************/
CityList::CityList()
{
	head = new ListNode;
	head->next = NULL;
	size = 0;
}

/**************************************************
Display the value stored in each node of
the linked list
**************************************************/
void CityList::displayList()
{
	ListNode *nodePtr = head->next;
	while (nodePtr)
	{
		nodePtr->data.display();
		nodePtr = nodePtr->next;
	}
}

/**************************************************
Insert a new node into a sorted list and
keeps the list sorted
**************************************************/
void CityList::insertNode(City dataIn)
{
	ListNode *newNode;
	ListNode *nodePtr = head->next;
	ListNode *prevNode = head;

	// Allocate a new node and store dataIn there.
	newNode = new ListNode;
	newNode->data = dataIn;

	// Skip all nodes whose value is less than num.
	while (nodePtr != NULL && nodePtr->data < dataIn)
	{
		prevNode = nodePtr;
		nodePtr = nodePtr->next;
	}
	// Update links to insert the new node
	prevNode->next = newNode;
	newNode->next = nodePtr;
	size++;
}

/**************************************************
Search for a city in the list
If found, it prints it.
**************************************************/

void CityList::searchList(string city)
{
	ListNode *nodePtr;

	nodePtr = head->next;

	while (nodePtr != NULL && nodePtr->data.getCity().compare(city) != 0)
	{
		nodePtr = nodePtr->next;
	}
	if (nodePtr != NULL && nodePtr->data.getCity().compare(city) == 0) // Display the value in this node.
	{
		cout << endl << left << setw(10) << "State" << setw(10) << "Year" << setw(20) << "City" << endl;
		cout << setw(10) << "-----" << setw(10) << "-----" << setw(20) << "----------" << endl;
		nodePtr->data.display();
	}
	else // Display error if there is no result in this node
	{
		cout << "<" << city << ">" << " was not found" << endl;
	}
}

/**************************************************
Delete a city from the list (if found)
**************************************************/
void CityList::deleteNode(string city)
{
	ListNode *nodePtr = head->next;
	ListNode *prevNode = head;

	while (nodePtr != NULL && nodePtr->data.getCity().compare(city) != 0)
	{
		prevNode = nodePtr;
		nodePtr = nodePtr->next;
	}
	if (nodePtr) // found
	{
		prevNode->next = nodePtr->next;
		cout << nodePtr->data.getCity() << endl;
		delete nodePtr;
		size--;
	}
	else
	{
		cout << "<" << city << ">" << " was not found" << endl;
	}
}
/*
Pre: nothing

Purpose: return the size of the list

Post: return size
*/
int CityList::getSize() {
	return size;
}
/*
Pre: nothing

Purpose: return the oldest city year from the list of cities

Post: return the oldest year
*/
int CityList::getOldestYear() 
{
	int oldestYear = 2000;

	ListNode* nodeptr = head->next;

	while (nodeptr != NULL) {
		if (nodeptr->data.getYear() < oldestYear) {
			oldestYear = nodeptr->data.getYear();
		}
		nodeptr = nodeptr->next;
	}

	return oldestYear;
}
/*
Pre: nothing

Purpose: return the youngest city year from the list of cities

Post: return the youngest year
*/
int CityList::getYoungestYear() 
{
	int youngestYear = 0;

	ListNode* nodeptr = head->next;

	while (nodeptr != NULL) {
		if (nodeptr->data.getYear() > youngestYear) {
			youngestYear = nodeptr->data.getYear();
		}
		nodeptr = nodeptr->next;
	}
	return youngestYear;
}
/*
Pre: nothing

Purpose: display the oldest cities whose year is equal to oldest year

Post: nothing
*/
void CityList::displayOldestCities() 
{
	int oldestYear = getOldestYear();

	ListNode* nodeptr = head;
	while (nodeptr != NULL) {
		if (nodeptr->data.getYear() == oldestYear) {
			nodeptr->data.display();
		}
		nodeptr = nodeptr->next;
	}

}
/*
Pre: nothing

Purpose: display the youngest cities from the list whose year is equal to youngest year

Post: return size
*/
void CityList::displayYoungestCities() 
{
	int youngestYear = getYoungestYear();

	ListNode* nodeptr = head;
	while (nodeptr != NULL) {
		if (nodeptr->data.getYear() == youngestYear) {
			nodeptr->data.display();
		}
		nodeptr = nodeptr->next;
	}

}

/**************************************************
Destructor
This function deletes every node in the list.
**************************************************/
CityList::~CityList()
{
	ListNode *nodePtr = head;
	ListNode *nextNode;
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}

}
