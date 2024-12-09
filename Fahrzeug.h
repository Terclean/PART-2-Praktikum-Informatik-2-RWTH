


#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

#include "Simulationsobjekt.h"

class Verhalten;

class Weg;

class Fahrzeug: public Simulationsobjekt {
protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	std::unique_ptr<Verhalten> p_pVerhalten;
	double p_dAbschnittStrecke;


public:
	Fahrzeug(std::string, double dMaxGeschwindigkeit = 0);
	Fahrzeug(const Fahrzeug&) = delete;            // Verbietet den Copy-Konstruktor
	Fahrzeug();
	virtual ~Fahrzeug();

	double getGesamtStrecke() const;
	double getAbschnittStrecke() const;

	virtual void vZeichnen(Weg& pWeg) const;

	//Funktionen:
	virtual void vKopf() const override;
	virtual void vAusgeben(std::ostream& os) const override;
	virtual void vSimulieren() override;

	void vNeueStrecke(Weg&);
	void vNeueStrecke(Weg&, double);

	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;


	bool operator<(const Fahrzeug& other) const;
	Fahrzeug& operator=(const Fahrzeug& other);

};

#endif /* FAHRZEUG_H_ */
