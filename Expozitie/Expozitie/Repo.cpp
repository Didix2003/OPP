#include "Repo.h"

Repo::Repo()
{

}

void Repo::addobiecte(Muzeu & m)
{
	this->obiecte.push_back(m);
}

void Repo::updateobiecte(int pos, Muzeu & newObiect)
{
	this->obiecte[pos] = newObiect;
}

void Repo::deleteobiecte(int pos)
{
	auto iteratrorRemove = std::next(this->obiecte.begin(), pos);
	this->obiecte.erase(iteratrorRemove);
}

Muzeu Repo::getItemFromPos(int pos)
{
	return this->obiecte.at(pos);
}

int Repo::getSize()
{
	return this->obiecte.size();
}

vector<Muzeu> Repo::getAll()
{
	return this->obiecte;
}
