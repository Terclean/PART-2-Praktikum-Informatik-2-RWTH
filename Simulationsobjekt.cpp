


#include "Simulationsobjekt.h"

int Simulationsobjekt::p_iMaxID = 0;

Simulationsobjekt::Simulationsobjekt(std::string name)
	 : p_sName(std::move(name)), p_iID(++p_iMaxID), p_dZeit(0.0)
{
}

Simulationsobjekt::~Simulationsobjekt() {
	std::cout << "Simulationsobjekt [" << p_iID << "] \"" << p_sName << "\" gelöscht." << std::endl;
	std::cout << "Löschen fertg" << std::endl;
}

void Simulationsobjekt::vKopf() const{
    std::cout 	<< std::left
    			<< std::setw(5) << "ID"
				<< std::setw(15) << "Name";
}

void Simulationsobjekt::vAusgeben(std::ostream& os) const {
    os 	<< std::left
    	<<std::setw(5) << p_iID
		<< std::setw(15) << p_sName;
}

std::string Simulationsobjekt::getName() const {
    return p_sName;
}

int Simulationsobjekt::getID() const {
    return p_iID;
}

std::ostream& operator<<(std::ostream& os, const Simulationsobjekt& obj) {
    obj.vAusgeben(os);
    return os;
}

bool Simulationsobjekt::operator==(const Simulationsobjekt& other) const
{
	return p_iID == other.p_iID;
}

Simulationsobjekt& Simulationsobjekt::operator=(const Simulationsobjekt& other) {
    if (this != &other) {
        p_sName = other.p_sName;
        // Keine Kopie der ID, da sie eindeutig bleiben muss
    }
    return *this;
}
