#include  <iostream>
#include "Rating.h"

using namespace std;

//Constructors

Rating::Rating(Book **bk, ClubMember **mb, int ra)
{
	//Pointers assigned to the variables.
	book = *bk;
	member = *mb;
	rating = ra;
}
//Setters
void Rating::setBook(Book*bo)//given a parameter that points to the book objects.
{
	book = bo;
}
void Rating::setmember(ClubMember* mem)//given a parameter that points to the clubmember objects.
{
	member = mem;
}
void Rating::setrating(int ra)
{
	rating = ra;
}
//Getters
Book* Rating::getBook() /*getter function that returns a single pointer
 that points to an object to the book class.*/
{
	return book;
}

ClubMember* Rating::getMember() //getter function that returns a single pointer that points to an object to the clubmember class.
{
	return member;
}
int Rating::getRating()
{
	return rating;
}

void Rating::print()//printing function.
{
	cout << "Book name:" << book -> gettitle() << endl;
	cout << "Member ID:" << member -> getID() << endl;
	cout << "Rating:" << rating << endl;
	cout << "--------------------------------------------------------------" << endl;
}


Rating::~Rating() //destructor that deletes the memory.
{
	cout << "Rating Desctructor..." <<endl;
	delete book;
	delete member;

}
