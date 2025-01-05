#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Print all the books" << endl;
  cout << "  (2) Print all the members" << endl;
  cout << "  (3) Rate a book" << endl;
  cout << "  (4) Print all the rated books" << endl;
  cout << "  (5) Print the best rated book" << endl;
  cout << "  (6) Print the most rated book" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0) //the program exits if the user entered 0.
    return;

  while (choice < 1 || choice > 6) //checks if the user entered the right choice number from the menu.
  {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::readBookRating(int &rate)
{
	cout << "Please insert your rating (1-10): " << endl;
	cin >> rate; //asks the user to rate the book.

	if (rate > 11 || rate < 0)//if rating exceeds the required range.
	{
		cout << "You inserted a wrong rating. Please reinsert your rating" << endl;
		cin >> rate;
	}
}

void View::readBookID(int &bookID)
{
	cout << "Please insert the book ID: " << endl;
	cin >> bookID; //asks the user for the book ID of the rated book.
}

void View::readMemberID(int &memberID)
{
	cout << "Please insert your Member ID: " << endl;
	cin >> memberID;//asks for the member ID of the user who rated the book.

}
