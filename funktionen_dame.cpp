//funktionen_dame.cpp
#include"damebrett.hpp"

Damebrett::Damebrett()
{
	setSpieler1();
	setSpieler2();
	spielfeld;
	SpielTest();
}

void Damebrett::setSpieler1()
{
	std::cout << "Spieler 1 > ";
	std::string sp1;
	std::getline(std::cin, sp1);
	
	spieler1 = sp1;
}

void Damebrett::setSpieler2()
{
	std::cout << "Spieler 2 > ";
	std::string sp2;
	std::getline(std::cin, sp2);

	spieler2 = sp2;
}

std::string Damebrett::getSpieler(int Person)
{
	switch(Person)
	{
		case 1:
			return spieler1;
			break;
		case 2:
			return spieler2;
			break;
		default:
			return "Kaputt";
			break;
	}
}

void Damebrett::initSpielfeld()
{
	for(int i = 0; i <= 9; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			if(i <= 2)
			{
				if((i+j)%2)
				{
					spielfeld.at(i).at(j) = "s";
				}
			}
			
			if(i >= 7)
			{
				if((i+j)%2)
				{
					spielfeld.at(i).at(j) = "w";
				}
			}

			if(i > 2 && i < 7)
			{
				spielfeld.at(i).at(j) = " ";
			}
		}
	}
}

void Damebrett::ausgabeSpielfeld()
{
	char buchstabe = 'A';
	for(int i = 0; i <= 9; i++)
	{
		std::cout << std::setw(2) << 10-i << " ";
		for(int j = 0; j <= 9; j++)
		{
			if(!((i+j)%2))
			{
				std::cout << "\33[47m   \33[0m"; // 47 = Weiß
			}
			else
			{
				if(spielfeld.at(i).at(j) == "w")
				{
					std::cout << "\33[96m\33[40m( )\33[0m";
				}
				if(spielfeld.at(i).at(j) == "s")
				{	
					std::cout << "\33[95m\33[40m( )\33[0m";
				}
				if(spielfeld.at(i).at(j) == " ")
				{
					std::cout << "\33[40m   \33[0m";
			
				}
			}
		}
	std::cout << "\n";
	}

	for(size_t z = 0; z <= 10; z++)
	{
		if(z < 1)
		{
			std::cout << "   ";
		}
		else
		{
			std::cout << " " << buchstabe++ << " ";
		}

	}
	std::cout << "\n";
}

void Damebrett::zug(int spielerDran)
{
	std::string zug;

	int spieler_erkennung = spielerDran;
	
	char B1, B2;
	int Z1, Z2;

	//std::cout << "Jeden Zug im Format BuchstabeZahl BuchstabeZahl eingeben. Zum Beispiel A1 B2.\n";
	//Erklärung der Züge in Startmenu

	do{	
		std::cout << getSpieler(spieler_erkennung) << ", gib deinen Zug ein > ";

		std::getline(std::cin, zug);
		std::stringstream test(zug);
		
		test >> B1 >> Z1 >> B2 >> Z2;

		B1 -= 'A'; //Fa
		B2 -= 'A'; //Fz
		Z1--;      //Za
		Z2--;	   //Zz

	}while(!((B1 >= 0 && B1 <= 9) && (Z1 >= 0 && Z1 <= 9) && (B2 >= 0 && B2 <= 9) && (Z2 >= 0 && Z2 <= 9) && ist_legalZug(spieler_erkennung, B1, B2, Z1, Z2)));

	if(spieler_erkennung == 1)
	{
		spielfeld.at(9-Z1).at(B1) = " ";
		spielfeld.at(9-Z2).at(B2) = "s";
	}
	if(spieler_erkennung == 2)
	{
		spielfeld.at(9-Z1).at(B1) = " ";
		spielfeld.at(9-Z2).at(B2) = "w";
	}
}

bool Damebrett::ist_legalZug(int von_spieler, char Fa, char Fz, int Za, int Zz)  // Switch Case mit Spieler1/2 als übergabe in dieser und Zugfunktion
{
	switch(von_spieler)
	{
		case 1: //Fz > Fa und Zz muss Za-- || Za++ sein -- Schlagen
			return true; //nur für test
			if(spielfeld.at(9-Zz).at(Fz) == " ")
			{
				std::cout << "Spieler 1 \n";
				return true;
			}
		case 2: //Fz < Fa und Zz muss Za-- || Za++ sein -- Schlagen
			return true;
			if(spielfeld.at(9-Zz).at(Fz) == " ")
			{
				std::cout << "Spieler 2 \n";
				return true;
			}
	}
	return false;
}

void Damebrett::Spieler1()
{
	zug(1);
	ausgabeSpielfeld();	
	setZugSpeicher();
}

void Damebrett::Spieler2()
{
	zug(2);
	ausgabeSpielfeld();
	setZugSpeicher();
}

void Damebrett::SpielTest()
{
	size_t i = 0;
	initSpielfeld();
	ausgabeSpielfeld();
	while(true)
	{
		Spieler1();
		Spieler2();
	}
	
	std::cout << "Letzter Zug zurück" << std::endl;

	ZugZurueck(); 

	ausgabeSpielfeld();	
}

void Damebrett::setZugSpeicher()
{
	speicherSpielfeld.push_back(spielfeld);	
}

void Damebrett::ZugZurueck()
{
	speicherSpielfeld.pop_back();
	spielfeld = speicherSpielfeld.at(speicherSpielfeld.size()-1);
}
