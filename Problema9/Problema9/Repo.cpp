#include "Repo.h"
#include <iostream>
#include <vector>

using namespace std;
Repo::Repo()
{
}
Repo::~Repo() {}

void Repo::update(int pos, Entitate newEntity)
{
	this->entitate[pos] = newEntity;
}
void Repo::deleteEntity(int position)
{
	auto iteratorToRemove = std::next(this->entitate.begin(), position);
	this->entitate.erase(iteratorToRemove);
}
void Repo::addEntitate(Entitate & t)
{
	this->entitate.push_back(t);
}
Entitate Repo::getItemFromPos(int pos)
{
	return this->entitate.at(pos);
}
int Repo::getSize()
{
	return this->entitate.size();
}
//vector<Entitate> Repo::getAll()
//{
//	return this->entitate;
//
//}