#pragma once
#include"Pupil.h"
#include<iostream>
#include<string>



class SchoolBoy : public Pupil
{
public:
	SchoolBoy( string name = "", int age=0, string className = "" );
	void printOutFit();
};



