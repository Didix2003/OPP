#pragma once
#include "Service.h"
#include "Validator.h"
class UI
{
private:
	Service service;
	Validator valid;

	int printMenu();
	void addEntitate();
	void update();
	void deleteEntity();
	void printAll();
	void filtrare_dupa_pret();
	void sortare_products();
	void purchase();
public:
	UI(Service& _service) : service(_service) {};
	~UI() = default;

	void start();
};