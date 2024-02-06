#define _CRT_SECURE_NO_WARNINGS
/*****************************************************************//**
 * \file   Rezept.hpp
 * \brief  Enthaltet die entwickelten Datentypen: class Drink, Tea, Cocktail
 * 
 * \author Karsai Janos
 * \date   May 2022
 *********************************************************************/
#ifndef REZEPT_H

#define REZEPT_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

/**
 * \class Drink
 * \brief Basisklasse fuer Getraenke, erweiterbar mit spezifischen Typen durch Vererbung.
 * 
 * Diese Klasse speichert gerade eine Menge von Informationen (Name, Geschmack, Substanz, ob das Getraenke heiss oder kalt zu
 * andienen ist, Methode der Preparation), weil sie als eine allgemeine Klasse fuer Getraenke behandelt ist.
 *  
 */

class Drink { 
protected:

	string name; /** Name des Getraenkes */
	string flavour; /** Geschmack des Getraenkes */
	string texture; /** Substanz des Getraenkes */
	bool served_hot; /** Eigenschaft des Getraenkes, die sagt uns, ob es kalt oder heiss am besten zu geniessen ist */
	string prep; /** Methode der Herstellung in einigen Saetzen */
	

public:
	/**
	 * Default Konstruktor fuer class Drink.
	 * 
	 * Um das Programm angenehm mit zusaetzlichen Klassen erweiterbar zu machen, ist es noetig fuer die Basisklasse, ein 
	 * parameterloser Defaultkonstruktor zu haben. Diejenige Subklasse-Konstruktorren, die die Informationen von einem File
	 * einlesen, werden mittels dieses Konstruktors das Basis-Subobjekt initialisieren.
	 * @see Tea::Tea(string filename)
	 * @see Cocktail::Cocktail(string filename)
	 * 
	 */
	Drink() : name(), flavour(), texture(), served_hot(false), prep() {} 

	/** Konstruktor, indem alle einzige Parameter koennen angegeben werden */
	Drink(string s, string f, string t, bool x, string p) : name(s), flavour(f), texture(t), served_hot(x), prep(p) {} 

	/**
	 * Diese Konstruktor ist empfehlenswert anzuwenden.
	 * @param filename .txt File, von welchem alle Membervariablen einlesbar sind.
	 */
	Drink(string filename);

	virtual ~Drink() {}


	string getName() { return name; }
	string getFlavour() { return flavour; }
	string getTexture() { return texture; }
	bool servedHot() { return served_hot; }


	/** Schreibt den Namen, den Geschmack, den Substanz, und die Methode der Preparation auf die Standardausgabe aus. */
	virtual void print()
	{
		cout << "Drink name: " << name << "\nFlavour: " << flavour
			<< "\nTexture: " << texture << endl;
		if (served_hot) cout << "Best served hot" << endl;
		else cout << "Best served cold" << endl;
		cout << "Preparation: " << prep << endl;
	}
	friend bool operator==(const Drink& d1, const Drink& d2);

	/** Ahnlich wie Drink::print(), aber kaskadierbar und wirkt fur allgemeine Streams. */
	friend ostream& operator<<(ostream& out, const Drink& d);
};

/**
 * @class Tea
 * @brief Subklasse von class Drink, mit der zusaetzlichen Membervariable string origin. 
 * 
 * Diese Subklasse, wie alle geplante Subklassen, werden am einfachsten von einem vorher geschriebenen File konstruiert werden.
 * Eine Neuigkeit ist aber, dass die Datei muss schon auch enthalten, woher die Teeart kommt.
 */
class Tea : public Drink{
private:
	
	string origin; /** Woher das Tee kommt */
public:
	
	Tea(string s, string f, string t, bool x, string o, string p) : Drink(s, f, t, x, p), origin(o) {}
	/**
	 * @brief Konstruktion von einer .txt Datei, erweitern mit dem Einlesen von 'string origin'.
	 */
	Tea(string filename); 
	~Tea() {}

	/**
	 * @brief Drueckt sowohl die Eigenschaften als auch den Ursprung des Tees.
	 * 
	 */
	void print()
	{
		Drink::print(); printOrigin();
	}
	/**
	 * @brief Ausgabefunktion fuer den Ursprung des Tees.
	 */
	void printOrigin() { cout << "Origin: " << origin << endl; }
	/**
	 * @brief Ausgabeoperator, erweitert mit string origin Membervariable.
	 */
	friend ostream& operator<<(ostream& out, const Tea& t);
};

/**
 * @class Cocktail 
 * @brief Speichert Zutaten in einem Vector.
 * 
 * Bei Cocktails wird typisch die Methode der Herstellung ein bisschen langer als bei anderen Typen, deshalb ist
 * der Konstruktor Drink::Drink(string filename) so entwickelt, dass string prep zeichenweise eingelest wird bis
 * der Ende der gegebenen .txt Datei. 
 */
class Cocktail : public Drink
{
private:
	vector<string> ingredients; /** Eigentlich die Menge der Zutaten, gespeichert in einem Vektor. */
public:
	Cocktail(string n, string f, string t, bool x, const vector<string>& v, string p) :
		Drink(n, f, t, x, p), ingredients(v) {} 

	/**
	 * Der empfehlenswerte Konstruktor, indem die Zutaten mit getline() Funktion nacheinander eingelesen werden, bis
	 * "Preparation:" Zeile erreicht ist.
	 * \param filename Die gegebene .txt Datei.
	 */
	Cocktail(string filename);
	/**
	 * @brief Eine solche print() Funktion fuer Cocktail Datentypen, die nur die Zutaten des Cocktails auf die Standardausgabe darstellt.
	 * 
	 */
	void printIngredients()
	{
		cout << "Ingredients: ";
		for (int i = 0; i < ingredients.size(); i++)
		{

			cout << " > " << ingredients[i] << endl;
		}
	}
	/**
	 * @brief Gibt alle Membervariablen auf die Standardausgabe aus.
	 * 
	 */
	void print()
	{
		Drink::print();
		printIngredients();
	}
	/**
	 * @brief Ueberladener kaskadierbarer Ausgabeoperator fuer Cocktail Datentypen.
	 */
	friend ostream& operator<<(ostream& out, const Cocktail& c);
};



#endif