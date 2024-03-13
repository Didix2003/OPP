#pragma once
#include <iostream>
#include "Exception.h"
#include <vector>
#include<string>
#include "Entitate.h"
using namespace std;
class Validator
{
public:
	void validare_pret(double pret);
	void validare_pozitie(vector<Entitate> produse, int pos);
	int checkInt(int pret);
};
