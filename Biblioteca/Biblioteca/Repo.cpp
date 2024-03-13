#include "Repo.h"

Repo::Repo()
{
}
/*
	adauga cartile
	obiect:obiect de tip Carte
	return: adauga obiectul in vector
*/
void Repo::addobiecte(Carte & m)
{
	this->obiecte.push_back(m);
}
/*
	modifica cartile
	pos: pozitia obiectului
	newObiect: obiect de tip Carte
	return: obiectul modificat de e pozitia pos
*/

void Repo::updateobiecte(int pos, Carte & newObiect)
{
	this->obiecte[pos] = newObiect;
}
/*
	sterge cartile
	pos: pozitia obiectului
	return: stergerea obiectului de pe pozitia pos
*/
void Repo::deleteobiecte(int pos)
{
	auto iteratrorRemove = std::next(this->obiecte.begin(), pos);
	this->obiecte.erase(iteratrorRemove);
}
/*
	pos: pozitia obiectului
	return: elementul de pozitia pos
*/
Carte Repo::getItemFromPos(int pos)
{
	return this->obiecte.at(pos);
}
/*
	return dimensiunea vectorului
*/

int Repo::getSize()
{
	return this->obiecte.size();
}
/*
	return tot vectorul Carte
*/
vector<Carte> Repo::getAll()
{
	return this->obiecte;
}
