#include "Banca.h"
#include "Repo.h"
#include <assert.h>
#include "Test.h"
#include "Ctrl.h"
#include <iostream>

using namespace std;
void testBanca()
{
	char* tip = new char[100];
	strcpy_s(tip, 100, "in");
	char* descriere = new char[100];
	strcpy_s(descriere, 100, "pizza");
	Banca s1 = Banca();
	assert(s1.getZiua() == 0);
	assert(s1.getSuma() == 0);
	assert(s1.getTip() == NULL);
	assert(s1.getDescriere() == NULL);
	Banca s2 = Banca(2, tip, 100, descriere);
	char* tip1 = new char[100];
	strcpy_s(tip1, 100, "in");
	Banca s3 = Banca(s2);
	assert(s3.getZiua() == 2);
	assert(s3.getSuma() == 100);
	assert(strcmp(s3.getTip(), tip) == 0);
	assert(strcmp(s3.getDescriere(), descriere) == 0);
	assert(strcmp(s3.toString(), "in;100;2;") == 0);
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
	char* desc = new char[100];
	char* desc1 = new char[100];
	strcpy_s(desc, 100, "pizza");
	strcpy_s(desc1, 100, "KFC");
	Banca c1 = Banca(25, tip, 100, desc);
	Banca  c2 = Banca(213, tip1, 100, desc1);
	r.addElem(c1);
	assert(r.getAll().size() == 1);
	r.addElem(c2);
	assert(r.getAll().size() == 2);
	//r.getAll();
	cout << "Testele la Repo au trecut. " << endl;
}


void testCtrl()
{
	Ctrl c;
	char* tip = new char[100];
	char* tip1 = new char[100];
	char* desc = new char[100];
	char* desc1 = new char[100];
	strcpy_s(tip, 100, "in");
	strcpy_s(tip1, 100, "out");
	strcpy_s(desc, 100, "salar");
	strcpy_s(desc1, 100, "solar");
	Banca b1 = Banca(25, tip, 100, desc);
	Banca  b2 = Banca(2, tip1, 100, desc);
	c.addElem(b1);
	c.addElem(b2);
	assert(c.getAll().size() == 2);
	c.eliminareTip(tip1);
	assert(c.getAll().size() == 1);
	c.eliminareIntervalZi(2, 6);
	assert(c.getAll().size() == 1);
	c.eliminareZi(25);
	assert(c.getAll().size() == 0);
	c.getAll();
	assert(c.getAll().size() == 0);
	cout << "Testele la Ctrl au trecut. " << endl;
}


