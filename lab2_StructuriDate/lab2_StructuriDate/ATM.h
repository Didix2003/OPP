#pragma once
#include "Collection.h"
#include "Tranzactie.h"
#include <vector>
#include <iostream>
using namespace std;
class ATM
{
private:
	Collection colectie;
	Tranzactie* tranzactii;
	vector<int> tipuriBancnote = { 100,50,10 };
	vector<int> numarBancnote = { 5,1,1 };
	Collection initialCollection;
	int nrElems;
public:

	ATM();
	ATM(Collection colectie);
	~ATM();
	int AdaugaTranzactie(int id,int suma);
	void addTranzactie(Tranzactie tr);
	void afisareTranzactii();
	void citireTranzactiiDinFisier();
	void salvareTranzactiiInFisier();
	void afisareTranzactiiDinFisier();
	//void printSolution(vector<int>& solution);
	//bool backtrack(int target, vector<int>& solution, int start);
	//void backtrack(Collection colectie, int suma, vector<int> bancnote, int index);
	
};

