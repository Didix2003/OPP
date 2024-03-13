#include<iostream>
#include "Tranzactie.h"
using namespace std;
Tranzactie::Tranzactie() {
	this->idTranzactie = 0;
	this->suma = 0;
}
Tranzactie::Tranzactie(int idTranzactie, int suma) {
	this->suma = suma;
	this->idTranzactie = idTranzactie;
}
Tranzactie::~Tranzactie() {

}
std::vector<int> Tranzactie::getTipuriBancnote() const {
	return tipBancnote;
}

std::vector<int> Tranzactie::getNumarBancnote() const {
	return numarBancnote;
}

int Tranzactie::getSuma() {
	return this->suma;
}
void Tranzactie::setSuma(int suma)
{
	this->suma = suma;
}
void Tranzactie::setId(int id)
{
	this->idTranzactie = id;
}
int Tranzactie::getidTranzactie() {
	return this->idTranzactie;
}



