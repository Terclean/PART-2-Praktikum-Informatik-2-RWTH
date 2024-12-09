


#ifndef VERHALTEN_H_
#define VERHALTEN_H_

#include "Weg.h"


class Verhalten {
protected:
	Weg* p_pWeg;
public:
	Verhalten(Weg& pWeg);
	virtual ~Verhalten();

	Weg* getWeg() const;

	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;
};

#endif /* VERHALTEN_H_ */
