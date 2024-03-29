#include "Admin.h"




Admin::Admin( string name, int age, double salary, int experience, POSITION position ) : Worker( name, age, salary, experience ) {
	setPosition( position );
}


//oraz obliczenia pensji( na wydruku pensja brutto, podatek i pensja netto ) przy czym :
//-dla admina podatek oblicza sie( ( kwota brutto - koszty uzysku ) * 18 % podatku - kwota wolna ),
//( kwota netto to brutto minus obliczony podatek )
//Jesli podatek wychodzi ujemny to go wyzerowac
//kwoty ponizej
//- koszty uzykania przychodu : 111.25 / miesiac
//- kwota wolna 556.02
double Admin::calcSalary() {
	double podatek = ( getSalary() - 111.25 ) * 0.18 - 556.02;
	if( podatek < 0 ) podatek = 0;
	double netto = getSalary() - podatek;
	
	return netto;
}

void Admin::printWorker() {
	cout << "Name: " << getName() << "\t Age: " << getAge() << "\t Experience: " << getExperience() << "\t Position: " << getPosition() << endl; 
	cout << " Salary-brutto: " << getSalary() << "\t Netto: " << calcSalary() << "\t Tax: " << getSalary() - calcSalary()  << endl;
}