/*****************************************************************//**
 * \file   main.cpp
 * \brief  Demonstration der entwickelten Funktionalitaeten in Rezept.hpp und Cocktailbuch.hpp.
 *
 * Dokumentation der main() Funktion befindet sich in der Benutzerdokumentation.
 * \author Karsai Janos
 * \date   May 2022
 *********************************************************************/
#include "Rezept.hpp"
#include "Cocktailbuch.hpp"

int main()
{
	
	Drink* wl = new Cocktail("WatermelonLemonade.txt");
	wl->print();
	cout << endl;

	Drink* pc = new Cocktail("PinaColada.txt");
	pc->print();

	
	vector<string> hugoIngredients;
	hugoIngredients.push_back("Raspberry Liqueur");
	hugoIngredients.push_back("Prosecco");
	hugoIngredients.push_back("Mint sprig");
	Drink* hugo = new Cocktail("Raspberry Hugo Spritz", "fruity", "sparkling", false, hugoIngredients,
		"Pour 4cl of Raspberry Liqueur into a chilled Martini glass and fill with Prosecco. Garnish with a mint sprig");

	/*rl->print(); cout << endl;*/
	hugo->print(); cout << endl;
	// ...aber wenn wir das alle in einem File schon haben, ist es einfacher, von dem File einzulesen


	

	Drink* cosmo = new Cocktail("Cosmopolitan.txt");
	Drink* mbt = new Tea("MarzipanBlackTea.txt");
	Drink* rl = new Drink("Raspberry Liqueuer", "friuty", "contains fermented chuncks of fruit", false,
		"Steep fermented raspberries in a bottle 0.5l vodka at room temperature for a month");
	// Jetzt: Sammeln wir diese Getraenke in einer Container-Klasse:

	Cocktailbook B1; // heterogene Sammlung fuer Getraenke

	B1.pushback(cosmo);
	B1.pushback(mbt);
	B1.pushback(rl);
	B1.list();

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "TEST: Operationen mit Cocktailbook, und dann list()" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;


	B1 + pc - mbt;
	B1.list();

	delete pc; delete hugo; delete wl;
	delete rl; delete mbt; delete cosmo;
	

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "TEST: Minimum Groesse des Buches voraussetzen, einezlne Elemente abfragen und veraendern" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	Cocktailbook B2(5);
	Drink* d1 = new Cocktail("Mojito.txt");
	Drink* d2 = new Tea("LongYing.txt");
	Drink* d3 = new Drink("Fresh orange juice", "citrusy", "contains orange chuncks", false,
		"Take three juicy oranges, cut them in half and squeeze with a squeezer.");
	*(B2[0]) = d1; *(B2[1]) = d2; (*B2[2]) = d3;
	B2.list(1);
	cout << "Texture of orange juice: " << (*B2[2])->getTexture() << endl;

	delete d1; delete d2; delete d3;
	return 0;
}