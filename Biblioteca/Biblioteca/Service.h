#pragma once
#include "Repo.h"
#include "Carte.h"
#include "RepoFile.h"
class Service
{
private:
	RepoFile repo;
public:
	Service() = default;
	Service(RepoFile repo) : repo(repo) {};
	~Service() = default;

	void addobiecte(Carte obiect);
	void updateobiecte(int pos, Carte newObiect);
	void deleteobiecte(int pos);
	Carte getItemFromPos(int pos);
	int getSize();
	vector <Carte> sortare_nume();
	vector <Carte> sortare_autor();
	vector<Carte> filtrare_dupa_an(int an);
	vector<Carte> filtrare_dupa_nr(int nr);

};