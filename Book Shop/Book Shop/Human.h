#pragma once
#ifndef Human_header
#define Human_header
#include"Date.h"
#include<string>
#include<iostream>
#include"Date.h"
using namespace std;
class Human 
{protected:
	string PersonName;
	int Age;
	Date BirthDate;
public:
	Human(Date D,string name, int age);
	Human();
	Human(const Human& H);
	~Human(){}
	friend ostream& operator<<(ostream& os, Human H)
	{
		os << "Name: " << H.PersonName << endl;
		os << "Birth Date: " << H.BirthDate << endl;
		os << "Age: " << H.Age << endl;
		return os;
	}
};
#endif 
