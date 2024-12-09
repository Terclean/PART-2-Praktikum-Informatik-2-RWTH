

#include "Parken.h"
#include "Fahrzeug.h"
#include "Losfahren.h"

Parken::Parken(Weg& pWeg, double dStartZeitpunkt)
:Verhalten(pWeg), p_dStartZeitpunkt(dStartZeitpunkt)
{


}

Parken::~Parken()
{
}

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if(dGlobaleZeit < p_dStartZeitpunkt)
	{
		return 0.0;
	}
	else
	{
		Losfahren* losfahren = new Losfahren(aFzg, *p_pWeg);
		throw 	losfahren;
	}
}
