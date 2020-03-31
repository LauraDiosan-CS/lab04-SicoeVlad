#include "Ui.h"
#include "Banca.h"
#include "Repo.h"
#include "Ctrl.h"
#include<iostream>
#include<string.h>
#include<vector>
#include <cstring>
#include<ctime>
using namespace std;

Ui::Ui()
{

}


Ui::~Ui()
{

}
Ui::Ui(Ctrl ctrl)
{
	this->ctrl = ctrl;
}
bool Ui::validTip(char* tip)
{//Valideaza daca tipul este in sau out
	if (strcmp(tip, "in") == 0 || strcmp(tip, "out") == 0)
		return true;
	return false;
}
void Ui::printMeniu()
{//afiseza meniu
	cout << "0)Exit\n";
	cout << "1) Adaugare zi curenta\n";
	cout << "2) Adaugare cheltuiala zi specificata\n";
	cout << "3) Eliminare zi\n";
	cout << "4) Eliminare interval zile\n";
	cout << "5) Eliminare tip tranzactie\n";
	cout << "6) Listare tranzactii\n";
	cout << "7) Listare tranzactii de anumit tip\n";
	cout << "8) Listare tranzactii cu suma mai mare decat\n";
	cout << "9)Listare tranzactii cu o anumita suma\n";
	cout << "10) Listare sold dintr-o anumita zi\n";
	cout << "11) Suma tranzatiilor de un anumit tip" << endl;
	cout << "12) Pastrare tranzactii de un anumit tip" << endl;
	cout << "13)Undo" << endl;

}
void Ui::addElem(Banca a)
{
	this->ctrl.addElem(a);
}

vector<Banca>Ui::getAll()
{
	return ctrl.getAll();
}
vector <Banca>Ui::zileSelectate(int limita)
{
	return ctrl.zileSelectate(limita);
}

void Ui::eliminareZi(int zi)
{
	ctrl.eliminareZi(zi);
}
void Ui::maxZiTip(int zi, char* tip)
{
	ctrl.maxZiTip(zi, tip);
}
void Ui::eliminareIntervalZi(int left, int right)
{
	ctrl.eliminareIntervalZi(left, right);
}

void Ui::eliminareTip(char* tip)
{
	ctrl.eliminareTip(tip);
}

vector<Banca> Ui::inlocuireSuma(char* tip, char* desc, int zi, int sumaNoua)
{
	return ctrl.inlocuireSuma(tip, desc, zi, sumaNoua);
}
vector<Banca> Ui::filtrareTip(char* tip) {
	return ctrl.filtrareTip(tip);

}
vector<Banca> Ui::filtrareSumaTip(int suma, char* tip)
{
	return ctrl.filtrareSumaTip(tip, suma);
}
void  Ui::inserareLista()
{
	ctrl.inserareLista();
}
void Ui::undoLista()
{
	ctrl.undoLista();
}
void Ui::listeaza()
{
	ctrl.listeaza();
}

void Ui::listeazaTip(char* tip)
{
	ctrl.listeazaTip(tip);
}

void Ui::listeazaSumaMaiMareDecat(int suma)
{
	ctrl.listeazaSumaMaiMareDecat(suma);
}

void Ui::listeazaSumaTip(char* tip)
{
	ctrl.listeazaSumaTip(tip);
}
void Ui::listeazaSuma(int suma)
{
	ctrl.listeazaSuma(suma);
}
void Ui::sold(int zi)
{
	ctrl.sold(zi);
}
int Ui::optiune()
{
	int optiune;
	cout << "Optiunea este :"; cin >> optiune;
	return optiune;
}
void Ui::run()
{//porneste aplicatia
	char* tip = new char[100];
	char* desc = new char[100];
	int zi, left, right;
	int suma, sumaNoua;
	vector<Banca> cheltuieli;
	vector<Banca> selectati;
	int limita;
	Banca a1 = Banca();
	int optiune;
	printMeniu();
	cout << "Optiunea este :"; cin >> optiune;
	while (optiune != 0)
	{
		while (optiune != 0)
		{
			if (optiune == 1)
			{
				time_t now = time(0);
				tm ltm;
				localtime_s(&ltm, &now);
				zi = ltm.tm_mday;
				cout << zi << endl;
				cout << "Introduceti tipul: ";
				cin >> tip;
				while (!validTip(tip))
				{
					cout << "Introduceti tipul: ";
					cin >> tip;
				}
				cout << "Introduceti suma: ";
				cin >> suma;

				cout << "Introduceti descrierea: ";
				cin >> desc;

				a1 = Banca(zi, tip, suma, desc);
				addElem(a1);

				cheltuieli = getAll();
				inserareLista();
				cout << "Optiunea este :"; cin >> optiune;

			}
			else
				if (optiune == 2)
				{
					cout << "Introduceti tipul: ";
					cin >> tip;
					while (!validTip(tip))
					{
						cout << "Introduceti tipul: ";
						cin >> tip;
					}
					cout << "Introduceti zi: ";
					cin >> zi;
					while (zi <= 0 || zi > 31)
					{
						cout << "Ziua nu exista\n";
						cout << "Introduceti zi: ";
						cin >> zi;
					}
					cout << "Introduceti suma: ";
					cin >> suma;

					cout << "Introduceti descrierea: ";
					cin >> desc;

					a1 = Banca(zi, tip, suma, desc);
					addElem(a1);

					cheltuieli = getAll();
					inserareLista();
					cout << "Optiunea este :"; cin >> optiune;
				}
				else
					if (optiune == 3)
					{//eliminare zi
						cheltuieli = getAll();
						cout << "Dati ziua tranzactiei care trebuie stearsa: ";
						cin >> zi;
						eliminareZi(zi);
						cheltuieli = getAll();
						inserareLista();
						cout << "Optiunea este :"; cin >> optiune;
					}
					else
						if (optiune == 4)
						{
							cheltuieli = getAll();
							cout << "Limita stanga:";
							cin >> left;
							cout << "limita dreapta:";
							cin >> right;
							eliminareIntervalZi(left, right);
							cheltuieli = getAll();
							inserareLista();
							cout << "Optiunea este :"; cin >> optiune;
						}
						else
							if (optiune == 5)
							{
								cheltuieli = getAll();
								cout << "Dati tipul tranzactiei: ";
								cin >> tip;
								while (!validTip(tip))
								{
									cout << "Dati tipul tranzactiei: ";
									cin >> tip;
								}
								eliminareTip(tip);
								cheltuieli = getAll();
								inserareLista();
								cout << "Optiunea este :"; cin >> optiune;
							}
							else
								if (optiune == 6)
								{
									//listare tranzactii
									cheltuieli = getAll();
									if (cheltuieli.size() == 0)
									{
										cout << "Nu exista elemente in lista" << endl;
										cout << "Optiunea este :"; cin >> optiune;
									}
									listeaza();
									cheltuieli = getAll();
									inserareLista();
									cout << "Optiunea este :"; cin >> optiune;

								}
								else
									if (optiune == 7)
									{
										//listare tranzacii de un anumit tip

										cout << "Tipul este:"; cin >> tip;
										cheltuieli = getAll();
										while (!validTip(tip))
										{
											cout << "Tipul este: ";
											cin >> tip;
										}
										listeazaTip(tip);
										cheltuieli = getAll();
										inserareLista();
										cout << "Optiunea este :"; cin >> optiune;
									}
									else
										if (optiune == 8)
										{
											//Listare tranzactii cu suma mai mare decat
											cheltuieli = getAll();
											cout << "Suma este:"; cin >> suma;
											listeazaSumaMaiMareDecat(suma);
											cheltuieli = getAll();
											inserareLista();
											cout << "Optiunea este :"; cin >> optiune;
										}
										else
											if (optiune == 9)
											{//Listare tranzactii de o anumita suma
												cheltuieli = getAll();
												cout << "Suma este:"; cin >> suma;
												listeazaSuma(suma);
												cheltuieli = getAll();
												inserareLista();
												cout << "Optiunea este :"; cin >> optiune;
											}
											else
												if (optiune == 10)
												{//Listare sold dintr-o anumita zi
													cheltuieli = getAll();
													cout << "Introduceti ziua: "; cin >> zi;
													sold(zi);
													cheltuieli = getAll();
													inserareLista();
													cout << "Optiunea este :"; cin >> optiune;
												}
												else
													if (optiune == 11)
													{
														//Suma tranzatiilor de un anumit tip
														cheltuieli = getAll();
														cout << "Tipul este: ";
														cin >> tip;
														while (!validTip(tip))
														{
															cout << "Tipul este: ";
															cin >> tip;
														}

														listeazaSumaTip(tip);
														cheltuieli = getAll();
														inserareLista();
														cout << "Optiunea este :"; cin >> optiune;
													}
													else

														if (optiune == 12)
														{//pastreaza tranzactia de un anumit tip
															
															cout << "Tipul este: ";
															cin >> tip;
															while (!validTip(tip))
															{
																cout << "Tipul este: ";
																cin >> tip;
															}
															cheltuieli = getAll();
															filtrareTip(tip);
															cheltuieli = getAll();
															inserareLista();
															cout << "Optiunea este :"; cin >> optiune;
														}
													
										               else
															if (optiune == 13)
															{
																undoLista();
																cout << "Optiunea este :"; cin >> optiune;
															}

		
		}
	}
	
}

