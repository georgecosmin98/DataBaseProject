#include "stock.h"
#include <vector>
#include "bilant.h"
#include <ostream>
#include"functiiIntrari.h"
stock::stock(std::string n, int c, float p)
{
	setStock(n, c, p);
}
void stock::setStock(std::string n, int c, float p)
{
	name = n;
	quantity = c;
	price = p;
}
void stock::printStock()
{
	std::cout << "Denumire: " << name << " "
		<< "Cantitate: " << quantity << " "
		<< "Pret pe unitate: " << price << std::endl;
}
void stock::insertStock()
{
	std::ofstream stockFile("stock.txt", std::ofstream::app);
	stockFile << std::endl;
	stockFile << name << " " << quantity << " " << price << std::flush;
}
void stock::insertStockFirstLine()
{
	std::ofstream stockFile("stock.txt", std::ofstream::app);
	stockFile << name << " " << quantity << " " << price << std::flush;
}
void stock::deleteStock()
{
	std::ofstream stockFile("stock.txt", std::ofstream::app);
	stockFile << name << " " << quantity << " " << price << std::endl << std::flush;
}
void stock::deleteStockLastLine()
{
	std::ofstream stockFile("stock.txt", std::ofstream::app);
	stockFile << name << " " << quantity << " " << price << std::flush;
}
std::string stock::getName()
{
	return name;
}
int&  stock::getQuantity()
{
	return quantity;
}
float& stock::getPrice()
{
	return price;
}
void stock::setQuantity(int q)
{
	quantity = q;
}
void stock::setPrice(float p)
{
	price = p;
}
void stock::add_Stock() {
	std::ifstream stockFile("stock.txt", std::ofstream::out);
	std::ifstream bilantFile("bilant.txt", std::ofstream::out);
	float cheltuieli = 0;
	float venit = 0;
	float profit = 0;
	bilantFile >> venit;
	bilantFile >> cheltuieli;
	bilantFile >> profit;
	std::vector<stock> vectorStock;
	std::string numeUser = "";
	std::cout << "Denumire: ";
	std::cin >> numeUser;
	bilant obiectBilant;
	FunctiiIntrari::formatNume(numeUser);
	int cantitate = 0, cantitateUser = 0;
	float pretUser = 0, pret = 0;
	std::string nume = "";
	bool existaNumeleInBazaDeDate = false;
	bool actualizareEfectuata = false;
	bool existaValoriInFisier = true; // variabila folosita pentru a vedea daca exista valori in fisier
	while (stockFile.good())
	{
		stockFile >> nume;
		if (nume == "")
			existaValoriInFisier = false;  //false daca nu exista nume in fisier
		stockFile >> cantitate;
		stockFile >> pret;
		existaNumeleInBazaDeDate = (nume == numeUser);
		if (existaNumeleInBazaDeDate) {
			//operatii cantitati
			actualizareEfectuata = true;
			std::cout << "Actualizare date pentru " << nume << std::endl;
			std::cout << "Cantitatea disponibila: " << cantitate << std::endl;
			std::cout << "Cantitatea pe care doriti sa o adaugati: ";
			std::cin >> cantitateUser;
			cantitate += cantitateUser;

			//operatie preturi
			bool estePretulModificat = false;
			std::cout << "Pretul actual este: " << pret << std::endl;
			std::cout << "Doriti modificarea pretului? 0 [NU] sau 1 [DA]: ";
			std::cin >> estePretulModificat;
			if (estePretulModificat) {
				std::cout << "Introduceti noul pret: ";
				std::cin >> pretUser;
				pret = pretUser;
				cheltuieli = (pret - pretUser)*cantitateUser + cheltuieli;
			}
			else
				cheltuieli = cantitateUser * pret + cheltuieli;
		}
		vectorStock.push_back(stock(nume, cantitate, pret));
	}
	if (actualizareEfectuata) {
		stockFile.close();
		std::ifstream stockFile1("stock.txt", std::ofstream::out | std::ofstream::trunc);
		vectorStock[0].insertStockFirstLine();
		for (int i = 1; i < vectorStock.size(); i++) {
			vectorStock[i].insertStock();
		}
		system("cls");
		std::cout << "Stocul de " << numeUser << " a fost actualizat cu succes!";
		getchar();
		std::cin.get();
	}
	if (!actualizareEfectuata) {
		std::cout << "Adaugare o noua inregistrare in baza de date" << std::endl;
		std::cout << "Cantitate: ";
		std::cin >> cantitateUser;
		std::cout << "Pret: ";
		std::cin >> pretUser;
		cheltuieli = cantitateUser * pretUser + cheltuieli;
		vectorStock.push_back(stock(numeUser, cantitateUser, pretUser));
		if (!existaValoriInFisier) //daca nu exista nume pe prima linie se adauga pe ea
			vectorStock[1].insertStockFirstLine();
		else  //altfel se adauga rand nou si valori noi
			vectorStock[vectorStock.size() - 1].insertStock();
		system("cls");
		std::cout << "Substanta a fost adaugata cu succes in stoc!";
		getchar();
		std::cin.get();
	}
	bilantFile.close();
	std::ifstream bilantFile1("bilant.txt", std::ofstream::out | std::ofstream::trunc);
	obiectBilant.setBilant(venit, cheltuieli, profit);
	obiectBilant.setProfit();
	obiectBilant.insertBilant();
}
void stock::read_Stock()
{
	std::ifstream stockFile("stock.txt");
	std::string nume = "";
	int cantitate = 0;
	float pret = 0;
	std::vector<stock> vectorStock;
	while (stockFile.good())
	{
		stockFile >> nume;
		stockFile >> cantitate;
		stockFile >> pret;
		if (nume != "")
			vectorStock.push_back(stock(nume, cantitate, pret));
	}
	if (vectorStock.size() != 0)
	{
		for (int i = 0; i < vectorStock.size(); i++)
			vectorStock[i].printStock();
		stockFile.close();
	}
	else
	{
		std::cout << "Nu exista produse in stoc !";
	}
}
void stock::delete_Stock()
{
	std::ifstream stockFile("stock.txt", std::ofstream::out);
	float pret = 0;
	int cantitate = 0;
	std::string nume = "";
	std::vector<stock> vectorStock;
	std::string numeUser = "";
	bool actualizareEfectuata = false;
	std::cout << "Introduceti numele substantei pe care doriti sa o stergeti: ";
	std::cin >> numeUser;
	FunctiiIntrari::formatNume(numeUser);
	while (stockFile.good())
	{
		stockFile >> nume;
		stockFile >> cantitate;
		stockFile >> pret;
		if (numeUser != nume)
			vectorStock.push_back(stock(nume, cantitate, pret));
		else
			actualizareEfectuata = true;
	}
	stockFile.close();
	std::ifstream stockFile1("stock.txt", std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < vectorStock.size(); i++)
	{
		if (i < vectorStock.size() - 1)
			vectorStock[i].deleteStock();
		else
			vectorStock[i].deleteStockLastLine();
	}
	if (actualizareEfectuata)
	{
		system("cls");
		std::cout << "Substanta " << numeUser << " a fost scoasa cu succes din stoc!";
		getchar();
		std::cin.get();
	}
	else
	{
		system("cls");
		std::cout << "Aceasta substanta nu exista in stoc.";
		getchar();
		std::cin.get();
	}
}