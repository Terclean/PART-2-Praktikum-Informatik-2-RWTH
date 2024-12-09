

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_

#include <exception> // Corrected the inclusion of exception
#include "fahrzeug.h"
#include "weg.h"
#include "vertagt_liste.h"

class Fahrausnahme: public std::exception {
protected:
    Fahrzeug& p_aFahrzeug;
    Weg& p_aWeg;
public:
    Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg);
    virtual ~Fahrausnahme();

    virtual void vBearbeiten() = 0;
};

#endif /* FAHRAUSNAHME_H_ */
