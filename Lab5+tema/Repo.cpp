#include "Repo.h"
#include <string.h>
#include <vector>

using namespace std;

Repo::Repo()
{

}
Repo::~Repo()
{//distruge elementele din lista
	cheltuieli.clear();
}
void Repo::addElem(Banca ch)
{
	this->cheltuieli.push_back(ch);
}

vector<Banca>Repo::getAll()
{//obtinem toate cheltuielile
	return this->cheltuieli;
}
vector <Banca>Repo::zileSelectate(int limita)
{//sterge cheltuielile din zilele selectate
	vector<Banca> conturiSelectate;
	for (Banca a : cheltuieli)
	{
		if (a.getSuma() > limita)
		{
			conturiSelectate.push_back(a);
		}
	}
	return conturiSelectate;
}
void Repo::eliminareZi(int ziua)
{//elimina o zi dintr-un interval

	for (int i = 0; i < cheltuieli.size(); i++)
	{
		//ia un element din lista
		Banca ch = cheltuieli.at(i);

		if (ch.getZiua() == ziua)
		{
			cheltuieli.erase(cheltuieli.begin() + i); // stergem al i-lea 
			i--;
		}
	}
}

void Repo::eliminareIntervalZi(int left, int right)
{
	//sterge cheltuielile din zilele selectate
	for (int i = 0; i < cheltuieli.size(); i++)
	{

		Banca ap = cheltuieli.at(i);

		// Parcurgem toate numerele de cheluielile care trebuie sa fie sterse
		for (int j = left; j <= right; j++)
		{
			// Daca cheltuiala curent are numarul de ziua care trebuie sters 
			if (ap.getZiua() == j)
			{
				cheltuieli.erase(cheltuieli.begin() + i);
				i--;
			}
		}
	}
}

void Repo::eliminareTip(char* tip)
{


	for (int i = 0; i < cheltuieli.size(); i++)
	{

		Banca ch = cheltuieli.at(i);

		if (strcmp(ch.getTip(), tip) == 0)
		{
			cheltuieli.erase(cheltuieli.begin() + i);
			i--;
		}
	}
}
vector<Banca> Repo::inlocuireSuma(char* tip, char* desc, int zi, int sumaNoua)
{//inlocuieste suma cu o anumita valoare data de la tastatura
	for (int i = 0; i < cheltuieli.size(); i++)
	{
		Banca ch = cheltuieli.at(i);

		if (strcmp(ch.getTip(), tip) == 0 && strcmp(ch.getDescriere(), desc) == 0 && ch.getZiua() == zi)
		{
			cheltuieli.erase(cheltuieli.begin() + i);
			i--;
			Banca chNou = Banca(zi, tip, sumaNoua, desc);
			addElem(chNou);


		}
		return cheltuieli;
	}
}

vector<Banca>Repo::filtrareTip(char* tip)
{
	//vector<Banca> filtrareTip;
	for (int i = 0; i < cheltuieli.size(); i++)
	{
		Banca ch = cheltuieli.at(i);

		// Daca tipul filtrarii e diferit de tipul curent atunci stergem cheltuiala
		if (strcmp(ch.getTip(), tip) != 0)
		{
			cheltuieli.erase(cheltuieli.begin() + i);
			i--;

		}
	}
	return cheltuieli;
}

vector<Banca> Repo::filtrareSumaTip(char* tip, int suma)
{//Mentine in lista doar cele cu un anumit tip si cu suma mai mica decat o valoare data
	for (int i = 0; i < cheltuieli.size(); i++)
	{
		Banca ch = cheltuieli.at(i);

		if (ch.getSuma() < suma && strcmp(ch.getTip(), tip) == 0)
		{
			cheltuieli.erase(cheltuieli.begin() + i);
			i--;
		}
		return cheltuieli;
	}
}
void Repo::inserareLista()
{//insereaza un element in lista
	vector<Banca> ch = cheltuieli;
	lista.push_back(ch);
}
void Repo::undoLista()
{//reface lista dupa o operatiune
	if (lista.empty())
		cout << "Nu avem undo" << endl;
	if (lista.size() == 1)
	{
		vector<Banca> vectorCh;
		cheltuieli = vectorCh;
		return;
	}
	vector<Banca> vectorCh = lista[lista.size() - 2];
	cheltuieli = vectorCh;
	lista.pop_back();
}
