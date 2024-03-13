#include "Bancomat.h"

void Bancomat::PurchaseProdus(char * cod, double amount)
{
	// Găsirea produsului după cod
	Entitate product;
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getCod() == cod) {
			product = products[i];
			break;
		}
	}

	// Verificarea dacă suma introdusă este suficientă pentru a cumpăra produsul
	if (amount < product.getPret()) {
		cout << "Suma introdusa este prea mica. Produsul costa " << product.getPret() << " lei." << endl;
		return;
	}

	// Calcularea restului
	double change = amount - product.getPret();
	vector<int> coin_counts_copy = coin_counts;
	vector<int> change_coins(coin_counts.size(), 0);
	for (int i = coins.size() - 1; i >= 0; i--) {
		while (change >= coins[i] && coin_counts_copy[i] > 0) {
			change -= coins[i];
			change_coins[i]++;
			coin_counts_copy[i]--;
		}
	}

	// Verificarea dacă tonomatul are destule monezi pentru a da restul
	if (change > 0) {
		cout << "Tonomatul nu are suficiente monezi pentru a da restul." << endl;
		return;
	}

	// Actualizarea stocului de monezi
	coin_counts = coin_counts_copy;

	// Afișarea mesajului de finalizare a achiziției și a restului dat
	cout << "Produsul " << product.getNume() << " a fost achizitionat cu succes. Restul dat: " << amount - product.getPret() << " lei	";
	for (int i = coins.size() - 1; i >= 0; i--) {
		if (change_coins[i] > 0) {
			cout << change;
		}
	}
}
