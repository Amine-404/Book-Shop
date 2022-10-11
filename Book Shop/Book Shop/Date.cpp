#include"Date.h"
#include<string>
Date::Date(int D = 0, int M = 0, int Y = 0) :Day(D), Month(M), Year(Y) {}
Date:: Date():Day(0), Month(0), Year(0) {}
Date::Date(const Date& D)
{ 
	Day = D.Day; Month = D.Month; Year = D.Year;
}
Date::Date(int d):Day(d),Month(d),Year(d){}
int Date::getDay()
{
	return Day;
}
int Date::getMonth()
{
	return Month;
}
int Date::getYear()
{
	return Year;
}
string function(void)
{
	string s;
	cin.clear();
	getline(cin,s);
	return s;
}