#pragma once
class Banca
{
private:
	int ziua;
	int suma;
	char* tip;
	char* descriere;
public:
	Banca();
	Banca(int ziua, char* tip, int suma, char* descriere);
	Banca(const Banca& a);
	~Banca();
	int getZiua();
	char* const getTip()const;
	int getSuma();
	char* const getDescriere() const;
	void setZiua(int n);
	void setTip(char* t);
	void setSuma(int s);
	void setDescriere(char* d);
	Banca& operator=(const Banca& a);
	char* toString();
	bool compare(Banca& a);
};

