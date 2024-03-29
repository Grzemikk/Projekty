#include"Person.h"


Person::Person( string name, int age ) noexcept
{
	this->m_name = name;
	this->m_age = age;
}


Person::~Person()
{
	delete this;
}

