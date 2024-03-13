// Problema9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Entitate.h"
#include "Repo.h"
#include "Teste.h"
#include "Service.h"
#include "UI.h"
#include "RepoFile.h"
#include "Validator.h"

using namespace std;
int main()
{
	//testAll();
	Validator val;
	RepoFile repo("Texte\\products.txt");
	//Repo repo;
	Service service(repo,val);
	UI ui(service);
	ui.start();
	return 0;


}
