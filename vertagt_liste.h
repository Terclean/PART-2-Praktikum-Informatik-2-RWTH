#pragma once

#include "memory"
#include "vertagt_aktion.h"
#include <list>

namespace vertagt
{
	template <class T>
	class VListe
	{
	private:
		std::list<T> p_objekte;
		std::list<std::unique_ptr<VAktion<T>>> p_aktionen;

	public:
		// Typdefinitionen
		using iterator = typename std::list<T>::iterator;
		using const_iterator = typename std::list<T>::const_iterator;

		// Konstruktoren
		VListe() = default; // Benötigt man einen Standardkonstruktor?
		// Destruktor
		~VListe()
		{
			vAktualisieren();
			p_objekte.clear();
		}

		void clear()
		{
			p_objekte.clear;
		}

		// Lesefunktionen
		const_iterator begin() const
		{
			return p_objekte.begin();
		}
		const_iterator end() const
		{
			return p_objekte.end();
		}
		iterator begin()
		{
			return p_objekte.begin();
		}
		iterator end()
		{
			return p_objekte.end();
		}
		bool empty() const
		{
			return p_objekte.empty();
		}

		// Schreibfunktionen
		void push_back(T obj)
		{
			// Aktionselement für PushBack auf Liste erzeugen
			p_aktionen.push_back(std::make_unique<VPushBack<T>>(p_objekte,std::move(obj)));
		}

		void push_front(T obj)
		{
			// Aktionselement für PushFront auf Liste erzeugen
			p_aktionen.push_back(std::make_unique<VPushFront<T>>(p_objekte,std::move(obj)));
		}

		void erase(iterator it)
		{
			// Aktionselement für PushBack auf Liste erzeugen (hier Iterator statt Objekt !)
			p_aktionen.push_back(std::make_unique<VErase<T>>(p_objekte, it));
		}

		// Änderungen auf Objektliste übertragen
		void vAktualisieren() //aktualisiert p_objekte
		{
			while (!p_aktionen.empty()) // Aktionen müssen nur ausgeführt werden, wenn welche vorhanden sind. Wenn Liste leer ist gibt es keine Aktionen mehr zu machen
			{
				// Aktionszeiger auf 1. Element bestimmen
				std::unique_ptr <VAktion<T>> p_aktion = std::move(*(p_aktionen.begin()));

				// Aktion ausführen
				p_aktion->vAusfuehren(); //Oberste Aktion wird ausgeführt
				p_aktionen.pop_front(); //Wenn Aktion ausgeführt von oben löschen, damit nächste behandelt werdne kann ->Stack Prinzip

			}

			p_aktionen.clear(); // Liste leeren

		}
	};
} // namespace vertagt
