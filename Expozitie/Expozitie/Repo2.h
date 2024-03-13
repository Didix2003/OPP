#pragma once
#include <iostream>
#include <vector>
#include "Muzeu.h"

using namespace std;
class Repo2
{
private:
	vector<Muzeu> voturi;
public:
	Repo2()=default;
	~Repo2() = default;
	void addvoturi(Muzeu &m);
	void updatevoturi(int pos, Muzeu &newObiect);
	void deletevoturi(int pos);
	vector<Muzeu> getAll();

};

