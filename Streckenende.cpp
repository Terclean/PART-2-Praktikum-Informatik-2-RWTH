

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <memory>


Streckenende::Streckenende(Fahrzeug& pFahrzeug, Weg& pWeg)
:Fahrausnahme(pFahrzeug, pWeg)
{
}

Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}

void Streckenende::vBearbeiten()
{
	std::cout << p_aFahrzeug.getName() << "  " << p_aWeg.getName() << "  Ausnahme: Streckenende " << std::endl;
	 p_aWeg.vAbgabe(p_aFahrzeug);
}

