//Wykreować nową aplikację konsolową o nazwie ComplexTest.
//Zdefiniować klasę o nazwie Complex, do reprezentacji liczb zespolonych w postaci( re, im ) o
//składowych m_re – część rzeczywista, m_im – część urojona typu double oraz metody
//klasy :
// konstruktor z parametrami domyślnymi( Re = 0, Im = 0 ),
// konstruktor kopiujący,
// operator podstawienia,
// SetRe( double re ); SetIm( double im ); ustawiające odpowiednio część
//rzeczywistą i urojoną liczby zespolonej.
// SetComplex( double re, double im );
// GetRe(); GetIm(); zwracające odpowiednio część rzeczywistą i jej część urojoną.
// operator dodawania i odejmowania gdzie a + bi = ( a, b ) :
//	( a1, b1 ) ±( a2, b2 ),
//	 mnożenia liczb zespolonych
//	( a1, b1 ) * ( a2, b2 )
//	 Dzielenia liczb zespolonych
//	( a1, b1 ) / ( a2, b2 )
//	 odpowiednie operatory +=, -=, *=, /=
//	 Rzutowanie na typ double
//	 Funkcje Mod()zwracającej wartość modułu liczy zespolonej :
//z  a2  b2
// zdefiniować operatory wejścia( wczytujemy dwie liczby przedzielone białym znakiem ) i wyjścia
//( wypisać w postaci( re, im ) )
//W programie zdefiniować liczbę zespoloną( 4, 3 ) oraz wczytać dowolną drugą.Odpowiednio
//obliczyć sumę, różnicę iloczyn.Obliczyć wartość funkcji Mod() dla otrzymanego wyniku


#pragma once
#include<iostream>

using namespace std;

class Complex
{
public:
	Complex( double m_re=0, double m_im=0 );
	Complex( const Complex& comp );
	virtual ~Complex();

	// Setters
	void setRe( double re );
	void setIm( double im );
	void setComplex( double re, double im );


	// Getters
	double getRe() const;
	double getIm() const;

	Complex& operator = ( const Complex& comp );

	//comparison
	friend bool operator == ( const Complex& comp1, const Complex& comp2 );
	friend bool operator != ( const Complex& comp1, const Complex& comp2 );

	//addition
		friend const Complex operator + ( const Complex& comp1, const Complex& comp2 );	
		friend const Complex operator + ( const Complex& comp, double x );
		friend const Complex operator + ( double x, const Complex& comp );
		Complex& operator += ( const Complex& comp );
		Complex& operator += ( double x );

	//subtraction
		friend const Complex operator - ( const Complex& comp1, const Complex& comp2 );
		friend const Complex operator - ( const Complex& comp, double x );
		friend const Complex operator - ( double x, const Complex& comp );
		Complex& operator -= ( const Complex& comp );
		Complex& operator -= ( double x );

		//multiplikation
		friend const Complex operator * ( const Complex& comp1, const Complex& comp2 );
		friend const Complex operator * ( const Complex& comp, double x );
		friend const Complex operator * ( double x, const Complex& comp );
		Complex& operator *= ( const Complex& comp );
		Complex& operator *= ( double x );

		//division
		friend const Complex operator / ( const Complex& comp1, const Complex& comp2 );
		friend const Complex operator / ( const Complex& comp, double x );
		Complex& operator /= ( const Complex& comp );
		Complex& operator /= ( double x );

		//cast
		operator double*() const;

		//mod
		double Mod() const;


		friend istream& operator >> ( istream& in, Complex& comp );
		friend ostream& operator << ( ostream& out, const Complex& comp );



private:
	double m_re;
	double m_im;
};



//INLINE FUNCTIONS

inline double Complex::getRe() const
{
	return m_re;
}

inline double Complex::getIm() const
{
	return m_im;
}

inline void Complex::setRe( double re )
{
	m_re = re;
}

inline void Complex::setIm( double im )
{
	m_im = im;
}

inline void Complex::setComplex( double re, double im )
{
	m_re = re;
	m_im = im;
}

