#pragma once
#include "Repo.h"
#include "Service.h"
class UI
{
private:
	Service service;
	int printMenu();
	void addobiecte();
	void updateobiecte();
	void deleteobiecte();
	void sortare_products();
	void sortare_products2();
	void filtrare_an();
	void filtrare_nr();
	void printAll();
	
public:
	UI(Service& _service) : service(_service) {};
	~UI() = default;

	void start();
};