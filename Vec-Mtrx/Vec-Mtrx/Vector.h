#pragma once

#include <iostream>
using namespace std;

#define VERROR 0x00
#define INDEX_OUT_OF_RANGE 0x01
#define ALLOCATION_ERROR 0x02
#define INCOMATIBLE_SIZES 0x03
#define INVALID_VECTOR_SIZE 0x04


class Vector
{
public: //construction/destruction
	Vector( int nDim=2, double nInitVal=0 );
	Vector( const Vector& v );
	virtual ~Vector();

	int GetDim() const;

public: //operators
	Vector& operator = ( const Vector& v ); // v1= v2 = v3

	// input/output
	friend istream& operator >> ( istream& in, Vector& v );
	friend ostream& operator << ( ostream& os, const Vector& v );

	// addition
	friend const Vector operator + ( const Vector& v1, const Vector& v2 ); // v1 + v2
	friend const Vector operator + ( const Vector& v1, double x );  // v1 + x
	friend const Vector operator + ( double x, const Vector& v1 ); // x + v1
	Vector& operator += ( const Vector& v );   // v1 += v2
	Vector& operator += ( double x ); // v1 += x

	// subtraction
	friend const Vector operator - ( const Vector& v1, const Vector& v2 ); // v1 - v2
	friend const Vector operator - ( const Vector& v1, double x );  // v1 - x
	friend const Vector operator - ( double x, const Vector& v1 ); // x - v1
	Vector& operator -= ( const Vector& v );   // v1 -= v2
	Vector& operator -= ( double x ); // v1 -= x

	// unary minus
	friend const Vector operator - ( const Vector& v ); // -v

	// multiplication
	friend const Vector operator * ( const Vector& v1, double x );  // v1 * x
	friend const Vector operator * ( double x, const Vector& v1 ); // x * v1
	Vector& operator *= ( double x ); // v1 *= x

	// scalar multiplication
	friend double operator * ( const Vector& v1, const Vector& v2 ); // v1 * v2	

	// indexation
	double& operator [] ( int i ); // v[i] = i;
	const double& operator [] ( int ix )const; // i = v[i];

	// comparison
	friend bool operator == ( const Vector& v1, const Vector& v2 ); // v1 == v2
	friend bool operator != ( const Vector& v1, const Vector& v2 ); // v1 != v2

	// cast
	operator double* ()const; // (double*)v


private:
	//methods
	void createVec( int nDim );
	void copyVec( const Vector& v );


private:
	int m_nDim; // vecotr dimension
	double* m_pCoords; // vector coordinates
};




// ====== INLINE FUNCTIONS ======


inline int Vector::GetDim() const
{
	return m_nDim;
}


inline Vector::operator double* ( ) const
{
	return m_pCoords;
}

inline void Vector::createVec( int nDim )
{
	if( nDim < 2 ) {
				cerr << "Vector::createVec: dimension must be >= 2" << endl;
				m_nDim = 0; 
				m_pCoords = NULL;
				return;
	}
	m_pCoords = new( nothrow ) double[ m_nDim=nDim ];
	
	if( m_pCoords == NULL ) {
		cerr << "Vector::createVec: memory allocation error" << endl;
		m_nDim = 0;	
		return;
	}

}

inline void Vector::copyVec( const Vector& v )
{
	if( m_nDim != v.m_nDim ) {
		if( m_pCoords != NULL )
			delete[] m_pCoords;
		createVec( v.m_nDim );
	}
	//for( int i = 0; i < m_nDim; i++ )
	//	m_pCoords[i] = v.m_pCoords[i];
	memcpy( m_pCoords, (double*) v, GetDim() * sizeof( double ) );

}

