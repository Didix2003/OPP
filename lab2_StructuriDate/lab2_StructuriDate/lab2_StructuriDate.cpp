#include <iostream>
#include "Collection.h"
#include "ATM.h"
#include "Tranzactie.h"
#include "VectorDinamic.h"
#include "TestList.h"

using namespace std;
void printmeniu() {
	cout << "1. Adaugare unei tranzactii: ->" << endl;
	cout << "2. Afisare tranzactii: -> " << endl;
	cout << "3. Adaugare tranzactie personalizata: ->" << endl;
	cout << "4. Citire tranzactii din fisier: " << endl;
	cout << "5. Salvare tranzactii in fisier: " << endl;
	cout << "6. Afisare tranzactii din fisier: " << endl;
	cout << "x. Oprire program" << endl;
}
int main() {
	VectorDinamic vecctor;
	TestList test;
	test.testAll();
	Collection colectie; 
	colectie.add(10);
	colectie.add(50);
	colectie.add(100);
	colectie.add(100);
	colectie.add(100);
	colectie.add(100);
	colectie.add(100);
	ATM atm(colectie);
	while (true) {
		printmeniu();
		char optiune;
		cout << "Dati optiunea dorita: ";
		cin >> optiune;
		if (optiune == '1') {
			vector<int> bancnote;
			int idTranzactie, suma;
			cout << "Dati id ul sumei si suma dorita: ";
			cin >> idTranzactie >> suma;
			Tranzactie tr(idTranzactie, suma);
			atm.addTranzactie(tr);
			//atm.backtrack(colectie, suma, bancnote, 0);
		}
		else if (optiune == '2') {
			atm.afisareTranzactii();
		}
		else if (optiune == '3') {
			
			int idTranzactie, suma;
			cout << "Dati id ul sumei si suma dorita: ";
			cin >> idTranzactie >> suma;
			Tranzactie tr(idTranzactie, suma);
			atm.AdaugaTranzactie(idTranzactie,suma);
			
		}
		else if(optiune=='4')
		{
			atm.citireTranzactiiDinFisier();
			cout << "Tranzactiile au fost citite din fisier" << endl;
		}
		else if (optiune == '5')
		{
			atm.salvareTranzactiiInFisier();
			cout << "Tranzactiile au fost salvate in fisier" << endl;

		}
		else if (optiune == '6')
		{
			atm.afisareTranzactiiDinFisier();
		}
		else if (optiune == 'x') {
			break;
		}
		else
			cout << "Optiune gresita!"<<endl;
	}

	return 0;
}
