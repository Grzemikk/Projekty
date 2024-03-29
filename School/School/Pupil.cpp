#include"Pupil.h"


static int ID = 10000;

Pupil::Pupil( string name, int age, string className ) : Person( name, age ) {
		setClassName( className );
		clearNotes();
		setID( to_string( ID++ ) );
}


Pupil::~Pupil() {
}



void Pupil::printPupil() {
	cout << getID() << "  " << getName() << "  " << getClassName() << "  " << getAge() << endl;
	cout << "Pupil average mark: " << getAve() << endl;
	cout << '\t';
	printOutFit();
}


void Pupil::clearNotes() {
	memset( m_Notes, 0, MAXNOTES * sizeof( double ) );
	m_Ave = 0;
}


double Pupil::calcAve() {
	double sum = 0;
	int noteNo = 0;
	for( int sub = POLSKI; sub < MAXNOTES; sub++ ) {
		if( m_Notes[ sub ] > 1 ) {
			sum += m_Notes[ sub ];
			noteNo++;
		}
	}
	m_Ave = ( noteNo ) ? sum / MAXNOTES : 0;
	return m_Ave;
}
