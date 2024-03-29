#include "Matrix.h"
#include <iostream>
using namespace std;



Matrix::Matrix( int nRows, int nCols, double nInitVal ) {
	CreateMatrix( nRows, nCols );
	for( int i = 0; i < nRows; i++ )
			m_pVec[ i ] = Vector( nCols, nInitVal );
}


Matrix::Matrix( const Matrix& m ) {
	m_pVec = NULL;
	m_nRows = 0;
	*this = m;
}

Matrix::~Matrix() {
	delete[] m_pVec;
}

Matrix& Matrix::operator = ( const Matrix& m ) {
	if( this->GetColNo() != m.GetColNo() || this->m_nRows != m.m_nRows ) {
		if( this->m_pVec != NULL )
			delete[] m_pVec;
		CreateMatrix( m.m_nRows, m.GetColNo() );
	}
	CopyMatrix( m );
	return *this;
}


istream& operator >> ( istream& in, Matrix& m ) {
	for( int i = 0; i < m.GetRowNo(); i++ ) {
			in >> m.m_pVec[i];
	}
	return in;
}


ostream& operator << ( ostream& out, const Matrix& m )
{
	for( int i = 0; i < m.GetRowNo(); i++ )
		out << m.m_pVec[ i ] << endl << "    ";
	return out;
}


Vector& Matrix::operator [] ( int i ) {
	if( i < 0 || i >= m_nRows ) {
		cerr << "Error:Operator out of range" << endl;
		return m_pVec[ 0 ];
	}
	return this->m_pVec[ i ];
}


const Vector& Matrix::operator [] ( int ix )const {
	if( ix < 0 || ix >= m_nRows ) {
		cerr << "Error:Operator out of range" << endl;
		return m_pVec[ 0 ];
	}
	return this->m_pVec[ ix ];
}



bool operator == ( const Matrix& m1, const Matrix& m2 ) {
	if( m1.GetColNo() != m2.GetColNo() || m1.GetRowNo() != m2.GetRowNo() )
		return false;
	for( int i = 0; i < m1.GetRowNo(); i++ ) {
			if( m1.m_pVec[ i ] != m2.m_pVec[ i ] )
				return false;
	}
	return true;
}


bool operator != ( const Matrix& m1, const Matrix& m2 ) {
	if( m1.GetColNo() != m2.GetColNo() || m1.GetRowNo() != m2.GetRowNo() )
		return true;
	for( int i = 0; i < m1.GetRowNo(); i++ ) {
			if( m1.m_pVec[ i ] != m2.m_pVec[ i ] )
				return true;
	}
	return false;
}


const Matrix operator * ( const Matrix& m1, const Matrix& m2 ) // m1 * m2 
{
	if( m1.GetColNo() != m2.GetRowNo() ) {
		cerr << "Error: incompatible dimensions" << endl;
		return 0;
	}
	Matrix res( m1.GetRowNo(), m2.GetColNo() );
	for( int i = 0; i < m1.GetRowNo(); i++ ) {
		for( int j = 0; j < m2.GetColNo(); j++ ) {
			for( int k = 0; k < m1.GetColNo(); k++ ) {
				res[ i ][ j ] += m1[ i ][ k ] * m2[ k ][ j ];
			}
		}
	}
	return res;
}


const Vector operator * ( const Matrix& m1, const Vector& v )  // m1 * v
{
	if( m1.GetColNo() != v.GetDim() ) {
		cerr << "Error: incompatible dimensions" << endl;
		return 0;
	}
	Vector res( m1.GetRowNo() );
	for( int i = 0; i < m1.GetRowNo(); i++ ) {
			res[ i ] = m1[ i ] * v;
	}
	return res;
}


const Vector operator * ( const Vector& v, const Matrix& m1 )  // m1 * v
{
	if( m1.GetColNo() != v.GetDim() ) {
		cerr << "Error: incompatible dimensions" << endl;
		return 0;
	}

	Vector res( m1.GetRowNo() );

	for( int i = 0; i < m1.GetRowNo(); i++ ) {
			res[ i ] = m1[ i ] * v;
	}
	return res;
}



