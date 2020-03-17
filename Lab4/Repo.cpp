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
	//std::cout << "Dest BR" << std::endl;
}
void Repo::addElem(Banca ch)
{
	this->cheltuieli.push_back(ch);
}

vector<Banca>Repo::getAll()
{//obtinem toate cheltuielile
	return this->cheltuieli;
}