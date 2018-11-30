#include "farmingArea.h"
farmingArea::farmingArea(std::string name, int area)
{
	setFarmingArea(name, area);
}
void farmingArea::setFarmingArea(std::string name, int a)
{
	areaName = name;
	area = a;
}
void farmingArea::printFarmingArea()
{
	std::cout << "Numele suprafetei: " << areaName << " Suprafata(m^2): " << area << std::endl;
}
void farmingArea::insertFarmingArea()
{
	std::ofstream farmingOf("farming.txt", std::ofstream::app);
	farmingOf << std::endl;
	farmingOf << areaName << " " << area << std::flush;
}
void farmingArea::insertFarmingAreaFirstLine()
{
	std::ofstream farmingOf("farming.txt", std::ofstream::app);
	farmingOf << areaName << " " << area << std::flush;
}
void farmingArea::deleteFarmingArea()
{
	std::ofstream farmingOf("farming.txt", std::ofstream::app);
	farmingOf << areaName << " " << area << std::endl << std::flush;
}
void farmingArea::deleteFarmingAreaLastLine()
{
	std::ofstream farmingOf("farming.txt", std::ofstream::app);
	farmingOf << areaName << " " << area << std::flush;
}
void farmingArea::read_Area()
{
	std::ifstream farmingIn("farming.txt");
	std::string nume = "";
	int aria;
	bool existaValoriInFisier = true;
	std::vector<farmingArea> vectorArea;
	while (farmingIn.good())
	{
		farmingIn >> nume;
		farmingIn >> aria;
		if (nume == "")
			existaValoriInFisier = false;
		vectorArea.push_back(farmingArea(nume, aria));
	}
	if (existaValoriInFisier)
	{
		for (int i = 0; i < vectorArea.size(); i++)
			vectorArea[i].printFarmingArea();
	}
	else
		std::cout << "Nu exista suprafete agricole";
	farmingIn.close();
}
void farmingArea::add_Area(std::string numeUser, bool &existaNumeleInBazaDeDate, bool &existaValoriInFisier)
{
	std::ifstream farmingFile("farming.txt");
	std::vector<farmingArea> vectorArea;
	FunctiiIntrari::formatNume(numeUser);
	int aria = 0, ariaUser = 0;
	std::string nume = "";
	bool actualizareEfectuata = false;
	while (farmingFile.good())
	{
		farmingFile >> nume;
		if (nume == "")
			existaValoriInFisier = false;
		farmingFile >> aria;
		existaNumeleInBazaDeDate = (nume == numeUser);
		if (existaNumeleInBazaDeDate)
		{
			//operatii 
			bool esteAriaModificata = false;
			actualizareEfectuata = true;
			std::cout << "Actualizare date pentru " << nume << std::endl;
			std::cout << "Suprafata actuala este de: " << aria << std::endl;
			std::cout << "Doriti extinderea suprafetei? 0 [NU] sau 1 [DA]: ";
			std::cin >> esteAriaModificata;
			if (esteAriaModificata)
			{
				std::cout << "Aria cu care doriti sa extindeti suprafata: ";
				std::cin >> ariaUser;
				aria += ariaUser;
			}
		}
		vectorArea.push_back(farmingArea(nume, aria));
	}
	if (actualizareEfectuata) {
		farmingFile.close();
		std::ifstream farmingFile1("farming.txt", std::ofstream::out | std::ofstream::trunc);
		vectorArea[0].insertFarmingAreaFirstLine();
		for (int i = 1; i < vectorArea.size(); i++)
		{
			vectorArea[i].insertFarmingArea();
		}
		system("cls");
		std::cout << "Actualizarea suprafetei " << numeUser << " a fost efectuata cu succes!";
	}
	if (!actualizareEfectuata) {
		std::cout << "Adaugare o noua inregistrare in baza de date" << std::endl;
		std::cout << "Aria: ";
		std::cin >> ariaUser;
		vectorArea.push_back(farmingArea(numeUser, ariaUser));
		if (!existaValoriInFisier)
			vectorArea[1].insertFarmingAreaFirstLine();
		else
			vectorArea[vectorArea.size() - 1].insertFarmingArea();

		system("cls");
		std::cout << "Suprafata " << numeUser << " a fost adaugata cu succes in baza de date!";
	}
}
void farmingArea::delete_Area(std::string numeUser, bool &existaNumeleInBazaDeDate)
{
	std::ifstream farmingFile("farming.txt");
	std::string nume = "";
	int aria;
	FunctiiIntrari::formatNume(numeUser);
	std::vector<farmingArea> vectorArea;
	while (farmingFile.good())
	{
		farmingFile >> nume;
		farmingFile >> aria;
		if (numeUser != nume)
			vectorArea.push_back(farmingArea(nume, aria));
		else
			existaNumeleInBazaDeDate = true;
	}
	farmingFile.close();
	std::ifstream farmingFileUpdate("farming.txt", std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < vectorArea.size(); i++)
	{
		if (i < vectorArea.size() - 1)
			vectorArea[i].deleteFarmingArea();
		else
			vectorArea[i].deleteFarmingAreaLastLine();
	}
	if (!existaNumeleInBazaDeDate)
	{
		system("cls");
		std::cout << "Numele nu exista in baza de date." << std::endl;
		std::cout << "Va rugam verificati lista suprafetelor agricole pentru a vedea daca exista suprafata: " << numeUser << std::endl;
	}
	else
	{
		system("cls");
		std::cout << "Vanzarea suprafetei agricole " << numeUser << " a fost efectuata cu succes!";
	}
}