


#include <iostream>
#include <map>
#include <vector>
#include "iomanip"
#include <random>
#include <cmath>
#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include <algorithm>
#include "Weg.h"
#include "Tempolimit.h"
#include <fstream>
#include "vertagt_liste.h"
#include "SimuClient.h"






using namespace std;
double dEpsilon = 0.001;


void vAufgabe_4()
{
	Weg* road = new Weg("Lübecker Str.", 10, Tempolimit::Innerorts);
	road->vKopf();
	std::cout << *road << std::endl;

	return;
}

void vAufgabe_5()
{

	std::unique_ptr<PKW> car = std::make_unique<PKW>("BMW", 60, 5); //PKW wird erzeugt
	std::unique_ptr<Fahrrad> bike = std::make_unique<Fahrrad>("BMX", 24); //Fahrrad wird erzeugt
	Weg road("Königsstraße", 50, Tempolimit::Innerorts); //Weg wird erzeugt

	road.vAnnahme(move(car), 3.0); //Die Fahrzeug Smartpointer werden der Weg Liste hinzugefügt
	road.vAnnahme(move(bike), 1.0);

	road.vKopf(); //Kopfzeile von Weg
	for (dGlobaleZeit = 0; dGlobaleZeit < 4; dGlobaleZeit += 0.1)
	{
		road.vSimulieren(); //Die Fahrzeuge werden Simuliert
		std::cout << road << std::endl; //Weg wird ausgebeben
	}

	std::cout <<"Simulationsende"<<std::endl; //Ausgabe "Simulationsende

	return;
}


void vAufgabe_6()
{

	Weg hin("A5", 500, Tempolimit::Autobahn);
	Weg ruck("Landstr2", 500, Tempolimit::Landstraße);

	std::unique_ptr<PKW> car1 = std::make_unique<PKW>("BMW", 180, 10, 100); //PKW wird erzeugt
	std::unique_ptr<PKW> car2 = std::make_unique<PKW>("Porsche", 300, 20, 100); //PKW wird erzeugt

	std::unique_ptr<Fahrrad> bike1 = std::make_unique<Fahrrad>("BMX", 26); //Fahrrad wird erzeugt
	std::unique_ptr<Fahrrad> bike2 = std::make_unique<Fahrrad>("CityBike", 24); //Fahrrad wird erzeugt

	hin.vAnnahme(move(car1));
	hin.vAnnahme(move(bike2), 0.4);
	ruck.vAnnahme(move(car2));
	ruck.vAnnahme(move(bike1));

	if (!bInitialisiereGrafik(800, 600))
	{
		std::cerr << "Fehler beim Starten des Simulationsservers." << std::endl;
	}

	int iCoords[] = { 700, 250, 100, 250 };
	bZeichneStrasse(hin.getName(), ruck.getName(), 500, 2, iCoords);

	hin.vKopf();
	for (dGlobaleZeit = 0.0f; dGlobaleZeit < 20; dGlobaleZeit += 0.05)
	{
		std::cout << "Aktuelle Zeit: " << dGlobaleZeit << std::endl;
		vSetzeZeit(dGlobaleZeit);
		hin.vSimulieren();
		ruck.vSimulieren();
		std::cout << hin << std::endl;
		std::cout << ruck << std::endl;
		hin.vZeichneFahrzeuge();
		ruck.vZeichneFahrzeuge();
		vSleep(100);

   }

	vBeendeGrafik();
}


void vAufgabe_6a()
{
	static std::mt19937 device(0);
	std::uniform_int_distribution<int> dist(1, 10);
	vertagt::VListe<int> liste1;
	for (int i = 0; i < 10; i++)
	{
		liste1.push_back(dist(device)); // Zufallszahlen von 1 bis 10 werden erzeugt, es immer die selben, da selber Seed, selber Anfang
	}
	std::cout << "Liste mit einlesen der Zahlen vor aktualisieren:  " << std::endl;
	for (auto it = liste1.begin(); it != liste1.end(); it++) // Liste ausgeben
		{ // Über Itaerator von Anfang bis Ende durchgehen; It beschreibt aktuelles Objekt
			std::cout << *it << std::endl;
		}

	liste1.vAktualisieren(); // Liste wird aktualisiert

	std::cout << "Liste mit einlesen der Zahlen nach aktualisieren:  " << std::endl;

	for (auto it = liste1.begin(); it != liste1.end(); it++) // Liste ausgeben
	{ // Über Itaerator von Anfang bis Ende durchgehen; It beschreibt aktuelles Objekt
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;

	for (auto it = liste1.begin(); it != liste1.end();++it)
	{
		if (*it > 5) // Jedes Objekt größer wird gelöscht
		{
			liste1.erase(it); // Objekt wird gelöscht
		}

	}

	std::cout << "Liste nach erase vor aktualisieren: " << std::endl;

	for (auto it = liste1.begin(); it != liste1.end(); it++) // Liste erneut ausgeben
	{ //da vAktualisieren() noch nicht ausgeführt wurde, sollte hier dieselbe Ausgabe erfolgen
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Liste nach erase nach aktualsieren: " << std::endl;

	liste1.vAktualisieren(); // jetzt wird die Liste aktualisiert, damit wird Löschen sichtbar

	for (auto it = liste1.begin(); it != liste1.end(); it++) // Liste wird nach Löschen jetzt ausgebeben
	{
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;

	//Zum Schluss fügen Sie am Anfang und am Ende der Liste noch zwei beliebige (verschiedene) Zahlen ein und geben die Liste zur Kontrolle nochmal aus
	liste1.push_front(4); //Vorne wird die 4 eingefügt
	liste1.push_back(1); // Am Ende wird die 1 hinzugefügt

	liste1.vAktualisieren(); //Liste wird ein letztes Mal aktualsiert

	std::cout << "Liste nach Einfüen der Zahlen und nach aktualisieren: " << std::endl;

	for (auto it = liste1.begin(); it != liste1.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	int eingabe;

	vAufgabe_5();
	while(1){

		std::cout << std::endl;
		std::cout << "Bitte geben Sie die Aufgabe ein, die Sie testen möchten: " << std::endl;
		std::cout << std::endl;
		std::cout << "0: Programm beenden" << std::endl;
		std::cout << "1: Aufgabe 4" << std::endl;
		std::cout << "2: Aufgabe 5" << std::endl;
		std::cout << "3: Aufgabe 6" << std::endl;
		std::cout << "4: Aufgabe 6a" << std::endl;
		std::cin >> eingabe;
		switch (eingabe) {

		case 0:
			return -1;
			break;

		case 1:
			vAufgabe_4();
			break;

		case 2:
			vAufgabe_5();
			break;

		case 3:
			vAufgabe_6();
			break;

		case 4:
			vAufgabe_6a();
			break;

		default:
			std::cout << "Falsche Eingabe" << std::endl;
			break;
		}

	}

    return 0;
}
