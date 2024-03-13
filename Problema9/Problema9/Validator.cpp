#include "Validator.h"
#include <iostream>
#include <string>

void Validator::validare_pret(double pret)
{
	if (pret < 0)
		throw AdaugareImposibilaException("Adaugare imposibila. Date nevide.");
	
}
void Validator::validare_pozitie(vector<Entitate> produse, int pos)
{
	if (pos >= produse.size())
		throw ProdusulNuExistaExcpetion("Produsul nu exista.");
}

int Validator::checkInt(int pret) {
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		return 0;
	}
	return 1;
}