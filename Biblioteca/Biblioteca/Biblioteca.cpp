// Biblioteca.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RepoFile.h"
#include "Service.h"
#include "UI.h"
#include "Teste.h"

int main()
{
	//testAll();
    std::cout << "Hello World!\n";
	RepoFile rep("Texte\\carti.txt");
	Service service(rep);
	UI ui(service);
	ui.start();
}


