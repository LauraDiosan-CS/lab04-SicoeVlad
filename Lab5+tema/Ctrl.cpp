#include "Ctrl.h"
#include"Repo.h"
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
vector<Banca>cheltuieli;
vector<vector<Banca>>lista;

Ctrl::Ctrl()
{

}


Ctrl::~Ctrl()
{

}
Ctrl::Ctrl(Repo repo)
{
	this->repo = repo;
}
void Ctrl::addElem(Banca a)
{
	repo.addElem(a);
}
vector<Banca> Ctrl::getAll()
{
	return this->repo.getAll();
}
vector<Banca>Ctrl::zileSelectate(int limita)
{
	return this->repo.zileSelectate(limita);
}
void Ctrl::eliminareZi(int zi)
{
	this->repo.eliminareZi(zi);
}
void Ctrl::eliminareIntervalZi(int left, int right)
{
	this->repo.eliminareIntervalZi(left, right);
}
void Ctrl::eliminareTip(char* tip)
{
	this->repo.eliminareTip(tip);
}
vector<Banca>Ctrl::inlocuireSuma(char* tip, char* desc, int zi, int suma)
{
	return this->repo.inlocuireSuma(tip, desc, zi, suma);
}
vector<Banca>Ctrl::filtrareTip(char* tip)
{
	return this->repo.filtrareTip(tip);
}
vector<Banca>Ctrl::filtrareSumaTip(char* tip, int suma)
{
	return this->repo.filtrareSumaTip(tip, suma);
}
void Ctrl::inserareLista()
{
	repo.inserareLista();
}


void Ctrl::listeaza()
{//listeaza toate tranzactiile existente in lista
	vector<Banca> lista = repo.getAll();
	for (int i = 0; i < lista.size(); i++)
	{
		Banca ch = lista.at(i);
		cout << "Tranzactia: ";
		cout << ch.getZiua();
		cout << " - ";
		cout << ch.getTip()<< " ";
		cout << ch.getSuma() << " ";
		cout << " lei -  ";
		cout << ch.getDescriere() << endl;

	}
}
void Ctrl::listeazaTip(char* tip)
{//lsteaza tranzactiile de un anumit tip
	vector<Banca> lista = repo.getAll();
	for (int i = 0; i < lista.size(); i++)
	{
		Banca ch = lista.at(i);
		if (strcmp(ch.getTip(), tip) == 0)
		{
			cout << "Tranzactia: ";
			cout << ch.getZiua();
			cout << " - ";
			cout << ch.getTip() << " ";
			cout << ch.getSuma() << " ";
			cout << " lei -  ";
			cout << ch.getDescriere() << endl;
		}
	}
}
void Ctrl::undoLista()
{
	repo.undoLista();
}

void Ctrl::listeazaSumaMaiMareDecat(int suma)
{//listeaza cheltuielide cu suma mai mare decat o anumita valoare
	cout << "in";
	vector<Banca>lista = repo.getAll();
	for (int i = 0; i < lista.size(); i++)
	{
		Banca ch = lista.at(i);
		if (ch.getSuma() > suma)
		{
			cout << "Tranzactia: ";
			cout << ch.getZiua();
			cout << " - ";
			cout << ch.getTip()<< " ";
			cout << ch.getSuma()<<" ";
			cout << " lei -  ";
			cout << ch.getDescriere() << endl;
		}
	}
}

void Ctrl::listeazaSuma(int suma)
{//listeaza cheltuielile care au suma egala cu o numita valoare
	vector<Banca>lista = repo.getAll();
	for (int i = 0; i < lista.size(); i++)
	{
		Banca ch = lista.at(i);
		if (ch.getSuma() == suma)
		{
			cout << "Tranzactia: ";
			cout << ch.getZiua();
			cout << " - ";
			cout << ch.getTip()<< " ";
			cout << ch.getSuma()<<" ";
			cout << " lei -  ";
			cout << ch.getDescriere() << endl;
		}

	}

}
void Ctrl::maxZiTip(int zi, char* tip)
{//listeaza cheltuielie care au un anumit tip si suma maxima
	int max = -1, p;
	vector<Banca>lista = repo.getAll();
	for (int i = 0; i < lista.size(); i++)
	{
		Banca ch = lista.at(i);
		if (strcmp(ch.getTip(), tip) == 0)
		{
			if (max == -1)
			{
				max = ch.getSuma();
			}
			else
				if (max < ch.getSuma())
					max = ch.getSuma();
		}
	}
	for (int i = 0; i < lista.size(); i++)
	{
		Banca ch = lista.at(i);
		if (ch.getSuma() == max)
		{
			cout << "Tranzactia:";
			cout << ch.getZiua();
			cout << " - ";
			cout << ch.getTip();
			cout << ch.getSuma();
			cout << " lei -  ";
			cout << ch.getDescriere() << endl;
		}
	}
}
void Ctrl::sold(int zi)
{//listeaza soldul dintr-o anumita zi
	vector<Banca> lista = repo.getAll();
	int in = 0, out = 0;
	for (int i = 0; i < lista.size(); i++)
	{
		Banca ch = lista.at(i);
		if (ch.getZiua() == zi)
		{
			if (strcmp(ch.getTip(), "in") == 0)
			{
				in = in + ch.getSuma();
			}
			else
			{
				out = out + ch.getSuma();
			}
			cout << "Tranzactia:";
			cout << ch.getZiua();
			cout << " - ";
			cout << ch.getTip();
			cout << ch.getSuma();
			cout << " lei -  ";
			cout << ch.getDescriere() << endl;
			cout << "Sold: ";
			cout << in - out << endl;

		}
	}

}

void Ctrl::listeazaSumaTip(char* tip)
{
	vector<Banca> lista = repo.getAll();
	int s = 0;
	for (int i = 0; i < lista.size(); i++)
	{
		Banca ch = lista.at(i);
		if (strcmp(ch.getTip(), tip) == 0)
		{
			s = s + ch.getSuma();
		}
	}
	cout << "suma: "<< s << endl;
}
