#ifndef CITY_H
#define CITY_H
#include <iostream>
using namespace std;

class City {
public:
	string state;
	int year;
	string city;
public:
	City();
	City(string, int, string);
	void setState(string);
	void setYear(int);
	void setCity(string);
	void display();
	string getState();
	int getYear();
	string getCity();
	bool operator<(const City&);
};
#endif

#pragma once