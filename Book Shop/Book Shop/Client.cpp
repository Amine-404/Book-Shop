#include "Client.h"
#include"Date.h"
#include"Human.h"
Client::Client(Date D, int id=0, string name="", int age=0):Human(D,name,age), ID(id), Loyalty(0) {}
Client::Client(const Client& C)
{
	PersonName = C.PersonName;
	Age = C.Age;
	BirthDate = C.BirthDate;
	ID = C.ID;
	Loyalty = C.Loyalty;
}
Client::Client()
{
	PersonName = "";
	Age = 0;
	ID = 0;
	Loyalty = 0;
	Date* D = new Date(0, 0, 0);
	BirthDate = *D;
	delete D;
}
void Client::SetClientID(int id)
{
	ID = id;
}
Client* Client::AddClient(Client* Clients, int *Number)
{
	bool IdUsed = false;
	for (int i = 0; i < *Number; i++)
	{
		if (Clients[i].ID == ID)
		{
			IdUsed = true;
			cout << "Identifiaction humber already used by another persaon under the name" << Clients[i].PersonName;
			break;
		}
	}
	if (IdUsed == false)
	{
		Client* Clients_tmp = new Client[*Number + 1];
		for (int i = 0; i < *Number; i++)
		{
			Clients_tmp[i] = Clients[i];
		}
		Clients_tmp[*Number].PersonName=PersonName;
		Clients_tmp[*Number].ID = ID;
		Clients_tmp[*Number].Age = Age;
		Clients_tmp[*Number].BirthDate = BirthDate;
		Clients_tmp[*Number].Loyalty = Loyalty;
		delete[] Clients;
		Clients = Clients_tmp;
		*Number = *Number + 1;
		cout << "CLient has been added successfully" << endl;
	}
	return Clients;
}
void Client::Ckeckloyalty(Client* Clients,int Number)
{
	bool ClientExists = false;
	for (int i = 0; i < Number; i++)
	{
		if (Clients[i].ID == ID)
		{
			cout << "You have " << Clients[i].Loyalty << " loyalty points" << endl;
			if (Clients[i].Loyalty >= 5)
			{
				cout << "you have a discount on your next purchase." << endl;
			}
			ClientExists = true;
		}
	}
	if (ClientExists == false)
	{
		cout << "Client not registered in the system" << endl;
	}
}
void Client::UpdateLoyalty(Client* Clients, int Number)
{
	bool ClientExists = false;
	int i ;
	for (i = 0; i < Number; i++)
	{
		if (Clients[i].ID == ID)
		{
			Clients[i].Loyalty = Clients[i].Loyalty + 1;
			ClientExists = true;
			break;
		}
	}
	if (ClientExists == true)
	{
		if (Clients[i].Loyalty >= 5)
		{
			cout << "Client has a 10% discount on the book he is buying" << endl;
		}
		cout << "Loyalty Points updated." << endl;
	}
	else
	{
		cout << "Client not registered in the system." << endl;
	}
}

