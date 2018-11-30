#include "state.h"
#include <fstream>
state::state(std::string name, std::string stare, int zi, int luna, int an) :ultimulTratament(zi, luna, an)
{
	setState(name, stare, zi, luna, an);
}
void state::setState(std::string nume, std::string stare, int zi, int luna, int an)
{
	numeSuprafata = nume;
	stareSuprafata = stare;
}
void state::printState()
{
	std::cout << "Numele suprafetei: " << numeSuprafata << std::endl << "Starea suprafetei: " << stareSuprafata << std::endl;
	std::cout << "Ultimul tratament a fost efectuat in data de : ";
	ultimulTratament.print();
	std::cout << std::endl << std::endl;
}
void state::insertState()
{
	std::ofstream stateFile("state.txt", std::ofstream::app);
	stateFile << std::endl;
	stateFile << numeSuprafata << " " << stareSuprafata << " " << std::flush;
	ultimulTratament.insertDate();
}
void state::insertStateFirstLine()
{
	std::ofstream stateFile("state.txt", std::ofstream::app);
	stateFile << numeSuprafata << " " << stareSuprafata << " " << std::flush;
	ultimulTratament.insertDate();
}
void state::read_State()
{
	std::ifstream stateFile("state.txt");
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
void state::add_AreaState(std::string denumire, bool existaValoriInFisier)
{
	std::ifstream stateFile("state.txt");
	std::vector<state> vectorState;
	std::string stare = "Nespecificat";
	int zi = 1;
	int luna = 1;
	int an = 2000;
	FunctiiIntrari::formatNume(denumire);
	vectorState.push_back(state(denumire, stare, zi, luna, an));
	if (!existaValoriInFisier)
		vectorState[0].insertStateFirstLine();
	else
		vectorState[0].insertState();
}
void state::switchState()
{
	system("cls");
	std::ifstream stateFile("state.txt");
	std::string nume = "";
	std::string stare = "";
	int zi, luna, an;
	std::vector<state> vectorState;
	std::string denumire = "";
	std::cout << "Introduceti numele suprafetei careia doriti sa-i modificati starea: ";
	std::cin >> denumire;
	FunctiiIntrari::formatNume(denumire);
	bool actualizareEfectuata = false;
	bool existaNumeleInBazaDeDate = false;
	while (stateFile.good())
	{
		stateFile >> nume;
		stateFile >> stare;
		stateFile >> zi;
		stateFile >> luna;
		stateFile >> an;
		existaNumeleInBazaDeDate = (nume == denumire);
		if (existaNumeleInBazaDeDate)
		{
			bool stareaSuprafetei = false;
			std::string stareUser = "";
			std::cout << "Starea actuala a suprafetei este: " << stare << std::endl;
			std::cout << "Schimbati starea suprafetei (Recoltat/Nerecoltat): ";
			std::cin >> stareUser;
			FunctiiIntrari::formatNume(stareUser);
			actualizareEfectuata = true;
			stare = stareUser;
		}
		vectorState.push_back(state(nume, stare, zi, luna, an));
	}
	if (actualizareEfectuata)
	{
		stateFile.close();
		std::ifstream stockFile1("state.txt", std::ofstream::out | std::ofstream::trunc);
		vectorState[0].insertStateFirstLine();
		for (int i = 1; i < vectorState.size(); i++)
			vectorState[i].insertState();
	}
	if (!actualizareEfectuata)
		std::cout << "Suprafata nu exista in baza de date." << std::endl;
}
void state::delete_AreaState(std::string denumire)
{
	std::ifstream stateFile("state.txt");
	std::vector<state> vectorState;
	std::string stare = "";
	std::string nume = "";
	int zi = 1;
	int luna = 1;
	int an = 2000;
	FunctiiIntrari::formatNume(denumire);
	bool existaNumeleInFisier = false;
	bool actualizareEfectuata = false;
	while (stateFile.good())
	{
		stateFile >> nume;
		stateFile >> stare;
		stateFile >> zi;
		stateFile >> luna;
		stateFile >> an;
		existaNumeleInFisier = (denumire == nume);
		if (!existaNumeleInFisier)
			vectorState.push_back(state(nume, stare, zi, luna, an));
	}
	stateFile.close();
	std::ifstream stateFileUpdate("state.txt", std::ofstream::out | std::ofstream::trunc);
	vectorState[0].insertStateFirstLine();
	for (int i = 1; i<vectorState.size(); i++)
		vectorState[i].insertState();
}