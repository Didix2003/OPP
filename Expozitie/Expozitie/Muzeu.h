#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Muzeu
{
private:
	char* autor;
	char* denumire;
	char* categoria;
public:
	Muzeu();
	Muzeu(char* autor, char*denumire, char *categoria);
	Muzeu(const Muzeu &m);
	~Muzeu();
	char* getAutor();
	void setAutor(char *autor);
	char* getDenumire();
	void setDenumire(char* denumire);
	char* getCategoria();
	void setCategoria(char* categoria);
	bool operator==(const Muzeu&m);

	friend std::ostream& operator<<(std::ostream& os, const Muzeu& p) {
		os << p.autor << " " << p.denumire << " " << p.categoria;
		return os;
	}
	friend std::istream& operator>>(std::istream& in, Muzeu& p) {
		char autor[50], denumire[50],categoria[50];
		in >> autor>> denumire >> categoria;
		p.setAutor(autor);
		p.setDenumire(denumire);
		p.setCategoria(categoria);
		return in;
	}

};

