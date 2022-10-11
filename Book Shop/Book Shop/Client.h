#pragma once
#ifndef Client_header
#define Client_header
#include"Date.h"
#include"Human.h"
#include"Book.h"
#include<iostream>
#include<fstream>
#include<string>
class Client: public Human
{
	int ID;
	int Loyalty;
public:
	Client(Date D, int id, string name, int age);
	Client(const Client& C);
	Client();
	~Client(){}
	void UpdateLoyalty(Client* Clients, int Number);
	void SetClientID(int id);
	Client* AddClient(Client* Clients, int* Number);
	void Ckeckloyalty(Client* Clients, int Number);
	friend istream& operator>>(istream& is, Client& C)
	{
		cout << "Enter the employee's details: " << endl;
		cout << "Identifiaction number: ";
		is >> C.ID;
		cout << "Name: ";
		is.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(is, C.PersonName, '\n');
		cout << "Birthdate: ";
		is >> C.BirthDate;
		cout << "Age: ";
		is >> C.Age;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Client& C)
	{
		os << "Identification number:" << C.ID << endl;
		os << "Name: " << C.PersonName << endl;
		os << "Birth Date: " << C.BirthDate << endl;
		os << "Age: " << C.Age << endl;
		os << "Loyalty points: " << C.Loyalty << endl << endl;
		return os;
	}
	friend Client* GetClients(Client* Clients);
	friend void WriteClientInFile(Client* Clients, int Number);
};
#endif
