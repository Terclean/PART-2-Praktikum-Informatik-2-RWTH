

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende: public Fahrausnahme {
public:
	Streckenende(Fahrzeug& pFahrzeug, Weg& pWeg);
	virtual ~Streckenende();

	void vBearbeiten() override;
};

#endif /* STRECKENENDE_H_ */
