#include <iostream>
#include <new>
#include "BookClub.h"
#include "Rating.h"
#include "BkArray.h"
#include "CmArray.h"

using namespace std;


BookClub::BookClub(string name)
{
	bookClubName = name;
	numRatings = 25;
	index = 0;
	rating = new Rating*[numRatings]; /*creates a dynamic array where each element
							is a pointer to an object in the rating class.*/
}

//Add
void BookClub::addBook(Book* b) //given a parameter than points to objects in the book class.
{
  books.add(b); /*calling the function that adds books and passing down the pointer
	variable b in order to access the book objects and add the required data of the book.*/
}
void BookClub::addMember(ClubMember* cb)
{
  members.add(cb); /*calling the function that adds members and passing down the pointer
	variable cb in order to access the clubmember objects and add the required data of the members.*/
}

void BookClub::addRating(int memberID, int bookID, int r)
{
	Book** b = new Book*(); //creating a double pointer to the book class.
	if (books.search(bookID,b)) //passed the double pointer to the parameter of search that is called by the books array.
	{
		ClubMember** m = new ClubMember*(); //created a double pointer to the clubmember.
		if  (members.search(memberID,m)) //passed the double pointer to the parameter of search that is called by the clubmember array.
		{
			rating[index++] = new Rating(b, m, r); /*created new object for rating and passed the rating
			 and the double pointers of book and clubmember.*/
			 //index increases by one to move to the next index.
		}
		else
			cout << " Couldn't find the Member ID" << memberID << endl;
	}
	else
		cout << "Couldn't find the Book ID " << bookID << "." << endl;

}

//Print
void BookClub::printMembers()
{
	members.print(); /*accessing the function member of the clubmember
	array (CmArray) class that prints out the club members' data.*/
}
void BookClub::printBooks()
{
	books.print(); /*accessing the function member of the book
	array (BkArray) class that prints out the books' data.*/
}
void BookClub::printRating()
{
	if (index != 0)//checks if elements exist in an array.
	{
		for (int i=0; i < index; i++) //passes by every index and prints each element in the array.
		{
			rating[i]->print();/*reaches out to the print function in the rating class
								          and Prints every rating and stores them in an array.*/
		}
	}
	else
		cout << "No available ratings." << endl;
}

void BookClub::most_occured_id()
{
int max_count = 0;
Rating* highest; //declaring a pointer variable that points to the rating class members.
highest = rating[0]; //assigning the first element in rating[] to highest.

for (int i = 0; i <index; i++) /*Because we have nested for loops, it will compare every element
																in a specific index with the rest of the elements.*/
																//for example,element in index 0 is compared to every other element in the array...
{
	int curr_count = 1; //set the counter to 1 because we're comparing every 2 adjacent IDs and finding the IDs that are repeated.
	for (int j = i+1; j<index; j++) //takes the next index in order to compare it with the previous one, and so on..
		{
			if(rating[i]->getBook()->getid() == rating[j]->getBook()->getid()) /*rating[] accesses the getbook function (from the rating class),
			simultaneously the getbook function accesses the getId function(from the Book class). */
			//The BookID of the first element will be compared to the BookID of the next element.
			//if both IDs are equal increment 1 to the count.
				curr_count++;
			if (curr_count > max_count) //if the current counter is greater than the max counter
				max_count = curr_count; //the counter becomes the max.
				//for example,if the current count is 3 and the max count is 2, the max count becomes 3.
		} //once the loop terminates and reaches this point, it means that the most occurred ID is found..
	if (curr_count == max_count)
		highest = rating[i]; //assign the highest to the element in index i in the array..
		//therefore the most occurred ID is the element in this specific index.
}
	cout << "The Most Rated Book : " << endl;
	highest -> getBook() -> print(); //prints out the data of the most occurred book.
}

void BookClub::bestRatedBook()
{
	Rating* max; //declaring a pointer variable that points to the rating class members.
	max = rating[0]; //assigning the first element in rating[] to max.
	//we are pretending that the first element is the best and then we start comparing it to every other element in the array.
	for (int i = 0; i < index; i++) //compares elements with each other
	{
		if (rating[i]->getRating() > max -> getRating()) //if the rating in the current index is greater than the best rating..
		{
			max = rating[i];  //assign the element in the current index to the best, which makes it the highest/best rated book.
		}
	}
	cout << "Best Rated Book:" << endl;
	max -> getBook() -> print(); //prints out the best rated book.
}
