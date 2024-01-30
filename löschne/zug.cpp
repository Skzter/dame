#include<iostream>
#include<array>
#include<sstream>
#include<string>

using FELD = std::array<std::array<std::string, 10>, 10 >; 

void Zug(std::string);
bool ist_legalZug(std::array, std::string, char, char, int, int);

int main()
{
	FELD spielfeld;
	std::string sp1 = Bruno;
	std::string sp2 = Vincent;

	while(true)
	{
		zug(Bruno);
		zug(Vincent);
	}
}

void Zug(std::string spieler)
{
	std::string zug;

	char B1, B2;
	int Z1, Z2;
	
	do{
		std::getline(std::cin, zug);
		std::stringstream test(zug);
		
		test >> B1 >> Z1 >> B2 >> Z2;
	}while(!((B1 >= 'A' && B1 <= 'J') && (Z1 >= 1 && Z1 <= 10) && (B2 >= 'A' && B2 <= 'J') && (Z2 >= 1 && Z2 <= 10) && ist_legalZug(feld, spieler, B1, Z1, B2, Z2)));
	
	std::cout << B1 << Z1 << " " << B2 << Z2;
}

bool ist_legalZug(std::array spielfeld, std::string spieler, char Fa, char Fz, int Za, int Zz)  // Switch Case mit Spieler1/2 als übergabe in dieser und Zugfunktion
{
	switch(spieler)
	{
		case "Spieler 1":
			if(spielfeld.at(9-Zz).at(Fz) == " ") // oben links bei Array/ Feld unten links Start -- Spieler 1 oben
			{
				return true;
			}
			break;
		case "Spieler 2":
			if(spielfeld.at(9-Zz).at(Fz) == " ") // oben links bei Array/ Feld unten links Start -- Spieler 2 unten
			{
				return true;
			}
			break;
	}

	return false;
}

