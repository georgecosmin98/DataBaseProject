#pragma once
#include <string>
#include "date.h"
class treatment
{
private:
	std::string numeSubstanta;
	int cantitateSubstanta;
	const date ultimulTratament;
public:
	treatment(std::string = "", int = 0, int = 1, int = 1, int = 2000);
	void setTreatment(std::string, int, int, int, int);
	void stockToTreatment(bool&);
	void treatmentToState(bool&, std::string);
	void add_Treatment();
	void read_Treatment();
};