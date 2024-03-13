#include "Service.h"
#include "Repo.h"
#include "Validator.h"
#include<map>

/*
	adauga obiectele
	obiect:obiect de tip Muzeu
	return: adauga obiectul in vector
*/
void Service::addobiecte(Muzeu obiect)
{
	Muzeu oldEntity = obiect;
	historyActions.push_back("add");
	history.push_back(oldEntity);
	this->validate.validare_existenta(this->repo.get_all(), obiect);
	this->repo.add(obiect);
}
/*
	modifica obiectele
	pos: pozitia obiectului
	newObiect: obiect de tip Muzeu
	return: obiectul modificat de e pozitia pos
*/
void Service::updateobiecte(int pos, Muzeu newObiect)
{
	Muzeu oldEntity = repo.get_all()[pos];
	historyActions.push_back("update");
	history.push_back(oldEntity);
	this->validate.validare_pozitie(this->repo.get_all(), pos);
	this->validate.validare_dimensiune(this->repo.get_all(), pos);
	this->repo.updateFile(pos, newObiect);
}
/*
	sterge obiectele
	pos: pozitia obiectului
	return: stergerea obiectului de pe pozitia pos
*/
void Service::deleteobiecte(int pos)
{
	Muzeu oldEntity = repo.get_all()[pos];
	historyActions.push_back("delete");
	history.push_back(oldEntity);
	this->validate.validare_pozitie(this->repo.get_all(), pos);
	this->validate.validare_dimensiune(this->repo.get_all(), pos);
	this->repo.deleteFile(pos);
}
/*
	pos: pozitia obiectului
	return: elementul de pozitia pos
*/
Muzeu Service::getItemFromPos(int pos)
{
	return this->repo.getItemFromPos(pos);
}
/*
	return dimensiunea vectorului
*/
int Service::getSize()
{
	return this->repo.getSize();
}
/*
	return categoriile sortate in functie de voturi
*/
void  Service::sortare()
{

	std::vector<std::pair<std::string, int>> sortedVotes(voturi.begin(), voturi.end());
	for (int i = 1; i < sortedVotes.size(); i++) {
		std::pair<std::string, int> key = sortedVotes[i];
		int j = i - 1;
		while (j >= 0 && sortedVotes[j].second < key.second) {
			sortedVotes[j + 1] = sortedVotes[j];
			j--;
		}
		sortedVotes[j + 1] = key;
	}
	std::cout << "Vote Statistics:" << std::endl;
	for (const auto& pair : sortedVotes) {
		std::cout << "Category: " << pair.first << ", Votes: " << pair.second << std::endl;
	}
}
/*
	pos:pozitia obiectului
	return: votarea unui obiect din vector dupa pozitia pos

*/

void Service::votare(int pos)
{
	vector<Muzeu> obiecte = this->repo.get_all();
	if (pos >= 0 && pos < obiecte.size()) {
		Muzeu& artObject = obiecte[pos];
		voturi[artObject.getCategoria()]++;
		std::cout << "Voted for Art Object at position " << pos << "." << std::endl;
	}
	else {
		std::cout << "Invalid position. Voting failed." << std::endl;
	}
}
/*
	autor: obiect de tip char
	return: vectorul in functie de data de intrare autor
*/

void Service::filtrare_artist(char * autor)
{
	for (auto entity : this->repo.get_all())
	{
		if (strcmp(entity.getAutor(), autor) == 0)
		{
			cout << "Autorul este: " << entity.getAutor() << ", Denumirea este: " << entity.getDenumire() << ", Categoria este: " << entity.getCategoria() << endl;
		}
	}
}
/*
	return: afiseaza tot vectorul
*/
vector<Muzeu> Service::getAll()
{
	return this->repo.get_all();
}

void Service::undo()
{
	if (historyActions.empty())
	{
		cout << "Nu exista actiuni de anulat " << endl;
		return;
	}
	string lastAction = historyActions.back();
	historyActions.pop_back();

	Muzeu lastEntity = history.back();
	history.pop_back();

	if (lastAction == "add") {
		repo.deleteFile(repo.getAll().size() - 1);
	}
	else if (lastAction == "update") {
		Muzeu oldEntity = lastEntity;
		repo.updateFile(history.size(), oldEntity);
	}
	else if (lastAction == "delete") {
		Muzeu deletedEntity = lastEntity;
		repo.add(deletedEntity);
	}
}
