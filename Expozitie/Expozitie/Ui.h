#pragma once
#include "Repo.h"
#include "Service.h"
class Ui
{
private:
	Service service;
	int printMenu();
	void addobiecte();
	void updateobiecte();
	void deleteobiecte();
	void printAll();
	void sortare_voturi();
	void voteaza();
	void undo();
	void filtreaza_dupa_autor();
public:
	Ui(Service& _service) : service(_service) {};
	~Ui()=default;

	void start();
};

