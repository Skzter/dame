//damebrett.hpp

#pragma once
#include<iostream>
#include<iomanip>
#include<array>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>

using FELD = std::array<std::array<std::string, 10>, 10 >; 


class Damebrett
{
private:
	std::string spieler1;
	std::string spieler2;

	unsigned int punkte_spieler1;
	unsigned int punkte_spieler2;

	std::vector <FELD> speicherSpielfeld;

	FELD spielfeld;
public:
	Damebrett(); //Konstruktor
	
	void initSpielfeld(); // Initialiesiert Spielfeld mit schwarzen und weißen Steinen
	void ausgabeSpielfeld() const; // gibt aktuelles Spielfeld aus

	void setSpieler1();
	void setSpieler2();
	std::string getSpieler(int) const;

	void zug(int); // "A1 B2" z.B.
	bool ist_legalZug(int, const char&, const char&, const int&, const int&);
	void ZugAusfuehren(int, char, int, char, int);

	void ZugZurueck();
	void setZugSpeicher();
	void PunkteZaehlen();

	void Pixelart_einlesen_ausgeben(std::string);
	void StartMenu();
	void Erklaerung();
	void SiegerMenu();
	//testmethoden damit game läuft, alles gebündelt
	void Spieler1();
	void Spieler2();
	void SpielTest();
};
