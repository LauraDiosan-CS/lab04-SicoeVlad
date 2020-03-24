#pragma once
#include <iostream>
#include "Banca.h"
#include <vector>
using namespace std;
class Repo
{
private:
	vector<Banca> cheltuieli;
	vector<vector<Banca>>lista;
public:
	Repo();
	~Repo();
	void addElem(Banca a);
	vector<Banca> getAll();
	vector<Banca> zileSelectate(int limita);
	void eliminareZi(int ziua);
	void eliminareIntervalZi(int left, int right);
	void eliminareTip(char* tip);
	vector<Banca>inlocuireSuma(char* tip, char* desc, int nrAp, int sumaNoua);
	vector<Banca> filtrareTip(char* tip);
	vector<Banca> filtrareSumaTip(char* tip, int suma);
	void inserareLista();
};

