#pragma once
// Projket systemu dla prywatnej szkoly
//W szkole pracuja nauczyciele oraz pracownicy administracji.Do szkoly chodzi mlodziez roznych klas, przy czym kazdy jest identyfikowany oprocz nazwiska i imienia rowniez ide ID ma byc dotopny z klasy opisujacej dowolnego ucznia( Pupil ) - aby mozna go drukowac majac tylko uczniow.Dodatkowo, ma byc tworzony w kazdej z klas reprezentujanej acznia( chlopak - SchoolBoy )
//oraz uczennice( dziewczyna - SchoolGirl ) przedrostek ID i dodawana liczba pieciocyfrowa.przedrostek ID F dla dziewczyn( F_12345 )
//- przedrostek ID M dla chlopcow( M_00100 )
//Dia kazdej osoby nalezy pamietac
//wiek( klasa bazowa Ferson )
//Dla kazdego ucznia( bez wzgledu czy uczen czy uczennica ) - pamietany oceny z przedni.bow:
//POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI( typ wylicznelowy ) PUPILE
//- mozemy drukowac ubior, ( tu nie moze byc implementacji bo zalezy czy dziewczyna czy chlopak )
//nazwa klasy( np 2a, lub 3b )
//mozliwosc ustawiania ocen dla danego przedmiotu,
//atorem ID
//- mozliwose obliczanai sredniej( jak nie ma oceny z danego przemdiotu to pamitacac 0 - mozna definovac stala tablice ).zliwosc wyczyszczenia wszystkich ocen.Oceny polowkowe tez moga byc oraz zakres ocen od 2.5
//- drukowaæ w zestawieniu uczniow : ID, imie, nazwisko, srednia ocen, klasa, ilose lat, ubior( abatrakcyjna )
//ID ustawiany na podstawie skladovej statycznej ktorej poczatkowa wartose jest 10000 ( konser Pupil )

#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person( string name = " ", int age = 0 ) noexcept;
	virtual ~Person();
	Person & operator=( const Person & p ) = default;

	void setName( string name );
	void setAge( int age );
	void setPerson( string name, int age );

	string getName();
	int getAge();

private:
	string m_name;
	int m_age;
};




inline void Person::setName(string name) {
	this->m_name = name;
}

inline void Person::setAge(int age) {
	this->m_age = age;
}

inline void Person::setPerson( string name, int age ) {
	setName( name );
	setAge( age );
}

inline string Person::getName() {
	return this->m_name;
}

inline int Person::getAge() {
	return this->m_age;
}