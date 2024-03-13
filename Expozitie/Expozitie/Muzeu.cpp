#include "Muzeu.h"
#include <iostream>
#include <string.h>

using namespace std;

Muzeu::Muzeu()
{
	this->autor = NULL;
	this->denumire = NULL;
	this->categoria = NULL;
}

Muzeu::Muzeu(char * autor, char * denumire, char * categoria)
{
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, strlen(autor) + 1, autor);
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	this->categoria = new char[strlen(categoria) + 1];
	strcpy_s(this->categoria, strlen(categoria) + 1, categoria);
}

Muzeu::Muzeu(const Muzeu & m)
{
	this->autor = new char[strlen(m.autor) + 1];
	strcpy_s(this->autor, strlen(m.autor) + 1, m.autor);
	this->denumire = new char[strlen(m.denumire) + 1];
	strcpy_s(this->denumire, strlen(m.denumire) + 1, m.denumire);
	this->categoria = new char[strlen(m.categoria) + 1];
	strcpy_s(this->categoria, strlen(m.categoria) + 1, m.categoria);
}

Muzeu::~Muzeu()
{
}

char * Muzeu::getAutor()
{
	return this->autor;
}

void Muzeu::setAutor(char * autor)
{
	if (this->autor)
	{
		delete[] this->autor;
	}
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, strlen(autor) + 1, autor);
}

char * Muzeu::getDenumire()
{
	return this->denumire;
}

void Muzeu::setDenumire(char * denumire)
{
	if (this->denumire)
		delete[] this->denumire;
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
}

char * Muzeu::getCategoria()
{
	return this->categoria;
}

void Muzeu::setCategoria(char* categoria)
{
	if (this->categoria)
		delete[] this->categoria;
	this->categoria = new char[strlen(categoria) + 1];
	strcpy_s(this->categoria, strlen(categoria) + 1, categoria);
}

bool Muzeu::operator==(const Muzeu & m)
{
	return ((strcmp(this->autor, m.autor) == 0) && (strcmp(this->denumire, m.denumire) == 0) && (strcmp(this->categoria, m.categoria) == 0));
}
