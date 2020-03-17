#pragma once
#include "Banca.h"
#include <string.h>
#include <iostream>
using namespace std;

Banca::Banca()
{//Descr: creeaza o cheltuiala 
//In: -
//Out: o instanta de tip familie
	//cout << "Constructor implicit" << endl;
	this->tip = NULL;
}
Banca::Banca(char* tip)
{//Descr:creeaza o cheltuiala
//In: un nume,un tip,o suma
//Out: o instanta de tip familie cu informatie
	//cout << "Constructor cu parametrii" << endl;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}
Banca::Banca(const Banca& a)
{//Descr: creeaza o cheltuiala folosind o alta cheltuiala
//In:  a o cheltuiala
//Out:o instanta de tip familie cu informatie
	//cout << "Constructor de copiere" << endl;
	this->tip = new char[strlen(a.tip) + 1];
	strcpy_s(this->tip, strlen(a.tip) + 1, a.tip);
}
Banca::~Banca()
{ //Descr: distruge o cheltuiala 
//In: o cheltuiala
//Out: - 

	if (this->tip != NULL)
	{
		//cout << "destructor" << endl;
		delete[]this->tip;
		this->tip = NULL;
	}
	
}
char* const Banca::getTip() const
{//Descr: acces la tipul cheltuieliii
//In: o cheltuiala
//Out: tipul
	return this->tip;
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

char* Banca::toString()
{//Descr: converteste o cheltuiala in string
//In: o cheltuiala
//Out: un string cu informatii despre cheltuiala
	int noChars = strlen(this->tip) + 1 + 5 + 2 + 5;
	char* s = new char[noChars];
	
	return s;


}



Banca& Banca::operator=(const Banca& a)
{//Descr: compara doua cheltuieli
//In: doua cheltuieli (cheltuiala curenta = this, alta cheltuiala = a)
//Out: true/false
	//cout << "supraincarcarea lui =" << endl;
	if (this != &a)
	{
		this->setTip(a.tip);
	}
	return *this;
}
bool Banca::compare(Banca& a)
{
	return ((strcmp(this->tip, a.tip) == 0));
}
