#pragma once
#ifndef Date_header
#define Date_header
#include<iostream>
using namespace std;
class Date 
{
	int Day;
	int Month;
	int Year;
public:
	Date(int D, int M, int Y );
	Date(int d);
	Date();
	Date(const Date& D);
	~Date(){}
	int getDay();
	int getMonth();
	int getYear();
	friend ostream& operator<<(ostream& os, const Date& D)
	{
		os << D.Day << "/" << D.Month << "/" << D.Year;
		return os;
	}
	friend istream& operator>>(istream& is, Date& D)
	{
		cout << "Enter the Date: " << endl << "Day: ";
		is >> D.Day;
		cout << "Month: ";
		is >> D.Month;
		cout << "Year: ";
		is >> D.Year;
		return is;
	}
	
};
string function(void);
#endif
