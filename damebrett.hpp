//damebrett.hpp

#pragma once
#include<array>
#include<string>

using FELD = std::array<std::array<std::string, 10>, 10 >; 


class Damebrett
{
private:
	std::string spieler1;
	std::string spieler2;
	
	FELD spielfeld;
public:
	Damebrett(FELD, std::string, std::string); //Konstruktor
	
	FELD initSpielfeld(FELD);


	FELD aktuelleSpielfeld(FELD);
	
	void zug(std::string); // "A1 B2" z.B.
	void zug_rück(char); // "-" Taste      

	void ausgabeFeld();

	std::string getSpieler1();
	std::string getSpieler2();

};
