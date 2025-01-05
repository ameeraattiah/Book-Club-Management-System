#ifndef CLUBMEMBER
#define CLUBMEMBER
#include <iostream>
#include <string>
using namespace std;

class ClubMember
{
  private:
    int id;
    string firstName;
    string lastName;

  public:
    //Default constructor.
    ClubMember();
	//Overloaded constructor.
    ClubMember(int,string,string);

    //Setters
    void setID(int ClubMemberID);
    void setFirstName(string ClubMemberFirstName);
    void setLastName(string ClubMemberLastName);

    //Getters
    int getID();
    string getFirstName();
    string getLastName();

    //Display
    void print();

    //Comparison
    bool lessThan(const ClubMember* m);

};

#endif
