#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

//Constrcutors
Book::Book()
{
	//initializing the objects.
	id = 0;
	title = "";
	author = "";
	year = 0;
}
Book::Book(int bookID,string bookTitle,string bookAuthor,int bookYear)
{
	id = bookID;
	title = bookTitle;
	author = bookAuthor;
	year = bookYear;
}
//Setters

void Book::Setid(int bookID)
{
	id = bookID;
}

void Book::Settitle(string bookTitle)
{
	title = bookTitle;
}

void Book::Setauthor(string bookAuthor)
{
	author = bookAuthor;
}

void Book::Setyear(int bookYear)
{
	year = bookYear;
}

//Getters
int Book::getid()
{
	return id;
}

string Book::gettitle()
{
	return title;
}

string Book::getauthor()
{
	return author;
}

int Book::getyear()
{
	return year;
}
//Displays the books' data.
void Book::print()
{
		cout << " ID: " << id <<endl;
		cout << " Title: "<< title << endl;
		cout << " Author: " << author << endl;
		cout << " Year: " << year << endl;
		cout << "--------------------------------------------------------------" << endl;
}

bool Book::lessThan(const Book* b) //given a parameter that points to objects in the book class.
{
	if (this->title > b ->title) //compares the book to the book passed in as a parameter.
		return true;
	else
		return false;
}
