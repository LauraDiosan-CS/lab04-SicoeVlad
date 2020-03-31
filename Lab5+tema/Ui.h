#pragma once
#include "Banca.h"
#include "Repo.h"
#include "Ctrl.h"
#include<iostream>
#include<string.h>
#include<vector>
#include <cstring>
using namespace std;
class Ui
{
private:
	Ctrl ctrl;

public:
	Ui();
	~Ui();
	Ui(Ctrl ctrl);
	bool validTip(char* tip);
	void printMeniu();
	void addElem(Banca a);
	vector<Banca> getAll();
	vector<Banca> zileSelectate(int limita);
	void eliminareZi(int zi);
	void maxZiTip(int zi, char* tip);
	void eliminareIntervalZi(int left, int right);
	void eliminareTip(char* tip);
	vector<Banca>inlocuireSuma(char* tip, char* desc, int nrzi, int sumaNoua);
	vector<Banca> filtrareTip(char* tip);
	vector<Banca> filtrareSumaTip(int suma, char* tip);
	void inserareLista();
	void undoLista();
	void listeaza();
	void listeazaTip(char* tip);
	void listeazaSumaMaiMareDecat(int suma);
	void listeazaSuma(int suma);
	int optiune();
	void run();
	void sold(int zi);
	void listeazaSumaTip(char* tip);



};

