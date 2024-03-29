#pragma once
#include"Person.h"
using namespace std;

#define MAXNOTES 7

typedef enum { POLSKI=0, MATEMATYKA = 1, FIZYKA = 2, CHEMIA = 3, INFORMATYKA = 4, NIEMIECKI = 5, ANGIELSKI = 6 } Subjects;


class Pupil : public Person {
public:
	Pupil( string name = " ", int age = 0, string className = " " );
	// Pupil( const Pupil& pupil );
	virtual ~Pupil();

	void setClassName( string className );
	string getClassName() const;
	
	void setID( string ID );
	string getID() const;

	void setNote( Subjects Subject, double note );
	void clearNotes();

	double calcAve();
	double getAve() const;

	void printPupil();
	virtual void printOutFit() {};

protected:
	string m_ID;

private:
	string m_ClassName;
	double m_Ave;
	static int m_baseID;
	double m_Notes[MAXNOTES];
};




inline void Pupil::setClassName( string className ) {
	m_ClassName = className;
}

inline string Pupil::getClassName() const {
	return m_ClassName;
}

inline void Pupil::setID( string ID ) {
	m_ID = ID;
}

inline string Pupil::getID() const {
	return m_ID;
}

inline void Pupil::setNote( Subjects Subject, double note ) {
	if( Subject >= POLSKI && Subject < MAXNOTES  )
		m_Notes[Subject] = note;
}


inline double Pupil::getAve() const {
	return m_Ave;
}