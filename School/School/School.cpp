#include <iostream>
using namespace std;

#define MAXPUPIL 9

#include"Person.h"
#include"Pupil.h"
#include"SchoolGirl.h"
#include"Teacher.h"
#include"Admin.h"
#include"SchoolBoy.h"
#include"Worker.h"

//- w programie glownym stowrzyc 6 - miu nauczycieli oraz 3 pracownikow administr.
//Napisac funkcje majaca na wejsciu tablice wskaznikow do pracownikow i drukujaca liste pracownikow


void printWorkers( Worker** workers, int WorkerNo );
void printPupils( Pupil** pupils, int PupilNo );
void sortPupils( Pupil** pupils, int PupilNo );


int main()
{
	

	Pupil* pupils[ MAXPUPIL ] = { NULL };
	Pupil* v = NULL;
	pupils[0] = v = new SchoolGirl( "Wojcik Anna", 7, "1a" );
	v->setNote( POLSKI, 5 );
	v->setNote( MATEMATYKA, 4 );
	v->setNote( FIZYKA, 3 );
	v->setNote( CHEMIA, 4 );
	v->setNote( INFORMATYKA, 5 );
	v->setNote( NIEMIECKI, 4 );
	v->setNote( ANGIELSKI, 3 );

	pupils[1] = v = new SchoolGirl( "Nowak Katarzyna", 8, "1b" );
	v->setNote( POLSKI, 3 );
	v->setNote( MATEMATYKA, 4 );
	v->setNote( FIZYKA, 4 );
	v->setNote( CHEMIA, 4 );
	v->setNote( INFORMATYKA, 3 );
	v->setNote( NIEMIECKI, 4 );
	v->setNote( ANGIELSKI, 5 );

	pupils[2] = v = new SchoolGirl( "Kowalczyk Marta", 7, "1a" );
	v->setNote( POLSKI, 5 );
	v->setNote( MATEMATYKA, 4 );
	v->setNote( FIZYKA, 3 );
	v->setNote( CHEMIA, 4 );
	v->setNote( INFORMATYKA, 5 );
	v->setNote( NIEMIECKI, 4 );
	v->setNote( ANGIELSKI, 3 );

	pupils[3] = v = new SchoolGirl( "Dabrowska Agnieszka", 8, "1b" );
	v->setNote( POLSKI, 3 );
	v->setNote( MATEMATYKA, 4 );
	v->setNote( FIZYKA, 4 );
	v->setNote( CHEMIA, 4 );
	v->setNote( INFORMATYKA, 3 );
	v->setNote( NIEMIECKI, 4 );
	v->setNote( ANGIELSKI, 5 );

	pupils[4] = v = new SchoolBoy( "Szymanski Mateusz", 8, "2a" );
	v->setNote( POLSKI, 3 );
	v->setNote( MATEMATYKA, 4 );
	v->setNote( FIZYKA, 4 );
	v->setNote( CHEMIA, 4 );
	v->setNote( INFORMATYKA, 3 );
	v->setNote( NIEMIECKI, 4 );
	v->setNote( ANGIELSKI, 5 );

	pupils[5] = v = new SchoolBoy( "Janusz Tracz", 9, "2b" );
	v->setNote( POLSKI, 3 );
	v->setNote( MATEMATYKA, 4 );
	v->setNote( FIZYKA, 4 );
	v->setNote( CHEMIA, 4 );
	v->setNote( INFORMATYKA, 3 );
	v->setNote( NIEMIECKI, 4 );
	v->setNote( ANGIELSKI, 5 );

	pupils[6] = v = new SchoolBoy( "Wisniewski Pawel", 8, "2a" );
	v->setNote( POLSKI, 3 );
	v->setNote( MATEMATYKA, 4 );
	v->setNote( FIZYKA, 4 );
	v->setNote( CHEMIA, 4 );
	v->setNote( INFORMATYKA, 3 );
	v->setNote( NIEMIECKI, 4 );
	v->setNote( ANGIELSKI, 5 );

	pupils[7] = v = new SchoolBoy( "Kowalski Michal", 9, "2b" );
	v->setNote( POLSKI, 3 );
	v->setNote( MATEMATYKA, 4 );
	v->setNote( FIZYKA, 4 );
	v->setNote( CHEMIA, 4 );
	v->setNote( INFORMATYKA, 3 );
	v->setNote( NIEMIECKI, 4 );
	v->setNote( ANGIELSKI, 5 );

	pupils[8] = v = new SchoolBoy( "Nowak Adam", 9, "2b" );
	v->setNote( POLSKI, 3 );
	v->setNote( MATEMATYKA, 4 );
	v->setNote( FIZYKA, 4 );
	v->setNote( CHEMIA, 4 );
	v->setNote( INFORMATYKA, 3 );
	v->setNote( NIEMIECKI, 4 );
	v->setNote( ANGIELSKI, 5 );

	for( int i = 0; i < MAXPUPIL; i++ ) {
		pupils[ i ]->calcAve();
	}


	sortPupils( pupils, MAXPUPIL );

	cout << "========== DRUKOWANIE LISTY UCZNIOW =========\n\n";

	printPupils( pupils, MAXPUPIL );


Teacher* t1 = new Teacher("Jan Kowalski", 40, 5000.00, 10, "MATEMATYKA", true, "1a" );
Teacher* t2 = new Teacher("Anna Nowak", 35, 4000.00, 5, "POLSKI", true, "1b" );
Teacher* t3 = new Teacher("Janina Kowalska", 45, 6000.00, 15, "HISTORIA", true, "2a" );
Teacher* t4 = new Teacher("Janusz Nowak", 50, 7000.00, 20, "FIZYKA", true, "2b" );
Teacher* t5 = new Teacher("Janusz Kowalski", 40, 5000.00, 10, "CHEMIA", true, "3a" );
Teacher* t6 = new Teacher("Anna Kowalska", 35, 4000.00, 5, "INFORMATYKA", true, "3b" );

Admin* a1 = new Admin("Mikolaj Grzesik", 40, 10000.00, 10, Starszy_Specjalista );
Admin* a2 = new Admin("Mateusz Podmokły", 35, 6000.00, 5, Mlodszy_Specjalista );
Admin* a3 = new Admin("Daniel Salawa", 45, 8000.00, 15, Specjalista );

Worker* workers[9] = { t1, t2, t3, t4, t5, t6, a1, a2, a3 };


cout << "\n\n========== DRUKOWANIE LISTY PRACOWNIKOW =========\n\n";
printWorkers(workers, 9);


	return 0;
}

//Napisac funkcje majaca na wejsciu tablice wskaznikow do pracownikow i drukujaca liste pracownikow
void printWorkers( Worker** workers, int  WorkerNo )
{
	for (int i = 0; i < WorkerNo; i++)
	{
		workers[i]->printWorker();
		cout << endl << endl;
	}
}


void printPupils( Pupil** pupils, int PupilNo ) {
	for( int i = 0; i < PupilNo; i++ ) {
		pupils[ i ]->printPupil();
		cout << endl << endl;
	}
}


void sortPupils( Pupil** pupils, int PupilNo ) {
	for( int i = 1; i < PupilNo; i++ ) {
		int j = i - 1;
		Pupil* v = pupils[ i ];
		while( j >= 0 && v->getName() < pupils[ j ]->getName() ) {
			pupils[ j + 1 ] = pupils[ j-- ];
			pupils[ j + 1 ] = v;
		}
	}
}