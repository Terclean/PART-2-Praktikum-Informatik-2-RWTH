

#include "Losfahren.h"

Losfahren::Losfahren(Fahrzeug& pFahrzeug, Weg& pWeg)
:Fahrausnahme(pFahrzeug, pWeg)
{
}

Losfahren::~Losfahren() {
}


void Losfahren::vBearbeiten()
{
	std::cout << p_aFahrzeug.getName() << "  " << p_aWeg.getName() << "  exception: Losfahren" << std::endl;
	std::unique_ptr<Fahrzeug> pFahrzeugKopie = p_aWeg.vAbgabe(p_aFahrzeug); //Fahrzeug wird abgegeben an pFahrzeugKopie
	p_aWeg.vAnnahme(move(pFahrzeugKopie));
}
