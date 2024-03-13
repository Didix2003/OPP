#include "UI.h"
#include <iostream>
#include "Validator.h"


int UI::printMenu()
{
	std::cout << "\n" << "1. Adauga produs ->" << "\n";
	std::cout << "2. Afisare produs ->" << "\n";
	std::cout << "3. Modifica o produds ->" << "\n";
	std::cout << "4. Sterge o produs ->" << "\n";
	std::cout << "5. Filtrare dupa pret ->" << "\n";
	std::cout << "6. Sortare produse ->" << "\n";
	std::cout << "7. Cumpara produs ->" << "\n";
	std::cout << "x. Exit ->" << "\n";

	return 0;
}

void UI::addEntitate() {
	try {
		char cod[50];
		char nume[50];
		double pret;
		cout << "Input cod: ";
		cin >> cod;
		cout << endl;
		cout << "Input nume: ";
		cin >> nume;
		cout << endl;
		bool prevalid = false;
		while (!prevalid)
		{
			cout << "Input pret: ";
			cin >> pret;
			cout << endl;
			if (valid.checkInt(pret) == 0)
			{
				throw AdaugareImposibilaException("Pretul este invalid. Trebuie sa fie int");
			}
			else
				prevalid = true;

		}

		this->service.addEntitate(Entitate(cod, nume, pret));

	}
	catch (const AdaugareImposibilaException& e)
	{
		cout << e.what() << endl;
	}
	
}
void UI::update()
{
	try {
		int position;
		cout << "Input position update: ";
		cin >> position;
		cout << endl;
		char cod[50];
		char nume[50];
		double pret;
		cout << "Input cod: ";
		cin >> cod;
		cout << endl;
		cout << "Input nume: ";
		cin >> nume;
		cout << endl;
		cout << "Input pret: ";
		cin >> pret;
		cout << endl;
		this->service.update(position, Entitate(cod, nume, pret));
	}
	catch (ProdusulNuExistaExcpetion& e)
	{
		cout << e.what() << endl;
	}
}

void UI::deleteEntity()
{
	try {
		int position;
		cout << "Input position: ";
		cin >> position;
		cout << endl;
		this->service.deleteEntity(position);

	}
	catch (ProdusulNuExistaExcpetion& e)
	{
		cout << e.what() << endl;
	}
}

void UI::printAll() {
	for (int i = 0; i < this->service.getSize(); i++) {
		cout << "Entity: " << i << ", Codul produsului este: " << this->service.getEntitateAtPos(i).getCod() << ", Numele produsului: " << this->service.getEntitateAtPos(i).getNume() << ", Pretul produsului este: " << this->service.getEntitateAtPos(i).getPret()<<endl;
	}
}
void UI::filtrare_dupa_pret()
{
	double pret;
	cout << "Input pret: ";
	cin >> pret;
	for (auto entity : this->service.filtrare_dupa_pret(pret))
	{
		cout << "Codul este: " << entity.getCod() << ", Numele este: " << entity.getNume() << ", Pretul este: " << entity.getPret()<<endl;
	}
}
void UI::sortare_products()
{
	for (auto entity : this->service.sortare())
	{
		cout << "Codul este: " << entity.getCod() << ", Numele este: " << entity.getNume() << ", Pretul este: " << entity.getPret()<<endl;
	}
	
}
void UI::purchase()
{
	char cod[50];
	double sumaPlatita;
	cout << "Input cod: ";
	cin >> cod;
	cout << endl;
	cout << "Input Suma pe care doriti sa o platiti: ";
	cin >> sumaPlatita;
	cout << endl;
	this->service.PurchaseProdus(cod,sumaPlatita);
}
void UI::start()
{
	char op;
	while (true)
	{
		printMenu();
		std::cin >> op;
		if (op == '1')
		{
			this->addEntitate();

		}
		else if (op == '2')
		{
			this->printAll();
		}
		else if (op == '3')
		{
			this->update();
		}
		else if (op == '4')
		{
			this->deleteEntity();
		}
		else if (op == '5')
		{
			this->filtrare_dupa_pret();
		}
		else if (op == '6')
		{
			this->sortare_products();
		}
		else if (op == '7')
		{
			this->purchase();
		}
		else if (op == 'x')
		{
			std::cout << "Bye!";
			break;
		}
		else
			std::cout << "Optiunea gresita!" << "\n";


	}
}
