#include "Node.h"

#ifndef CURS7_P_LIST_H
#define CURS7_P_LIST_H
#include <iostream>
using namespace std;

template <class T>
class List {
private:
	/* definiti o reprezentare inlantuita pe elementele din lista */
	Node<T>* first;
	Node<T>* last;

public:
	/// constructor implicit
	List() {
		this->first = nullptr;
		this->last = nullptr;
	}


	/// \return dimensiunea listei
	int size();

	///  verifica daca lista e vida
	/// \return true, daca lista e vida, altfel returneaza false
	bool is_empty() const;

	/// adaugare element la sfarsit
	/// \param e - elementul adaugat
	void push_back(T e);

	///
	/// \param i - pozitia unui elem in lista , 0<=i<size()
	/// \return  elementul de pe pozitia i
	/// \raise   exceptie daca i nu e valid
	T get_at(int i) const;

	// modifica element de pe pozitia i si returneaza vechea valoare
	//arunca exceptie daca i nu e valid
	T update(int i, T e);



	// adaugare element pe o pozitie i
	//arunca exceptie daca i nu e valid
	//void set_at(int i, T e);

	// sterge element de pe o pozitie i si returneaza elementul sters
	//arunca exceptie daca i nu e valid
	T delete_at(int i);
	void clear();
	Node<T>* getFirst() const;
	int indexOf(T value) const;


	// cauta element si returneaza prima pozitie pe care apare (sau -1)
	//int search(T e)  const;

	// returnare iterator
//    Iterator iterator() const;

	///
	/// destructor
	//~List();

};

template<class T>
T List<T>::update(int i, T e) {
	if (i < 0 || i >= size())
		throw invalid_argument("pozitia nu e valida");
	Node<T>* crt = first;
	int noE = 0;
	while (noE < i) {
		crt = crt->next;
		noE++;
	}
	T old_value = crt->info;
	crt->info = e;

	return old_value;
}

template<class T>
inline T List<T>::delete_at(int i)
{
	if (i < 0) {
		throw std::out_of_range("Index out of bounds");
	}
	if (i == 0) {
		if (!first) {
			throw std::out_of_range("Index out of bounds");
		}
		Node<T>* temp = first;
		T result = temp->info;
		first = first->next;
		delete temp;
		return result;
	}
	Node<T>* prev = first;
	for (int j = 0; j < i - 1; j++) {
		if (!prev || !prev->next) {
			throw std::out_of_range("Index out of bounds");
		}
		prev = prev->next;
	}
	Node<T>* curr = prev->next;
	if (!curr) {
		throw std::out_of_range("Index out of bounds");
	}
	T result = curr->info;
	prev->next = curr->next;
	delete curr;
	return result;
}

template<class T>
inline void List<T>::clear()
{
	Node<T>* current = first;
	while (current != nullptr) {
		Node<T>* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	first = nullptr;
	last = nullptr;
}

template<class T>
inline Node<T>* List<T>::getFirst() const
{
	return first;
}

template<class T>
inline int List<T>::indexOf(T value) const
{
	Node<T>* current = first;
	int index = 0;
	while (current != nullptr) {
		if (current->getData() == value) {
			return index;
		}
		current = current->getNext();
		index++;
	}

	return -1;
}


template<class T>
T List<T>::get_at(int i) const {
	Node<T>* crt = first;
	int noE = 0;
	while (noE < i) {
		crt = crt->next;
		noE++;
	}
	return crt->info;
}

template<class T>
void List<T>::push_back(T e) {
	Node<T>* node = new Node<T>(e, nullptr, nullptr);
	if (!first) {
		first = node;
		last = node;
	}
	else {
		Node<T>* curr = first;
		while (curr && curr->info < e) {
			curr = curr->next;
		}
		if (!curr) {
			node->prev = last;
			last->next = node;
			last = node;
		}
		else if (curr == first) {
			node->next = first;
			first->prev = node;
			first = node;
		}
		else {
			node->next = curr;
			node->prev = curr->prev;
			curr->prev->next = node;
			curr->prev = node;
		}
	}
}
template<class T>
bool List<T>::is_empty() const {
	return first == nullptr;
}

template<class T>
int List<T>::size() {
	int contor = 0;
	Node<T>* last = first;
	while (last != nullptr)
	{
		contor++;
		last = last->next;
	}
	return contor;
}


#endif //CURS7_P_LIST_H
