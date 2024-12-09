

#include "Fahren.h"
#include "Fahrzeug.h"
#include "Streckenende.h"

Fahren::Fahren(Weg& pWeg)
:Verhalten(pWeg)
{
}

Fahren::~Fahren()
{
}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if(aFzg.dGeschwindigkeit() * dZeitIntervall < p_pWeg->getLaenge() - aFzg.getAbschnittStrecke())
	{
		return aFzg.dGeschwindigkeit() * dZeitIntervall;
	}

	else
	{
		Streckenende* streckenende = new Streckenende(aFzg, *p_pWeg);
		throw 	streckenende;
	}
}

