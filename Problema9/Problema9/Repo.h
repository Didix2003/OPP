#pragma once
#include "entitate.h"
#include <iostream>
#include <vector>
using namespace std;

class Repo {
private:
	vector<Entitate> entitate;
public:
	Repo();
	~Repo();
	void addEntitate(Entitate &t);
	void update(int pos, Entitate newEntity);
	void deleteEntity(int position);
	Entitate getItemFromPos(int pos);
	int getSize();
	//vector<Entitate> getAll();
};