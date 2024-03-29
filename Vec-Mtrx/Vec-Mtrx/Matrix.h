#pragma once

#include <iostream>
#include "Vector.h"

using namespace std;

class Matrix
{
	// reprezentacja to tablica wektorow ( dynamiczna)
public: // construction//destruction
	Matrix( int nRows = 2, int nCols = 2, double nInitVal = 0 );
	Matrix ( const Matrix& m );
	virtual ~Matrix();

	int GetColNo() const;
	int GetRowNo() const;

	public: // operators
		Matrix& operator = ( const Matrix& m ); // m1 = m2 = m3

	// input/output
		friend istream& operator >> ( istream& in, Matrix& m );
		friend ostream& operator << ( ostream& out, const Matrix& m );

	// indexation
		Vector& operator [] ( int i );
		const Vector& operator [] ( int ix )const;

	// operator rzutownia na wskaŸnik do wektora 
		operator Vector* ()const;

	// comparison
		friend bool operator == ( const Matrix& m1, const Matrix& m2 );
		friend bool operator != ( const Matrix& m1, const Matrix& m2 );

	// multiplication
		friend const Matrix operator * ( const Matrix& m1, const Matrix& m2 ); // m1 * m2
		friend const Vector operator * ( const Matrix& m1, const Vector& v );  // m1 * v
		friend const Matrix operator * ( const Matrix& m2, const Matrix& m1 ); // m1 * m2
		friend const Vector operator * ( const Vector& v, const Matrix& m1 );  // m1 * v


private:
	void CreateMatrix( int nRows, int nCols );
	void CopyMatrix( const Matrix& m );


private:
	int m_nRows;
	Vector* m_pVec;
};


// ==== INLINE FUNCTIONS ====


inline int Matrix::GetColNo() const {
	return m_pVec[ 0 ].GetDim();
}


inline int Matrix::GetRowNo() const {
	return m_nRows;
}


inline Matrix::operator Vector* ( )const {
		return (Vector*)m_pVec;
}


inline void Matrix::CreateMatrix( int nRows, int nCols ) {
	if( nRows < 2 || nCols < 2 ) {
		cerr << "Matrix::createVec: nRows and nCols must be >= 2" << endl;
		m_nRows = 2;
		m_pVec = NULL;
		return;
	}

	m_pVec = new( nothrow ) Vector[ m_nRows = nRows ];

	if( m_pVec == NULL ) {
		cerr << "Matrix::createMatrix: memory allocation error" << endl;
		m_nRows = 0;
		m_pVec = NULL;
		return;
	}
}


inline void Matrix::CopyMatrix( const Matrix& m ) {
	if( m_pVec->GetDim() != m.GetColNo() || m_nRows != m.m_nRows ) {
		if( m_pVec != NULL )
			delete[] m_pVec;
		CreateMatrix( m.m_nRows, m.GetColNo() );
	}
	memcpy( m_pVec, m, GetRowNo() * sizeof( double ) );
}