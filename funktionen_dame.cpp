//funktionen_dame.cpp
#include"damebrett.hpp"

#include<string>
#include<array>

Damebrett::Damebrett(FELD f, std::string sp1, std::string sp2)
{
	spieler1 = sp1;
	spieler2 = sp2;
	spielfeld = f;

}

std::string Damebrett::getSpieler1()
{
	return spieler1;
}

std::string Damebrett::getSpieler2()
{
	return spieler2;
}

FELD Damebrett::initSpielfeld(FELD feld_neu)
{
	/*
	 * Feld mit weißen und schwarzen Steinen
	 * vllt Vector
	 */
	return feld_neu;
}

	
