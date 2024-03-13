#include "Teste.h"
#include "Entitate.h"
#include "Repo.h"
#include <cassert>
#include "RepoFile.h"

void testRepo()
{
	/*Repo rep;
	char orice[] = "haide cu tipul ala";
	Entitate e1 = Entitate(orice);
	rep.addEntitate(e1);
	assert(rep.getSize() == 1);
	std::cout << "Test passed" << "\n";*/
}
void test_entitate()
{
	Entitate e1;
	assert(e1.getNume() == NULL);
	assert(e1.getCod() == NULL);
	assert(e1.getPret() == 0);
	char orice[] = { "aldoileaorice" };
	char orice2[] = { "orice" };
	Entitate e2(orice,orice2,34);
	assert(strcmp(e2.getCod(), orice) == 0);
	assert(strcmp(e2.getNume(), orice2) == 0);
	char da[] = { "haidemergi" };
	char da2[] = { "haidemergiodata" };
	e2.setCod(da);
	e2.setNume(da2);
	e2.setPret(10);
	//std::cout << e2.getTipul();
	assert(strcmp(e2.getCod(), "haidemergi") == 0);
	assert(strcmp(e2.getNume(), "haidemergiodata") == 0);
	assert(e2.getPret() == 10);
	std::cout << "Test passed Entity" << "\n";
}

void testAll()
{
	test_entitate();
	test_get_all_products();
	test_add_file();


}

void test_add_file()
{
	RepoFile repo{ "Texte\\test.txt" };
	char nume[] = { "orice_nume" };
	char cod[] = { "orice_cod" };
	Entitate e1(cod, nume, 10);
	repo.add(e1);
	assert(repo.size() == 3);
	cout << "Test passed RepoFile Add"<<endl;
	
}

void test_get_all_products()
{
	RepoFile repo{ "Texte\\test.txt" };
	char nume[] = { "orice_nume" };
	char cod[] = { "orice_cod" };
	Entitate e1(cod, nume, 10);
	char nume2[] = { "orice_nume2" };
	char cod2[] = { "orice_cod2" };
	Entitate e2(cod2, nume2, 10);
	repo.add(e1);
	repo.add(e2);
	auto products = repo.get_all();
	assert(products.size() == 2);
	assert(strcmp(products[0].getNume(), "orice_nume") == 0);
	assert(strcmp(products[1].getNume(), "orice_nume2") == 0);
	cout << "Test passed RepoFile Get_All"<<endl;
}
