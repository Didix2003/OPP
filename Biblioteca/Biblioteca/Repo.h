#pragma once
#include <iostream>
#include <vector>
#include "Carte.h"

using namespace std;
class Repo
{
private:
	vector<Carte> obiecte;
public:
	Repo();
	~Repo() = default;
	void addobiecte(Carte &m);
	void updateobiecte(int pos, Carte &newObiect);
	void deleteobiecte(int pos);
	Carte getItemFromPos(int pos);
	int getSize();
	vector<Carte> getAll();

};

