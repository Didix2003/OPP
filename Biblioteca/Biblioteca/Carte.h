#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Carte
{
private:
	char* nume;
	int an;
	char* autor;
	int nr_carti;
public:
	Carte();
	Carte(char* nume,int an,char* autor, int nr_carti);
	Carte(const Carte &m);
	~Carte();
	char* getNume();
	void setNume(char *nume);
	int getAn();
	void setAn(int an);
	char* getAutor();
	void setAutor(char *autor);
	int getnr_carti();
	void setNr_Carti(int nr_carti);
	bool operator==(const Carte&m);

	friend std::ostream& operator<<(std::ostream& os, const Carte& p) {
		os << p.nume << " " << p.an << " " << p.autor<<" "<<p.nr_carti;
		return os;
	}
	friend std::istream& operator>>(std::istream& in, Carte& p) {
		char autor[50], nume[50];
		int an, nr_carti;
		in >> nume >> an >> autor>>nr_carti;
		p.setNume(nume);
		p.setAn(an);
		p.setAutor(autor);
		p.setNr_Carti(nr_carti);
		return in;
	}

};

