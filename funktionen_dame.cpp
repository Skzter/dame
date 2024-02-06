//funktionen_dame.cpp
#include"damebrett.hpp"

Damebrett::Damebrett()
{
	setSpieler1();
	setSpieler2();
	FELD spielfeld;
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

std::string Damebrett::getSpieler(int Person) const
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

void Damebrett::ausgabeSpielfeld() const
{
	char buchstabe = 'A';
	for(int i = 0; i <= 9; i++)
	{
		std::cout << std::setw(2) << 10-i << " ";
		for(int j = 0; j <= 9; j++)
		{
			if(!((i+j)%2))
			{
				std::cout << "\33[47m   \33[0m"; // 47 = Weiß (bg)
			}
			else
			{
				if(spielfeld.at(i).at(j) == "w")
				{
					std::cout << "\33[96m\33[40m( )\33[0m"; // 96 = Cyan (fg); 40 = Schwarz (bg)
				}
				if(spielfeld.at(i).at(j) == "s")
				{	
					std::cout << "\33[95m\33[40m( )\33[0m"; // 95 = Magenta (fg); 40 = Schwarz (bg)
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

	do{	
		std::cout << getSpieler(spieler_erkennung) << " " << spieler_erkennung << " (1 = unten, 2 = oben), gib deinen Zug ein > ";

		std::getline(std::cin, zug);
		std::stringstream test(zug);
		
		test >> B1 >> Z1 >> B2 >> Z2;

		B1 -= 'A'; //Fa
		B2 -= 'A'; //Fz
		Z1--;      //Za
		Z2--;	   //Zz

	}while(!((B1 >= 0 && B1 <= 9) && (Z1 >= 0 && Z1 <= 9) && (B2 >= 0 && B2 <= 9) && (Z2 >= 0 && Z2 <= 9) && ist_legalZug(spieler_erkennung, B1, B2, Z1, Z2) || (B1 == -20)));

	if(B1 == -20)
	{
		std::cout << "weruhjoi \n";
	}

	ZugAusfuehren(spieler_erkennung, B1, Z1, B2, Z2);

}

bool Damebrett::ist_legalZug(int von_spieler, const char& Fa, const char& Fz, const int& Za, const int& Zz)  // Switch Case mit Spieler1/2 als übergabe in dieser und Zugfunktion
{
	if(von_spieler == 1)
	{
		if(((Zz == Za+1) && ((Fz == Fa+1) || (Fz == Fa-1))) && (spielfeld.at(9-Zz).at(Fz) == " ")) // Zug eine Zeile nach unten und eine Spalte nach links/recht und Zielfeld frei
		{																 				 // normaler Zug, fehlt noch, dass feld grade aber theoretisch keine falschen Züge mgl
			return true;
		}
		
		else if(((Zz == Za+2) && (Fz == Fa+2) && (spielfeld.at(9-Zz).at(Fz) == " ")) && (spielfeld.at(9-Zz+1).at(Fz-1) == "s")) // Schlag für diagonal rechts oben, zwischen "s" und ziel frei
		{
			return true;
		} 
	
		else if(((Zz == Za+2) && (Fz == Fa-2) && (spielfeld.at(9-Zz).at(Fz) == " ")) && (spielfeld.at(9-Zz+1).at(Fz+1) == "s")) // Schlag für diagobal links oben, zwischen "s" und ziel frei
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(von_spieler == 2)
	{
		if((Zz == Za-1) && ((Fz == Fa+1) || (Fz == Fa-1))&& spielfeld.at(9-Zz).at(Fz) == " ")
		{
			return true;
		}
		if(((Zz == Za-2) && (Fz == Fa-2) && (spielfeld.at(9-Zz).at(Fz) == " ")) && (spielfeld.at(9-Zz-1).at(Fz+1) == "s")) // Schlag für diagonal links unten, zwischen "s" und ziel frei
		{
			return true;
		} 
		if(((Zz == Za-2) && (Fz == Fa+2) && (spielfeld.at(9-Zz).at(Fz) == " ")) && (spielfeld.at(9-Zz-1).at(Fz-1) == "s")) // Schlag für diagonal links unten, zwischen "s" und ziel frei
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	return false;
}
void Damebrett::ZugAusfuehren(int welcher_spieler, char ReiheJetzt, int SpalteJetzt, char ReiheDanach, int SpalteDanach )
{
	spielfeld.at(9-SpalteJetzt).at(ReiheJetzt) = " ";

	switch(welcher_spieler)
	{
		case 1:
		{
			spielfeld.at(9-SpalteDanach).at(ReiheDanach) = "w";
			break;
		}
		case 2:
		{
			spielfeld.at(9-SpalteDanach).at(ReiheDanach) = "s";
			break;
		}
	}
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
