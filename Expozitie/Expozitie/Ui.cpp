#include "Ui.h"
#include <iostream>
#include "Muzeu.h"
#include "Validator.h"
#include "Exception.h"

using namespace std;

int Ui::printMenu()
{
	cout << endl << "1. Adauga obiect." << endl;
	cout << endl << "2. Afiseaza obiecte." << endl;
	cout << endl << "3. Voteaza! " << endl;
	cout << endl << "4. Sortare voturi." << endl;
	cout << endl << "5. Filtreaza dupa autor. " << endl;
	cout << endl << "u. Undo. " << endl;
	cout << endl << "x. Exit. " << endl;
	return 0;
}

void Ui::addobiecte()
{
	try
	{
		char autor[50], denumire[100], categorie[100];
		cout << endl << "Input autor: ";
		cin >> autor;
		cout << endl << "Input denumire: ";
		cin >> denumire;
		cout << endl << "Input categorie: ";
		cin >> categorie;
		this->service.addobiecte(Muzeu(autor, denumire, categorie));

	}
	catch (const ExistadejaException& e)
	{
		cout << e.what() << endl;
	}
}

void Ui::printAll()
{
	for (int i = 0; i < this->service.getSize(); i++)
	{
		cout << "Obiectul " << i << " Autorul este: " << this->service.getItemFromPos(i).getAutor() << ", Denumirea este: " << this->service.getItemFromPos(i).getDenumire() << ", Categoria este: " << this->service.getItemFromPos(i).getCategoria() << endl;
	}
}

void Ui::sortare_voturi()
{
	this->service.sortare();
}

void Ui::voteaza()
{
	int pos;
	cout << "Input position: ";
	cin >> pos;
	this->service.votare(pos);
}

void Ui::undo()
{
	this->service.undo();
}

void Ui::filtreaza_dupa_autor()
{
	char autor[50];
	cout << "Input autor: ";
	cin >> autor;
	this->service.filtrare_artist(autor);
}

void Ui::start()
{		
	char op;
	while (true)
	{
		printMenu();
		cin >> op;
		if (op == '1')
		{
			this->addobiecte();
		}
		else if (op == '2')
		{
			this->printAll();
		}
		else if (op == '3')
		{
			this->voteaza();
		}
		else if (op == '4')
		{
			this->sortare_voturi();
		}
		else if (op == '5')
		{
			this->filtreaza_dupa_autor();
		}
		else if (op == 'u')
		{
			this->undo();
		}
		else if (op == 'x')
			break;
		else
			cout << "Optiune gresita!";
	}
}
