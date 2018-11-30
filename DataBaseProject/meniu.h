#pragma once
#include <iostream>
#include <string>
#include "stock.h"
#include <vector>
#include "storage.h"
#include "farmingArea.h"
#include "state.h"
#include "bilant.h"
#include "treatment.h"
#include "functiiIntrari.h"
using std::cin;
using std::cout;
using std::endl;
void meniu1()
{
	int optiuneMeniu1 = -1;
	while (optiuneMeniu1 != 0)
	{
		cout << "1.Afisare stoc substante" << endl;
		cout << "2.Adaugare substanta in stoc" << endl;
		cout << "3.Stergere substanta din stoc" << endl;
		cout << "0.Inapoi la meniul principal" << endl;
		cout << "Introduceti cifra corespunzatoare submeniului pe care doriti sa-l accesati: ";
		std::string optiuneMeniuString;
		cin >> optiuneMeniuString;
		bool actualizareEfectuata = false;
		FunctiiIntrari::testCifra(optiuneMeniuString, actualizareEfectuata, optiuneMeniu1);
		if (!actualizareEfectuata)
			optiuneMeniu1 = -1;
		system("cls");
		stock obiectStock;
		if (optiuneMeniu1 == 1)
		{
			obiectStock.read_Stock();
			cin.get();
			getchar();
			system("cls");
		}
		else
			if (optiuneMeniu1 == 2)
			{
				obiectStock.add_Stock();
				system("cls");
			}
			else
				if (optiuneMeniu1 == 3)
				{
					obiectStock.delete_Stock();
					system("cls");
				}

	}
}
void meniu2()
{
	int optiuneMeniu2 = -1;
	while (optiuneMeniu2 != 0)
	{
		cout << "1.Bilant venituri" << endl;
		cout << "2.Bilant cheltuieli" << endl;
		cout << "3.Bilant total" << endl;
		cout << "4.Bilanturi din anii trecuti" << endl;
		cout << "5.Inchiderea anului financiar" << endl;
		cout << "0.Inapoi la meniul principal" << endl;
		cout << "Introduceti cifra corespunzatoare submeniului pe care doriti sa-l accesati: ";
		std::string optiuneMeniuString;
		cin >> optiuneMeniuString;
		bool actualizareEfectuata = false;
		FunctiiIntrari::testCifra(optiuneMeniuString, actualizareEfectuata, optiuneMeniu2);
		if (!actualizareEfectuata)
			optiuneMeniu2 = -1;
		system("cls");
		bilant obiectBilant;
		if (optiuneMeniu2 == 1)
		{
			obiectBilant.readVenit();
		}
		else
			if (optiuneMeniu2 == 2)
			{
				obiectBilant.readCheltuieli();
			}
			else
				if (optiuneMeniu2 == 3)
				{
					obiectBilant.readBilant();
				}
				else
					if (optiuneMeniu2 == 4)
					{
						obiectBilant.readLastYear();
					}
					else
						if (optiuneMeniu2 == 5)
						{
							obiectBilant.nextYear();
						}
	}
}
void meniu3()
{
	int optiuneMeniu3 = -1;
	while (optiuneMeniu3 != 0)
	{
		cout << "1.Afisarea produselor din depozit" << endl;
		cout << "2.Adaugarea produselor in depozit" << endl;
		cout << "3.Vanzarea produselor din depozit" << endl;
		cout << "0.Inapoi la meniul principal" << endl;
		cout << "Introduceti cifra corespunzatoare submeniului pe care doriti sa-l accesati: ";
		std::string optiuneMeniuString;
		cin >> optiuneMeniuString;
		bool actualizareEfectuata = false;
		FunctiiIntrari::testCifra(optiuneMeniuString, actualizareEfectuata, optiuneMeniu3);
		if (!actualizareEfectuata)
			optiuneMeniu3 = -1;
		system("cls");
		storage obiectStorage;
		if (optiuneMeniu3 == 1)
		{
			obiectStorage.read_Storage();
			cin.get();
		}
		else
			if (optiuneMeniu3 == 2)
			{
				obiectStorage.add_Storage();
				cin.get();
			}
			else
				if (optiuneMeniu3 == 3)
				{
					obiectStorage.delete_Storage();
				}
		cin.get();
		system("cls");
	}
}
void meniu4()
{
	int optiuneMeniu4 = -1;
	while (optiuneMeniu4 != 0)
	{
		cout << "1.Afisarea suprafetelor agricole detinute" << endl;
		cout << "2.Cumpararea unei suprafete agricole" << endl;
		cout << "3.Vanzarea unei suprafete agricole" << endl;
		cout << "0.Inapoi la meniul principal" << endl;
		cout << "Introduceti cifra corespunzatoare submeniului pe care doriti sa-l accesati: ";

		std::string optiuneMeniuString;
		cin >> optiuneMeniuString;
		bool actualizareEfectuata = false;
		FunctiiIntrari::testCifra(optiuneMeniuString, actualizareEfectuata, optiuneMeniu4);
		if (!actualizareEfectuata)
			optiuneMeniu4 = -1;
		system("cls");
		farmingArea obiectArea;
		state obiectState;
		if (optiuneMeniu4 == 1)
		{
			obiectArea.read_Area();
			cin.get();
		}
		else
			if (optiuneMeniu4 == 2)
			{
				std::string denumire = "";
				std::cout << "Denumire: ";
				std::cin >> denumire;
				bool existaNumeleInBazaDeDate = false;
				bool existaValoriInFisier = true;
				obiectArea.add_Area(denumire, existaNumeleInBazaDeDate, existaValoriInFisier);
				if (!existaNumeleInBazaDeDate)
					obiectState.add_AreaState(denumire, existaValoriInFisier);
				cin.get();
			}
			else
				if (optiuneMeniu4 == 3)
				{
					std::string nume;
					cout << "Numele suprafetei pe care doriti sa o vindeti: ";
					cin >> nume;
					bool existaNumeleInBazaDeDate = false;
					obiectArea.delete_Area(nume, existaNumeleInBazaDeDate);
					if (existaNumeleInBazaDeDate)
						obiectState.delete_AreaState(nume);
					cin.get();
				}
		cin.get();
		system("cls");
	}
}
void meniu5()
{
	int optiuneMeniu5 = -1;
	while (optiuneMeniu5 != 0)
	{
		cout << "1.Adaugarea unui tratament" << endl;
		cout << "0.Inapoi la meniul principal" << endl;
		cout << "Introduceti cifra corespunzatoare submeniului pe care doriti sa-l accesati: ";
		std::string optiuneMeniuString;
		cin >> optiuneMeniuString;
		bool actualizareEfectuata = false;
		FunctiiIntrari::testCifra(optiuneMeniuString, actualizareEfectuata, optiuneMeniu5);
		if (!actualizareEfectuata)
			optiuneMeniu5 = -1;

		treatment obiectTreatment;
		system("cls");
		if (optiuneMeniu5 == 1)
		{
			obiectTreatment.add_Treatment();
			system("cls");
		}
	}
}
void meniu6()
{
	int optiuneMeniu6 = -1;
	while (optiuneMeniu6 != 0)
	{
		cout << "1.Afisarea starii suprafetelor agricole" << endl;
		cout << "2.Schimbarea starii suprafetelor agricole" << endl;
		cout << "0.Inapoi la meniul principal" << endl;
		cout << "Introduceti cifra corespunzatoare submeniului pe care doriti sa-l accesati: ";
		std::string optiuneMeniuString;
		cin >> optiuneMeniuString;
		bool actualizareEfectuata = false;
		FunctiiIntrari::testCifra(optiuneMeniuString, actualizareEfectuata, optiuneMeniu6);
		if (!actualizareEfectuata)
			optiuneMeniu6 = -1;
		system("cls");
		state obiectState;
		if (optiuneMeniu6 == 1)
		{
			obiectState.read_State();
			cin.get();
		}
		if (optiuneMeniu6 == 2)
		{
			obiectState.switchState();
		}
		cin.get();
		system("cls");
	}

}
void meniu()
{
	int optiuneMeniu = -1;
	while (optiuneMeniu != 0)
	{
		cout << "1.Stoc substante" << endl;
		cout << "2.Bilant" << endl;
		cout << "3.Depozit" << endl;
		cout << "4.Suprafete agricole" << endl;
		cout << "5.Tratamente" << endl;
		cout << "6.Stare" << endl;
		cout << "0.Iesire" << endl;
		cout << "Introduceti cifra corespunzatoare submeniului pe care doriti sa-l accesati: ";
		cin >> optiuneMeniu;
		system("cls");

		if (optiuneMeniu == 1)
		{
			meniu1();
		}
		else
			if (optiuneMeniu == 2)
			{
				meniu2();
			}
			else
				if (optiuneMeniu == 3)
				{
					meniu3();
				}
				else
					if (optiuneMeniu == 4)
					{
						meniu4();
					}
					else
						if (optiuneMeniu == 5)
						{
							meniu5();
						}
						else
							if (optiuneMeniu == 6)
							{
								meniu6();
							}
	}
}
