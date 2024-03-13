#pragma once

typedef int TElem;

class VectorDinamic {
private:
	//TODO definiti o reprezentare
	int capacity;
	int nrElems;
	TElem* elems;
	void resize();
public:

	VectorDinamic();
	int size() const;
	TElem getAt(int i) const;
	TElem update(int i, TElem e);
	void push_back(TElem e);
	void addAt(int i, TElem e);
	TElem sterge(int i);
	bool search(TElem elem);
	void setDown(int i);
	void setUp(int pos);
	int IndexOf(TElem elem);
	void setAt(int poz, TElem elem);
	~VectorDinamic();

};


