#include "Service.h"
#include "Repo.h"
#include "RepoFile.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <iomanip>

using namespace std;
vector<Entitate> Service::getAll() {
	return this->repo.get_all();
}

void Service::addEntitate(Entitate entity) {
	this->validate.validare_pret(entity.getPret());
	this->repo.add(entity);
}

void Service::update(int pos, Entitate newEntity)
{
	this->validate.validare_pozitie(this->repo.get_all(), pos);
	repo.updateFile(pos, newEntity);
}

void Service::deleteEntity(int pos)
{
	this->validate.validare_pozitie(this->repo.get_all(), pos);
	this->repo.deleteFile(pos);
}
Entitate Service::getEntitateAtPos(int position) {
	return this->repo.getItemFromPos(position);
}

vector<Entitate> Service::filtrare_dupa_pret(int val)
{
	vector<Entitate> results;
	for (auto entity : this->repo.get_all()) {
		if (entity.getPret() <= val) {
			results.push_back(entity);
		}
	}
	return results;
}

vector<Entitate> Service::sortare()
{
	vector<Entitate> products = this->repo.get_all();
	for (int i = 1; i < products.size(); i++) {
		for (int j = i; j > 0 && products[j - 1].getPret() > products[j].getPret(); j--) {
			std::swap(products[j], products[j - 1]);
		}
	}
	return products;
}
void Service::PurchaseProdus(char * cod, double amount)
{
	vector<Entitate> products = this->repo.get_all();
	// Găsirea produsului după cod
	Entitate product;
	for (int i = 0; i < products.size(); i++) {
		if (strcmp(products[i].getCod(), cod) == 0) {
			product = products[i];
			break;
		}
	}

	// Verificarea dacă suma introdusă este suficientă pentru a cumpăra produsul
	if (amount < product.getPret()) {
		cout << "Suma introdusa este prea mica. Produsul costa " << product.getPret() << " lei." << endl;
		return;
	}

	// Calcularea restului
	double change = amount - product.getPret();
	double roundedNumber = round(change*100)/100;
	change = roundedNumber;
	//cout << change;
	vector<int> coin_counts_copy = coin_counts;
	vector<double> change_coins(coin_counts.size(), 0);
	for (int i = coins.size() - 1; i >= 0; i--) {
		while (change >= coins[i] && coin_counts_copy[i] > 0) {
			change -= coins[i];
			change_coins[i]++;
			coin_counts_copy[i]--;
		}
	}
	// Verificarea dacă tonomatul are destule monezi pentru a da restul
	if (change > 0){
		cout << "Tonomatul nu are suficiente monezi pentru a da restul." << endl;
		return;
	}
	// Actualizarea stocului de monezi
	coin_counts = coin_counts_copy;

	// Afișarea mesajului de finalizare a achiziției și a restului dat
	cout << "Produsul " << product.getNume() << " a fost achizitionat cu succes. Restul dat: " << amount - product.getPret() << " lei"<<endl;
	for (int i = 0; i < change_coins.size(); i++) {
		if (change_coins[i] > 0) {
			cout <<" Bancontele primite sunt: "<< change_coins[i] << " x " << coins[i] << " lei ";
		}
	}
	cout << endl;
}
int Service::getSize()
{
	return repo.size();

}
