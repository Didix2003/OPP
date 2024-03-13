#pragma once
#include "VectorDinamic.h"
#include "List.h"
typedef int TElem;

class Collection
{
private:
	List<TElem> elements;
	List<int> occurrences;
	int distinctelements;
public:
	Collection();
	void add(TElem elem);
	bool remove(TElem elem);
	bool search(TElem elem);
	int size();
	int nroccurrences(TElem elem);
	void destroy();
	void setUp(int i);
	/**
	 * this will be removed
	 */
	int getAt(int position) const;
	void setDown(int i);
	void setUpBack(int i);
	Collection& operator=(const Collection& other);

};

