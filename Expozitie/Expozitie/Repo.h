#pragma once
#include <iostream>
#include <vector>
#include "Muzeu.h"

using namespace std;
class Repo
{
private:
	vector<Muzeu> obiecte;
public:
	Repo();
	~Repo()=default;
	void addobiecte(Muzeu &m);
	void updateobiecte(int pos, Muzeu &newObiect);
	void deleteobiecte(int pos);
	Muzeu getItemFromPos(int pos);
	int getSize();
	vector<Muzeu> getAll();

};

