#ifndef BOOKCLUB
#define BOOKCLUB
#include <iostream>
#include <string>
#include "BkArray.h"
#include "CmArray.h"
#include "Rating.h"
#include "BookClub.h"

using namespace std;

class BookClub
{
	private:
		BkArray books; //Book array object.
		CmArray members; //ClubMember array object.
		Rating **rating; /*pointer variable pointing to an array
		full of pointers that points to rating objects.*/
		string bookClubName;
		int numRatings , index; //used to determine the number of elements and the index of an array.

	public:
		//Default Constructor
		BookClub(string name = " ");
		//Functions resposible for adding books,clubmembers,and ratings.
		void addBook(Book *b);
		void addMember(ClubMember *cb);
		void addRating(int memberID,int bookID, int r);

		//Functions responsible for printing the data under members,books, and ratings.
		void printMembers();
		void printBooks();
		void printRating();

		void bestRatedBook(); //Function responsible for printing out the best/highest rated book in the book club.
		void most_occured_id(); //Function responsible for printing the most rated Book including the ID, Name, Author, and Year of the book.

};

#endif
