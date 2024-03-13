#pragma once
#include <iostream>
#include <vector>
#include "Collection.h"
using namespace std;
class Tranzactie
{
private:
	int idTranzactie;
	int suma;
	std::vector<int> tipBancnote;
	std::vector<int> numarBancnote;
public:
	Tranzactie();
	Tranzactie(int idTranzactie, int suma);
	Tranzactie(int id, int s, const std::vector<int>& tipuri, const std::vector<int>& numere)
		: idTranzactie(id), suma(s), tipBancnote(tipuri), numarBancnote(numere) {}
	~Tranzactie();
	int getidTranzactie();
	int getSuma();
	void setSuma(int suma);
	void setId(int id);
	std::vector<int> getTipuriBancnote() const;
	std::vector<int> getNumarBancnote() const;
	friend std::ostream& operator<<(std::ostream& os, const Tranzactie& p) {
		os << p.idTranzactie << " " << p.suma;
		return os;
	}
	friend std::istream& operator>>(std::istream& in, Tranzactie& p) {
		int id, suma;
		in >> id>>suma;
		p.setId(id);
		p.setSuma(suma);
		return in;
	}

};

