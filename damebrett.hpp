//damebrett.hpp

#pragma once
#include<iostream>
#include<iomanip>
#include<array>
#include<vector>
#include<string>
#include<sstream>

using FELD = std::array<std::array<std::string, 10>, 10 >; 


class Damebrett
{
private:
	std::string spieler1;
	std::string spieler2;
	
	std::vector <FELD> speicherSpielfeld;

	FELD spielfeld;
public:
	Damebrett(); //Konstruktor
	
	void initSpielfeld(); // Initialiesiert Spielfeld mit schwarzen und weißen Steinen


	void ausgabeSpielfeld(); // gibt aktuelles Spielfeld aus
	
	void zug(int); // "A1 B2" z.B.
	//void zug_rück(); // "-" Taste      

	void ausgabeFeld();

	void setSpieler1();
	void setSpieler2();

	bool ist_legalZug(int, char, char, int, int);

	std::string getSpieler(int);
	
	void setZugSpeicher();
	void ZugZurueck();

	void Spieler1();
	void Spieler2();
	
	void SpielTest();
};
