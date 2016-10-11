// Specification file for the CityList class
#ifndef CITYLIST_H
#define CITYLIST_H
#include <iostream>
#include "City.h"
using namespace std;

class CityList
{
private:
	struct ListNode
	{
		City data;
		ListNode *next;
	};
	ListNode *head;

	int size;
public:

	// Constructor
	CityList();

	// Destructor
	~CityList();

	// Linked list operations
	void insertNode(City);
	void deleteNode(string);
	void searchList(string);
	void displayList();
	int getOldestYear();
	int getYoungestYear();
	int getSize();
	void displayOldestCities();
	void displayYoungestCities();
};

#endif
#pragma once
