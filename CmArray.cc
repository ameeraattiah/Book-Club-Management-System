#include "CmArray.h"
#include <iostream>
#include <new>
using namespace std;

CmArray::CmArray() //default constructor.
{
	//initializing the objects.
	index = 0;
	SIZE = 10;
	members = new ClubMember*[SIZE]; //allocating new memory space for the members' array.
}

void CmArray::add(ClubMember* mbrs)
//mbrs pointer passed as parameter to point to the address of the clubmembers objects.
{

	if (index > SIZE - 1) //Assures that the index does not exceed the size of the array.
	{
		cout << "Cannot add more members." << endl;
	}
	else
	{
		int position = 0; //this is the position where the new member will be added to.
		for (int i=0; i < index - 1; i++) /*loop that passes by and checks every element and compares the name
			                              of the member alphabetically in order to add a new member to
										  the array alphabetically.*/
		{
			/*these statements basically check elements alphabetically, in order to shift all the other elements
				 to the right and place the added member to the left of the shifted elements.*/
			if (mbrs->lessThan(members[i]))//if the member if lessthan any index.
			{
				position = i; //assigns the position of the member to i.
				break;
			}
		}
		for (int i= SIZE; i > position ;--i) //loop begins from the last element and i decrements with every loop.
		{
			members[i]=members[i-1]; //shifts the elements and places the member to the left of i.
		}
		members[position]=mbrs; //the member with the suitable position is then assigned to mbrs.
		index++; //moves to the next index.

	}

}


bool CmArray::search(int id,ClubMember** m)
{
	if (index != 0)//checks if elements exist in an array.
	{
		for (int i =0; i < index; i++)//loop that checks every element to find a specific member.
		{
			if (members[i]->getID() == id)/*checks if the member ID in index [i] is the same as the ID we got from
										    the clubmember class.*/
			{
				*m =members[i];//store the value of the element in m and return true.
				return true;
			}

		}

	}
	else //the array has no elements.
		cout << "No members are found in the list." << endl;
		*m = nullptr; //since the array has no elements, m does not point to any object.
		return false;


}

void CmArray::print()
{
	if (index != 0)//checks if elements exist in an array.
	{
		cout << "Club Member data:\n" << endl;
		for (int i=0; i < index; i++) //loop that passes by every member and prints them out.
		{
			cout << "Club Member: " << i+1 << endl;//prints out Club Member:1,Club Member:2 and so on.
			members[i]->print();/*reaches out to the print function in the Club Member class
								  and Prints every member and stores them in an array.*/
		}
	}
	else
		cout << "No available members." << endl;

}
//destructor to delete the memory.
CmArray::~CmArray()
{
	for (int i=0; i< index - 1; i++)//loop that passes through every element .
	{
		delete members[i]; //deletes every element.
	}
	delete [] members; //deletes the array.
}
