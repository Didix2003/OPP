#include "Service.h"
#include "Repo.h"
#include<map>

/*
	adauga cartile
	obiect:obiect de tip Carte
	return: adauga obiectul in vector
*/
void Service::addobiecte(Carte obiect)
{
	this->repo.add(obiect);
}
/*
	modifica cartile
	pos: pozitia obiectului
	newObiect: obiect de tip Carte
	return: obiectul modificat de e pozitia pos
*/
void Service::updateobiecte(int pos, Carte newObiect)
{
	
	this->repo.updateFile(pos, newObiect);
}
/*
	sterge cartile
	pos: pozitia obiectului
	return: stergerea obiectului de pe pozitia pos
*/
void Service::deleteobiecte(int pos)
{
	
	this->repo.deleteFile(pos);
}
/*
	pos: pozitia obiectului
	return: elementul de pozitia pos
*/
Carte Service::getItemFromPos(int pos)
{
	return this->repo.getItemFromPos(pos);
}
/*
	return dimensiunea vectorului
*/
int Service::getSize()
{
	return this->repo.getSize();
}
/*
	return cartile sortate in functie de nume
*/
vector<Carte> Service::sortare_nume()
{
	vector<Carte> products = this->repo.get_all();
	for (int i = 1; i < products.size(); i++) {
		for (int j = i; j > 0 && products[j - 1].getNume() < products[j].getNume(); j--) {
			std::swap(products[j], products[j - 1]);
		}
	}
	return products;
}
/* 

	return cartile sortate in functie de autor
*/
vector<Carte> Service::sortare_autor()
{
	vector<Carte> products = this->repo.get_all();
	for (int i = 1; i < products.size(); i++) {
		for (int j = i; j > 0 && products[j - 1].getAutor() < products[j].getAutor(); j--) {
			std::swap(products[j], products[j - 1]);
		}
	}
	return products;
}
/*

	return cartile filtrate dupa un an
*/
vector<Carte> Service::filtrare_dupa_an(int an)
{
	vector<Carte> results;
	for (auto entity : this->repo.get_all()) {
		if (entity.getAn() <= an) {
			results.push_back(entity);
		}
	}
	return results;
}
/*

	return cartilefiltrate in functie de nr
*/
vector<Carte> Service::filtrare_dupa_nr(int nr)
{
	vector<Carte> results;
	for (auto entity : this->repo.get_all()) {
		if (entity.getnr_carti() <= nr) {
			results.push_back(entity);
		}
	}
	return results;
}
