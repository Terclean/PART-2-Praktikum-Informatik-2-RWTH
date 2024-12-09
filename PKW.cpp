


#include "PKW.h"
#include "Weg.h"
#include "Verhalten.h"
#include <cmath>
#include "SimuClient.h"

PKW::PKW(const std::string& sName, double dmaxGeschwindigkeit, double dVerbrauch, double dTankvolumen)
	: Fahrzeug(sName, dmaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dTankvolumen), p_dTankinhalt(dTankvolumen / 2)
{
}



void PKW::vAusgeben(std::ostream& os) const {
    Fahrzeug::vAusgeben(os);
    os 		<< std::left
    		<< std::setw(10) << std::fixed << std::setprecision(2) << p_dMaxGeschwindigkeit
    		<< std::setw(10) << std::fixed << std::setprecision(2) << p_dGesamtStrecke * (p_dVerbrauch / 100)
    		<< std::setw(10) << std::fixed << std::setprecision(2) << p_dTankinhalt;
}


void PKW::vKopf() const
{
	std::cout << "vKopf 1" << std::endl;
	Fahrzeug::vKopf();
}


void PKW::vZeichnen(Weg& pWeg) const
{
	double dRelPosition = p_dAbschnittStrecke / pWeg.getLaenge();

	if (dRelPosition > 1)
	{
	dRelPosition = 1;
	}

	bZeichnePKW(p_sName, pWeg.getName(), dRelPosition, dGeschwindigkeit(), p_dTankinhalt);
}


void PKW::vSimulieren() {

	if (p_dTankinhalt > 0 && (dGlobaleZeit-p_dZeit)*dGeschwindigkeit()<= p_dTankinhalt/p_dVerbrauch*100) // es ist noch was drin
	{

		p_dTankinhalt -= p_dVerbrauch/100*dGeschwindigkeit()*(dGlobaleZeit-p_dZeit); //Tankinhalt wird reduziert
		Fahrzeug::vSimulieren(); //Fahrzeug f hrt
		double dVerbrauchTank = p_dGesamtStrecke * p_dVerbrauch / 100; // gibt an wieviel verbraucht wurde bisher


		if (p_dTankinhalt <= 0)
		{
			p_dTankinhalt = 0;
		}
	}

	if (p_dTankinhalt > 0 && (dGlobaleZeit - p_dZeit) * dGeschwindigkeit()> p_dTankinhalt / p_dVerbrauch * 100)
		// Fahrzeug schafft es nicht den gesamten Zeitschritt zu fahren

	{



	    double dZeitSeitAbfertigung = dGlobaleZeit - p_dZeit;

	    if (dZeitSeitAbfertigung > 0) {

	    	double dTeilstrecke = p_dTankinhalt / p_dVerbrauch * 100;

	    	p_dAbschnittStrecke += dTeilstrecke;

	        p_dGesamtStrecke += dTeilstrecke;

	        p_dGesamtZeit += dZeitSeitAbfertigung;

	        p_dZeit = dGlobaleZeit;
	    }
	    p_dTankinhalt = 0;

	}

	if ((dGlobaleZeit - p_dZeit) * dGeschwindigkeit()
			> p_dTankinhalt / p_dVerbrauch * 100) {





			    double dZeitSeitAbfertigung = dGlobaleZeit - p_dZeit;

			    if (dZeitSeitAbfertigung > 0) {

			    	double dTeilstrecke = p_dTankinhalt / p_dVerbrauch * 100;

			    	p_dAbschnittStrecke += dTeilstrecke;

			        p_dGesamtStrecke += dTeilstrecke;

			        p_dGesamtZeit += dZeitSeitAbfertigung;

			        p_dZeit = dGlobaleZeit;
			    }
			    p_dTankinhalt = 0;


	}


	else
	{


		if (fabs(this->p_pVerhalten->getWeg()->getLaenge() - p_dAbschnittStrecke) < 1e-100)
		{
			Fahrzeug::vSimulieren();
		}

		p_dZeit = dGlobaleZeit; //Fahrzeug bleibt stehen
	}
}


double PKW::dTanken(double dMenge)
{
	if (dMenge < 0) return 0;
	if (dMenge == 0.0) {
	        dMenge = p_dTankvolumen;
	    }
	double dTankvorher = p_dTankinhalt;
	p_dTankinhalt = std::min(p_dTankinhalt + dMenge,p_dTankvolumen);
	return p_dTankinhalt - dTankvorher;
}


double PKW::dGeschwindigkeit() const
{
    return std::min(p_dMaxGeschwindigkeit , p_pVerhalten->getWeg()->getTempolimit());
}

PKW& PKW::operator=(const PKW& other) {
    if (this != &other) {
        Fahrzeug::operator=(other);

        // Attribute der Unterklasse kopieren
        p_dVerbrauch = other.p_dVerbrauch;
        p_dTankvolumen = other.p_dTankvolumen;
    }
    return *this;
}
