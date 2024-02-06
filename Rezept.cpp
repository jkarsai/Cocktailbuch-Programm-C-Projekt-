/*****************************************************************//**
 * \file   Rezept.cpp
 * \brief  Enthaltet manche Funktiondefinitionen, die zu den entwickelten Datentypen gehören
 * 
 * \author User
 * \date   May 2022
 *********************************************************************/
#include "Rezept.hpp"

Drink::Drink(string filename) : name(), flavour(), texture(), served_hot(false) {
	ifstream in; string HotOrCold; int c = 0;
	in.open(filename);
	if (!in.is_open())
	{
		cout << "ERROR: Could not read from file" << endl;
		return;
	}
	getline(in, name);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, flavour);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, texture);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, HotOrCold);
	if (HotOrCold == "Best served hot") served_hot = true;
	else served_hot = false;
	while (in.good())
	{
		c = in.get(); prep.push_back(char(c));
	}


	in.close();
}


/**
 * Initialisiert das Subobjekt von class Drink mit Hilfe von Drink::Drink() parameterloser Konstruktor.
 * 
 * Funktioniert genau wie Drink::Drink(string filename), aber muss noch string origin Membervariable
 * einlesen. Diese Information kann höchstens eine Zeile lang sein in der .txt Datei.
 * \param filename Name der .txt Datei woher das Tee eingelesen wird.
 */
Tea::Tea(string filename) : Drink(), origin()
{
	ifstream in; string HotOrCold; int c = 0;
	in.open(filename);
	if (!in.is_open())
	{
		cout << "ERROR: Could not read from file" << endl;
		return;
	}
	getline(in, name);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, flavour);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, texture);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, HotOrCold);
	if (HotOrCold == "Best served hot") served_hot = true;
	else served_hot = false;
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, origin);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	while (in.good())
	{
		c = in.get(); prep.push_back(char(c));
	}

	in.close();
}

Cocktail::Cocktail(string filename) : Drink(), ingredients()
{
	ifstream in; string input; int c = 0;
	in.open(filename);
	if (!in.is_open())
	{
		cout << "ERROR: Could not read from file" << endl;
		return;
	}
	getline(in, name);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, flavour);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, texture);
	if (!in.good()) {
		cout << "ERROR: Could not compile drink" << endl; return;
	}
	getline(in, input);
	if (input == "Best served hot") served_hot = true;
	else served_hot = false;

	while (in.good())
	{
		getline(in, input);
		if (input == "Preparation:") break;
		ingredients.push_back(input);
		
	}
	while (in.good())
	{
		c = in.get(); prep.push_back(char(c));
	}

	in.close();
}

bool operator==(const Drink& d1, const Drink& d2)
{
	if (d1.name != d2.name) return false;
	if (d1.flavour != d2.flavour) return false;
	if (d1.texture != d2.texture) return false;
	if (d1.served_hot != d2.served_hot) return false;
	if (d1.prep != d2.prep) return false;
	return true;
}

ostream& operator<<(ostream& out, const Drink& d)
{
	out << "Drink name: " << d.name << endl;
	out << "Flavour: " << d.flavour << endl;
	out << "Texture: " << d.texture << endl;
	if (d.served_hot) out << "Best served hot" << endl;
	else out << "Best served cold" << endl;
	out << d.prep << endl;
	return out;
}

ostream& operator<<(ostream& out, const Tea& t)
{
	out << "Drink name: " << t.name << endl;
	out << "Flavour: " << t.flavour << endl;
	out << "Texture: " << t.texture << endl;
	if (t.served_hot) out << "Best served hot" << endl;
	else out << "Best served cold" << endl;
	out << t.origin << endl;
	out << t.prep << endl;
	return out;
}

ostream& operator<<(ostream& out, const Cocktail& c)
{
	out << "Drink name: " << c.name << endl;
	out << "Flavour: " << c.flavour << endl;
	out << "Texture: " << c.texture << endl;
	if (c.served_hot) out << "Best served hot" << endl;
	else out << "Best served cold" << endl;
	cout << "Ingredients: " << endl;
	for (int i = 0; i < c.ingredients.size(); i++) out << " > " <<  c.ingredients[i] << endl;
	out << c.prep << endl;
	return out;
}
