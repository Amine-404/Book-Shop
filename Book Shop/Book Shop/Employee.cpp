#include "Employee.h"
#include"Date.h"
#include"Human.h"
#include<string>
#include<iostream>
#include<fstream>
Employee::Employee(Date D,int Employeeid, string name="", int age=0, string position="", int salary=0, int Phone=0, string add=""):Human(D,name,age),EmployeeID(Employeeid),Position(position),Salary(salary),PhoneNum(Phone),Address(add)     {}
Employee::Employee(const Employee& E)
{
	PersonName = E.PersonName;
	Age = E.Age;
	BirthDate = E.BirthDate;
	Salary = E.Salary;
	PhoneNum = E.PhoneNum;
	Address = E.Address;
	Position = E.Position;
}
Employee::Employee()
{
	Position = "";
	Salary = 0;
	PhoneNum = 0;
	Address = "";
	Date* D = new Date(0, 0, 0);
	BirthDate = *D;
}
Employee* Employee::AddEmployee(Employee* Employees, int* Number)
{
	bool EmployeeExists = false;
	for (int i = 0; i < *Number; i++)
	{
		if (Employees[i].EmployeeID == EmployeeID)
		{
			cout << "Identifaction number used by another employee: " << Employees[i].PersonName << endl;
			EmployeeExists = true;
			break;
		}
	}
	if (EmployeeExists == false)
	{
		Employee* Employees_tmp = new Employee[*Number + 1];
		for (int i = 0; i < *Number; i++)
		{
			Employees_tmp[i] = Employees[i];
		}
		Employees_tmp[*Number].EmployeeID = EmployeeID;
		Employees_tmp[*Number].PersonName = PersonName;
		Employees_tmp[*Number].BirthDate = BirthDate;
		Employees_tmp[*Number].Age = Age;
		Employees_tmp[*Number].PhoneNum = PhoneNum;
		Employees_tmp[*Number].Salary = Salary;
		Employees_tmp[*Number].Position = Position;
		Employees_tmp[*Number].Address = Address;
		delete[] Employees;
		Employees = Employees_tmp;
		*Number = *Number + 1;
		cout << "Employee Added successfully." << endl;
	}
	return Employees;
	
}
void Employee::ModifyAdd(Employee* Employees,string add, int Number)
{
	bool EmployeeExists = false;
	for (int i = 0; i < Number; i++)
	{
		if (Employees[i].EmployeeID == EmployeeID)
		{
			Employees[i].Address = add;
			EmployeeExists = true;
			cout << "Address of the employee has been modified." << endl;
			break;
		}
	}
	if (EmployeeExists == false)
	{
		cout << "Employee Not Found." << endl;
	}
}
void Employee::Modifyphone(Employee* Employees,int phone,int Number)
{
	bool EmployeeExists = false;
	for (int i = 0; i < Number; i++)
	{
		if (Employees[i].EmployeeID == EmployeeID)
		{
			Employees[i].PhoneNum = phone;
			EmployeeExists = true;
			cout << "Phone Number of the employee has been modified." << endl;
			break;
		}
	}
	if (EmployeeExists == false)
	{
		cout << "Employee Not Found." << endl;
	}
}
void Employee::ModifyPos(Employee* Employees, string pos , int Number)
{
	bool EmployeeExists = false;
	for (int i = 0; i < Number; i++)
	{
		if (Employees[i].EmployeeID == EmployeeID)
		{
			Employees[i].Position = pos;
			EmployeeExists = true;
			cout << "Position of the employee has been modified." << endl;
			break;
		}
	}
	if (EmployeeExists == false)
	{
		cout << "Employee Not Found." << endl;
	}
}
void Employee::ModifySalary(Employee* Employees, int s, int Number)
{
	bool EmployeeExists = false;
	for (int i = 0; i < Number; i++)
	{
		if (Employees[i].EmployeeID == EmployeeID)
		{
			Employees[i].Salary = s;
			EmployeeExists = true;
			cout << "Salary of the employee has been modified." << endl;
			break;
		}
	}
	if (EmployeeExists == false)
	{
		cout << "Employee Not Found." << endl;
	}
}
void Employee::SetID(int id)
{
	EmployeeID = id;
}