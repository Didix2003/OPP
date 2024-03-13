#pragma once
#include "Repo.h"
#include"RepoFile.h"
#include "Validator.h"
class Service
{
private:
	RepoFile repo;
	Validator validate;
	vector<string> historyActions;
	vector<Entitate> history;
	vector<double> coins = {0.10,0.50, 1, 5, 10, 50, 100, 500 };
	vector<int> coin_counts = { 10, 10, 10, 10, 10, 10, 10, 10 };
public:
	Service() = default;
	Service(RepoFile repo, Validator& val) : repo(repo) {};
	~Service()=default;

	vector<Entitate> getAll();
	void addEntitate(Entitate stud);
	void update(int pos, Entitate newEntity);
	void deleteEntity(int pos);
	Entitate getEntitateAtPos(int position);
	vector<Entitate> filtrare_dupa_pret(int val);
	vector < Entitate> sortare();
	void PurchaseProdus(char *cod, double amount);
	int getSize();
};

