#include "UI.h"
#include <iostream>
#include "Carte.h"

using namespace std;

int UI::printMenu()
{
	cout << endl << "1. Adauga carte." << endl;
	cout << endl << "2. Update carte." << endl;
	cout << endl << "3. Sterge carte." << endl;
	cout << endl << "4. Afiseaza carti." << endl;
	cout << endl << "5. Sorteaza carti dupa nume." << endl;
	cout << endl << "6. Sorteaza carti dupa autor." << endl;
	cout << endl << "7. Filtrare carti dupa an." << endl;
	cout << endl << "8. Filtrare carti dupa nr." << endl;
	cout << endl << "x. Exit. " << endl;
	return 0;
}

void UI::addobiecte()
{

		char autor[50], nume[100];
		int an,nr_carti;
		cout << endl << "Input nume: ";
		cin >> nume;
		cout << endl << "Input an: ";
		cin >> an;
		cout << endl << "Input autor: ";
		cin >> autor;
		cout << endl << "Input nr_carti: ";
		cin >> nr_carti;
		this->service.addobiecte(Carte(nume,an,autor,nr_carti));

}
void UI::updateobiecte()
{
	int position;
	cout << "Input position update: ";
	cin >> position;
	cout << endl;
	char autor[50], nume[100];
	int an, nr_carti;
	cout << endl << "Input nume: ";
	cin >> nume;
	cout << endl << "Input an: ";
	cin >> an;
	cout << endl << "Input autor: ";
	cin >> autor;
	cout << endl << "Input nr_carti: ";
	cin >> nr_carti;
	this->service.updateobiecte(position,Carte(nume, an, autor, nr_carti));
}

void UI::deleteobiecte()
{
		int position;
		cout << "Input position: ";
		cin >> position;
		cout << endl;
		this->service.deleteobiecte(position);
}

void UI::sortare_products()
{
	for (auto entity : this->service.sortare_nume())
	{
		cout << "Numele este: " << entity.getNume() << ", Anul este: " << entity.getAn() << ", Autorul este: " << entity.getAutor()<<", Nr_de_carti este: "<<entity.getnr_carti() << endl;
	}
}

void UI::sortare_products2()
{
	for (auto entity : this->service.sortare_autor())
	{
		cout << "Numele este: " << entity.getNume() << ", Anul este: " << entity.getAn() << ", Autorul este: " << entity.getAutor() << ", Nr_de_carti este: " << entity.getnr_carti() << endl;
	}
}

void UI::filtrare_an()
{
	int an;
	cout << "Input an: ";
	cin >> an;
	for (auto entity : this->service.filtrare_dupa_an(an))
	{
		cout << "Numele este: " << entity.getNume() << ", Anul este: " << entity.getAn() << ", Autorul este: " << entity.getAutor() << ", Nr_de_carti este: " << entity.getnr_carti() << endl;
	}
}

void UI::filtrare_nr()
{
	int nr_carti;
	cout << "Input nrc_carti: ";
	cin >> nr_carti;
	for (auto entity : this->service.filtrare_dupa_nr(nr_carti))
	{
		cout << "Numele este: " << entity.getNume() << ", Anul este: " << entity.getAn() << ", Autorul este: " << entity.getAutor() << ", Nr_de_carti este: " << entity.getnr_carti() << endl;
	}
}

void UI::printAll()
{
	for (int i = 0; i < this->service.getSize(); i++)
	{
		cout << "Cartea " << i << " Numele este: " << this->service.getItemFromPos(i).getNume() << ", Anul este: " << this->service.getItemFromPos(i).getAn() << ", Autorul este: " << this->service.getItemFromPos(i).getAutor()<<", Nr de carti este: "<<this->service.getItemFromPos(i).getnr_carti() << endl;
	}
}

void UI::start()
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
			this->updateobiecte();
		}
		else if (op == '3')
		{
			this->deleteobiecte();
		}
		else if (op == '4')
		{
			this->printAll();
		}
		else if (op == '5')
		{
			this->sortare_products();
		}
		else if (op == '6')
		{
			this->sortare_products2();
		}
		else if (op == '7')
		{
			this->filtrare_an();
		}
		else if (op == '8')
		{
			this->filtrare_nr();
		}
		else if (op == 'x')
			break;
		else
			cout << "Optiune gresita!";
	}
}
