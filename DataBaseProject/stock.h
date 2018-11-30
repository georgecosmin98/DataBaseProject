#pragma once
#include <iostream>
#include <string>
#include <fstream>
class stock {
private:
	std::string name;
	int quantity;
	float price;
public:
	stock(std::string = "", int = 0, float = 0);
	void setStock(std::string, int, float);
	void printStock();
	void insertStock();
	void insertStockFirstLine();
	void deleteStock();
	void deleteStockLastLine();
	void add_Stock();
	void read_Stock();
	void delete_Stock();
	std::string getName();
	int& getQuantity();
	float& getPrice();
	void setQuantity(int);
	void setPrice(float);
};
