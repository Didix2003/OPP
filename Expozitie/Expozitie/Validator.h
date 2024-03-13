#pragma once
#include <iostream>
#include "Exception.h"
#include <vector>
#include<string>
#include "Muzeu.h"
using namespace std;
class Validator
{
public:
	void validare_pret(double pret);
	void validare_pozitie(vector<Muzeu> produse, int pos);
	void validare_dimensiune(vector<Muzeu> produse, int pos);
	bool containsProduct(vector<Muzeu> produse,Muzeu& m)const;
	void validare_existenta(vector<Muzeu> produse, Muzeu& m);
};