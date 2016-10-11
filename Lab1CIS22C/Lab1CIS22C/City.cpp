#include "City.h"
#include <iomanip>
#include <string>

/*
Pre: nothing

Purpose: construct City object with default data

Post: return nothing
*/
City::City() {
	state = "";
	year = 0;
	city = "";
}
/*
Pre: m_state: string to be set to state instance variable
	 m_year: int to be set to year instance variable
	 m_city: string to be set to city instance variable
Purpose: construce City with input data

Post: return nothing
*/
City::City(string m_state, int m_year, string m_city) {
	state = m_state;
	year = m_year;
	city = m_city;
}
/*
Pre: m_state: string to be set to state instance variable

Purpose: set the state of the city

Post: return nothing
*/
void City::setState(string m_state) {
	state = m_state;
}
/*
Pre: m_year: int to be set to year instance variable

Purpose: set the year the city was made

Post: return nothing
*/
void City::setYear(int m_year) {
	year = m_year;
}
/*
Pre: m_city: string to be set to city instance variable

Purpose: set the name of the city

Post: return nothing
*/
void City::setCity(string m_city) {
	city = m_city;
}
/*
Pre: nothing

Purpose: return the state of the city

Post: return state
*/
string City::getState() {
	return state;
}
/*
Pre: nothing

Purpose: return the year the city was made

Post: return year
*/
int City::getYear() {
	return year;
}
/*
Pre: nothing

Purpose: return the name of the city

Post: return city
*/
string City::getCity() {
	return city;
}
/*
Pre: right: const reference to another city that will be compared to this object

Purpose: compare this with right to see which city is less than the other

Post: return a bool indicating whether this city is less than right's city
*/
bool City::operator<(const City& right) {
	if (city < right.city) {
		return true;
	}
	return false;
}
/*
Pre: nothing

Purpose: display the city's information

Post: return nothing
*/
void City::display() {
	cout << setw(10) << state;
	cout << setw(10) << year;
	cout << setw(20) << city << endl;
}