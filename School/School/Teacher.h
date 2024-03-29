#pragma once 
#include"Worker.h"

//W szkole pracuj¹ nauczyciele( Teacher ) oraz pracownicy administarcyjni( Admin )
//Dla kazdego pracownika pamietac : nawisko i imie, wiek oraz pensja brutto, sta¿ pracy w latach.
//Dla pracownika administracyjnego pamietac na jakim stanowisku pracuje( mozliwosci : mlodszy specjalista, specjalista, starszy specjalista )
//Dla nauczyciela pamietac jakiego przedmiotu uczy i czy jest wychowawca a jesli tak to jakiej klasy( np "2b" )
//
//MA byc mozliwosc wydrukowania listy pracownikow( nazwisko i imie, stanowisko - jesli nauczyciel wydrukowac jaki przedmiot uczy )
//oraz obliczenia pensji( na wydruku pensja brutto, podatek i pensja netto ) przy czym :
//- dla nauczycieli od 80 % pensji naliczac 50 % koszty uzysku a od reszty tak jak dla admina przy czym uwzglednic w kwocie brutto
//wysluge lat( w zakresie od 5 do 20 lat pracy doliczac do kwoty brutto odpowiednio od 5 do 20 % kwoty brutto ) oraz jesli jest wychowawca
//dodac dodatek 400 zl
//np dla 10 stazu pracy od 5000 brutto doliczyc 500 czyli lacznie jest 5500 brutto( bez wychowacy ).
//Powyzej 20 lat stazowe sie nie zwieksza)
//
//- koszty uzykania przychodu : 111.25 / miesiac
//- kwota wolna 556.02
//
//- w programie glownym stowrzyc 6 - miu nauczycieli oraz 3 pracownikow administr.
//Napisac funkcje majaca na wejsciu tablice wskaznikow do pracownikow i drukujaca liste pracownikow



class Teacher : public Worker {
public:
	Teacher( string name="", int age=0, double salary=0, int exp=0, string subject = "", bool isTutor = false, string clas = "" );
	
	void setSubject( string subject );
	void setIfTut( bool isTutor );
	void setClass( string clas );
	string getSubject();
	bool getIfTut();
	string getClass();

	double calcSalary();

	void printWorker();

private:
	string t_subject;
	bool t_isTutor;
	string t_class;
};


inline void Teacher::setSubject( string subject ) {
	t_subject = subject;
}


inline void Teacher::setIfTut( bool isTutor ) {
	t_isTutor = isTutor;
}


inline void Teacher::setClass( string clas ) {
	t_class = clas;
}

inline string Teacher::getSubject() {
	return t_subject;
}

inline bool Teacher::getIfTut() {
	return t_isTutor;
}

inline string Teacher::getClass() {
	return t_class;
}