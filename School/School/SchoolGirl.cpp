#include "SchoolGirl.h"


SchoolGirl::SchoolGirl( string name, int age, string className ) : Pupil( name, age, className ) {
	setID( "F_" + getID() );
}


void SchoolGirl::printOutFit() {
	cout << "SchoolGirl outfit: biala bluzka z krawatem, szkolna marynarka, granatowa / czarna spodniczka, plaskie obuwie" << endl;
}