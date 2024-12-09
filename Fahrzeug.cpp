


#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Fahren.h"
#include "Parken.h"
#include "SimuClient.h"


Fahrzeug::Fahrzeug(std::string sName, double dMaxGeschwindigkeit)
:Simulationsobjekt(std::move(sName)),p_dGesamtZeit(0.0),p_dGesamtStrecke(0.0),p_dMaxGeschwindigkeit(dMaxGeschwindigkeit > 0 ? dMaxGeschwindigkeit : 0), p_dAbschnittStrecke(0.0)
{
}

Fahrzeug::Fahrzeug()
:Simulationsobjekt(),p_dGesamtZeit(0.0),p_dGesamtStrecke(0.0),p_dMaxGeschwindigkeit(0.0), p_dAbschnittStrecke(0.0)
	{

	}

Fahrzeug::~Fahrzeug() = default;



double Fahrzeug::getGesamtStrecke() const
{
	return p_dGesamtStrecke;
}

double Fahrzeug::getAbschnittStrecke() const
{
	return p_dAbschnittStrecke;
}

void Fahrzeug::vKopf() const
{
	Simulationsobjekt::vKopf();
	std::cout 	<< std::left
				<< std::setw(10) << "Gesamtstrecke"
            	<< std::setw(10) << "MaxGeschwindigkeit"
				<< std::setw(10) << "Geschwindigkeit"
				<< std::setw(10) << "Gesamtverbrauch"
				<< std::setw(10) << "Tankinhalt"
				<< std::endl;
	std::cout << std::string(120, '-') << std::endl;
}

void Fahrzeug::vAusgeben(std::ostream& os) const {
    Simulationsobjekt::vAusgeben(os); // Basisdaten ausgeben
    os << std::left << std::setw(10) << std::fixed << std::setprecision(2) << p_dGesamtStrecke
       << std::setw(10) << p_dMaxGeschwindigkeit;
}

void Fahrzeug::vSimulieren() {
    double dZeitSeitAbfertigung = dGlobaleZeit - p_dZeit;

    if (dZeitSeitAbfertigung > 0) {
    	double dTeilstrecke = p_pVerhalten->dStrecke(*this,dZeitSeitAbfertigung);

    	p_dAbschnittStrecke += dTeilstrecke;

        p_dGesamtStrecke += dTeilstrecke;

        p_dGesamtZeit += dZeitSeitAbfertigung;

        p_dZeit = dGlobaleZeit;
    }
}


void Fahrzeug::vZeichnen(Weg& pWeg) const
{
	double dRelPosition = p_dAbschnittStrecke / pWeg.getLaenge();
	bZeichneFahrrad(p_sName, pWeg.getName(), dRelPosition, dGeschwindigkeit());
}


void Fahrzeug::vNeueStrecke(Weg& pWeg)
{
	p_pVerhalten = std::make_unique<Fahren>(pWeg);
	p_dAbschnittStrecke = 0;
}

void Fahrzeug::vNeueStrecke(Weg& pWeg, double dStartzeit)
{
	p_pVerhalten = std::make_unique<Parken>(pWeg,dStartzeit);
	p_dAbschnittStrecke = 0;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

bool Fahrzeug::operator<(const Fahrzeug& other) const {
    return p_dGesamtStrecke < other.p_dGesamtStrecke;
}

Fahrzeug& Fahrzeug::operator=(const Fahrzeug& other) {
    if (this != &other) {
    	Simulationsobjekt::operator=(other);
        p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;
        p_dGesamtStrecke = other.p_dGesamtStrecke;
        p_dGesamtZeit = other.p_dGesamtZeit;
        // Keine Kopie der ID, da sie eindeutig bleiben muss
        // Keine Kopie von Zustandsdaten wie p_dGesamtStrecke, da diese spezifisch für die Instanz sind
    }
    return *this;
}
