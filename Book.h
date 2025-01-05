#ifndef BOOK
#define BOOK
#include <iostream>
#include <string>
using namespace std;

class Book
{
	private:
		int id;
		string title;
		string author;
		int year;


	public:
		//Default Constrcutor
		Book();
		//Overloaded Constrcutor
		Book(int,string,string,int);
		//Setters
		void Setid(int bookID);
		void Settitle(string bookTitle);
		void Setauthor(string bookAuthor);
		void Setyear(int bookYear);
		//Getters
		int getid();
		string gettitle();
		string getauthor();
		int getyear();
		//Display
		void print();
		//Function that compares Books alphabetically.
		bool lessThan(const Book* b);

};

#endif
