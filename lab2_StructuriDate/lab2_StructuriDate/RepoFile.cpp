#include "RepoFile.h"

RepoFile::RepoFile(const std::string & file_name)
{
	this->file_name = file_name;
	load();
}

void RepoFile::add(Tranzactie & p)
{
	ATM::addTranzactie(p); // adaugam produsul in memorie
	tranzactii.push_back(p); // adaugam produsul nou in vectorul de produse
	save();
}


void RepoFile::load()
{
	std::ifstream input_file(this->file_name); // deschidem fisierul pentru citire
	if (!input_file) {
		throw std::runtime_error("Could not open file: " + file_name); // aruncam exceptie daca nu am putut deschide fisierul
	}
	Tranzactie p;
	while (input_file >> p) { // citim fiecare produs din fisier pana la sfarsitul fisierului
		add(p); // adaugam produsul la lista de produse
	}
	input_file.close();
}
void RepoFile::save()
{
	std::ofstream output_file(this->file_name); // deschidem fisierul pentru scriere
	if (!output_file) {
		throw std::runtime_error("Could not open file: " + file_name); // aruncam exceptie daca nu am putut deschide fisierul
	}

	for (const auto& p : tranzactii) { // parcurgem toate produsele din lista
		output_file << p << "\n"; // scriem fiecare produs pe o linie separata
	}
}
int RepoFile::size()
{
	return get_all().size(); //calculam size pentru lista
}
vector<Tranzactie> RepoFile::get_all()
{
	std::vector<Tranzactie> get;
	std::ifstream fin(this->file_name);//deschidem fisierul pentru citire

	if (!fin.is_open()) {
		throw std::runtime_error("Could not open file");//aruncam exceptie daca nu am putut deschide fisierul
	}
	Tranzactie p;
	while (fin >> p) {	//citimi fiecare linie
		get.push_back(p); // adaugam fiecare produs in vector 
	}

	fin.close();
	return get; //returnam lista
}
