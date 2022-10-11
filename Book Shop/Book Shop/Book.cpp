#include"Book.h"
#include"Date.h"
#include<fstream>
#include<iostream>
#include<string>
#include "Exceptions.h"
using namespace std;
Book::Book(Date d, int id=0, string name="", int num=0, string author="",int price=0):BookID(id), BookName(name),CopiesNum(num),AuthorName(author),Publishing(d),Price(price) {}
Book::Book(const Book& B)
{
	BookID = B.BookID;
	BookName = B.BookName;
	CopiesNum = B.CopiesNum;
	AuthorName = B.AuthorName;
	Publishing = B.Publishing;
	Price = B.Price;
}
Book::Book()
{
	BookID = 0;
	BookName = "";
	CopiesNum = 0;
	AuthorName = "";
	Date* D = new Date(0, 0, 0);
	Publishing = *D;
	Price = 0;
}
Book* Book::AddBook(Book* Books, int* n)
{
	bool BookExists = false;
	for (int i = 0; i < *n; i++)
	{
		if (Books[i].BookID == BookID)
		{
			if (Books[i].BookName == BookName)
			{
				Books[i].CopiesNum = Books[i].CopiesNum + CopiesNum;
				cout << "The book is already in the shop.The number of copies is updated" << endl;
				BookExists = true;
			}
			else 
			{
				cout << "The Identifiaction number is used for another book named " << Books[i].BookName << endl;
				BookExists = true;
			}
			break;
		}
	}
	if (BookExists == false)
	{
		Book* Books_tmp = new Book[*n + 1];
		for (int i = 0; i < *n; i++)
		{
			Books_tmp[i] = Books[i];
		}
		Books_tmp[*n].BookID=BookID;
		Books_tmp[*n].BookName = BookName;
		Books_tmp[*n].Publishing = Publishing;
		Books_tmp[*n].CopiesNum = CopiesNum;
		Books_tmp[*n].Price = Price;
		Books_tmp[*n].AuthorName = AuthorName;
		delete[] Books;
		Books = Books_tmp;
		*n = *n + 1;
	}
	return Books;
}
void Book::ModifyPrice(Book* Books,int P,int Number )
{
	bool BookExists = false;
	for (int i = 0; i < Number; i++)
	{
		if (Books[i].BookID == BookID)
		{
			Books[i].Price = P;
			BookExists = true;
			break;
		}
	}
	if (BookExists == true)
	{
		cout << "The price of the book has been modified successfully" << endl;
	}
	else
	{
		throw BookNotFoundEx;
	}
}
void Book::ModifyCopiesNum(Book* Books,int Num, int Number)
{
	bool BookExists = false;
	for (int i = 0; i < Number; i++)
	{
		if (Books[i].BookID == BookID)
		{
			Books[i].CopiesNum = Num;
			BookExists = true;
			break;
		}
	}
	if (BookExists == true)
	{
		cout << "The number of copies of the book has been modified successfully" << endl;
	}
	else
	{
		throw BookNotFoundEx;
	}
}
void Book::SetBookID(int id)
{
	BookID = id;
}
void Book::SetBookName(string s)
{
	BookName = s;
}
void Book::SearchByID(Book* Books, int Number)
{
	bool Idexists = false;
	for (int i = 0; i < Number;i++)
	{
		if (Books[i].BookID == BookID)
		{
			cout << Books[i];
			Idexists = true;
		}
	}
	if (Idexists == false)
	{
		throw BookNotFoundEx;
	}
}
void Book::SearchByName(Book* Books,int Number)
{
	bool Nameexists = false;
	for (int i = 0; i < Number; i++)
	{
		if (Books[i].BookName == BookName)
		{
			cout << Books[i];
			Nameexists = true;
		}
	}
	if (Nameexists == false)
	{
		throw BookNotFoundEx;
	}
	
}
bool Book::BookSold(Book* Books, int BooksNumber)
{
	bool BookExists = false;
	for (int i = 0; i < BooksNumber; i++)
	{
		if (Books[i].BookID == BookID)
		{
			if (Books[i].CopiesNum == 0)
			{
				throw BookOutOfStockEx;
			}
			else
			{
				Books[i].CopiesNum = Books[i].CopiesNum - 1;
				BookExists = true;
			}
		}
	}
	if (BookExists == true)
	{
		return true;
	}
	else
	{
		throw BookNotFoundEx;
		return false;
	}
}

