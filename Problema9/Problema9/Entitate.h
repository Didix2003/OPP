#pragma once
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
class Entitate {
private:
	char *cod;
	char *nume;
	double pret;

public:
	//Constructor without parameters
	Entitate();
	//Constructor with parameters
	Entitate(char *cod,char *nume,double pret);
	//Copy constructor
	Entitate(const Entitate &t);
	//Destructor
	~Entitate();
	char* getCod();
	void setCod(const char* cod);
	char* getNume();
	void setNume(const char* name);
	double getPret();
	void setPret(double pret);
	//string split(string str, char sep, int index);
	//bool operator==(const Entitate &e);
//	Entitate& operator=(const Entitate &e);

	//void afis();
	friend std::ostream& operator<<(std::ostream& os, const Entitate& p) {
		os << p.cod << " " << p.nume << " " << p.pret;
		return os;
	}
	friend std::istream& operator>>(std::istream& in, Entitate& p) {
		char cod[50], nume[50];
		double pret;
		in >> cod>> nume>> pret;
		p.setCod(cod);
		p.setNume(nume);
		p.setPret(pret);
		return in;
	}
};

