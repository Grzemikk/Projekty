//Dla kazdego pracownika pamietac : nawisko i imie, wiek oraz pensja brutto, sta¿ pracy w latach.
//Dla pracownika administracyjnego pamietac na jakim stanowisku pracuje( mozliwosci : mlodszy specjalista, specjalista, starszy specjalista )

//MA byc mozliwosc wydrukowania listy pracownikow( nazwisko i imie, stanowisko - jesli nauczyciel wydrukowac jaki przedmiot uczy )
//oraz obliczenia pensji( na wydruku pensja brutto, podatek i pensja netto ) przy czym :
//-dla admina podatek oblicza sie( ( kwota brutto - koszty uzysku ) * 18 % podatku - kwota wolna ),
//( kwota netto to brutto minus obliczony podatek )
//Jesli podatek wychodzi ujemny to go wyzerowac
//kwoty ponizej

#pragma once 
#include "Worker.h"

enum POSITION { Mlodszy_Specjalista, Specjalista, Starszy_Specjalista };
const string pos[] = { "Mlodszy Specjalista", "Specjalista", "Starszy Specjalista" };


class Admin : public Worker {
public: 
	Admin( string name="", int age=0, double salary=0, int experience=0, POSITION position = Mlodszy_Specjalista );

	void setPosition( POSITION position );
	string getPosition();
	double calcSalary();

	void printWorker();

private:
	string a_position;
};


inline void Admin::setPosition( POSITION position ) {
	a_position = pos[position];
}

inline string Admin::getPosition() {
	return a_position;
}

