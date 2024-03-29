#include "Vector.h"
#include <iostream>


Vector::Vector( int nDim, double nInitVal ) 
{
	createVec( nDim );
	for( int i = 0; i < nDim; i++ )
		m_pCoords[i] = nInitVal;
}

Vector::Vector( const Vector& v ) {
	m_pCoords = NULL;
	m_nDim = 0;
	*this = v;
}

Vector::~Vector() {
	delete [] m_pCoords; 
}

Vector& Vector::operator = ( const Vector& v ) {
	if( this->GetDim() != v.GetDim() ) {
		if( m_pCoords != NULL )
			delete [] m_pCoords;
		createVec( v.GetDim() );
	}
	copyVec( v );
	return *this;
}

istream& operator >> ( istream& in, Vector& v ) {
	
	for( int i = 0; i < v.GetDim(); i++ )
		in >> v.m_pCoords[ i ];
	return in;
}

ostream& operator << ( ostream& out, const Vector& v ) {
	out << '[';
	for( int i = 0; i < v.GetDim(); i++ ) {
		out << v[i];
		if( i < v.GetDim() - 1 )
			out << ", ";
	}

	out << ']';
	return out;
}


const Vector operator + ( const Vector& v1, const Vector& v2 ) {
	Vector res( v1 );
	return res += v2;
}

const Vector operator + ( const Vector& v1, double x ) {
	Vector res( v1 );
	return res += x;
}

const Vector operator + ( double x, const Vector& v1 ) {
	return v1 + x;
}

Vector& Vector::operator += ( const Vector& v ) {
	if( this->GetDim() != v.GetDim() ) {
		cout << "Error: vectors have different dimensions" << endl;
		return *this;
	}

	for( int i = 0; i < m_nDim; i++ )
		m_pCoords[ i ] += v.m_pCoords[ i ];

	return *this;
}

Vector& Vector::operator += ( double x ) {
	for( int i = 0; i < m_nDim; i++ )
		m_pCoords[i] += x;  // *this[i] += x;
	return *this;
}


const Vector operator - ( const Vector& v1, const Vector& v2 ) // v1 - v2
{
	Vector res( v1 );
	return res -= v2;
}

const Vector operator - ( const Vector& v1, double x )  // v1 - x
{
	Vector res( v1 );
	return res -= x;
}

const Vector operator - ( double x, const Vector& v1 ) // x - v1 
{
	return v1 - x;
}

Vector& Vector::operator -= ( const Vector& v )  // v1 -= v2 
{
	if( this->GetDim() != v.GetDim() ) {
		cout << "Error: vectors have different demensions" << endl;
		return *this;
	 }
	for( int i = 0; i < m_nDim; i++ ) {
		m_pCoords[i] -= v.m_pCoords[i];
	}
	return *this;
}


Vector& Vector::operator -= ( double x ) // v1 -= x
{
	for( int i = 0; i < m_nDim; i++ ) {
		m_pCoords[i] -= x;
	}
	return *this;
}


const Vector operator - ( const Vector& v ) {

	Vector res( v );
	for( int i = 0; i < v.GetDim(); i++ )
		res.m_pCoords[ i ] = -res.m_pCoords[ i ];
	return res;
}

const Vector operator * ( const Vector& v1, double x )  // v1 * x 
{
	Vector res( v1 );
	return res *= x;
}

const Vector operator * ( double x, const Vector& v1 ) // x * v1
{
	return v1 * x;
}

Vector& Vector::operator *= ( double x ) // v1 *= x
{
	for( int i = 0; i < m_nDim; i++ ) {
		m_pCoords[ i ] *= x;
	}

	return *this;
}


// scalar multiplication
double operator * ( const Vector& v1, const Vector& v2 ) // v1 * v2	
{
	if( v1.GetDim() != v2.GetDim() ) {
		cout << "Error: vectors have different dimensions" << endl;
		return 0;
	}
	double res = 0;
	for ( int i = 0; i < v1.GetDim(); i++ ) {
		res += v1[i] * v2[i];
	}
	return res;
}

// indexation
double& Vector::operator [] ( int i ) // v[i] = i; 
{
	if( i < 0 || i >= m_nDim ) {
		cout << "Error: index out of range" << endl;
		return m_pCoords[ 0 ];
	}
	return this->m_pCoords[i];
}

const double& Vector::operator [] ( int ix )const // i = v[i];
{
	if( ix < 0 || ix >= m_nDim ) {
		cout << "Error: index out of range" << endl;
		return m_pCoords[ 0 ];
	}
	return this->m_pCoords[ix];
}


bool operator == ( const Vector& v1, const Vector& v2 ) // v1 == v2
{
	if( v1.GetDim() != v2.GetDim() )
		return false;
	for( int i = 0; i < v1.GetDim(); i++ ) {
		if( v1[i] != v2[i] )
			return false;
	}
	return true;
}


bool operator != ( const Vector& v1, const Vector& v2 ) // v1 != v2
{
	if( v1.GetDim() != v2.GetDim() )
		return true; 
	for( int i = 0; i < v1.GetDim(); i++ ) {
		if( v1[i] != v2[i] )
			return true;
	}
	return false;
}

