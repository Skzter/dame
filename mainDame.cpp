//mainDame.cpp

#include<iostream>
#include<array>
#include<string>

#include"damebrett.hpp"

int main()
{
	FELD testfeld;

	std::cout << "Spieler 1 > ";
	std::string name1;
	std::cin >> name1;

	std::cout << "Spieler 2 > ";
	std::string name2;
	std::cin >> name2;


	Damebrett testobjekt(testfeld, name1, name2);
	std::cout << testobjekt.getSpieler1() << "\n";
	std::cout << testobjekt.getSpieler2() << std::endl;

	testobjekt.initSpielfeld();
	testobjekt.ausgabeSpielfeld();
}
