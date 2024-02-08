//damebrett.hpp
#pragma once
#include<iostream>
#include<iomanip>
#include<array>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>

using FELD = std::array<std::array<std::string, 10>, 10 >; 

const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);

/**
 * @brief Die Klasse Damebrett initialiesiert das Spielfeld mit den Spielsteinen beider Spieler. Es erstellt ein Spiel für zwei Spieler und führt die eingegebenen Züge aus.
 * 
 * Die Klasse Damebrett ist für das gesamte Spiel Dame zuständig. Im private-Teil der Klasse werden die Spielernamen sowie deren Punkte gespeichert. Zudem wird das Spielfeld als Array initialisiert und der Speicher von allen Spielfeldern als Vector initialisiert.
 * Im public-Teil werden die gesamten Methoden definiert für die das Spiel wichtig sind. Zum einen werden Methoden definiert, welche für die Initialisierung und Ausgabe des Spielfelds zuständig sind. Dann gibt es Methoden die die Spieler erstellen und abrufen. Des weiteren gibt es Methoden die für die Züge der Spieler verantwortlich sind. Sie nehmen den Zug auf, überprüfen ihn und führen ihn aus. In manchen Fällen wird der vorherrige Zug rückgängig gemacht und die Punkte errechnet.
 * Dann gibt es noch Methoden für die Ausgabe der Start, Erklärung und Siegermenus. Zu guter Letzt gibt es zwei Methoden die die Abläufe für den jeweiligen Spieler definieren und eine Methode, welche die Abläufe der Spieler und alle Menus zusammennimmt, um das vollständige Spiel zu kreieren.
 * 
 * @author Vincent Götze
 */

class Damebrett
{
private:
	std::string spieler1;
	std::string spieler2;

	unsigned int punkte_spieler1;
	unsigned int punkte_spieler2;

	FELD spielfeld;

	std::vector <FELD> speicherSpielfeld;
public:
	
	/**
	 * @brief Konstruktor für die Klasse
	 * 
	 * Setzt die Punkte beider Spieler auf 0. Definiert das Array Spielfeld mit seiner Größe. Ruft die Funktion Spiel auf, welche das gesamte Spiel startet.
	 * @see Spiel()
	 * @post Das Damespiel wurde gestartet und es kann losgehen.
	 * @since 23.01.2024 
	*/
	Damebrett();

	/**
	 * @brief Initialiesiert das Spielfeld mit den Steinen
	 * 
	 * Initialisert das 10x10 Spielfeld mit schwarzen und weißen Steinen. Alle Spielsteine stehen auf graden Feldern. Die schwarzen Steine werden mit "s" im Array vermerkt und gehen von Index 0-2. Die weißen Steine werden mit "w" im Array vermerkt und gehen von Index 7-9. Wenn kein Stein gesetzt wird, wird die Stelle mit " " besetzt.
	 * 
	 * @see Spiel()
	 * @pre Spiel() muss aufgerufen werden
	 * @post Steine für die Spieler stehen bereit. Sie können diese nun bewegen.
	 * @since 25.01.2024
	*/
	void initSpielfeld();

	/**
	 * @brief Gibt das Spielfeld in der Konsole aus.
	 * 
	 * Das 10x10 Spielfeld wird mit schwarz-weißem Hintergrund und einer Beschriftung der Seiten ausgegeben. Die Steine der Spieler sind mit eingefärbten '( )' gekennzeichnet. Die Farbe der Steine ist gleich der Namen der Spieler neben dem Feld. Zudem sind die Namen und aktuellen Punkte auf Höhe der Startposition der eigenen Steine.
	 * 
	 * @see Spiel()
	 * @pre setSpieler1(), setSpieler2(), damit mit getSpieler(int Person) die Namen neben dem Spielfeld zusehen sind
	 * @post Der Spieler sieht das aktuelle Spielfeld und kann sich einen Zug ausdenken.
	 * @since 25.01.2024
	*/
	void ausgabeSpielfeld() const; 

	/**
	 * @brief Spieler 1 wird initialisiert 
	 * 
	 * Spieler 1 wird nach seinem Namen gefragt. Dieser wird dann gespeichert.
	 * 
	 * @see Spiel() -- StartMenu() in Spiel()
	 * @pre StartMenu()
	 * @post Spieler 1 besitzt Namen der neben Spielfeld und bei Eingabe angegeben werden kann
	 * @since 26.01.2024
	*/
	void setSpieler1();

	/**
	 * @brief Spieler 2 wird initialisiert 
	 * 
	 * Spieler 2 wird nach seinem Namen gefragt. Dieser wird dann gespeichert.
	 * 
	 * @see Spiel() -- StartMenu() in Spiel()
	 * @pre StartMenu()
	 * @post Spieler 2 besitzt Namen der neben Spielfeld und bei Eingabe angegeben werden kann
	 * @since 26.01.2024
	*/
	void setSpieler2();

	/**
	 * @brief Gibt Spielernamen aus
	 * 
	 * Gibt, je nach Parameter, den dazugehörigen Spielernamen aus.
	 * 
	 * @param Person 1 oder 2 --> für Spieler 1 oder Spieler 2
	 * @see 
	 * @pre setSpieler1(), setSpieler2()
	 * @post kann in ausgabeSpielfeld() und SiegerMenu(int Sieger) benutzt werden
	 * @since 04.02.2024
	*/
	std::string getSpieler(int Person) const;

	void zug(int); //25.1.
	bool ist_legalZug(int, const char&, const char&, const int&, const int&);
	void ZugAusfuehren(int, char, int, char, int); // 4.2. 
	void ZugZurueck();
	void setZugSpeicher();
	void PunkteZaehlen();

	void Pixelart_einlesen_ausgeben(std::string);
	void StartMenu();
	void Erklaerung();
	void SiegerMenu(int);
	
	void Spieler1(); //@since 30.01.2024
	void Spieler2();
	void Spiel(); 
};
