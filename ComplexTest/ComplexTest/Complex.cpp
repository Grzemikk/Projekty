#include"Complex.h"

Complex::Complex( double m_re, double m_im )
{
		setComplex( m_re, m_im );
}

Complex::Complex( const Complex& comp )
{
	*this = comp;
}

Complex::~Complex()
{
	/*delete this;*/
}

Complex& Complex::operator = ( const Complex& comp )
{
		/*return *this = Complex( comp.m_re, comp.m_im );*/
	if( this != &comp )
	{
		m_re = comp.m_re;
		m_im = comp.m_im;
	}
	return *this;
}

bool operator == ( const Complex& comp1, const Complex& comp2 )
{
	if( comp1.m_re != comp2.m_re || comp1.m_im != comp2.m_im )
		return 0;
	else
		return 1;
}

bool operator != ( const Complex& comp1, const Complex& comp2 )
{
	if( comp1.m_re != comp2.m_re || comp1.m_im != comp2.m_im )
		return 1;
	else
		return 0;
}

const Complex operator + ( const Complex& comp1, const Complex& comp2 )
{
	Complex res( comp1 );
	res.m_re += comp2.m_re;
	res.m_im += comp2.m_im;

	return res;
}

const Complex operator + ( const Complex& comp, double x )
{
	Complex res( comp );
	res.m_re += x;

	return res;
}

const Complex operator + ( double x, const Complex& comp )
{
		Complex res( comp );
	res.m_re += x;

	return res;
}

Complex& Complex::operator += ( const Complex& comp )
{
	*this = *this + comp;
	return *this;
}																	

Complex& Complex::operator += ( double x )
{
	*this = *this + x;
	return *this;
}

const Complex operator - ( const Complex& comp1, const Complex& comp2 )
{
	Complex res( comp1 );

	res.m_re -= comp2.m_re;
	res.m_im -= comp2.m_im;

	return res;
}

const Complex operator - ( const Complex& comp, double x )
{
	Complex res( comp );
	res.m_re -= x;

	return res;
}

const Complex operator - ( double x, const Complex& comp )
{
	Complex res( comp );
	res.m_re -= x;

	return res;
}

Complex& Complex::operator -= ( const Complex& comp )
{
	this->m_re -= comp.m_re;
	this->m_im -= comp.m_im;

	return *this;
}

Complex& Complex::operator -= ( double x )
{
		this->m_re -= x;

	return *this;
}

const Complex operator * ( const Complex& comp1, const Complex& comp2 )
{
		Complex res( comp1 );

	res.m_re = comp1.m_re * comp2.m_re - comp1.m_im * comp2.m_im;
	res.m_im = comp1.m_re * comp2.m_im + comp1.m_im * comp2.m_re;

	return res;
}

const Complex operator * ( const Complex& comp, double x )
{
	Complex res( comp );
	res.m_re *= x;
	res.m_im *= x;

	return res;
}

const Complex operator * ( double x, const Complex& comp )
{
	Complex res( comp );
	res.m_re *= x;
	res.m_im *= x;

	return res;
}

Complex& Complex::operator *= ( const Complex& comp )
{
	this->m_re  = this->m_re * comp.m_re - this->m_im * comp.m_im;
	this->m_im  = this->m_re * comp.m_im + this->m_im * comp.m_re;

	return *this;
}

Complex& Complex::operator *= ( double x )
{
		this->m_re *= x;
	this->m_im *= x;

	return *this;
}

const Complex operator / ( const Complex& comp1, const Complex& comp2 )
{
	Complex res( comp1 );
	res.m_re = comp1.m_re * comp2.m_re + comp1.m_im * ( -( comp2.m_im ));
	res.m_im = comp1.m_re * ( -comp2.m_im ) + comp1.m_im * comp2.m_re;
	double div = comp2.m_re * comp2.m_re + comp2.m_im * comp2.m_im;
	res.m_re /= div;
	res.m_im /= div;

	return res;
}

const Complex operator / ( const Complex& comp, double x )
{
	Complex res( comp );
	res.m_re /= x;
	res.m_im /= x;

	return res;
}

Complex& Complex::operator /= ( const Complex& comp )
{
	this->m_re = this->m_re * comp.m_re + this->m_im * ( -( comp.m_im ));
	this->m_im = this->m_re * ( -comp.m_im ) + this->m_im * comp.m_re;
	double div = comp.m_re * comp.m_re + comp.m_im * comp.m_im;
	this->m_re /= div;
	this->m_im /= div;

	return *this;
}

Complex& Complex::operator /= ( double x )
{
	this->m_re /= x;

	return *this;
}

Complex::operator double*( ) const
{
	double* res = new double[2];
	res[0] = this->m_re;
	res[1] = this->m_im;

	return res;
}
	
double Complex::Mod() const
{
	return sqrt( m_re * m_re + m_im * m_im );
}

istream& operator >> ( istream& in, Complex& comp )
{
	in >> comp.m_re >> comp.m_im;
	return in;
}

ostream& operator << ( ostream& out, const Complex& comp )
{
	out << comp.m_re << " + " << comp.m_im << "i";
	return out;
}


