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
	Damebrett(FELD); //Konstruktor
	
	void initSpielfeld(); // Initialiesiert Spielfeld mit schwarzen und weißen Steinen


	void ausgabeSpielfeld(); // gibt aktuelles Spielfeld aus
	
	void zug(); // "A1 B2" z.B.
	void zug_rück(); // "-" Taste      

	void ausgabeFeld();

	void setSpieler1();
	void setSpieler2();
	
	std::string getSpieler1();
	std::string getSpieler2();


};
