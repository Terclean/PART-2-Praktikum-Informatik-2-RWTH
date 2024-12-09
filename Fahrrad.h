


#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"

class Fahrrad: public Fahrzeug {

public:
	 Fahrrad(const std::string& sname, double dmaxGeschwindigkeit = 0);
	    ~Fahrrad() override = default;

	    void vAusgeben(std::ostream& os) const override;

	    void vKopf() const override;
	    void vZeichnen(Weg& pWeg) const override;

	    double dTanken(double dMenge) override;
	    double dGeschwindigkeit() const override;

};

#endif /* FAHRRAD_H_ */
