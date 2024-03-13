#pragma once
#include "Repo.h"
#include <fstream>
#include "Muzeu.h"

class RepoFile : public Repo {
private:
	std::string file_name; // numele fisierului in care se salveaza produsele
	std::vector<Muzeu> objects;
public:
	RepoFile(const std::string& file_name);
	void add(Muzeu& p);
	void updateFile(int pos, Muzeu newEntity);
	void deleteFile(int pos);
	void load();
	void save();
	int size();
	std::vector<Muzeu> get_all();

};
