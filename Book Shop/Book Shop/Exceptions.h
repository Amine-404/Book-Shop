#pragma once
#include<exception>
using namespace std;
class EmployeeFileNotOpenException : public exception
{
	virtual const char* what() const throw()
	{
		return "Employee file could not be accessed.";
	}
}EmployeeFileNotEx;
class BooksFileNotOpen : public exception
{
	virtual const char* what() const throw()
	{
		return"Books File could not be accessed.";
	}
}BookFileNotOpenEx;
class CllientsFileNotOpen : public exception
{
	virtual const char* what() const throw()
	{
		return"Books File could not be accessed.";
	}
}ClientsFileNotOpenEx;
class BookOutOfStockException : public exception
{
	virtual const char* what() const throw()
	{
		return "Book is out of stock. You will be notified once we update the stock.";
	}
}BookOutOfStockEx;
class BookNotFoundException : public exception
{
	virtual const char* what() const throw()
	{
		return "The book does not exist in the shop.";
	}
}BookNotFoundEx;