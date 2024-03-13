
#include <iostream>
#include "Repo.h"
#include "Service.h"
#include "Ui.h"
#include "Validator.h"

int main()
{
    std::cout << "Hello World!\n";
	RepoFile rep("Texte\\objects.txt");
	Validator val;
	Service service(rep, val);
	Ui ui(service);
	ui.start();

}

