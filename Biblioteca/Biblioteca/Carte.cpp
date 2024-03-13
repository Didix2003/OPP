#include "Carte.h"
#include <iostream>
#include <string.h>

Carte::Carte()
{
	this->nume = NULL;
	this->an = 0;
	this->autor = NULL;
	this->nr_carti = 0;
}

Carte::Carte(char * nume, int an, char * autor, int nr_carti)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->an = an;
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, strlen(autor) + 1, autor);
	this->nr_carti = nr_carti;
}

Carte::Carte(const Carte & m)
{
	this->nume = new char[strlen(m.nume) + 1];
	strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);
	this->an =m.an;
	this->autor = new char[strlen(m.autor) + 1];
	strcpy_s(this->autor, strlen(m.autor) + 1, m.autor);
	this->nr_carti = m.nr_carti;
}

Carte::~Carte()
{
}

char * Carte::getNume()
{
	return this->nume;
}

void Carte::setNume(char * nume)
{
	if (this->nume) {
		delete[] this->nume;
	}
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

int Carte::getAn()
{
	return this->an;
}

void Carte::setAn(int an)
{
	this->an = an;
}

char * Carte::getAutor()
{
	return this->autor;
}

void Carte::setAutor(char * autor)
{
	if (this->autor)
	{
		delete[] this->autor;
	}
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, strlen(autor) + 1, autor);
}

int Carte::getnr_carti()
{
	return this->nr_carti;
}

void Carte::setNr_Carti(int nr_carti)
{
	this->nr_carti = nr_carti;
}

bool Carte::operator==(const Carte & m)
{
	return ((strcmp(this->nume, m.nume) == 0) && (this->an == m.an) && (strcmp(this->autor, m.autor) == 0) && (this->nr_carti == m.nr_carti));
}
