#include "bilant.h"
#include <iostream>
#include <fstream>
bilant::bilant(float v, float c, float p)
{
	setBilant(v, c, p);
}
void bilant::setBilant(float v, float c, float p)
{
	venit = v;
	cheltuieli = c;
	profit = p;
}
void bilant::printBilant() const
{
	std::cout << "Venituri: " << venit << std::endl;
	std::cout << "Cheltuieli: " << cheltuieli << std::endl;
	std::cout << "Profit: " << profit << std::endl;
}
void bilant::readVenit()
{
	std::ifstream bilantFile("bilant.txt");
	float venit = 0;
	bilantFile >> venit;
	std::cout << "Venitul este: " << venit << " lei.";
	getchar();
	std::cin.get();
	system("cls");
}
void bilant::readCheltuieli()
{
	std::ifstream bilantFile("bilant.txt");
	float venit = 0;
	float cheltuieli = 0;
	bilantFile >> venit;
	bilantFile >> cheltuieli;
	std::cout << "Cheltuielile se ridica la suma de: " << cheltuieli << " lei.";
	getchar();
	std::cin.get();
	system("cls");
}
void bilant::readBilant()
{
	std::ifstream bilantFile("bilant.txt");
	float venit = 0;
	float cheltuieli = 0;
	float profit = 0;
	bilantFile >> venit;
	bilantFile >> cheltuieli;
	bilantFile >> profit;
	std::cout << "Venituri: " << venit << " lei." << std::endl;
	std::cout << "Cheltuieli: " << cheltuieli << " lei." << std::endl;
	std::cout << "Profit: " << profit << " lei." << std::endl;
	getchar();
	std::cin.get();
	system("cls");
}
void bilant::setVenit(float venitUser)
{
	venit = venitUser;
}
void bilant::setCheltuieli(float cheltuieliUser)
{
	cheltuieli = cheltuieliUser;
}
void bilant::setProfit()
{
	profit = venit - cheltuieli;
}
void bilant::insertBilant()
{
	std::ofstream bilantFile("bilant.txt", std::ofstream::app);
	bilantFile << venit << " " << cheltuieli << " " << profit << std::flush;
}
void bilant::insertBilantNextLine()
{
	std::ofstream bilantFile("bilantLastYear.txt", std::ofstream::app);
	bilantFile << std::endl;
	bilantFile << venit << " " << cheltuieli << " " << profit << std::flush;
}
void bilant::nextYear()
{

	bool inchidereAnFinanciar = false;
	int primulAn = 2017;
	int anFisier = 0;
	int anFisierTemp = 0;
	system("cls");
	std::cout << "Sunteti sigur ca doriti sa incheiati anul financiar? 1 [DA]  0 [NU]: ";
	std::cin >> inchidereAnFinanciar;
	if (inchidereAnFinanciar)
	{
		std::ifstream oldBilantFile("bilantLastYear.txt", std::ofstream::app);
		while (oldBilantFile.good())
		{
			oldBilantFile >> anFisierTemp;
			oldBilantFile >> venit;
			oldBilantFile >> cheltuieli;
			oldBilantFile >> profit;
			if (anFisierTemp != 0)
			{
				anFisier = anFisierTemp;
			}
		}
		oldBilantFile.close();
		std::ofstream oldBilantFile1("bilantLastYear.txt", std::ofstream::app);

		if (anFisier == 0)
		{
			std::ifstream bilantFile("bilant.txt");
			bilantFile >> venit;
			bilantFile >> cheltuieli;
			bilantFile >> profit;
			oldBilantFile1 << primulAn << " " << venit << " " << cheltuieli << " " << profit << std::flush;
		}
		else
			if (anFisier != 0)
			{
				anFisier++;
				std::ifstream bilantFile("bilant.txt");
				bilantFile >> venit;
				bilantFile >> cheltuieli;
				bilantFile >> profit;
				oldBilantFile1 << std::endl;
				oldBilantFile1 << anFisier << " " << venit << " " << cheltuieli << " " << profit << std::flush;
				bilantFile.close();
				oldBilantFile1.close();

			}
	}
	std::ifstream newBilantFile("bilant.txt", std::ofstream::out | std::ofstream::trunc);
	newBilantFile.close();
	system("cls");
}
void bilant::readLastYear()
{
	int anFisier = 0;
	std::ifstream oldBilantFile("bilantLastYear.txt");
	while (oldBilantFile.good())
	{
		oldBilantFile >> anFisier;
		oldBilantFile >> venit;
		oldBilantFile >> cheltuieli;
		oldBilantFile >> profit;
		std::cout << "Bilantul pe anul: " << anFisier << std::endl;
		std::cout << "Venit: " << venit << std::endl;
		std::cout << "Cheltuieli: " << cheltuieli << std::endl;
		std::cout << "Profit: " << profit << std::endl;
		std::cout << std::endl;
	}
	if (anFisier == 0)
	{
		system("cls");
		std::cout << "Acesta este primul an. Pentru a afla bilantul actual va rugam verificati -Bilant total- disponibil la punctul 3 al acestui meniu!" << std::endl;
		std::cout << "Va multumim!";
	}
	oldBilantFile.close();
	getchar();
	std::cin.get();
	system("cls");
}