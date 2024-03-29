//W programie zdefiniować liczbę zespoloną( 4, 3 ) oraz wczytać dowolną drugą.Odpowiednio
//obliczyć sumę, różnicę iloczyn.Obliczyć wartość funkcji Mod() dla otrzymanego wyniku

#include <iostream>
#include "Complex.h"

int main()
{
	Complex comp1( 4, 3 );
	Complex comp2;

	cout << "Podaj liczbe zespolona: ";
	cin >> comp2;

	cout << "Suma: " << comp1 + comp2 << endl;
	cout << "Roznica: " << comp1 - comp2 << endl;
	cout << "Iloczyn: " << comp1 * comp2 << endl;
	cout << "Iloraz: " << comp1 / comp2 << endl;
	cout << "Modul: " << comp1.Mod() << endl;

	system( "pause" );
	return 0;	
  
}
