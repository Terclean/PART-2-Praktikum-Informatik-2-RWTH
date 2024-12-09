

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"

class Losfahren: public Fahrausnahme {
public:
	Losfahren(Fahrzeug& pFahrzeug, Weg& pWeg);
	virtual ~Losfahren();

	void vBearbeiten() override;
};

#endif /* LOSFAHREN_H_ */
