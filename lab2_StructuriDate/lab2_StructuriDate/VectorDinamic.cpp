
#include <iostream>
#include "VectorDinamic.h"

VectorDinamic::VectorDinamic() {
	this->capacity = 10;
	this->elems = new TElem[capacity];
	this->nrElems = 0;
}

int VectorDinamic::size() const {
	return this->nrElems;
}

TElem VectorDinamic::getAt(int i) const {
	return elems[i];
}

TElem VectorDinamic::update(int i, TElem e) {
	//TODO - IMPLEMENT METHOD
	return 0;
}

void VectorDinamic::push_back(TElem e) {
	//TODO - IMPLEMENT METHOD
	if (nrElems == capacity)
		resize();
	this->elems[nrElems] = e;
	this->nrElems++;
}
bool VectorDinamic::search(TElem elem) {
	for (int i = 0; i < nrElems; i++) {
		if (elems[i] == elem) {
			return true;
		}
	}
	return false;
}

void VectorDinamic::setDown(int i)
{
	for (int j = i + 1; j < nrElems; j++) {
		elems[j - 1] = elems[j];
	}
	nrElems--;
}

void VectorDinamic::setUp(int pos)
{
	if (pos >= 0 && pos < nrElems) {
		for (int i = pos; i < nrElems - 1; i++) {
			elems[i] = elems[i + 1];
		}
		nrElems--;
	}
}

int VectorDinamic::IndexOf(TElem elem)
{
	for (int i = 0; i < size(); i++) {
		if (elems[i] == elem) {
			return i;
		}
	}
	return -1;
}

void VectorDinamic::setAt(int poz, TElem elem)
{
	if (poz < 0 || poz >= size()) {
		throw std::out_of_range("Index out of range");
	}
	elems[poz] = elem;
}


void VectorDinamic::addAt(int i, TElem e) {
	//TODO
}

TElem VectorDinamic::sterge(int i) {
	if (i < 0 || i >= nrElems) {
		throw "Index invalid";
	}
	TElem oldValue = elems[i];
	for (int j = i; j < nrElems - 1; j++) {
		elems[j] = elems[j + 1];
	}
	nrElems--;
	return oldValue;

}

VectorDinamic::~VectorDinamic() {
	//lasa
}

void VectorDinamic::resize() {
	capacity *= 2;
	TElem* newArray = new TElem[capacity];
	for (int i = 0; i < nrElems; i++) {
		newArray[i] = elems[i];
	}
	delete[] elems;
	elems = newArray;
}
