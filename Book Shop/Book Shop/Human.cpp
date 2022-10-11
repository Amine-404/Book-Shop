#include "Human.h"
#include"Date.h"
Human::Human(Date D, string name="", int age=0): PersonName(name), Age(age),BirthDate(D) {}
Human::Human()
{
	Date* D = new Date(0, 0, 0);
	BirthDate = *D;
	PersonName = "";
	Age = 0;
}
Human::Human(const Human& H)
{
	PersonName = H.PersonName;
	Age = H.Age;
	BirthDate = H.BirthDate;
}
