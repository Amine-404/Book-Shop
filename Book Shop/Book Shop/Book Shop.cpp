// Book Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include<fstream>
#include<string>
#include"Book.h"
#include"Employee.h"
#include"Date.h"
#include"Client.h" 
using namespace std;


int NumberOfBooks(void)
{
    int number = 0;
    string s;
    fstream fbook;
    fbook.open("Books.txt");
    while (!fbook.eof())
    {
        getline(fbook, s);
        number++;
    }
    fbook.close();
    return number / 8;
}
int NumberOfClients(void)
{
    fstream fclient;
    string s;
    int counter = 0;
    fclient.open("Client.txt", ios::in);
    while (!fclient.eof())
    {
        getline(fclient, s);
        counter++;
    }
    return counter / 7;
}
int NumberOfEmployees(void)
{
    fstream femployee;
    femployee.open("Employee.txt", ios::in);
    int counter = 0; string s;
    while (!femployee.eof())
    {
        getline(femployee, s);
        counter++;
    }
    return counter / 10;
}
Book* GetBooks(Book* Books)
{
    fstream fbook;
    fbook.open("Books.txt", ios::in);
    int i = 0;
    int Number = NumberOfBooks();
    while (i < Number)
    {
        fbook >> Books[i].BookID;
        fbook.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(fbook, Books[i].BookName);
        fbook >> Books[i].CopiesNum;
        fbook.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(fbook, Books[i].AuthorName);
        int d, m, y;
        fbook >> d;
        fbook >> m;
        fbook >> y;
        Date* D = new Date(d, m, y);
        Books[i].Publishing = *D;
        fbook >> Books[i].Price;
        i++;
    }
    return Books;
}
Client* GetClients(Client* Clients)
{
    fstream fclient;
    fclient.open("Client.txt", ios::in);
    int Number = NumberOfClients();
    int i = 0;
    while (i < Number)
    {
        fclient >> Clients[i].ID;
        fclient.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(fclient, Clients[i].PersonName);
        int d, m, y;
        fclient >> d;
        fclient >> m;
        fclient >> y;
        Date* D = new Date(d, m, y);
        Clients[i].BirthDate = *D;
        delete D;
        fclient >> Clients[i].Age;
        fclient >> Clients[i].Loyalty;
        i++;
    }
    fclient.close();
    return Clients;
}
Employee* GetEmployees(Employee* Employees)
{
    fstream femployee;
    femployee.open("Employee.txt", ios::in);
    int Number = NumberOfEmployees();
    int i = 0;
    while (i < Number)
    {
        femployee >> Employees[i].EmployeeID;
        femployee.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(femployee, Employees[i].PersonName);
        int d, m, y;
        femployee >> d;
        femployee >> m;
        femployee >> y;
        Date* D = new Date(d, m, y);
        Employees[i].BirthDate = *D;
        delete D;
        femployee >> Employees[i].Age;
        femployee.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(femployee, Employees[i].Address);
        femployee >> Employees[i].PhoneNum;
        femployee.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(femployee, Employees[i].Position);
        femployee >> Employees[i].Salary;
        i++;
    }
    femployee.close();
    return Employees;
}
void WriteBooksInFile(Book* Books, int Number)
{
    fstream fbook;
    fbook.open("Books.txt", ios::in | ios::out);
    for (int i = 0; i < Number; i++)
    {
        fbook << Books[i].BookID << endl << Books[i].BookName << endl << Books[i].CopiesNum << endl << Books[i].AuthorName << endl << Books[i].Publishing.getDay() << endl << Books[i].Publishing.getMonth() << endl << Books[i].Publishing.getYear() << endl << Books[i].Price << endl;
    }
    fbook.close();
}
void WriteClientInFile(Client* Clients, int Number)
{
    fstream fclient;
    fclient.open("Client.txt", ios::in | ios::out);
    for (int i = 0; i < Number; i++)
    {
        fclient << Clients[i].ID << endl << Clients[i].PersonName << endl << Clients[i].BirthDate.getDay() << endl << Clients[i].BirthDate.getMonth() << endl << Clients[i].BirthDate.getYear() << endl << Clients[i].Age << endl << Clients[i].Loyalty << endl;
    }
    fclient.close();
}
void WriteEmployeeInFile(Employee* Employees, int Number)
{
    fstream femployee;
    femployee.open("Employee.txt", ios::out | ios::in);
    for (int i = 0; i < Number; i++)
    {
        femployee << Employees[i].EmployeeID << endl << Employees[i].PersonName << endl << Employees[i].BirthDate.getDay() << endl << Employees[i].BirthDate.getMonth() << endl << Employees[i].BirthDate.getYear() << endl << Employees[i].Age << endl << Employees[i].Address << endl << Employees[i].PhoneNum << endl << Employees[i].Position << endl << Employees[i].Salary << endl;
    }
    femployee.close();
}
int main()
{
    int BooksNumber = NumberOfBooks(), ClientsNumber = NumberOfClients(), EmployeesNumber = NumberOfEmployees();
    Book* Books = new Book[NumberOfBooks()];
    Books = GetBooks(Books);
    Client* Clients = new Client[NumberOfClients()];
    Clients = GetClients(Clients);
    Employee* Employees = new Employee[NumberOfEmployees()];
    Employees = GetEmployees(Employees);
    int choice = 0;
    int EmployeeChoice = 0;
    int ClientChoice = 0;
    cout << "Welcome to the Shop: " << endl << "login as: 1- an Employee" << endl << "          2- a Client" << endl << "Your choice: ";
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "invalid choice, Please re-enter your choice " << endl << "login as: an Employee --> Type 1" << endl << "          a Client --> Type 2" << endl;
        cin >> choice;
    }
    if (choice == 1)
    {
        cout << "1- Add a book" << endl << "2- Modify details of a book" << endl;
        cout << "3- Add an Employee" << endl << "4- Modify details of an employee " << endl << "5- Sell a book " << endl << "Your choice: ";
        cin >> EmployeeChoice;
        while (EmployeeChoice != 1 && EmployeeChoice != 2 && EmployeeChoice != 3 && EmployeeChoice != 4 && EmployeeChoice != 5)
        {
            cout << "invalid choice, Please re-enter your choice " << endl;
            cout << "1- Add a book" << endl << "2- Modify details of a book" << endl;
            cout << "3- Add an Employee" << endl << "4- Modify details of an employee " << "5- Sell a book" << endl;
            cin >> EmployeeChoice;
        }
        if (EmployeeChoice == 1)
        {
            Book* B = new Book();
            cin >> *B;
            Books = B->AddBook(Books, &BooksNumber);
            delete B;
        }
        else if (EmployeeChoice == 2)
        {
            int EmployeeChoice2 = 0;
            cout << "Modify: 1- Price " << endl << "        2- Number of copies: " << endl << "Your choice: ";
            cin >> EmployeeChoice2;
            while (EmployeeChoice2 != 1 && EmployeeChoice2 != 2)
            {
                cout << "Invalid Choice, please re-enter your choice " << endl;
                cout << "Modify: 1- Price " << endl << "        2- Number of copies: " << endl;
                cin >> EmployeeChoice2;
            }
            cout << "Enter the ID of the book to modify: ";
            int bookid = 0;
            Book* B = new Book();
            cin >> bookid;
            B->SetBookID(bookid);
            if (EmployeeChoice2 == 1)
            {
                int P = 0;
                cout << "Enter the new price: ";
                cin >> P;
                try
                {
                    B->ModifyPrice(Books, P, BooksNumber);
                }
                catch (exception& ex)
                {
                    cout << ex.what() << endl;
                }
            }
            else
            {
                int Num = 0;
                cout << "Enter the new number of copies: ";
                cin >> Num;
                try
                {
                    B->ModifyCopiesNum(Books, Num, BooksNumber);
                }
                catch (exception& ex)
                {
                    cout << ex.what() << endl;
                }
            }
            delete B;
        }
        else if (EmployeeChoice == 3)
        {
            Employee* E = new Employee();
            cin >> *E;
            Employees = E->AddEmployee(Employees, &EmployeesNumber);
            delete E;
        }
        else if (EmployeeChoice == 4)
        {
            int EmployeeChoice4 = 0;
            Employee* E = new Employee();
            cout << "Enter the idenitification number of the employee: ";
            int id = 0;
            cin >> id;
            E->SetID(id);
            cout << "Modify: 1- Address " << endl << "        2- Phone number: " << endl << "        3- Position" << endl << "        4- Salary" << endl;
            cout << "Your choice: ";
            cin >> EmployeeChoice4;
            while (EmployeeChoice4 != 1 && EmployeeChoice4 != 2 && EmployeeChoice4 != 3 && EmployeeChoice4 != 4)
            {
                cout << "Invalid choice, Please re-enter your choice" << endl;
                cout << "Modify: 1- Address " << endl << "        2- Phone number: " << endl << "        3- Position" << endl << "        4- Salary" << endl;
                cout << "Your choice: ";
                cin >> EmployeeChoice4;
            }
            if (EmployeeChoice4 == 1)
            {
                string add;
                cout << "Type the new address: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, add);
                E->ModifyAdd(Employees, add, EmployeesNumber);
            }
            else if (EmployeeChoice4 == 2)
            {
                int phone = 0;
                cout << "Type the new phone number: ";
                cin >> phone;
                E->Modifyphone(Employees, phone, EmployeesNumber);
            }
            else if (EmployeeChoice4 == 3)
            {
                string pos;
                cout << "Type the new position: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, pos);
                E->ModifyPos(Employees, pos, EmployeesNumber);
            }
            else if (EmployeeChoice4 == 4)
            {
                int s;
                cout << "Type the new salary: ";
                cin >> s;
                E->ModifySalary(Employees, s, EmployeesNumber);
            }
            delete E;
        }
        else if (EmployeeChoice == 5)
        {
            bool BookSold = false;
            int bookid = 0, clientid = 0;
            Book* B = new Book();
            Client* C = new Client();
            cout << "Enter the ID of the book to sell: ";
            cin >> bookid;
            cout << "Enter the ID of the client: ";
            cin >> clientid;
            C->SetClientID(clientid);
            B->SetBookID(bookid);
            try
            {
                BookSold = B->BookSold(Books, BooksNumber);
            }
            catch (exception& ex)
            {
                cout << ex.what() << endl;
            }
            if (BookSold == true)
            {
                C->UpdateLoyalty(Clients, ClientsNumber);
            }
            delete B;
        }
    }
    else
    {
        int ClientChoice1;
        cout << "Choose how you want to look for the Book: " << "1- By its identification number" << endl << "                                          2- By its name" << endl;
        cout << "3- Dispaly all the books in store" << endl << "4- Register in the system :" << endl << "5- Check my loyalty points: " << endl << "Your choice: ";
        cin >> ClientChoice1;
        while (ClientChoice1 != 1 && ClientChoice1 != 2 && ClientChoice1 != 3 && ClientChoice1 != 4 && ClientChoice1 != 5)
        {
            cout << "invalid choice, Please re-enter your choice " << endl;
            cout << "Choose how you want to look for the Book " << endl << "1- By its identification number" << endl << "2- By its name" << endl;
            cout << "3- Dispaly all available the books in store" << endl << "Your choice: ";
            cin >> ClientChoice1;
        }
        if (ClientChoice1 == 1)
        {
            int id = 0;
            cout << "Please enter the ID of the book you are looking for: " << endl << "ID: ";
            cin >> id;
            Book* B = new Book();
            B->SetBookID(id);
            try
            {
                B->SearchByID(Books, BooksNumber);
            }
            catch (exception& ex)
            {
                cout << ex.what() << endl;
            }
            delete B;
        }
        else if (ClientChoice1 == 2)
        {
            string name;
            cout << "Please enter the name of the book you are looking for: " << endl << "Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            Book* B = new Book();
            B->SetBookName(name);
            try
            {
                B->SearchByName(Books, BooksNumber);
            }
            catch (exception& ex)
            {
                cout << ex.what() << endl;
            }
            delete B;
        }
        else if (ClientChoice1 == 3)
        {
            for (int i = 0; i < BooksNumber; i++)
            {
                cout << Books[i];
            }
        }
        else if (ClientChoice1 == 4)
        {
            Client* C = new Client();
            cin >> *C;
            Clients = C->AddClient(Clients, &ClientsNumber);
            delete C;
        }
        else if (ClientChoice1 == 5)
        {
            int id = 0;
            cout << "Enter your identification number: ";
            cin >> id;
            Client* C = new Client();
            C->SetClientID(id);
            C->Ckeckloyalty(Clients, ClientsNumber);
            delete C;
        }
    }
    WriteBooksInFile(Books, BooksNumber);
    WriteClientInFile(Clients, ClientsNumber);
    WriteEmployeeInFile(Employees, EmployeesNumber);
    delete[] Books;
    delete[] Clients;
    delete[] Employees;
    int FinalChoice = 0;
    cout << "<<<< If you want to go back to the main page please type 1 else press any key >>>> " << endl << "Your choice: ";
    cin >> FinalChoice;
    if (FinalChoice == 1)
    {
        main();
    }
}
