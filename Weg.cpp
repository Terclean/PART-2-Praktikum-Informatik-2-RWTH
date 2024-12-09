#include "Weg.h"
#include "Fahrzeug.h"
#include "Streckenende.h"
#include "Losfahren.h"

Weg::Weg()
    : Simulationsobjekt(""), p_dLaenge(0.0), p_eTempolimit(Tempolimit::Autobahn)
{
}


Weg::Weg(const std::string& name, double laenge, Tempolimit tempolimit)
    : Simulationsobjekt(name), p_dLaenge(laenge), p_eTempolimit(tempolimit)
{
}

Weg::~Weg() = default;

double Weg::getTempolimit() const
{
	if(p_eTempolimit == Tempolimit::Autobahn)
		return std::numeric_limits<int>::max();
	else if(p_eTempolimit == Tempolimit::Innerorts)
		return 50;
	else
		return 100;
}

double Weg::getLaenge() const
{
	return p_dLaenge;
}

void Weg::vKopf() const
{
	Simulationsobjekt::vKopf();
	std::cout 	<< std::left
				<< std::setw(15) << "Laenge"
				<< std::setw(15) << "Fahrzeuge"
				<< std::endl;
	std::cout << std::string(120, '-') << std::endl;
}

void Weg::vAusgeben(std::ostream& os) const {
    Simulationsobjekt::vAusgeben(os); // Basisdaten ausgeben
    os << std::left << std::setw(15) << std::fixed << std::setprecision(2) << p_dLaenge << "(";
    for(auto& it : p_pFahrzeuge)
    {
    	os << std::setw(10) << it->getName() << "  ";
    }
    os << ")" << std::endl;
}

void Weg::vSimulieren()
{

	p_pFahrzeuge.vAktualisieren();
	for(auto& it : p_pFahrzeuge)
	{
		p_pFahrzeuge.vAktualisieren();
		try
		{
			it->vSimulieren();

		}
		catch (Fahrausnahme* fahrausnahme)
		{

			fahrausnahme->vBearbeiten();
		}

	}


	p_pFahrzeuge.vAktualisieren();
}


void Weg::vZeichneFahrzeuge()
{
    if (!p_pFahrzeuge.empty())
    {
        for (auto& it : p_pFahrzeuge)
        {
            it->vZeichnen(*this);
        }
    }
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFzg)
{
	pFzg->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(move(pFzg));
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFzg, double dStartzeit)
{
	pFzg->vNeueStrecke(*this, dStartzeit);
	p_pFahrzeuge.push_front(move(pFzg));
}

std::unique_ptr<Fahrzeug> Weg::vAbgabe(const Fahrzeug& pFahrzeug) //spezifisches Fahrzeug löschen

{
	p_pFahrzeuge.vAktualisieren();
	for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		if ((*it != nullptr) && (**it == pFahrzeug))
		{
			std::unique_ptr<Fahrzeug>pFahrzeugLokal = std::move(*it); //Zwischenspeicherung

			p_pFahrzeuge.erase((it)); //Listenelement wird gelöcht



			return pFahrzeugLokal;
		}
	}
	return nullptr;
}
