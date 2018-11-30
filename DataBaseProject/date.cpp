#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
#include "date.h"
//constructor fara verificarea valorilor
date::date(int d, int m, int y)
{
	setDate(d, m, y);
}void date::setDate(int d, int m, int y) {
	if (m > 0 && m <= 12)
		month = m;
	else {
		month = 1;
		cout << "Luna " << m << " incorecta. "
			<< "Valoarea implicita este 1.\n";
	}
	year = y;
	day = checkDay(d); //valideaza ziua
}
void date::insertDate() const
{
	std::ofstream stateFile("state.txt", std::ofstream::app);
	stateFile << day << " " << month << " " << year;
}
int date::checkDay(int testDay)
{
	static const int daysPerMonth[13] =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;
	//Februarie: test pentru an bisect
	if (month == 2 && testDay == 29 &&
		(year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		return testDay;
	cout << "Ziua " << testDay << " incorecta. "
		<< "Valoarea implicita este 1.\n";
	return 1;
}
void date::print() const
{
	cout << day << '/' << month << '/' << year;
}