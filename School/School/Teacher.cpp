#include "Teacher.h"


Teacher::Teacher( string name, int age, double salary, int exp, string subject, bool isTutor, string clas ) : Worker( name, age, salary, exp ) {
	setSubject( subject );
	setIfTut( isTutor );
	setClass( clas );
}


//- dla nauczycieli od 80 % pensji naliczac 50 % koszty uzysku a od reszty tak jak dla admina przy czym uwzglednic w kwocie brutto
//wysluge lat( w zakresie od 5 do 20 lat pracy doliczac do kwoty brutto odpowiednio od 5 do 20 % kwoty brutto ) oraz jesli jest wychowawca
//dodac dodatek 400 zl
//np dla 10 stazu pracy od 5000 brutto doliczyc 500 czyli lacznie jest 5500 brutto( bez wychowacy ).
//Powyzej 20 lat stazowe sie nie zwieksza)
//
//- koszty uzykania przychodu : 111.25 / miesiac
//- kwota wolna 556.02
//
double Teacher::calcSalary() {
	double salary = getSalary();
	if( 5 <= getExperience() <= 20 ) salary *= ( 1 + getExperience() / 100 );
	if( getIfTut() ) salary += 400;

	double podatek = (( getSalary() - (111.25/2) ) * 0.18 - 556.02) * 0.8;
	podatek += ( ( getSalary() - ( 111.25 / 2 ) ) * 0.18 - 556.02 ) * 0.2;
	if( podatek < 0 ) podatek = 0;
	double netto = getSalary() - podatek;

	return netto;
}


void Teacher::printWorker() {
	cout << "Name: " << getName() << "\t Age: " << getAge() << "\t Experience: " << getExperience() << endl;
	if( getIfTut() ) cout << "Tutor: " << getClass() << endl;
	cout << "Salary-brutto: " << getSalary() << "\t Netto: " << calcSalary() << "\t Tax: " << getSalary() - calcSalary() << endl;
}
