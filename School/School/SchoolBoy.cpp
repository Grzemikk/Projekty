#include "SchoolBoy.h"
#include <iostream>
using namespace std;


SchoolBoy::SchoolBoy( string name, int age, string className ) : Pupil( name, age, className ){
	setID( "M_" + getID() );
}

void SchoolBoy::printOutFit() {
	cout << "SchoolBoy outfit: biala / niebieska koszula z krawatem, szkolna marynarka, polbuty, granatowa / czarna spodnie" << endl;
}

