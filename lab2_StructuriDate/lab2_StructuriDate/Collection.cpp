#include "Collection.h"
#include "List.h"


Collection::Collection() {
	distinctelements = 0;
	occurrences = List<TElem>();
}

bool Collection::search(TElem elem) {
	Node<int>* current = elements.getFirst();
	while (current) {
		if (current->getData() == elem) {
			return true;
		}
		current = current->getNext();
	}
	return false;
}

void Collection::add(TElem elem) {
	int index = occurrences.indexOf(elem);
	if (index != -1) {
		int occ = occurrences.get_at(index);
		occurrences.update(index, occ + 1);
	}
	else {
		elements.push_back(elem);
		occurrences.push_back(1);
		distinctelements++;
	}
}

bool Collection::remove(TElem elem) {
	int index = elements.indexOf(elem);
	if (index == -1) {
		return false;
	}
	int occ = occurrences.get_at(index);
	if (occ > 1) {
		occurrences.update(index, occ - 1);
	}
	else {
		elements.delete_at(index);
		occurrences.delete_at(index);
		distinctelements--;
	}
	return true;
}

int Collection::size() {
	return distinctelements;
}

int Collection::nroccurrences(TElem elem) {
	int count = 0;
	Node<int>* current = elements.getFirst();
	while (current) {
		if (current->getData() == elem) {
			count++;
		}
		current = current->getNext();
	}
	return count;
}

void Collection::destroy() {
	elements.clear();
	occurrences.clear();
	distinctelements = 0;
}

void Collection::setUp(int pos) {
	int occ = occurrences.get_at(pos);
	occurrences.update(pos, occ - 1);
}

int Collection::getAt(int position) const {
	return elements.get_at(position);
}

void Collection::setDown(int i) {
	elements.delete_at(i);
	occurrences.delete_at(i);
	distinctelements--;
}

void Collection::setUpBack(int i) {
	int occ = occurrences.get_at(i);
	occurrences.update(i, occ + 1);
}

Collection & Collection::operator=(const Collection & other)
{
	if (this != &other) {
		// Copierea listei de elemente
		elements = other.elements;

		// Copierea listei de frecvențe
		occurrences = other.occurrences;

		// Actualizarea numărului distinct de elemente
		distinctelements = other.distinctelements;
	}
	return *this;
}
