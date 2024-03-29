#include <iostream>
using namespace std;
#include "Vector.h"
#include "Matrix.h"

int main()
{

  Vector v1( 2 );
  Vector v2( 4, 1 );
  Vector v3( 4, 2 );
  Vector v4( v2 );

  cout << "v1= " << v1 << endl;

  cout << "Podaj dwie wspolrzedne wektora : ";
  cin >> v1;
  cout << "v1= " << v1 << endl;

  cout << "v2= " << v2 << endl;
  cout << "v3= " << v3 << endl;
  cout << "v4= " << v4 << endl;
  cout << "v3 + v4 = " << v3 + v4 << endl;
  cout << "il skalarne v2 i v3 = " << v2 * v3 << endl;
  cout << "-2*v4 = " << -2*v4 << endl;
  cout << " 2 + v1 = " << 2 + v1 << endl;

  double* p = (double*) v3;
  cout << "rzutowanie na p -- p[1] " << *( p + 1 ) << "\n\n";
  
  Vector v = v2 + v3;
  cout << "v = v2 + v3 = " << v << endl;

  v3[0] += 3;
  cout << "v3[ 0 ] += 3 = " << v3 << endl;

  v3[1] = 4;
  cout << "v3[ 1 ] = 4 = " << v3 << endl;

  v3[1] = v3[ 2 ] + v3[ 0 ];
  cout << "v3[ 1 ] = v3[ 2 ] + v3[ 0 ] = " << v3 << endl;

  cout << "-v1 = " << -v1 << endl;
  cout << "v3 - 1 = " << v3 - 1 << endl;
  cout << "v3 - v2 = " << v3 - v2 << endl;

  if( v2 != v3 )
		cout << "v2 != v3\n";
	else
		cout << "v2 == v3\n"; 

  cout << "\n\n=============================\n\n"<< "Test klasy Matrix\n\n";

  Matrix m1;
  Matrix m2( 2, 3 );
  Matrix m3( 2, 3, 1 );

  cout << "m1= " << m1 << endl;
  cout << "m2= " << m2 << endl;
  cout << "m3= " << m3 << endl;

  Vector* pVec = (Vector*) m3;
  cout << "pVec[1] = " << pVec[ 1 ] << endl << endl; 
  m1 = m2;
  cout << "m1=m2= " << m1 << endl;
  cout << "m1 == m2 : " << (( m1 == m2 )?1:0) << endl;
  m3[ 0 ][ 1 ] = -2;
  m3[ 1 ][ 1 ] = -2;
  m3[ 2 ][ 1 ] = -2;
  cout << "m3= " << m3 << endl;

  Vector v5( 3, 4 );
  cout << "m1*v5= " << m1 * v5 << endl;


  system( "pause" );

  return 0;
}
