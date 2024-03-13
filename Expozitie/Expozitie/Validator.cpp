#include "Validator.h"

#include "Validator.h"
#include <iostream>
#include <string>

void Validator::validare_pret(double pret)
{
	if (pret < 0)
		throw AdaugareImposibilaException("Adaugare imposibila. Date nevide.");

}
void Validator::validare_pozitie(vector<Muzeu> produse, int pos)
{
	if (pos >= produse.size())
		throw ProdusulNuExistaExcpetion("Produsul nu exista.");
}

void Validator::validare_dimensiune(vector<Muzeu> produse, int pos)
{
	if (pos < 0 || pos >= produse.size())
		throw DepasireDimensiuneException("Dimensiune incalata!");
}

bool Validator::containsProduct(vector<Muzeu> produse, Muzeu & m) const
{
	for (auto& p : produse) {
		if (strcmp(p.getCategoria(),m.getCategoria())==0) {
			return true;
		}
	}
	return false;
}

void Validator::validare_existenta(vector<Muzeu> produse, Muzeu & m)
{
	if (this->containsProduct(produse, m))
		throw ExistadejaException("Exista deja acest obiect.");
}
