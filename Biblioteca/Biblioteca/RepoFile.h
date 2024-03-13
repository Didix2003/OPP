#pragma once
#include "Repo.h"
#include <fstream>
#include "Carte.h"

class RepoFile : public Repo {
private:
	std::string file_name; // numele fisierului in care se salveaza produsele
	std::vector<Carte> objects;
public:
	RepoFile(const std::string& file_name);
	void add(Carte& p);
	void updateFile(int pos,Carte newEntity);
	void deleteFile(int pos);
	void load();
	void save();
	int size();
	std::vector<Carte> get_all();

};
