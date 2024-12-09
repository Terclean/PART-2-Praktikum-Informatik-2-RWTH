
#ifndef PARKEN_H_
#define PARKEN_H_

#include "Verhalten.h"

class Parken: public Verhalten {
private:
	const double p_dStartZeitpunkt;
public:
	Parken(Weg& pWeg, double dStartZeitpunkt);
	virtual ~Parken();

	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
};

#endif /* PARKEN_H_ */
