


#include "Fahrrad.h"
#include "Weg.h"
#include "SimuClient.h"

Fahrrad::Fahrrad(const std::string& sname, double dmaxGeschwindigkeit)
	:Fahrzeug(sname,dmaxGeschwindigkeit)
{
}

void Fahrrad::vAusgeben(std::ostream& os) const {
    Fahrzeug::vAusgeben(os);
    os << std::left << std::setw(10) << std::fixed << std::setprecision(2) << dGeschwindigkeit();
}

void Fahrrad::vKopf() const
{
	Fahrzeug::vKopf();
}


void Fahrrad::vZeichnen(Weg& pWeg) const // Methode noch nachvollziehen
{
	double dRelPosition = p_dAbschnittStrecke / pWeg.getLaenge();

	if (dRelPosition > 1)
	{
		dRelPosition = 1;
	}

	bZeichneFahrrad(p_sName, pWeg.getName(), dRelPosition, dGeschwindigkeit());
}


double Fahrrad::dTanken(double dMenge = 0.0)
{
	return 0.0;
}


double Fahrrad::dGeschwindigkeit() const {
	//weil der natürlich die 90% barucht um das richtig zu berechnen
    double dReduktion = 1.0 - 0.1 * (p_dGesamtStrecke / 20);
    double dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * dReduktion;
    return std::max(dAktuelleGeschwindigkeit, 12.0);
}
