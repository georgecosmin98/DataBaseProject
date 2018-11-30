#include "storage.h"
#include <iostream>
#include <fstream>
#include "bilant.h"
storage::storage(std::string name, int quantity, float price)
{
	setStorage(name, quantity, price);
}
void storage::setStorage(std::string name, int q, float p)
{
	nameProduct = name;
	quantity = q;
	price = p;
}
void storage::printStorage()
{
	std::cout << "Numele produsului: " << nameProduct << " Cantitatea: " << quantity << " Pretul pe unitate: " << price << std::endl;
}
void storage::insertStorage()
{
	std::ofstream storageOf("storage.txt", std::ofstream::app);
	storageOf << std::endl;
	storageOf << nameProduct << " " << quantity << " " << price << std::flush;
}
void storage::insertStorageFirstLine()
{
	std::ofstream storageOf("storage.txt", std::ofstream::app);
	storageOf << nameProduct << " " << quantity << " " << price << std::flush;
}
void storage::deleteStorage()
{
	std::ofstream storageOf("storage.txt", std::ofstream::app);
	storageOf << nameProduct << " " << quantity << " " << price << std::endl << std::flush;
}
void storage::deleteStorageLastLine()
{
	std::ofstream storageOf("storage.txt", std::ofstream::app);
	storageOf << nameProduct << " " << quantity << " " << price << std::flush;
}
void storage::read_Storage()
{
	std::ifstream storageIn("storage.txt");
	std::string nume = "";
	int cantitate = 0;
	float pret = 0;
	std::vector<storage> vectorStorage;
	while (storageIn.good())
	{
		storageIn >> nume;
		storageIn >> cantitate;
		storageIn >> pret;
		if (nume != "")
			vectorStorage.push_back(storage(nume, cantitate, pret));
	}
	if (vectorStorage.size() != 0)
	{
		for (int i = 0; i < vectorStorage.size(); i++)
			vectorStorage[i].printStorage();
		storageIn.close();
	}
	else
		std::cout << "Nu exista produse in depozit!";
}
void storage::add_Storage()
{
	std::ifstream storageFile("storage.txt");
	std::string numeUser = "";
	std::string nume = "";
	int cantitate = 0, cantitateUser = 0;
	float pret = 0, pretUser = 0;
	std::vector<storage> vectorStorage;
	std::cout << "Denumire: ";
	std::cin >> numeUser;
	FunctiiIntrari::formatNume(numeUser);
	bool existaNumeleInBazaDeDate = false;
	bool actualizareEfectuata = false;
	bool existaValoriInFisier = true;
	while (storageFile.good())
	{
		storageFile >> nume;
		if (nume == "")
			existaValoriInFisier = false;
		storageFile >> cantitate;
		storageFile >> pret;
		existaNumeleInBazaDeDate = (nume == numeUser);
		if (existaNumeleInBazaDeDate) {
			//operatii cantitati
			actualizareEfectuata = true;
			std::cout << "Actualizare date pentru " << nume << std::endl;
			std::cout << "Cantitatea disponibila in depozit: " << cantitate << std::endl;
			std::cout << "Cantitatea pe care doriti sa o adaugati: ";
			std::cin >> cantitateUser;
			cantitate += cantitateUser;
			//operatii preturi
			bool estePretulModificat = false;
			std::cout << "Pretul actual este: " << pret << std::endl;
			std::cout << "Doriti modificarea pretului? 0 [NU] sau 1 [DA]: ";
			std::cin >> estePretulModificat;
			if (estePretulModificat) {
				std::cout << "Introduceti noul pret: ";
				std::cin >> pretUser;
				pret = pretUser;
			}

		}
		vectorStorage.push_back(storage(nume, cantitate, pret));
	}
	if (actualizareEfectuata) {
		storageFile.close();
		std::ifstream storageFile1("storage.txt", std::ofstream::out | std::ofstream::trunc);
		vectorStorage[0].insertStorageFirstLine();
		for (int i = 1; i < vectorStorage.size(); i++) {
			vectorStorage[i].insertStorage();
		}
		system("cls");
		std::cout << "Stocul de " << numeUser << " a fost actualizat cu succes!";
	}
	if (!actualizareEfectuata) {
		std::cout << "Adaugare o noua inregistrare in baza de date" << std::endl;
		std::cout << "Cantitate: ";
		std::cin >> cantitateUser;
		std::cout << "Pret: ";
		std::cin >> pretUser;
		vectorStorage.push_back(storage(numeUser, cantitateUser, pretUser));
		if (!existaValoriInFisier) // daca nu exista un nume pe prima linie se adauga pe ea
			vectorStorage[1].insertStorageFirstLine();
		else //altfel se adauga rand nou si valori noi
			vectorStorage[vectorStorage.size() - 1].insertStorage();
		system("cls");
		std::cout << "Produsul a fost adaugata cu succes in depozit!";
	}
}
void storage::delete_Storage()
{
	std::ifstream storageFile("storage.txt");
	std::ifstream bilantFile("bilant.txt", std::ofstream::out);
	float cheltuieli = 0;
	float venit = 0;
	float profit = 0;
	bilantFile >> venit;
	bilantFile >> cheltuieli;
	bilantFile >> profit;
	bilant obiectBilant;
	float pret = 0;
	int cantitate = 0;
	int cantitateUser = 0;
	float pretUser = 0;
	std::string nume = "";
	std::vector<storage> vectorStorage;
	std::string numeUser = "";
	bool existaNumeleInBazaDeDate = false;
	std::cout << "Numele produsului pe care doriti sa-l vindeti: ";
	std::cin >> numeUser;
	FunctiiIntrari::formatNume(numeUser);
	while (storageFile.good())
	{
		storageFile >> nume;
		storageFile >> cantitate;
		storageFile >> pret;
		if (numeUser != nume)
			vectorStorage.push_back(storage(nume, cantitate, pret));
		else
			if (numeUser == nume)
			{
				std::cout << "Cantitatea disponibila de: " << nume << " este de: " << cantitate << " kg." << std::endl;
				std::cout << "Cantitatea pe care doriti sa o vindeti: ";
				std::cin >> cantitateUser;
				if (cantitate > cantitateUser)
				{
					bool estePretulModificat = false;
					existaNumeleInBazaDeDate = true;
					cantitate = cantitate - cantitateUser;
					std::cout << "Pretul de lista este de: " << pret << std::endl;
					std::cout << "Doriti sa-l modificati? 0 [NU] sau 1 [DA]: ";
					std::cin >> estePretulModificat;
					if (estePretulModificat)
					{
						std::cout << "Introduceti noul pret de vanzare: ";
						std::cin >> pretUser;
						venit = venit + pretUser * cantitateUser;

					}
					else
					{
						venit = venit + pret * cantitateUser;
					}
					vectorStorage.push_back(storage(nume, cantitate, pret));
				}
				else
				{
					std::cout << "Valoarea introdusa este prea mare. Va rugam reincercati si introduceti o valoarea valida!";
				}
			}
	}
	if (existaNumeleInBazaDeDate)
	{
		storageFile.close();
		std::ifstream storageFile1("storage.txt", std::ofstream::out | std::ofstream::trunc);
		for (int i = 0; i < vectorStorage.size(); i++)
		{
			if (i < vectorStorage.size() - 1)
				vectorStorage[i].deleteStorage();
			else
				vectorStorage[i].deleteStorageLastLine();
		}
		system("cls");
		std::cout << "Produsul a fost vandut cu succes din depozit!";
		getchar();
	}
	else
	{
		system("cls");
		std::cout << "Produsul nu se afla in baza de date. Va rugam sa verificati produsele disponibile in depozit!";
		getchar();
	}
	bilantFile.close();
	std::ifstream bilantFile1("bilant.txt", std::ofstream::out | std::ofstream::trunc);
	obiectBilant.setBilant(venit, cheltuieli, profit);
	obiectBilant.setProfit();
	obiectBilant.insertBilant();
}