#pragma once
#include <string>
#include <iostream>
#include "date.h"
#include <vector>
#include "functiiIntrari.h"
class state
{
private: std::string numeSuprafata;
		 std::string stareSuprafata;
		 const date ultimulTratament;
public:
	state(std::string = "", std::string = "", int = 1, int = 1, int = 2000);
	void setState(std::string, std::string, int, int, int);
	void printState();
	void insertState();
	void insertStateFirstLine();
	void read_State();
	void add_AreaState(std::string, bool);
	void switchState();
	void delete_AreaState(std::string);
};

#pragma once
