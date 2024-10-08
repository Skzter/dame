//funktionen_dame.cpp
#include"damebrett.hpp"

Damebrett::Damebrett()
{
	punkte_spieler1 = 0;
	punkte_spieler2 = 0;
	
	FELD spielfeld;

    Spiel();
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
	std::system("clear -x");
	std::cout << std::endl;
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
	char Buchstabe1, Buchstabe2;
	int Zahl1, Zahl2;

	do{	
		std::cout << getSpieler(spieler_erkennung) << ", gib deinen Zug ein > ";

		std::getline(std::cin, eingabeSpieler);
		std::stringstream eingabe(eingabeSpieler);
		
		eingabe >> Buchstabe1 >> Zahl1 >> Buchstabe2 >> Zahl2;

		Buchstabe1 -= 'A';	
		Buchstabe2 -= 'A'; 	
		Zahl1--;      		
		Zahl2--;	   		

	}while(!(((Buchstabe1 >= 0 && Buchstabe1 <= 9) && (Zahl1 >= 0 && Zahl1 <= 9) && (Buchstabe2 >= 0 && Buchstabe2 <= 9) && (Zahl2 >= 0 && Zahl2 <= 9) && ist_legalZug(spieler_erkennung, Buchstabe1, Buchstabe2, Zahl1, Zahl2)) || (Buchstabe1 == -20)));

	if(Buchstabe1 == -20)
	{
		ZugZurueck();
		PunkteZaehlen();
	}
	else
	{
		ZugAusfuehren(spieler_erkennung, Buchstabe1, Zahl1, Buchstabe2, Zahl2);
		setZugSpeicher();
	}
}

bool Damebrett::ist_legalZug(int von_spieler, const char& FeldAnfang, const char& FeldZiel, const int& ZahlAnfang, const int& ZahlZiel)
{
	if(von_spieler == 1 && spielfeld.at(9-ZahlAnfang).at(FeldAnfang) == "w")
	{
		if(((ZahlZiel == ZahlAnfang+1) && ((FeldZiel == FeldAnfang+1) || (FeldZiel == FeldAnfang-1))) && (spielfeld.at(9-ZahlZiel).at(FeldZiel) == " "))
		{																 				 
			return true;
		}
		else if(((ZahlZiel == ZahlAnfang+2) && (FeldZiel == FeldAnfang+2) && (spielfeld.at(9-ZahlZiel).at(FeldZiel) == " ")) && (spielfeld.at(9-ZahlZiel+1).at(FeldZiel-1) == "s"))
		{
			return true;
		} 
		else if(((ZahlZiel == ZahlAnfang+2) && (FeldZiel == FeldAnfang-2) && (spielfeld.at(9-ZahlZiel).at(FeldZiel) == " ")) && (spielfeld.at(9-ZahlZiel+1).at(FeldZiel+1) == "s"))
		{
			return true;
		}
		else
		{	
			std::cout << "Falscher Zug! Bitte gib deinen Zug erneut ein. \n";
			return false;
		}
	}
	else if(von_spieler == 2 && spielfeld.at(9-ZahlAnfang).at(FeldAnfang) == "s")
	{
		if((ZahlZiel == ZahlAnfang-1) && ((FeldZiel == FeldAnfang+1) || (FeldZiel == FeldAnfang-1)) && spielfeld.at(9-ZahlZiel).at(FeldZiel) == " ")
		{
			return true;
		}
		if(((ZahlZiel == ZahlAnfang-2) && (FeldZiel == FeldAnfang-2) && (spielfeld.at(9-ZahlZiel).at(FeldZiel) == " ")) && (spielfeld.at(9-ZahlZiel-1).at(FeldZiel+1) == "w"))
		{
			return true;
		} 
		if(((ZahlZiel == ZahlAnfang-2) && (FeldZiel == FeldAnfang+2) && (spielfeld.at(9-ZahlZiel).at(FeldZiel) == " ")) && (spielfeld.at(9-ZahlZiel-1).at(FeldZiel-1) == "w"))
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
	while(datei)
	{
		std::getline(datei, line);
		std::cout<<line<<std::endl;
	}
}

void Damebrett::StartMenu()
{
	std::system("clear -x");
	Pixelart_einlesen_ausgeben("pixelart.txt");
	std::cout << "Wähle 'Start', um zu spielen oder 'Beenden', um das Programm zu beenden.\n";
	std::cout << "1. Start \n2. Beenden" << std::endl;
	std::string eingabe_benutzer;
	
	do
	{
		std::cout << "> ";
		std::getline(std::cin, eingabe_benutzer);

	}
	while(!((eingabe_benutzer == "1") || (eingabe_benutzer == "2")));

	if(eingabe_benutzer == "1")
	{
		Erklaerung();
		setSpieler1();
		setSpieler2();
	}
	else
	{
		exit(0);
	}
}

void Damebrett::Erklaerung()
{
	std::system("clear -x");
	std::cout << "Tutorial für das Spiel Dame \n \n";
	std::cout << "Es gibt zwei Spieler mit je 15 Steinen. \33[96mSpieler 1\33[0m besitzt die weißen (\33[96mhier Cyan\33[0m) Steine und \33[95mSpieler 2\33[0m die schwarzen (\33[95mhier Magenta\33[0m) Steine. Jeder Spieler startet mit 0 Punkten. Man bekommt einen Punkt, wenn man einengegnerischen Stein schlägt. Der erste Spieler, der 15 Punkte errreicht gewinnt das Spiel. Wenn das Spiel vorzeitig endet, da keine Züge mehr ausgeführt werden könnnen, gewinnt der Spieler mit den meisten Punkten.\nEingabe der Züge:\nDie Züge werden wie im Schach angegeben. Ein Beispielzug wäre C3 D4. Das bewegt den Stein von Feld C3 zu Feld D4. Möchte man einen Spieler schlagen, gibt man wie gewohnt das Start- und Zielfeld an. Ein Beispielzug wäre D4 B6. Dieser wird nur ausgeführt, wenn auch ein Gegner auf dem übersprungenen Feld steht. Man kann Züge rückgängig machen, indem man '-' eingibt.\nGibt man einen falschen Zug ein, fragt das Programm erneut nach einer Eingabe. Dies geschieht solange bis ein korrekter Zug eingegeben wurde.\n";
	
	std::string eingabe;
	
	do
	{
		std::cout << "Regeln verstanden? (j/n): ";
		std::getline(std::cin, eingabe);
	}
	while(!((eingabe == "j") || (eingabe == "n")));

	std::system("clear -x");
	
	if(eingabe == "n")
	{
		exit(0);
	}
	else if(eingabe == "j")
	{
		std::cout << "Viel Spaß beim Spielen!\n" << std::endl;
		std::cout << "Bitte gebt eure Namen ein damit ihr mit dem Spielen beginnen könnt!" << std::endl;
	}
}


void Damebrett::SiegerMenu(int sieger)
{
	std::system("clear -x");
	std::cout << "Glückwunsch zum Sieg " << getSpieler(sieger) << ". \n";
	std::cout << "Du hast erfolgreich deinen Gegner besiegt. Mögen Ruhm und Reichtum die Folge sein!\n";
}

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

void Damebrett::Spiel()
{	
	StartMenu();
	initSpielfeld();
	setZugSpeicher();
	while(!((punkte_spieler1 == 15) || (punkte_spieler2 == 15)))
	{
		Spieler1();
		if(punkte_spieler1 == 15)
		{
			break;
		}
		Spieler2();
	}

	if(punkte_spieler1 == 15)
	{
		SiegerMenu(1);
	}
	else if(punkte_spieler2 == 15)
	{
		SiegerMenu(2);
	}
}
