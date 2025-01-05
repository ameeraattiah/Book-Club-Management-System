#ifndef CONTROL_H
#define CONTROL_H

#include "BookClub.h"
#include "View.h"

/*Control class that controls the classes and initializes books and members in the book club,
and allows the user to choose what he/she intends to do from a menu*/
class Control
{
	private:
		View view; //declaring a variable with datatype view.

	public:
		//Constructor
		Control();
		//the launch function that launches the options from the view class
		void launch();
		//Initializing functions
		//a pointer that points to objects of bookclub is passed to all three functions.
		void initBooks(BookClub* bclub);
		void initMembers(BookClub* bclub);
		void initRating(BookClub* bclub);

};

#endif
