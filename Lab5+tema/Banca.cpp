#pragma once
#include "Banca.h"
#include <string.h>
#include <iostream>
using namespace std;

Banca::Banca()
{//Descr: creeaza o cheltuiala 
//In: -
//Out: o instanta de tip familie

	this->ziua = 0;
	this->tip = NULL;
	this->suma = 0;
	this->descriere = NULL;

}
Banca::Banca(int ziua, char* tip, int suma, char* descriere)
{//Descr:creeaza o cheltuiala
//In: un nume,un tip,o suma
//Out: o instanta de tip familie cu informatie

	this->ziua = ziua;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->suma = suma;
	this->descriere = new char[strlen(descriere) + 1];
	strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
}
Banca::Banca(const Banca& a)
{//Descr: creeaza o cheltuiala folosind o alta cheltuiala
//In:  a o cheltuiala
//Out:o instanta de tip familie cu informatie

	this->ziua = a.ziua;
	this->tip = new char[strlen(a.tip) + 1];
	strcpy_s(this->tip, strlen(a.tip) + 1, a.tip);
	this->suma = a.suma;
	this->descriere = new char[strlen(a.descriere) + 1];
	strcpy_s(this->descriere, strlen(a.descriere) + 1, a.descriere);
}
Banca::~Banca()
{ //Descr: distruge o cheltuiala 
//In: o cheltuiala
//Out: - 

	if (this->tip != NULL)
	{
		delete[]this->tip;
		this->tip = NULL;
	}

	if (this->descriere != NULL)
	{

		delete[]this->descriere;
		this->descriere = NULL;
	}

}
int Banca::getZiua()
{//Descr: acces la ziua in care s-a facut cheltuiala
//In: o cheltuiala
//Out: ziua
	return this->ziua;
}
char* const Banca::getTip() const
{//Descr: acces la tipul cheltuieliii
//In: o cheltuiala
//Out: tipul
	return this->tip;
}
int Banca::getSuma()
{//Descr: acces la suma 
//In: o cheltuiala
//Out: suma
	return this->suma;
}
char* const Banca::getDescriere() const
{//Descr: acces la tipul cheltuieliii
//In: o cheltuiala
//Out: tipul
	return this->descriere;
}
void Banca::setZiua(int n)
{//Descr: schimba ziua in care s-a facut cheltuiala 
//In: o cheltuiala
//Out: o cheltuiala cu ziua schimbata
	this->ziua = n;
}
void Banca::setTip(char* t)
{//Descr: schimba tipul de cheltuiala
//In: o cheltuiala
//Out: o cheltuiala cu tipul schimbat
	if (this->tip)
	{
		delete[]this->tip;
	}
	this->tip = new char[strlen(t) + 1];
	strcpy_s(this->tip, strlen(t) + 1, t);
}
void Banca::setSuma(int s)
{//Descr: schimba suma cheltuielii
//In: o cheltuiala
//Out: o cheltuiala cu suma schimbata
	this->suma = s;
}
void Banca::setDescriere(char* d)
{//Descr: schimba tipul de cheltuiala
//In: o cheltuiala
//Out: o cheltuiala cu tipul schimbat
	if (this->descriere)
	{
		delete[]this->descriere;
	}
	this->descriere = new char[strlen(d) + 1];
	strcpy_s(this->descriere, strlen(d) + 1, d);
}

char* Banca::toString()
{//Descr: converteste o cheltuiala in string
//In: o cheltuiala
//Out: un string cu informatii despre cheltuiala
	int noChars = strlen(this->tip) + 1 + 5 + 2 + 5 + strlen(this->descriere) + 1 + 1;
	char* s = new char[noChars];
	char* aux = new char[5];
	strcpy_s(s, noChars, this->tip);
	strcat_s(s, noChars, ";");
	_itoa_s(this->suma, aux, 5, 10);
	strcat_s(s, noChars, aux);
	strcat_s(s, noChars, ";");
	char* aux1 = new char[5];
	_itoa_s(this->ziua, aux1, 5, 10);
	strcat_s(s, noChars, aux1);
	if (aux) {
		delete[] aux;
		aux = NULL;
	}
	if (aux1) {
		delete[] aux;
		aux = NULL;
	}

	strcat_s(s, noChars, ";");
	return s;


}



Banca& Banca::operator=(const Banca& a)
{//Descr: compara doua cheltuieli
//In: doua cheltuieli (cheltuiala curenta = this, alta cheltuiala = a)
//Out: true/false

	if (this != &a)
	{
		this->setZiua(a.ziua);
		this->setTip(a.tip);
		this->setSuma(a.suma);
		this->setDescriere(a.descriere);

	}
	return *this;
}
bool Banca::compare(Banca& a)
{
	return ((strcmp(this->tip, a.tip) == 0) && (strcmp(this->descriere, a.descriere) == 0) && (this->ziua == a.ziua) && (this->suma == a.suma));
}
