#pragma once
class Banca
{
private:
	char* tip;
public:
	Banca();
	Banca(char* tip);
	Banca(const Banca& a);
	~Banca();
	char* const getTip()const;
	void setTip(char* t);
	Banca& operator=(const Banca& a);
	char* toString();
	bool compare(Banca& a);
};