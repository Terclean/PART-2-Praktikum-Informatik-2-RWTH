


#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"

class PKW: public Fahrzeug {
private:
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;
public:
	PKW(const std::string& sName, double dmaxGeschwindigkeit, double dVerbrauch, double dTankvolumen = 55);
	~PKW() override = default;

	void vAusgeben(std::ostream& os) const override;
	void vSimulieren() override;

	void vZeichnen(Weg& pWeg) const override;

	void vKopf() const override;

	double dTanken(double dMenge) override;
	double dGeschwindigkeit() const override;

	PKW& operator=(const PKW& other);
};

#endif /* PKW_H_ */
