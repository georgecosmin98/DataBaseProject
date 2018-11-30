#pragma once
#pragma once
class bilant
{
	float venit;
	float cheltuieli;
	float profit;
public:
	bilant(float = 0, float = 0, float = 0);
	void setBilant(float, float, float);
	void setVenit(float);
	void setCheltuieli(float);
	void setProfit();
	void insertBilant() const;
	void printBilant() const;
	void readVenit();
	void readCheltuieli();
	void readBilant();
	void insertBilant();
	void insertBilantNextLine();
	void nextYear();
	void readLastYear();
};