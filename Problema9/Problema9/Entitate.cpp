#include "Entitate.h"
#include <string.h>
#include <iostream>

using namespace std;

Entitate::Entitate()
{
	this->nume = NULL;
	this->cod = NULL;
	this->pret = 0;

}

Entitate::Entitate(char *cod,char* nume,double pret)
{
	this->cod = new char[strlen(cod) + 1];
	strcpy_s(this->cod, strlen(cod) + 1, cod);
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->pret = pret;

}

Entitate::Entitate(const Entitate & t)
{
	this->cod = new char[strlen(t.cod) + 1];
	strcpy_s(this->cod, strlen(t.cod) + 1, t.cod);
	this->nume= new char[strlen(t.nume) + 1];
	strcpy_s(this->nume, strlen(t.nume) + 1, t.nume);
	this->pret = t.pret;
}
Entitate::~Entitate()
{
}

char* Entitate::getCod()
{
	return this->cod;
}

void Entitate::setCod(const char* cod)
{
	if (this->cod) {
		delete[] this->cod;
	}
	this->cod = new char[strlen(cod) + 1];
	strcpy_s(this->cod, strlen(cod) + 1, cod);
}
char* Entitate::getNume()
{
	return this->nume;
}

void Entitate::setNume(const char* name)
{
	if (this->nume) {
		delete[] this->nume;
	}
	this->nume = new char[strlen(name) + 1];
	strcpy_s(this->nume, strlen(name) + 1, name);
}

double Entitate::getPret()
{
	return this->pret;
}

void Entitate::setPret(double pret)
{
	this->pret = pret;
}