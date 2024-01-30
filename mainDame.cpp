//mainDame.cpp

#include"damebrett.hpp"

int main()
{
	FELD testfeld;

	Damebrett testobjekt(testfeld);
	
	/*
	std::cout << testobjekt.getSpieler1() << "\n";
	std::cout << testobjekt.getSpieler2() << std::endl;

	testobjekt.initSpielfeld();
	testobjekt.ausgabeSpielfeld();
	testobjekt.zug();

	*/

	testobjekt.SpielTest();
}
