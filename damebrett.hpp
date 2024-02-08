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

/*
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);
*/

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
	 * @brief Konstruktor für die Klasse.
	 * 
	 * Setzt die Punkte beider Spieler auf 0. Definiert das Array Spielfeld mit seiner Größe. Ruft die Funktion Spiel auf, welche das gesamte Spiel startet.
	 * @see Spiel()
	 * @post Das Damespiel wurde gestartet und es kann losgehen.
	 * @since 23.01.2024 
	*/
	Damebrett();

	/**
	 * @brief Initialiesiert das Spielfeld mit den Steinen.
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
	 * @pre setSpieler1(), setSpieler2(), damit mit getSpieler() die Namen neben dem Spielfeld zusehen sind
	 * @post Der Spieler sieht das aktuelle Spielfeld und kann sich einen Zug ausdenken.
	 * @since 25.01.2024
	*/
	void ausgabeSpielfeld() const; 

	/**
	 * @brief Spieler 1 wird initialisiert.
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
	 * @brief Spieler 2 wird initialisiert.
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
	 * @brief Gibt Spielernamen aus.
	 * 
	 * Gibt, je nach Parameter, den dazugehörigen Spielernamen aus.
	 * 
	 * @param Person 1 oder 2 --> für Spieler 1 oder Spieler 2
	 * @see ausgabeSpielfeld()
	 * @pre setSpieler1(), setSpieler2()
	 * @post kann in ausgabeSpielfeld() und SiegerMenu() benutzt werden
	 * @since 04.02.2024
	*/
	std::string getSpieler(int Person) const;

	/**
	 * @brief Ließt Zug ein und verarbeitet ihn.
	 * 
	 * Der zuziehende Spieler wird aufgefordert seinen Zug einzugeben. Das Programm überprüft, ob der eingeben Zug im Spielfeld liegt, legal ist (eigene Steine werden bewegt und nur gegnerische Geschlagen) und ob das Feld eine Instanz zurückgesetzt werden soll.
	 * 
	 * @see ist_legalZug(), ZugAusfuehren(), setZugSpeicher(), ZugZueruck(), PunkteZaehlen(), Spieler1(), Spieler2()
	 * @pre StartMenu(), initSpielfeld(), setZugSpeicher()
	 * @post ist_legalZug() wahr, dann ZugAusführen, setZugSpeicher oder ZugZueruck(), PunkteZaehlen()
	 * @since 25.01.2024
	*/
	void zug(int);

	/**
	 * @brief Überprüft ob der Zug legal ist.
	 * 
	 * Es überprüft den Zug für den zuziehenden Spieler. Es schaut ob es sich um einen normalen Zug, schlagenden Zug oder Zurück handelt.
	 * 
	 * @param von_spieler Gibt an welcher Spieler am Zug ist -- 1 oder 2
	 * @param FeldAnfang Übergibt Buchstaben vom Anfangsfeld
	 * @param FeldZiel Übergibt Buchstaben vom Zielfeld
	 * @param ZahlAnfang Übergibt Zahl vom Anfangsfeld
	 * @param ZahlZiel Übergibt Zah vom Zielfeld
	 * @see zug()
	 * @return true, wenn Zug legal oder false, wenn zug nicht legal
	 * @pre Zug innerhalb des Feldes eingegeben
	 * @post Zug ist legal und kann ausgeführt werden
	 * @since 29.01.2024
	*/
	bool ist_legalZug(int von_spieler, const char& FeldAnfang, const char& FeldZiel, const int& ZahlAnfang, const int& ZahlZiel);

	/**
	 * @brief Führt Zug aus
	 * 
	 * Führt den Zug für den Spieler aus. Bei normalem Zug löscht es den Stein an der alten Stelle und schreib ihn in die neue Stelle. Bei Schlag wird der eigenen Stein an der alten Stelle gelöscht, der übersprungene Stein gelöscht, Punkte um 1 erhöht und der Stein an der neuen Stelle platziert.
	 * 
	 * @param welcher_spieler Gibt an von welchem Spieler der Zug ist -- 1 oder 2
	 * @param ReiheJetzt Buchstabe vom Anfangsfeld
	 * @param SpalteJetzt Zahl vom Anfangsfeld
	 * @param ReiheDanach Buchstabe vom Zielfeld
	 * @param SpalteDanach Zahl vom Zielfeld 
	 * @see zug()
	 * @pre korrekte Eingabe eines Zuges der durch ist_legalZug() verifiziert wurde
	 * @post Zug vom Spieler wird angezeigt
	 * @since 04.02.2024
	*/
	void ZugAusfuehren(int welcher_spieler, char ReiheJetzt, int SpalteJetzt, char ReiheDanach, int SpalteDanach);

	/**
	 * @brief Setzt Spielfeld zurück
	 * 
	 * Die Funktioniert löscht das letzte Element des Vektors und setzt das aktuelle Spielfeld gleich dem Spielfeld an der letzten Position des Vektors. Passiert nur, wenn mindestens 1 Feld im Vektor ist.
	 * 
	 * @see Zug()
	 * @pre Spielfeld muss gespeichert sein
	 * @post Vorheriges Spielfeld ist nun aktuelles Spielfeld
	 * @since 02.04.2024 
	*/ 
	void ZugZurueck();

	/**
	 * @brief Speichert Zug
	 * 
	 * Speichert das aktuelle Spielfeld nachdem der Zug vom Spieler ausgeführt wurde in einem Vektor ab.
	 * 
	 * @see Zug()
	 * @pre legaler Zug, welcher nicht das Spielfeld zurücksetzt wurde ausgeführt
	 * @post aktuelle Spielfeld gespeichert
	 * @since @02.04.2024
	*/
	void setZugSpeicher();

	/**
	 * @brief Zählt Punkte der Spieler
	 * 
	 * Wird nach zurücksetzten des Spielfeldes aufgerufen. Geht über Spielfeld drüber und zählt die weißen und schwarzen Steine. Dadurch errechnet es den aktuellen Punktestand und trägt in ein.
	 * 
	 * @see Zug()
	 * @pre ZugZurueck() wurde ausgeführt
	 * @post Spieler besitzen Punkte entsprechend des aktuellen Spielfeldes
	 * @since 07.02.2024
	*/
	void PunkteZaehlen();

	/**
	 * @brief Ließt .txt Datei ein und gibt sie aus.
	 *  
	 * Ließt die Datei ein die im StartMenu() gezeigt wird. Nur kosmetischer Natur, da sie 'DAME' als gepixelt darstellt.
	 *  
	 * @param datei_name Name der .txt Datei die eingelesen wird
	 * @see StartMenu(), Spiel()
	 * @pre Spiel(), da dort StartMenu() aufgerufen wird
	 * @post Bild im Startmenu
	 * @since 07.02.2024
	*/
	void Pixelart_einlesen_ausgeben(std::string datei_name);

	/**
	 * @brief Startmenu zum Starten/Beenden
	 * 
	 * Startmenu mit Einleitungstext. Der Benutzer kann zwischen 'Start' und 'Beenden' wählen.
	 * @see Spiel(), Pixelart_einlesen_ausgeben()
	 * @pre Spiel()
	 * @post Spiel startet oder Programm beendet
	 * @since 07.02.2024
	*/
	void StartMenu(); // 7
	
	/**
	 * @brief Spielerklärung
	 * 
	 * Erklärt die Spielregeln. Geht auf die Eingabe der Züge ein und wie man gewinnen kann.
	 * 
	 * @see StartMenu(), Spiel()
	 * @pre Spiel(), StartMenu() mit 'Start' 
	 * @post Spieler 1 und Spieler 2 initialisiert
	 * @since 07.02.2024
	*/
	void Erklaerung();

	/**
	 * @brief SiegerMenu
	 * 
	 * Das Siegermenu erscheint, wenn ein Spieler 15 Punkte erreicht hat. Es gratuliert ihm zum Sieg und das Programm wird beendet.
	 * 
	 * @see Spiel()
	 * @pre ein Spieler muss 15 Punkte erreicht haben
	 * @post Spieler gewonnen, Programm beendet
	 * @since 07.02.2024
	*/
	void SiegerMenu(int);
	
	/**
	 * @brief Aktionen Spieler 1
	 * 
	 * Alle Aktionen die einen Zug von Spieler 1 darstellen werden abgearbeitet. Das heißt das Spielfeld wird ausgegeben und er kann einen Zug ausführen.
	 * 
	 * @see Zug()
	 * @pre StartMenu(), initSpielfeld(), setZugSpeicher()
	 * @post Spieler 1 abgeschlossen, Spieler 2 am Zug
	 * @since 30.01.2024
	*/
	void Spieler1();

	/**
	 * @brief Aktionen Spieler 2
	 * 
	 * Alle Aktionen die einen Zug von Spieler 2 darstellen werden abgearbeitet. Das heißt das Spielfeld wird ausgegeben und er kann einen Zug ausführen.
	 * 
	 * @see Zug()
	 * @pre StartMenu(), initSpielfeld(), setZugSpeicher()
	 * @post Spieler 2 abgeschlossen, Spieler 1 am Zug
	 * @since 30.01.2024
	*/
	void Spieler2();

	/**
	 * @brief Spiel wird ausgeführt
	 * 
	 * Es wird in der Methode zuerst das StartMenu aufgerufen. Darin werden die Spieler festgelegt. Danach wird das Spielfeld initialisiert und das erste mal abgespeichert. Danach machen Spieler 1 und Spieler 2 Züge bis einer gewonnen hat. Dann erscheint das Siegermenu und das Programm wird beendet.
	 * 
	 * @pre Konstruktor aufgerufen in der Maindatei
	 * @post Spiel startet
	 * @since 30.01.2024
	*/
	void Spiel();
};