//funktionen_dame.cpp
#include"damebrett.hpp"

Damebrett::Damebrett()
{
	punkte_spieler1 = 0;
	punkte_spieler2 = 0;
	
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
	std::system("clear");
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
	if(i == 1)
	{
		std::cout << "\t\33[95m" << getSpieler(2) << "\33[m: " << punkte_spieler2;
	}
	else if(i == 8)
	{
		std::cout << "\t\33[96m" << getSpieler(1) << "\33[m: " << punkte_spieler1;
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
	int spieler_erkennung = spielerDran;
	std::string eingabeSpieler;	
	char B1, B2;
	int Z1, Z2;

	do{	
		std::cout << getSpieler(spieler_erkennung) << ", gib deinen Zug ein > ";

		std::getline(std::cin, eingabeSpieler);
		std::stringstream eingabe(eingabeSpieler);
		
		eingabe >> B1 >> Z1 >> B2 >> Z2;

		B1 -= 'A'; //Fa
		B2 -= 'A'; //Fz
		Z1--;      //Za
		Z2--;	   //Zz

	}while(!(((B1 >= 0 && B1 <= 9) && (Z1 >= 0 && Z1 <= 9) && (B2 >= 0 && B2 <= 9) && (Z2 >= 0 && Z2 <= 9) && ist_legalZug(spieler_erkennung, B1, B2, Z1, Z2)) || (B1 == -20)));

	if(B1 == -20)
	{
		ZugZurueck();
		PunkteZaehlen();
	}
	else
	{
		ZugAusfuehren(spieler_erkennung, B1, Z1, B2, Z2);
		setZugSpeicher();
	}
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
			std::cout << "Falscher Zug! Bitte gib deinen Zug erneut ein. \n";
			return false;
		}
	}
	else if(von_spieler == 2)
	{
		if((Zz == Za-1) && ((Fz == Fa+1) || (Fz == Fa-1))&& spielfeld.at(9-Zz).at(Fz) == " ")
		{
			return true;
		}
		if(((Zz == Za-2) && (Fz == Fa-2) && (spielfeld.at(9-Zz).at(Fz) == " ")) && (spielfeld.at(9-Zz-1).at(Fz+1) == "w")) // Schlag für diagonal links unten, zwischen "s" und ziel frei
		{
			return true;
		} 
		if(((Zz == Za-2) && (Fz == Fa+2) && (spielfeld.at(9-Zz).at(Fz) == " ")) && (spielfeld.at(9-Zz-1).at(Fz-1) == "w")) // Schlag für diagonal links unten, zwischen "s" und ziel frei
		{
			return true;
		}
		else
		{
			std::cout << "Falscher Zug! Bitte gib deinen Zug erneut ein. \n";
			return false;
		}
	}
	
	std::cout << "Falscher Zug! Bitte gib deinen Zug erneut ein. \n";
	return false;
}
void Damebrett::ZugAusfuehren(int welcher_spieler, char ReiheJetzt, int SpalteJetzt, char ReiheDanach, int SpalteDanach )
{
	spielfeld.at(9-SpalteJetzt).at(ReiheJetzt) = " ";
	
	if(welcher_spieler == 1)
	{
		if(SpalteDanach == SpalteJetzt+1)
		{
			spielfeld.at(9-SpalteDanach).at(ReiheDanach) = "w";
		}
		else if((SpalteDanach == SpalteJetzt+2) && (ReiheDanach == ReiheJetzt+2))
		{
			spielfeld.at(9-SpalteDanach+1).at(ReiheDanach-1) = " ";
			spielfeld.at(9-SpalteDanach).at(ReiheDanach) = "w";
			punkte_spieler1++;
		}
		else if((SpalteDanach == SpalteJetzt+2) && (ReiheDanach == ReiheJetzt-2))
		{
			spielfeld.at(9-SpalteDanach+1).at(ReiheDanach+1) = " ";
			spielfeld.at(9-SpalteDanach).at(ReiheDanach) = "w";
			punkte_spieler1++;
		}
	}
	else if(welcher_spieler == 2)
	{
		if(SpalteDanach == SpalteJetzt-1)
		{
			spielfeld.at(9-SpalteDanach).at(ReiheDanach) = "s";
		}
		else if((SpalteDanach == SpalteJetzt-2) && (ReiheDanach == ReiheJetzt+2))
		{
			spielfeld.at(9-SpalteDanach-1).at(ReiheDanach-1) = " ";
			spielfeld.at(9-SpalteDanach).at(ReiheDanach) = "s";
			punkte_spieler2++;
		}
		else if((SpalteDanach == SpalteJetzt-2) && (ReiheDanach == ReiheJetzt-2))
		{
			spielfeld.at(9-SpalteDanach-1).at(ReiheDanach+1) = " ";
			spielfeld.at(9-SpalteDanach).at(ReiheDanach) = "s";
			punkte_spieler2++;
		}
	}
}

void Damebrett::setZugSpeicher()
{
	speicherSpielfeld.push_back(spielfeld);	
}

void Damebrett::ZugZurueck()
{
	if(speicherSpielfeld.size() > 1)
	{
		speicherSpielfeld.pop_back();
		spielfeld = speicherSpielfeld.at(speicherSpielfeld.size()-1);
	}
}

void Damebrett::PunkteZaehlen()
{
	punkte_spieler1 = 15;
	punkte_spieler2 = 15;
	for(size_t i = 0; i <= 9; i++)
	{
		for(size_t j = 0; j <= 9; j++)
		{
			if(spielfeld.at(i).at(j) == "w")
			{
				punkte_spieler2--;
			}
			else if(spielfeld.at(i).at(j) == "s")
			{
				punkte_spieler1--;
			}
		}
	}
}

void Damebrett::Pixelart_einlesen_ausgeben(std::string datei_name)
{
	std::ifstream datei;
	datei.open(datei_name, std::ios::in);

	std::string line;
	while(datei){
		getline(datei, line);
		std::cout<<line<<std::endl;
	}
}

void Damebrett::StartMenu()
{
	std::system("clear");
	Pixelart_einlesen_ausgeben("pixelart.txt");
	std::cout << "Das ist das Startmenu \n";
	std::cout << "Wähle 'Start', um zu spielen oder 'Beenden', um das Programm zu beenden.\n";
	std::cout << "1. Start \n"
		     "2. Beenden \n";
	int eingabe_benutzer;
	do
	{
		std::cin >> eingabe_benutzer;
		std::cin.ignore(100,'\n');

	}
	while(!((eingabe_benutzer == 1) || (eingabe_benutzer == 2)));

	if(eingabe_benutzer == 1)
	{
		setSpieler1();
		setSpieler2();
	}
	else
	{
		std::system("reboot");
	}
}


void Damebrett::SiegerMenu()
{
}


/*----------------------------*/


void Damebrett::Spieler1()
{
	ausgabeSpielfeld();
	zug(1);
}

void Damebrett::Spieler2()
{
	ausgabeSpielfeld();	
	zug(2);
}

void Damebrett::SpielTest()
{	
	StartMenu();
	initSpielfeld();
	setZugSpeicher();
	do
	{
		Spieler1();
		Spieler2();
	}
	while((punkte_spieler1 != 15) || (punkte_spieler2 != 15));

	//Sieger()
}
