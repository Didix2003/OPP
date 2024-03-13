#pragma once
#include"Repo.h"
#include "Validator.h"
#include <map>
#include "RepoFile.h"
class Service
{
private:
	RepoFile repo;
	Validator validate;
	vector<string> historyActions;
	vector<Muzeu> history;
	std::map<std::string, int> voturi;
public:
	Service() = default;
	Service(RepoFile repo, Validator& val) : repo(repo) {};
	~Service()=default;

	void addobiecte(Muzeu obiect);
	void updateobiecte(int pos, Muzeu newObiect);
	void deleteobiecte(int pos);
	Muzeu getItemFromPos(int pos);
	int getSize();
	void sortare();
	void votare(int pos);
	void filtrare_artist(char *autor);
	vector<Muzeu> getAll();
	void undo();

};

