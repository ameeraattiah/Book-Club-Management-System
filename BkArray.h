#ifndef BKARRAY
#define BKARRAY
#include "Book.h"
#include <iostream>
using namespace std;

class BkArray
{
	private:
		Book** books; //pointer that points to elements in an array of pointers.
		int index;
		int SIZE;


	public:
		BkArray(); //default constructor.
		~BkArray(); //destructor..deletes the array from memory.
		void print();//printing function.
		bool search(int id, Book** b); //searches for books in order to add a new one alphabetically.
										//book pointer is taken as a parameter.
		void add(Book* bk); //function that adds books to the array of books.

};

#endif
