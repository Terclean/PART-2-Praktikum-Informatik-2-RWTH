


#include "Verhalten.h"


Verhalten::Verhalten(Weg& pWeg)
:p_pWeg(&pWeg)
{
}

Verhalten::~Verhalten()
{
}

Weg* Verhalten::getWeg() const
{
	return p_pWeg;
}


