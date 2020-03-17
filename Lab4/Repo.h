#pragma once
#include <iostream>
#include "Banca.h"
#include <vector>
using namespace std;
class Repo
{
private:
	vector<Banca> cheltuieli;
public:
	Repo();
	~Repo();
	void addElem(Banca a);
	vector<Banca> getAll();
};