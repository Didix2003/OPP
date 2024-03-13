#include "ATM.h"
#include "Collection.h"
#include "Tranzactie.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
ATM::ATM() {
	this->tranzactii = new Tranzactie[20];
	this->nrElems = 0;
}
ATM::ATM(Collection colectie) {
	this->colectie = colectie;
	this->tranzactii = new Tranzactie[20];
	this->nrElems = 0;

}
ATM::~ATM() {
	delete[] tranzactii;
}
void ATM::addTranzactie(Tranzactie tr) {
	tranzactii[nrElems++] = tr;
}
int ATM::AdaugaTranzactie(int id,int suma) {
	
	vector<int> numarBancnoteActualizat(numarBancnote);
	int suma2 = suma;
	initialCollection = colectie;
	while (suma > 0) {

		// Verificarea disponibilității bancnotelor în colecție
		for (int i = 0; i < tipuriBancnote.size(); i++) {
			int tipBancnota = tipuriBancnote[i];
			//int numarBancnota = numarBancnoteActualizat[i];
			int numarBancnoteDisponibile = colectie.nroccurrences(tipBancnota);
			//int numarBancnoteInitale = colectie.nroccurrences(tipBancnota);
			while (numarBancnoteDisponibile > 0 && suma >= tipBancnota && colectie.search(tipBancnota)) {
				colectie.remove(tipBancnota);
				suma -= tipBancnota;
				numarBancnoteDisponibile--;

			}
			numarBancnoteActualizat[i] = numarBancnoteDisponibile;
			
		//vector<int> coin_counts_copy = numarBancnote;
		//vector<int> change_coins(numarBancnote.size(), 0);
		//for (int i = tipuriBancnote.size() - 1; i >= 0; i--) {
		//	int tipBancnota = tipuriBancnote[i];
		//	int numarBancnoteDisponibile = colectie.nroccurrences(tipBancnota);
		//	while (suma >= tipuriBancnote[i] && coin_counts_copy[i] > 0&& colectie.search(tipBancnota)&&numarBancnoteDisponibile>0) {
		//		
		//		colectie.remove(tipBancnota);
		//		suma -= tipuriBancnote[i];
		//		change_coins[i]++;
		//		coin_counts_copy[i]--;
		//	}
		//	numarBancnote = coin_counts_copy;
		/*for (int i = 0; i < change_coins.size(); i++) {
			if (change_coins[i] > 0) {
				cout << " Bancontele primite sunt: " << change_coins[i] << " x " << tipuriBancnote[i] << " lei ";
			}
		}
		cout << endl;*/
		// Adăugarea tranzacției în lista de tranzacții a ATM-ului
			if (suma == 0) {
				break;  // S-a atins suma dorită, ieșim din buclă
			}
		}
		if (suma > 0) {

			std::cout << "Nu sunt suficiente bancnote disponibile in ATM pentru a plati suma " << suma2 << "." << std::endl;
			//colectie = initialCollection;
			return 0;
		}
		else
		{
				int optiune;
				cout << "1- Efectuarea tranzactiei" << "\n" << "0-Anularea tranzactiei: " << "\n" << "->";
				cin >> optiune;
				if (optiune == 1) {
					Tranzactie tranzactie(id, suma2, tipuriBancnote, numarBancnoteActualizat);
					addTranzactie(tranzactie);
					cout << "Multumim de confirmare!" << endl;
				}
				else
				{
					cout << "Tranzactie anulata!" << endl;

				}
				std::cout << "Tranzactia a fost efectuata cu succes!" << std::endl;

			
		}
		
	}
}

void ATM::afisareTranzactii() {
	for (int i = 0; i < this->nrElems; i++)
	{
		std::cout << "ID: " << tranzactii[i].getidTranzactie();
		std::cout << ", Suma: " << tranzactii[i].getSuma() << std::endl<<std::endl;
		std::cout << "Numarul actualizat de bancnote:" << std::endl;
	}
	for (size_t j = 0; j < tipuriBancnote.size(); j++) {
		int tipBancnota = tipuriBancnote[j];
		std::cout << "Tip bancnota: " << tipuriBancnote[j] << ", Numar bancnote: " << colectie.nroccurrences(tipBancnota) << std::endl;
	}
	std::cout << std::endl;
}
void ATM::citireTranzactiiDinFisier()
{
	ifstream f("Texte\\tranzactii.txt");
	int nrTranzactii;
	f >> nrTranzactii;
	for (int i = 0; i < nrTranzactii; i++)
	{
		int suma;
		int id;
		f >> id;
		f >> suma;
		Tranzactie tranzactie(id, suma);
		addTranzactie(tranzactie);
	}
	f.close();
}

void ATM::salvareTranzactiiInFisier()
{
	ofstream g("Texte\\tranzactii.txt");
	g << nrElems << endl;
	for (int i = 0; i < this->nrElems; i++)
	{
		g << tranzactii[i].getidTranzactie() << " " << tranzactii[i].getSuma() << endl;
	}
	g.close();
}

void ATM::afisareTranzactiiDinFisier()
{
	ifstream f("Texte\\tranzactii.txt");
	int nrTranzactii;
	f >> nrTranzactii;
	for (int i = 0; i < nrTranzactii; i++)
	{
		int suma;
		int id;
		f >> id;
		f >> suma;
		Tranzactie tranzactie(id, suma);
		cout << tranzactie << endl;
	}
	f.close();
}




