#include <iostream>
#include <string>
#include "Control.h"
#include "View.h"
#include "BookClub.h"

using namespace std;

//Constructor
Control::Control()
{

}
//function that launches the options' functions from the View class.
void Control::launch()
{

  BookClub* effatClub = new BookClub("Effat Uni"); /*allocates heap memory, initializes the memory,
  //function calls.                               and returns its address to the pointer variable effatClub.*/
  initMembers(effatClub);
  initBooks(effatClub);
  initRating(effatClub);
  int choice = 0;

  while (1) {
    view.showMenu(choice);
    //controls the view menu
    if (choice == 0) //gets you out of the program
		{
			cout << "Bye Bye..." << endl;
			break;
		}
    else if (choice == 1) //prints all the books that are already in the book club.
    {
      effatClub -> printBooks();
    }
    else if (choice == 2) //prints all the members that are already in the book code
    {
      effatClub -> printMembers();
    }
    else if (choice == 3) //allows the user to add ratings for books.
    {
  	  int memberID,bookID,r; //declaring variables.
  	  view.readBookRating(r); /*accessing the function member of the view
      class that asks the user to rate books and checks if the inserted rating is within the required range (1-10).*/
  	  view.readMemberID(memberID); /*accessing the function member of the view
      class that asks the user to insert the user's member ID.*/
  	  view.readBookID(bookID);  /*accessing the function member of the view
      class that asks the user to insert the Book ID in which the user is rating.*/
  	  effatClub -> addRating(memberID,bookID,r); /*accessing the function member of the Book club class
      that is responsible for adding a rate to the rating array.*/
    }
    else if (choice == 4)/*accesses the function member of the book club class
     that is responsible for printing out all the ratings that are already in the book club.*/
    {
  		effatClub->printRating();
    }
    else if (choice == 5) /*accesses the function member of the book club class
     that is responsible for printing out the best rated book in the book club.*/
    {
      effatClub-> bestRatedBook();
    }
    else if (choice == 6) /*accesses the function member of the book club class
     that is responsible for printing out the most rated book in the book club.*/
    {
      effatClub -> most_occured_id();
    }
  }
}

void Control::initBooks(BookClub* effatClub) /*initializes the books' data by accessing
the function member of the book club class.*/
{
	cout << "Initializing the books data...." << endl;
	effatClub->addBook(new Book(139851,"It Starts With Us","Colleen Hoover",2022));
	effatClub->addBook(new Book(198214,"It Ends With Us","Colleen Hoover",2016));
	effatClub->addBook(new Book(074324,"Fahrenheit 451","Ray Bradbury",2003));
	effatClub->addBook(new Book(152471,"The Da Vinci Code","Dan Brown",2016));
	effatClub->addBook(new Book(137434,"Angels & Demons","Dan Brown",2016));
	effatClub->addBook(new Book(147675,"Ugly Love","Colleen Hoover",2014));
	effatClub->addBook(new Book(144819,"The Sun is also a Star","Nicola Yoon",2016));
	effatClub->addBook(new Book(148470,"Every Last Word","Tamara Ireland Stone",2015));
	effatClub->addBook(new Book(073527,"Normal People","Sally Rooney",2020));
	effatClub->addBook(new Book(129143,"Notes from the Underground","Fyodor Dostoyevsky",2013));

}
void Control::initRating(BookClub* effatClub)  /*initializes the ratings' data by accessing
// the function member of the book club class.*/
{
	cout << "Initializing the rating data...." << endl;
  effatClub->addRating(002, 139851, 8);
  effatClub->addRating(001, 073527, 10);
  effatClub->addRating(005, 139851, 5);
  effatClub->addRating(003, 139851, 2);
  effatClub->addRating(002, 198214, 4);
  effatClub->addRating(004, 074324, 6);
  effatClub->addRating(003, 152471, 7);
  effatClub->addRating(002, 144819, 9);
  effatClub->addRating(001, 073527, 1);
  effatClub->addRating(004, 129143, 3);
  effatClub->addRating(005, 147675, 2);
  effatClub->addRating(002, 148470, 10);
  effatClub->addRating(005, 137434, 5);
  effatClub->addRating(003, 139851, 8);
  effatClub->addRating(002, 147675, 7);
  effatClub->addRating(001, 073527, 9);
  effatClub->addRating(002, 198214, 5);
  effatClub->addRating(004, 129143, 4);
  effatClub->addRating(001, 152471, 10);
  effatClub->addRating(005, 129143, 7);
}

void Control::initMembers(BookClub* effatClub)  /*initializes the members' data by accessing
the function member of the book club class.*/
{
	cout << "Initializing the club members data...." << endl;
	effatClub->addMember(new ClubMember(001,"Ameera","Attiah"));
	effatClub->addMember(new ClubMember(002,"Leen","Sharab"));
	effatClub->addMember(new ClubMember(003,"Sara","Alashumiry"));
	effatClub->addMember(new ClubMember(004,"Esraa","Basalamah"));
	effatClub->addMember(new ClubMember(005,"Akila","Sarirete"));
}
