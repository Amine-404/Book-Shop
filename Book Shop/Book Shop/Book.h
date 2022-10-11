#pragma once
#ifndef Book_header
#define Book_header
#include"Date.h"
#include<string>
#include"Client.h"
#include<iostream>
#include<fstream>
using namespace std;

class Book
{
	int BookID;
	string BookName;
	string AuthorName;
	Date Publishing;
	int CopiesNum;
	int Price;
public:
	Book(Date d,int id, string name, int num, string author,int price);
	Book(const Book& B);
	Book();
	Book* AddBook(Book* Books, int* n);
	bool BookSold(Book* Books, int BooksNumber);
	void ModifyPrice(Book* Books, int P, int Number);
	void ModifyCopiesNum(Book* Books,int Num,int Number);
	void SetBookID(int id);
	void SetBookName(string s);
	void SearchByID(Book* Books,int Number);
	void SearchByName(Book* Books, int Number);
	friend ostream& operator<<(ostream& os, const Book& B)
	{
		Date D;
		D = B.Publishing;
		os << endl;
		os << "Book ID: " << B.BookID << endl << "Book name: "
			<< B.BookName << endl << "Number of copies: " << B.CopiesNum << endl << "Price: " << B.Price << endl;
		os << "Author: " << B.AuthorName << endl 
			<< "Publishing date: " << D.getDay() << "/" << D.getMonth() << "/" << D.getYear() << endl ;
		return os;
	}
	friend istream& operator>>(istream& is, Book& B)
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter the book details: " << endl << "ID: ";
		is >> B.BookID;
		cout << "Name: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(is, B.BookName, '\n');
		cout << "Author: ";
		getline(is, B.AuthorName);
		cout << "Publishing date: ";
		is >> B.Publishing;
		cout << "Number of copies: ";
		is >> B.CopiesNum;
		cout << "Price: ";
		is >> B.Price;
		return is;
	}	
	friend Book* GetBooks(Book* Books);
	friend void WriteBooksInFile(Book* Books, int Number);
};

#endif

