 #pragma once
#ifndef Employee_header
#define Employee_header
#include"Human.h"
#include"Date.h"
#include<iostream>
#include<string>
class Employee : public Human 
{
	int EmployeeID;
	string Position;
	int Salary;
	int PhoneNum;
	string Address;
public:
	Employee(Date D,int Employeeid, string name, int age,string position, int salary, int Phone, string add);
	Employee(const Employee& E);
	Employee();
	~Employee(){}
	Employee* AddEmployee(Employee* Employees,int* Number);
	void ModifyAdd(Employee* Employees,string add, int Number);
	void Modifyphone(Employee* Employees, int phone, int Number);
	void ModifyPos(Employee* Employees, string pos, int Number);
	void ModifySalary(Employee* Employees, int s, int Number);
	void SetID(int id);
	friend ostream& operator<<(ostream& os, const Employee& E)
	{
		os << "Identification number:" << E.EmployeeID << endl;
		os << "Name: " << E.PersonName << endl;
		os << "Birth Date: " << E.BirthDate << endl;
		os << "Age: " << E.Age << endl;
		os << "Address: " << E.Address << endl;
		os << "Phone number: " << E.PhoneNum << endl;
		os << "Position: " << E.Position << endl;
		os << "Salary: " << E.Salary << endl << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Employee& E)
	{
		cout << "Enter the employee's details: " << endl;
		cout << "Identifiaction number: ";
		is >> E.EmployeeID;
		cout << "Name: ";
		is.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(is,E.PersonName,'\n');
		cout << "Birthdate: ";
		is >> E.BirthDate;
		cout << "Age: ";
		is >> E.Age;
		cout << "Address: ";
		is.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(is, E.Address, '\n');
		cout << "Phone number: ";
		is >> E.PhoneNum;
		cout << "Position: ";
		is.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(is, E.Position,'\n');
		cout << "Salary: ";
		is >> E.Salary;
		return is;
	}
	friend Employee* GetEmployees(Employee* Employee);
	friend void WriteEmployeeInFile(Employee* Employee, int Number);
};
#endif
