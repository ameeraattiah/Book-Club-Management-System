#ifndef CMARRAY
#define CMARRAY
#include "ClubMember.h"
#include <iostream>
using namespace std;

class CmArray
{
	private:
		ClubMember** members; //pointer that points to a pointer to objects in the clubmember class.
		int index;
		int SIZE;


	public:
		CmArray(); //default constructor.
		~CmArray(); //destructor
		/*mbrs points to the address of the clubmember objects
		and the club members are added to the array that is created
		in the destructor alphabetically.*/
		void add(ClubMember* mbrs);
		//searches for the member in the array with the ID indicated in the parameter
		//and returns the member to m.
		bool search(int id,ClubMember** m);
		void print(); //prints out the output.

};

#endif
