#pragma once
#include<iostream>
using namespace std;

//? Poni¿ej opisano co ma zawieraæ ta klasa
//? Po pierwsze klasa musi byæ zadeklarowana jako : class TESTDLL_API Date aby by³a
//eksportowana do biblioteki tego DLL - a( czyli ka¿da metoda tej klasy z wyj¹tkiem np.
//operatorów we / wy bo musza byæ friend - ami wiêc s¹ funkcjami globalnymi ).To samo
//dotyczy metod zaprzyjaŸnionych a wiêc funkcji globalnych – opisano w wymaganiach
//klasy.
//? Wymagania - jeœli trzeba implementowaæ klasê.Jak nie to sprawdziæ ró¿nice i
//zmodyfikowaæ wczeœniej implementowan¹ klasê Time – dot.firend - ów):
//? Ca³kowite sk³adowe prywatne m_nDay, m_nMont, m_nYear.
//? Konstruktor z parametrami domyœlnymi( godzina 0:0 : 0 ) oraz drugi konstruktor kopiuj¹cy
//? Dla implementacji kopiuj¹cego nale¿y zdefiniowaæ( choæ tu nie jest to konieczne bo
//kompilator sam dostarcza operator podstawienia ale gdyby by³y sk³adowe dynamiczne to
//niezbêdne ) operator podstawienia.Konstruktor kopiuj¹cy ma wywo³aæ operator
//podstawienia!!!
//? Gettery i settery( implementowane jako inline w pliku nag³ówkowym nie w klasie ).
//Gettery oczywiœcie nie zmieniaj¹ obiektu klasy wiêc const.
//? Dla u³atwienia nie trzeba sprawdzaæ poprawnoœci godzin minut i sekund ale u¿ywaæ
//metod set aby tylko w jednym miejscu ewentualnie dodawaæ tak¹ walidacjê.Dlatego
//metoda setDate( int, int, int ); musi wywo³aæ poszczególne set - ery.
//Konstruktor z parametrami wywo³uje setTime() oraz operator podstawienia te¿ wywo³uje
//t¹ funkcjê.
//? Operatory we / wy jako friendy.
//? Operatory we / wy.Poniewa¿ to funkcje globalne a musz¹ byæ eksportowane to musi byæ
//u¿yta sta³a preprocesora TESTDLL_API przed nag³ówkiem( po frined )


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

