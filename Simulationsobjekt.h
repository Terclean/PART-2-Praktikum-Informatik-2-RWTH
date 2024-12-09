


#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <memory>

#include "global.h"


class Simulationsobjekt {
private:

	const int p_iID;
	static int p_iMaxID;

protected:
	double p_dZeit;
	std::string p_sName;

public:
	Simulationsobjekt(std::string name = "");
	Simulationsobjekt(const Simulationsobjekt&) = delete; // Verbietet den Copy-Konstruktor
	virtual ~Simulationsobjekt();

	//Funktionen
	virtual void vKopf() const;
	virtual void vAusgeben(std::ostream& os) const = 0;
	virtual void vSimulieren() = 0; //Das ist die reine virtuelle Methode der Abstraken Oberklasse

	std::string getName() const;
	int getID() const;

	friend std::ostream& operator<<(std::ostream& os, const Simulationsobjekt& obj);
	bool operator==(const Simulationsobjekt&) const;
	Simulationsobjekt& operator=(const Simulationsobjekt& other);
};

#endif /* SIMULATIONSOBJEKT_H_ */
