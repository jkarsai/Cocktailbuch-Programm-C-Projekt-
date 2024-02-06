/*****************************************************************//**
 * \file   Cocktailbuch.hpp
 * \brief  Enthaltet die Containerklasse
 * 
 * \author Karsai Janos
 * \date   May 2022
 *********************************************************************/
#ifndef COCKTAILBUCH_H
#define COCKTAILBUCH_H
#include "Rezept.hpp"
#include <cassert>

/**
 * @class Cocktailbook 
 * 
 * @brief Diese Klasse ist eine Containerklasse fuer solche Objekte, die die Basisklasse 'class Drink' haben.
 */
class Cocktailbook {
	
	const static unsigned max_size; /** Der dynamische Speicherplatz fuer Getraenke kann als diese Konstante nicht groesser sein. Definiert in Cocktailbuch.cpp. */
	
	Drink** arr; /** Dynamische heterogene Sammlung fuer Pointer vom Typ "Drink*". */
	unsigned size; /** Aktuelle Groesse von 'Drink** arr'. */
public:
	/**
	 * @brief Allokiert Speicherplatz fuer Membervariable 'arr'.
	 * 
	 * Wenn u > 0, dann allokiert dieser Konstruktor leere Stellen, die mit Hilfe des [] Operators einzufuellen sind.
	 * @see operator[]
	 * \param u Erwuenschte (mininale) Groesse von 'arr'.
	 */
	Cocktailbook(unsigned u = 0) : size(u)
	{
		if (size == 0) arr = nullptr;
		else
		{
			assert(size <= max_size);
			arr = new Drink*[size];
		}
	}
	Cocktailbook(const Cocktailbook& other)
	{
		size = other.size;
		if (size == 0) arr = nullptr;
		else
		{
			arr = new Drink * [size];
			for (int i = 0; i < size; i++)
			{
				arr[i] = other.arr[i];
			}
		}
	}
	/**
	 * Vom Anfang bis Ende alle Elemente von 'arr' durch std::cout
		 auf dem Bildschirm schriebet.

		 Weitere erklaerung in Cocktailbuch.cpp.
	 */
	void list(); 
	
	/**
	 * @brief Vom Anfang bis ein gegebenen Position alle Elemente von 'arr' durch std::cout
		 auf dem Bildschirm schriebet.
		

		 Nutzhaft zum Beispiel, wenn der Benutzer mehr Speicherplatz fuer 'arr' als er anwendet allokiert hat. 
		 @param endPos Die gegebene Endposition.
	 */
	void list(unsigned endPos); // vom Anfang bis ein gegebenen Position

	
	Drink atCopy(unsigned pos); 

	/**
	 * @brief Memberfunktion, womit man die heterogene Sammlung mit einem zusaetzlichen Element erweitern kann.
	 * 
	 * Nach der Anruf dieser Funktion wird die Groeße von Membervariable 'arr' inkrementiert. Wenn die Membervariable
	 * 'size' und daimt die Groesse von 'arr' uberflussig waere (d.h. groesser als 'const static unsigned Cocktailbook::max_size'),
	 * dann terminiert dass Programm.
	 * \param d das Element, welches am Ende der Liste zugefuegt wird
	 */
	void pushback(Drink* d);


	// ueberladene Operatoren

	/**
	 * @brief Kaskadierbarer Operator, der ein Element zur heterogener Sammlung zufugt.
	 * 
	 * \param d Pointer auf das Element, das zur Sammlung zugefuegt wird.
	 * \return Referenz auf das Buch selbst, sodass der Operation kaskadierbar sei.
	 */
	Cocktailbook& operator+(Drink* d)
	{
		pushback(d);
		return *this;
	}

	Cocktailbook& operator-(Drink* d);

	/**
	 * @brief Unaerer Operator, der die Addresse an dem gegebenen Position zurueckgibt.
	 * 
	 * Wenn die gegebene Position kleiner als die hoechste Position der heterogenen Sammlung ist, dann terminiert das Programm.
	 * @attention Rueckgabewerttyp ist "Drink**", also muss der Benutzer den Rueckgabewert DEREFERENZIEREN!
	 * \param pos Die abgefragte Position.
	 * \return Pointer auf demjenigen Pointer, der auf der gegebenen Stelle gespeichert wurde.
	 */
	Drink** operator[](unsigned pos);

	/**
	 * @brief Destruktor, der die dynamische heterogene Sammlung freigibt.
	 * 
	 */
	~Cocktailbook() { delete[] arr; }
	
};


#endif