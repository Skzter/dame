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

const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);

class Damebrett
{
private:
	std::string spieler1;
	std::string spieler2;

	unsigned int punkte_spieler1;
	unsigned int punkte_spieler2;

	FELD spielfeld;

	std::vector <FELD> speicherSpielfeld;
public:
	Damebrett();
	void initSpielfeld();
	void ausgabeSpielfeld() const;

	void setSpieler1();
	void setSpieler2();
	std::string getSpieler(int) const;

	void zug(int);
	bool ist_legalZug(int, const char&, const char&, const int&, const int&);
	void ZugAusfuehren(int, char, int, char, int);
	void ZugZurueck();
	void setZugSpeicher();
	void PunkteZaehlen();

	void Pixelart_einlesen_ausgeben(std::string);
	void StartMenu();
	void Erklaerung();
	void SiegerMenu(int);
	
	void Spieler1();
	void Spieler2();
	void Spiel();
};