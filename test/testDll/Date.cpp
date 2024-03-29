#include "pch.h"
#include "testDll.h"
#include"Date.h"
#include<iostream>


using namespace std;


Date::Date( int newDay, int newMonth, int newYear )
{
	setDate( newDay, newMonth, newYear );
}

Date::Date( const Date& d ) {
	*this = d;
}

/*
Date& Date::operator = ( const Date& d ) {
	if( this != &d ) {
		m_nDay = d.m_nDay;
		m_nMont = d.m_nMont;
		m_nYear = d.m_nYear;
	}

	return *this;
}
*/


ostream& operator << ( ostream& out, const Date& d ) {

	out << d.m_nDay << "/" << d.m_nMont << "/" << d.m_nYear;

	return out;
}


istream& operator >> ( istream& in, Date& d ) {
	// hh:mm:ss
	char c; // do czytania separatora
	int  x;
	cin >> x >> c;
	d.setDay( x );
	cin >> x >> c;
	d.setMonth( x );
	cin >> x;
	d.setYear( x );

	return in;
}
