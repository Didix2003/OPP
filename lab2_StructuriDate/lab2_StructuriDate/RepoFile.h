#pragma once
#include <fstream>
#include "ATM.h"
#include <vector>

class RepoFile : public ATM {
private:
	std::string file_name; // numele fisierului in care se salveaza produsele
	std::vector<Tranzactie> tranzactii;
public:
	RepoFile(const std::string& file_name);
	void add(Tranzactie& p);
	void load();
	void save();
	int size();
	std::vector<Tranzactie> get_all();

};
