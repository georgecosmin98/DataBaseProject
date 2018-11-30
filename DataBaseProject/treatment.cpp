#include "treatment.h"
#include "state.h"
#include "stock.h"
treatment::treatment(std::string nume, int cantitate, int zi, int luna, int an)
{
	setTreatment(nume, cantitate, zi, luna, an);
}
void treatment::setTreatment(std::string nume, int cantitate, int zi, int luna, int an)
{
	numeSubstanta = nume;
	cantitateSubstanta = cantitate;
}
void treatment::stockToTreatment(bool &actualizareEfectuata)
{
	std::string numeSubstanta = "";
	std::string numeSubstantaUser = "";
	int cantitate = 0;
	int cantitateUser = 0;
	int pret = 0;
	std::vector<stock> vectorStock;
	bool toateSubstanteleSuntInStock = true;
	bool existaSubstantaInStock = false;
	bool esteNevoieDeMaiMulteSubstante = true;
	bool stocSuficient = true;
	std::ifstream stockFile("stock.txt");
	while (stockFile.good())
	{
		stockFile >> numeSubstanta;
		stockFile >> cantitate;
		stockFile >> pret;
		vectorStock.push_back(stock(numeSubstanta, cantitate, pret));
	}
	while (esteNevoieDeMaiMulteSubstante == 1)
	{
		std::cout << "Numele substantei pe care doriti sa o utilizati: ";
		std::cin >> numeSubstantaUser;
		std::cout << std::endl;
		std::cout << "Cantitatea de substanta necesara: ";
		std::cin >> cantitateUser;
		FunctiiIntrari::formatNume(numeSubstantaUser);
		for (int i = 0; i < vectorStock.size(); i++)
		{
			if (vectorStock[i].getName() == numeSubstantaUser)
			{
				vectorStock[i].getQuantity() -= cantitateUser;
				actualizareEfectuata = true;
				if (vectorStock[i].getQuantity() < 0)
				{
					system("cls");
					stocSuficient = false;
					actualizareEfectuata = false;
					std::cout << "Nu exista suficienta: " << numeSubstantaUser << " in stoc!";
					getchar();
					std::cin.get();
					return;
				}
			}
		}
		system("cls");
		std::cout << "Doriti sa adaugati inca o substanta la tratament? 0 [NU] sau 1 [DA]: ";
		std::cin >> esteNevoieDeMaiMulteSubstante;
	}
	if (!actualizareEfectuata)
	{
		system("cls");
		std::cout << "Substanta nu exista in baza de date." << std::endl;
		std::cout << "Va rog sa verificati stocul si apoi sa reincercati sa introduceti o entitate valida!";
	}
	else
		if (actualizareEfectuata&&stocSuficient)
		{
			stockFile.close();
			std::ifstream stockFile1("stock.txt", std::ofstream::out | std::ofstream::trunc);
			vectorStock[0].insertStockFirstLine();
			for (int i = 1; i < vectorStock.size(); i++)
			{
				vectorStock[i].insertStock();
			}
			vectorStock.clear();
		}
}
void treatment::treatmentToState(bool &actualizareEfectuata, std::string numeSuprafataUser)
{
	std::ifstream stateFile("state.txt");
	std::string numeSuprafata = "";
	std::string stare = "";
	int zi = 1, luna = 1, an = 2000;
	int ziUser = 1, lunaUser = 1, anUser = 2000;
	date ultimulTratament;
	std::vector<state> vectorStare;
	bool existaSuprafataInFisier = false;
	FunctiiIntrari::formatNume(numeSuprafataUser);
	while (stateFile.good())
	{
		stateFile >> numeSuprafata;
		stateFile >> stare;
		stateFile >> zi;
		stateFile >> luna;
		stateFile >> an;
		ultimulTratament.setDate(zi, luna, an);
		existaSuprafataInFisier = (numeSuprafata == numeSuprafataUser);
		if (existaSuprafataInFisier)
		{
			std::cout << "Data tratamentului este: ";
			std::cout << std::endl << "Ziua: ";
			std::cin >> ziUser;
			zi = ziUser;
			std::cout << std::endl << "Luna: ";
			std::cin >> lunaUser;
			luna = lunaUser;
			std::cout << std::endl << "Anul: ";
			std::cin >> anUser;
			an = anUser;
			actualizareEfectuata = true;
		}
		vectorStare.push_back(state(numeSuprafata, stare, zi, luna, an));
	}
	if (actualizareEfectuata)
	{
		stateFile.close();
		std::ifstream stateFile1("state.txt", std::ofstream::out | std::ofstream::trunc);
		vectorStare[0].insertStateFirstLine();
		for (int i = 1; i < vectorStare.size(); i++)
		{
			vectorStare[i].insertState();
		}
		vectorStare.clear();
	}
}
void treatment::add_Treatment()
{
	bool actualizareEfectuata = false;
	stockToTreatment(actualizareEfectuata);
	if (actualizareEfectuata)
	{
		std::string numeSuprafataUser = "";
		if (actualizareEfectuata)
		{
			std::cout << "Numele suprafetei pe care doriti sa efectuati tratamentul: ";
			std::cin >> numeSuprafataUser;
			treatmentToState(actualizareEfectuata, numeSuprafataUser);
		}
	}
}
void treatment::read_Treatment()
{
	std::ifstream stateFile("treatment.txt");
	std::string nume = "";
	std::string stare = "";
	int zi, luna, an;
	std::vector<state> vectorState;
	while (stateFile.good())
	{
		stateFile >> nume;
		stateFile >> stare;
		stateFile >> zi;
		stateFile >> luna;
		stateFile >> an;
		vectorState.push_back(state(nume, stare, zi, luna, an));
	}
	for (int i = 0; i < vectorState.size(); i++)
		vectorState[i].printState();
	stateFile.close();
}