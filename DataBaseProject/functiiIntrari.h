#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
//#pragma warning(disable : 4996)
class FunctiiIntrari
{
public:
	static void formatNume(std::string &nume)
	{
		nume[0] = toupper(nume[0]);
		for (int i = 1; i < size(nume); i++)
			nume[i] = tolower(nume[i]);
	}
	static void testCifra(std::string& cifra, bool &actualizareEfectuata, int& cifraInt)
	{
		int numarulDeCifre = 0;
		for (int i = 0; i < cifra.size(); i++)
		{
			numarulDeCifre += (int)cifra[i] >= 48 && (int)cifra[i] <= 57 ? 1 : 0;
		}
		if (numarulDeCifre == cifra.size())
		{
			actualizareEfectuata = true;
			cifraInt = stoi(cifra);
		}
		else
			std::cout << "Cifra introdusa este incorecta!";
	}
};