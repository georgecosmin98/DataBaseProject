#pragma once
#include <iostream>
#include <string>
class date
{
public:
	date(int = 1, int = 1, int = 1990);
	void setDate(int, int, int);
	void print() const;
	void insertDate() const;
private:
	int day; //1-12
	int month;//1-31
	int year;
	int checkDay(int);
};