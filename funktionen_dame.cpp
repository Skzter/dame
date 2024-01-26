//funktionen_dame.cpp
#include"damebrett.hpp"

#include<iostream>
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
				std::cout << "\33[47m \33[0m"; // 47 = Weiß
			}
			else
			{
				std::cout << "\33[40m" << spielfeld.at(i).at(j) << "\33[0m"; //40 = Schwarz 
			}
		}
	std::cout << "\n";
	}
}
