/**
CIS 22C
Linked Lists

*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "CityList.h"
using namespace std;

void intro();
void readCities(CityList &list, const char inputFileName[]);
void printCities(CityList &list);
void searchCities(CityList &list);
void deleteCities(CityList &list);
void printOldestCities(CityList& list);
void printYoungestCities(CityList& list);
void printEndMsg();


int main()
{
	const char inputFileName[] = "cities.txt";
	CityList list;

	intro();
	readCities(list, inputFileName);
	printCities(list);
	searchCities(list);
	deleteCities(list);
	printCities(list);
	printOldestCities(list);
	printYoungestCities(list);
	printEndMsg();

	//cout << list.getOldestYear() << endl;
	//cout << list.getYoungestYear() << endl;

	//cout << list.getNumberOfCities() << endl;

	system("pause");

	return 0;
}

/*****************************************************************************
Display a short statement about the purpose of the program
*****************************************************************************/
void intro()
{
	cout << "Build and process a Linked List of Cities\n";
	cout << "_________________________________________\n\n";
}

/********************************************************************************
Read data about cities from a file and build a sorted linked list
The list is sorted by city name.

Input Parameter: inputFileName
Output Parameter: list
Return Value : none
*****************************************************************************/
void readCities(CityList &list, const char inputFileName[])
{
	cout << "Reading City data from " << inputFileName << " . . .";

	City dataIn;
	string state;
	int year;
	string city;

	ifstream infile;
	infile.open(inputFileName);

	while (!infile)
	{
		cout << "Error opening " << inputFileName << "for reading\n";
		exit(111);
	}

	while (infile >> state)
	{
		cout << state << endl;
		infile >> year;
		infile.ignore();
		getline(infile, city, '\n');
		if (city.at(city.size() - 1) == ' ') {
			city = city.substr(0, city.size() - 1);
		}
		dataIn.setState(state);
		dataIn.setYear(year);
		dataIn.setCity(city);
		list.insertNode(dataIn);

	}
	infile.close();

	cout << " . . . Done reading!\n";
	cout << "___________________________________________________________\n";

}

/*****************************************************************************
Display the city list
Input Parameter: list
*****************************************************************************/
void printCities(CityList &list)
{
	cout << "\n      Print City Data\n";
	cout << "______________________________\n\n";

	cout << left << setw(10) << "State" << setw(10) << "Year" << setw(20) << "City" << endl;
	cout << setw(10) << "-----" << setw(10) << "-----" << setw(20) << "----------" << endl;
	list.displayList();

	cout << "___________________\n";
	cout << "Size: " << list.getSize() << endl;
}

void printOldestCities(CityList& list) {
	cout << "\n      Print Oldest Cities\n";
	cout << "______________________________\n\n";

	cout << left << setw(10) << "State" << setw(10) << "Year" << setw(20) << "City" << endl;
	cout << setw(10) << "-----" << setw(10) << "-----" << setw(20) << "----------" << endl;
	list.displayOldestCities();

	cout << "___________________\n";
}

void printYoungestCities(CityList& list) {
	cout << "\n      Print Youngest Cities\n";
	cout << "______________________________\n\n";

	cout << left << setw(10) << "State" << setw(10) << "Year" << setw(20) << "City" << endl;
	cout << setw(10) << "-----" << setw(10) << "-----" << setw(20) << "----------" << endl;
	list.displayYoungestCities();

	cout << "___________________\n";
}


/*****************************************************************************
Search manager: search the city list until the user enters QUIT
Input Parameter: list
*****************************************************************************/
void searchCities(CityList &list)
{
	string targetCity;

	cout << "\nSearch\n";
	cout << "______\n";

	while (targetCity != "QUIT")
	{
		cout << "\nEnter the city for search (QUIT for stop searching) : ";
		getline(cin, targetCity);

		if (targetCity != "QUIT")
		{
			list.searchList(targetCity);
		}


	}
	cout << "___________________\n";
}

/*****************************************************************************
Delete manager: delete cities from the list until the user enters QUIT
Input Parameter: list
*****************************************************************************/
void deleteCities(CityList &list)
{
	string targetCity;

	cout << "\n Delete\n";
	cout << "______\n";

	while (targetCity != "QUIT")
	{
		cout << endl << "Enter the city for delete (QUIT for stop searching) : ";
		getline(cin, targetCity);

		if (targetCity != "QUIT")
		{
			list.deleteNode(targetCity);
		}
	}
	cout << "___________________\n";
	cout << "Size: " << list.getSize() << endl;
}




/*****************************************************************************
Display an "End of the program" message
*****************************************************************************/
void printEndMsg()
{
	cout << "\n\n____________________________________________\n\n";
	cout << "   End of the Sorted Linked List program!\n";
	cout << "____________________________________________\n";
}

/*
Build and process a Linked List of Cities
_________________________________________

Reading City data from cities.txt . ..CA
MA
TX
IL
WI
TX
IN
DC
FL
CA
MI
TN
TX
NY
PA
MD
AZ
CA
OH
CA
. ..Done reading!
___________________________________________________________

Print City Data
______________________________

State     Year      City
---- - ---- - ----------
MD        1797      Baltimore
MA        1822      Boston
IL        1837      Chicago
OH        1834      Columbus
TX        1856      Dallas
MI        1701      Detroit
TX        1837      Houston
IN        1832      Indianapolis
FL        1822      Jacksonville
CA        1850      Los Angeles
TN        1826      Memphis
WI        1846      Milwaukee
NY        1898      New York
PA        1701      Philadelphia
AZ        1881      Phoenix
TX        1837      San Antonio
CA        1850      San Diego
CA        1850      San Francisco
CA        1850      San Jose
DC        1788      Washington
___________________
Size : 20

	Search
	______

	Enter the city for search(QUIT for stop searching) : San Jose

	State     Year      City
	---- - ---- - ----------
	CA        1850      San Jose

	Enter the city for search(QUIT for stop searching) : Washington

	State     Year      City
	---- - ---- - ----------
	DC        1788      Washington

	Enter the city for search(QUIT for stop searching) : Los Angeles

	State     Year      City
	---- - ---- - ----------
	CA        1850      Los Angeles

	Enter the city for search(QUIT for stop searching) : QUIT
	___________________

	Delete
	______

	Enter the city for delete (QUIT for stop searching) : San Jose
	San Jose

	Enter the city for delete (QUIT for stop searching) : Washington
	Washington

	Enter the city for delete (QUIT for stop searching) : Los Angeles
	Los Angeles

	Enter the city for delete (QUIT for stop searching) : QUIT
	___________________
	Size : 17

	Print City Data
	______________________________

	State     Year      City
	---- - ---- - ----------
	MD        1797      Baltimore
	MA        1822      Boston
	IL        1837      Chicago
	OH        1834      Columbus
	TX        1856      Dallas
	MI        1701      Detroit
	TX        1837      Houston
	IN        1832      Indianapolis
	FL        1822      Jacksonville
	TN        1826      Memphis
	WI        1846      Milwaukee
	NY        1898      New York
	PA        1701      Philadelphia
	AZ        1881      Phoenix
	TX        1837      San Antonio
	CA        1850      San Diego
	CA        1850      San Francisco
	___________________
	Size : 17

	Print Oldest Cities
	______________________________

	State     Year      City
	---- - ---- - ----------
	MI        1701      Detroit
	PA        1701      Philadelphia
	___________________

	Print Youngest Cities
	______________________________

	State     Year      City
	---- - ---- - ----------
	NY        1898      New York
	___________________


	____________________________________________

	End of the Sorted Linked List program!
	____________________________________________
	Press any key to continue . . .
	*/