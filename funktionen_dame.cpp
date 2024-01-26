//funktionen_dame.cpp
#include"damebrett.hpp"

Damebrett::Damebrett(FELD f)
{
	setSpieler1();
	setSpieler2();
	spielfeld = f;

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

std::string Damebrett::getSpieler1()
{
	return spieler1;
}

std::string Damebrett::getSpieler2()
{
	return spieler2;
}

void Damebrett::initSpielfeld()
{
	/*
	 * Feld mit weißen und schwarzen Steinen
	 * vllt Vector
	 */
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
	for(int i = 0; i <= 9; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			if(!((i+j)%2))
			{
				std::cout << "\33[47m  \33[0m"; // 47 = Weiß
			}
			else
			{
				std::cout << "\33[40m" << /*spielfeld.at(i).at(j) << */"()" << "\33[0m"; //40 = Schwarz 
			}
		}
	std::cout << "\n";
	}
}

void Damebrett::zug()
{
	size_t posSpace = 0;
	std::string zug_nutzer = "xxxxx";
	while(!((zug_nutzer.at(0) >= 'A' && zug_nutzer.at(0) <= 'J') && (zug_nutzer.at(1) >= '0' && zug_nutzer.at(1) <= '9') && (zug_nutzer.at(2) == ' ') && (zug_nutzer.at(3) >= 'A' && zug_nutzer.at(3) <= 'J') && (zug_nutzer.at(4) >= '0' && zug_nutzer.at(4) <= '9'))) // 0: Buchstabe 'A' bis 'J', 1: Zahl 1 bis 10, 2: space, 3: Buchstabe 'A' bis 'J', 4: Zahl 1 - 10
	{
		std::cout << "Geben sie ihren Zug ein > ";
		std::getline(std::cin, zug_nutzer);
	}
	std::string alt;
	std::string neu;
	
	alt = zug_nutzer.substr(0,2);
	neu = zug_nutzer.substr(3,2);
	
	std::cout << alt << "*" << neu << std::endl;
}

