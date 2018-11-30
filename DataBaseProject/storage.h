#pragma once
#include <string>
#include "functiiIntrari.h"
#include <vector>
class storage
{
private: std::string nameProduct;
		 int quantity;
		 float price;
public:
	storage(std::string = "", int = 0, float = 0);
	void setStorage(std::string, int, float);
	void printStorage();
	void insertStorage();
	void insertStorageFirstLine();
	void deleteStorage();
	void deleteStorageLastLine();
	void read_Storage();
	void add_Storage();
	void delete_Storage();
};