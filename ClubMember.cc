#include <iostream>
#include <string>
#include "ClubMember.h"
using namespace std;

//Default constructor.
ClubMember::ClubMember()
{
  //initializing the objects.
  id = 0;
  firstName = "";
  lastName = "";
}
//Overloaded Constructor.
ClubMember::ClubMember(int ClubMemberID,string ClubMemberFirstName,string ClubMemberLastName)
{
  id = ClubMemberID;
  firstName = ClubMemberFirstName;
  lastName = ClubMemberLastName;
}

//Setters
void ClubMember::setID(int ClubMemberID)
{
  id = ClubMemberID;
}
void ClubMember::setFirstName(string ClubMemberFirstName)
{
  firstName = ClubMemberFirstName;
}
void ClubMember::setLastName(string ClubMemberLastName)
{
  lastName = ClubMemberLastName;
}

//Getters
int ClubMember::getID()
{
  return id;
}
string ClubMember::getFirstName()
{
  return firstName;
}
string ClubMember::getLastName()
{
  return lastName;
}

//Displays the club members' data.
void ClubMember::print()
{
  cout << " ID: " << id <<  endl;
  cout << " First Name: " << firstName << endl;
  cout << " Last Name: " << lastName << endl;
  cout << "--------------------------------------------------------------" << endl;
}

bool ClubMember::lessThan(const ClubMember* m) //given a parameter that points to objects in the clubmember class.
{
  //compares the first and last name with the first and last names passed as parameters.
  if (firstName < m->firstName && lastName < m -> lastName)
     return true;
   else
    return false;
}
