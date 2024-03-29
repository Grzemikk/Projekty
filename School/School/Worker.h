#pragma once
#include "Person.h"

using namespace std;
//Dla kazdego pracownika pamietac : nawisko i imie, wiek oraz pensja brutto, sta¿ pracy w latach.
//MA byc mozliwosc wydrukowania listy pracownikow( nazwisko i imie, stanowisko - jesli nauczyciel wydrukowac jaki przedmiot uczy )


class Worker : public Person
{
public:
	Worker( string name="", int age = 0, double salary = 0, int exp = 0);
	virtual ~Worker();

	void setSalary( double salary );
	void setExperience( int experience );
	double getSalary();
	int getExperience();

	virtual void printWorker() = 0;

private:
	double m_salary;
	int m_experience;
};

