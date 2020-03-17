#include "Banca.h"
#include "Repo.h"
#include <assert.h>
#include "Test.h"
#include <iostream>

using namespace std;
void testBanca()
{
	char* tip = new char[100];
	strcpy_s(tip, 100, "in");
	Banca s1 = Banca();
	assert(s1.getTip() == NULL);
	
	Banca s2 = Banca(tip);
	char* tip1 = new char[100];
	strcpy_s(tip1, 100, "in");
	Banca s3 = Banca(s2);
	assert(strcmp(s3.getTip(), tip) == 0);
	assert(s2.compare(s3) == true);
	cout << "Testele la clasa au trecut." << endl;

}
void testRepo()
{
	Repo r;
	char* tip = new char[100];
	char* tip1 = new char[100];
	strcpy_s(tip, 100, "in");
	strcpy_s(tip1, 100, "out");
	Banca c1 = Banca(tip);
	Banca  c2 = Banca(tip1);
	r.addElem(c1);
	assert(r.getAll().size() == 1);
	r.addElem(c2);
	assert(r.getAll().size() == 2);
	r.getAll();
	cout << "Testele la Repo au trecut. " << endl;
}



