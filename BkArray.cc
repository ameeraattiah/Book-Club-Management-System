#include "BkArray.h"
#include <iostream>
#include <new>
using namespace std;

BkArray::BkArray()
{
	index=0;
	SIZE = 20;
	books = new Book*[SIZE];/*creates a dynamic array where each element
							is a pointer to the book class.*/
}

void BkArray::add(Book* bk)//a pointer variable of datatype Book is passed to the parameter.
//it points to objects in the book class in order to use it for comparing titles and adding books.
{
	if (index > SIZE - 1) //Assures that the index does not exceed the size of the array.
	{
		cout << "Cannot add more Books." << endl;  //if the array is full,we cannot add more books.
	}
	else
	{
		int position = 0;//this is the position where the new book will be added to.
		for (int i=0; i < index - 1; i++) //loop that checks every element and compares the title of the books
		                              //alphabetically in order to add a book alphabetically.
		{/*these statements basically check elements alphabetically, in order to shift all the other elements
			 to the right and place the added book to the left of the shifted elements.*/
			if (bk->lessThan(books[i]))//checks the title alphabetically.
			{
				position = i;//assigns the position of the book to i.
				break;
			}
		}
		for (int i= SIZE; i > position ;--i)//loop begins from the last element and i decrements with every loop.
		{
			books[i]=books[i-1];//places the book to the left of i.
		}
		books[position]=bk;//the book with the suitable position is then assigned to bk.
		index++;//moves to the next index.
	}

}

bool BkArray::search(int id, Book** b)
{
	if (index != 0)//checks if elements exist in an array.
	{
		for (int i =0; i < index; i++)//loop that checks every element to find a specific book.
		{
			if (books[i]->getid() == id)//if the id in index i is the same as the id we got using getid function.
			{
				*b = books[i];//store the element in b and return true.
				return true;
			}
		}
	}
	else //the array has no elements.
		cout << "Books are not found in the list." << endl;
	*b = nullptr;//since the array has no elements, the pointer will not point to anything.
	return false;
}

void BkArray::print()
{
	if (index != 0)//checks if elements exist in an array.
	{
		cout << "Book data:\n";
		for (int i=0; i < index; i++) //loop that prints out every book.
		{
			cout << "Book: " << i+1 << endl;//prints out Book:1,Book:2 and so on.
			books[i]->print();//reaches out to the print function in the book class.
								//and Prints every book and stores them in an array.
		}
	}
	else
		cout << "No available books." << endl;
}

//destructor to delete the memory.
BkArray::~BkArray()
{
	for (int i=0; i< index - 1; i++)//loop that passes through every element .
	{
		delete books[i]; //deletes every element.
	}
	delete [] books; //deletes the array.


}
