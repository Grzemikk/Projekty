#include "Worker.h"



Worker::Worker( string name, int age, double salary, int exp ) : Person( name, age ) {
	setSalary( salary );
	setExperience( exp );
}

Worker::~Worker() {
}


void Worker::setSalary( double salary ) {
	m_salary = salary;
}

double Worker::getSalary() {
	return m_salary;
}

void Worker::setExperience( int exp ) {
	m_experience = exp;
}

int Worker::getExperience() {
	return m_experience;
}


//void Worker::printWorker() {
//	cout << "Name: " << getName() << ",  Age: " << getAge() << ",  Salary: " << getSalary() << ",  Experience: " << getExperience() << endl;
//}
