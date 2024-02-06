/*****************************************************************//**
 * \file   Cocktailbuch.cpp
 * \brief  Enthaltet manche Funktiondefinitionen die zu der Containerklasse gehoeren
 * 
 * \author Karsai Janos
 * \date   May 2022
 *********************************************************************/
#include "Cocktailbuch.hpp"

/**
 * Konstante, die fuer alle Instanzen der Klasse Cocktailbuch derselbe Wert haben muss.
 * 
 * Wenn irgendwann der Benutzer probiert eine Cocktailbook Objekt mit Arraygroesse mehr als max_size
 * instanziieren will, terminiert das Programm.
 * @see Cocktailbuch::Cocktailbuch(unsigned u = 0)
 */
const unsigned Cocktailbook::max_size = 1000;

/**
 * Listet alle Elemenente, die in einem Cocktailbuch sind, auf die Standardausgabe.
 * 
 * Da die Containerklasse eigentlich eine heterogene Sammlung (mit weiteren Funktionalitaeten) ist, ist es moglich,
 * fur jedes Element  waehrend Durchiterierung eines Buches die print() Funktion des aktuellen Objektes anzurufen.
 */
void Cocktailbook::list()
{
	cout << " >> Contents of the book:" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i]->print();
		cout << "- - - - - - - - - - - - -" << endl;
	}
}

void Cocktailbook::list(unsigned endPos)
{
	assert(endPos < size);
	for (int i = 0; i <= endPos; i++)
	{
		arr[i]->print();
		cout << "- - - - - - - - - - - - -" << endl;
	}
}

/**
 *Gibt eine Kopie von demjenigen Element zurueck, welches an der angegebenen Stelle gespeichert ist.
 * 
 * \param pos die angegebene Stelle
 * \return Kopie des Getraenkes, der auf der gefragten Stelle gespeichert ist. 
 */
Drink Cocktailbook::atCopy(unsigned pos)
{
	assert(pos < size);
	return *(arr[pos]);
}


void Cocktailbook::pushback(Drink* d) {
	Drink** temp = new Drink*[size + 1];
	for (size_t i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	temp[size++] = d;
	delete[] arr;
	arr = temp;
}

/**
 * Sucht nach eine Addresse in der heterogene Sammlung, die mit Eingangsparameter 'Drink* d' uebereinstimmt, und entfernt
 * dieses Element von der Sammlung, wenn es ein solches Element gibt.
 * 
 * \param d Addresse eines Getraenkes
 * \return Referenz auf das Buch selbst, sodass der Operation kaskadierbar sei.
 */
Cocktailbook& Cocktailbook::operator-(Drink* d)
{
	Drink** temp; temp = new Drink * [size - 1];
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (arr[i] == d) j--;
		else
		{
			temp[j] = arr[i];
		}
	}
	size--;
	delete[]arr; arr = temp;
	return *this;
}


Drink** Cocktailbook::operator[](unsigned pos)
{
	assert(pos < size);
	return &(arr[pos]);
}


