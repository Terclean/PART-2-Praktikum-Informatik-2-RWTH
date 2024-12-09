


#ifndef WEG_H_
#define WEG_H_

#include "Simulationsobjekt.h"
#include <list>
#include "Tempolimit.h"
#include "vertagt_liste.h"


class Fahrzeug;

class Weg: public Simulationsobjekt {
private:
	const double p_dLaenge;
	Tempolimit p_eTempolimit;
	vertagt::VListe<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;


public:
	Weg();  // Standardkonstruktor
	Weg(const std::string& name, double laenge, Tempolimit tempolimit = Tempolimit::Autobahn);

	~Weg();

	double getTempolimit() const;
	double getLaenge() const;

	void vKopf() const override;
	void vAusgeben(std::ostream& os) const override;
	void vSimulieren() override;


	void vZeichneFahrzeuge();

	void vAnnahme(std::unique_ptr<Fahrzeug>);
	void vAnnahme(std::unique_ptr<Fahrzeug>, double);
	std::unique_ptr<Fahrzeug> vAbgabe(const Fahrzeug& fahrzeug);

};

#endif /* WEG_H_ */
