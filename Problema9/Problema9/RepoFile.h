#pragma once
#include "Repo.h"
#include <fstream>

class RepoFile : public Repo {
private:
	std::string file_name; // numele fisierului in care se salveaza produsele
	std::vector<Entitate> products;
public:
	RepoFile(const std::string& file_name);
	void add(Entitate& p);
	void updateFile(int pos, Entitate newEntity);
	void deleteFile(int pos);
	void load();
	void save();
	int size();
	std::vector<Entitate> get_all();

};
