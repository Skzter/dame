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
				if(spielfeld.at(i).at(j) == "w")
				{
					std::cout << "\33[96m\33[40m()\33[0m";
				}
				if(spielfeld.at(i).at(j) == "s")
				{
					std::cout << "\33[95m\33[40m()\33[0m";
				}
				if(spielfeld.at(i).at(j) == " ")
				{
					std::cout << "\33[40m  \33[0m";
				}
			}
		}
	std::cout << "\n";
	}
}

void Damebrett::zug()
{
	std::string zug;

	char B1, B2;
	int Z1, Z2;


	std::cout << "Jeden Zug im Format BuchstabeZahl BuchstabeZahl eingeben. Zum Beispiel A1 B2.\n";

	do{	
		std::cout << "Bitte geben sie ihren Zug ein > ";

		std::getline(std::cin, zug);
		std::stringstream test(zug);
		
		test >> B1 >> Z1 >> B2 >> Z2;

		B1 -= 'A'; //Fa
		B2 -= 'A'; //Fz
		Z1--;      //Za
		Z2--;	   //Zz
		
			

	}while(!((B1 >= 0 && B1 <= 9) && (Z1 >= 0 && Z1 <= 9) && (B2 >= 0 && B2 <= 9) && (Z2 >= 0 && Z2 <= 9) && ist_legalZug(B1, B2, Z1, Z2)));
		

}

bool Damebrett::ist_legalZug(char Fa, char Fz, int Za, int Zz)
{
	if(spielfeld.at(9-Zz).at(Fz) == " ")
	{
		return true;
	}
	return false;
}

