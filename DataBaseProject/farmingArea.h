#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "functiiIntrari.h"
class farmingArea
{
private:
	std::string areaName;
	int area;
public:
	farmingArea(std::string = "", int = 0);
	void setFarmingArea(std::string, int);
	void printFarmingArea();
	void insertFarmingArea();
	void insertFarmingAreaFirstLine();
	void deleteFarmingArea();
	void deleteFarmingAreaLastLine();
	void read_Area();
	void add_Area(std::string, bool&, bool&);
	void delete_Area(std::string, bool&);
};
