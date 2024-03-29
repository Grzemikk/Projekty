#pragma once
#include<iostream>
using namespace std;

//? Poni�ej opisano co ma zawiera� ta klasa
//? Po pierwsze klasa musi by� zadeklarowana jako : class TESTDLL_API Date aby by�a
//eksportowana do biblioteki tego DLL - a( czyli ka�da metoda tej klasy z wyj�tkiem np.
//operator�w we / wy bo musza by� friend - ami wi�c s� funkcjami globalnymi ).To samo
//dotyczy metod zaprzyja�nionych a wi�c funkcji globalnych � opisano w wymaganiach
//klasy.
//? Wymagania - je�li trzeba implementowa� klas�.Jak nie to sprawdzi� r�nice i
//zmodyfikowa� wcze�niej implementowan� klas� Time � dot.firend - �w):
//? Ca�kowite sk�adowe prywatne m_nDay, m_nMont, m_nYear.
//? Konstruktor z parametrami domy�lnymi( godzina 0:0 : 0 ) oraz drugi konstruktor kopiuj�cy
//? Dla implementacji kopiuj�cego nale�y zdefiniowa�( cho� tu nie jest to konieczne bo
//kompilator sam dostarcza operator podstawienia ale gdyby by�y sk�adowe dynamiczne to
//niezb�dne ) operator podstawienia.Konstruktor kopiuj�cy ma wywo�a� operator
//podstawienia!!!
//? Gettery i settery( implementowane jako inline w pliku nag��wkowym nie w klasie ).
//Gettery oczywi�cie nie zmieniaj� obiektu klasy wi�c const.
//? Dla u�atwienia nie trzeba sprawdza� poprawno�ci godzin minut i sekund ale u�ywa�
//metod set aby tylko w jednym miejscu ewentualnie dodawa� tak� walidacj�.Dlatego
//metoda setDate( int, int, int ); musi wywo�a� poszczeg�lne set - ery.
//Konstruktor z parametrami wywo�uje setTime() oraz operator podstawienia te� wywo�uje
//t� funkcj�.
//? Operatory we / wy jako friendy.
//? Operatory we / wy.Poniewa� to funkcje globalne a musz� by� eksportowane to musi by�
//u�yta sta�a preprocesora TESTDLL_API przed nag��wkiem( po frined )


class TESTDLL_API Date {
	public:
		Date( int newDay = 1, int newMonth = 1, int newYear = 1999 );
		Date( const Date& d );

		// Date& operator = ( const Date& d );

		void setDay( int newDay );
		void setMonth( int newMonth );
		void setYear( int newYear );
		void setDate( int newDay, int newMonth, int newYear );

		int getDay()const;
		int getMonth()const;
		int getYear()const;


		friend TESTDLL_API ostream& operator << ( ostream& out, const Date& d );
		friend TESTDLL_API istream& operator >> ( istream& in, Date& d );


	private:
		int m_nDay;
		int m_nMont;
		int m_nYear;
};



// INLINE FUNCTIONS

inline void Date::setDate( int newDay, int newMonth, int newYear ) {
	setDay( newDay );
	setMonth( newMonth );
	setYear( newYear );
}

inline void Date::setDay( int newDay ) {
	m_nDay = newDay;
}

inline void Date::setMonth( int newMonth ) {
	m_nMont = newMonth;
}

inline void Date::setYear( int newYear ) {
	m_nYear = newYear;
}

inline int Date::getDay()const {
	return m_nDay;
}

inline int Date::getMonth()const {
	return m_nMont;
}

inline int Date::getYear()const {
	return m_nYear;
}

