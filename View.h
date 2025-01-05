#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;


class View
{
  public:
    void showMenu(int&); //Function resposible for displaying the menu for the user.
  	void readBookRating(int&);/*Function responsible for asking the user to insert the rating
  	                            and checks if its within the rating range. */
  	void readBookID(int&); //Function responsible for taking the book ID from the user.
  	void readMemberID(int&); //Function responsible for taking the member ID from the user.

};

#endif
