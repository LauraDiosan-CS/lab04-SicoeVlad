#pragma once
#include"Repo.h"
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
class Ctrl
{
private:
	Repo repo;
public:
	Ctrl();
	~Ctrl();
	Ctrl(Repo repo);
	void addElem(Banca a);
	vector<Banca> getAll();
	vector<Banca> zileSelectate(int limita);
	void eliminareZi(int ziua);
	void eliminareIntervalZi(int left, int right);
	void eliminareTip(char* tip);
	vector<Banca>inlocuireSuma(char* tip, char* desc, int zi, int sumaNoua);
	vector<Banca> filtrareTip(char* tip);
	vector<Banca> filtrareSumaTip(char* tip, int suma);
	void inserareLista();
	void listeaza();
	void listeazaTip(char* tip);
	void undoLista();
	void listeazaSumaMaiMareDecat(int suma);
	void listeazaSuma(int suma);
	void sold(int zi);
	void maxZiTip(int zi, char* tip);
	void listeazaSumaTip(char* tip);
};


