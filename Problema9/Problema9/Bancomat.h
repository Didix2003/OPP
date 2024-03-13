#pragma once
#include "Entitate.h"
#include <vector>
class Bancomat
{
private:
	vector<Entitate> products;
	vector<int> coins = { 1, 5, 10, 50, 100, 500 };
	vector<int> coin_counts = { 10, 10, 10, 10, 10, 10 };
public:
	void PurchaseProdus(char *cod, double amount);



};

