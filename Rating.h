#ifndef RATING
#define RATING
#include <iostream>
#include <string>
#include "Book.h"
#include "ClubMember.h"
using namespace std;

class Rating
{
	private:
		Book* book; //points to the book class objects
		ClubMember* member;//points to the clubmember class objects.
		int rating;

	public:

		//Overloaded constructor that takes a book pointer, a clubmember pointer, and a rating as parameters.
		Rating(Book **bk, ClubMember **mb, int rating);
		//Setters
		void setBook(Book* bo);
		void setmember(ClubMember* mem);
		void setrating(int ra);
		//Getters
		Book* getBook();
		ClubMember* getMember();
		int getRating();
		//explanation required....
		void print();//prints out the book name, member id,and the rating of the book.
		//Destructor.
		~Rating();
};
#endif
