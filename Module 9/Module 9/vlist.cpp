#include <iostream>
#include <vector>
#include <string>
#include <algorithm>//Used for sort() function
#include "vlist.h"
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////// ///////////////
//Function Name: vlist
//Precondition: Constructor has not been invoked.
//Postcondition: count=0, vector size is 9.
//Description: Constructs an instance of a vlist object.
////////////////////////////////////////////////////////////////////////////////////////////// ///////////////
vlist::vlist()
{
	cout << "Default Constructor Invoked\n";
	count = 0;
	DB.reserve(9);

}
/////////////////////////////////////////////////////////////////////////////////////////////// ///////////////
//Function Name: vlist
//Precondition: A vlist object is being passed by reference.
//Postcondition: A hard copy of a vlist object has been created.
//Description: Creates a hard copy of a vlist object.
/////////////////////////////////////////////////////////////////////////////////////////////// ///////////////
vlist::vlist(vlist& Org)
{
	cout << "\nCopy Constructor Invoked";
	DB = Org.getVector();
	count = Org.count;
	this->Print();
}
/////////////////////////////////////////////////////////////////////////////////////////////// ///////////////
//Function Name: ~vlist
//Precondition: Destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: Deallocates memory of a vlist object.
/////////////////////////////////////////////////////////////////////////////////////////////// ///////////////
vlist::~vlist()
{
	cout << "Destructor Invoked" << endl;
	DB.erase(DB.begin(), DB.end()); //erases all of the elements in the vector list
	DB.shrink_to_fit();//Reduces the capacity of the list to 0
	count = 0;

}
vector<string> vlist::getVector()
{
	//Function returns vector
	return DB;
}
bool vlist::is_Empty()
{
	//Returns true if vector is empty otherwise false
	if (DB.empty())
		return true;
	return false;
}
/*The function will return an iterator to the location of
* the item in the vector it is there. The function prints
*the message, “Item Found” or “Item Not Found” along with key name
*/
vector<string>::iterator vlist::Search(const string& key)
{
	vector<string>::iterator i;
	for (i = DB.begin(); i != DB.end(); i++)
	{
		if (*i == key)
		{
			//Item found in vector
			cout << "\nItem found " << key;
			return i;
		}
	}
	cout << "\nItem not found " << key;
	//return NULL;
}
void vlist::Insert(const string& key)
{
	//Adds an item to the vector and to arrange
	//in order sort() is used from algorithm header
	DB.push_back(key);
	sort(DB.begin(), DB.end());
	count++;
}
void vlist::Remove(string key)
{
	//Removes an item from the vector if it is there
	//otherwise prints a message stating it was not in vector
	if (!is_Empty())
	{
		vector<string>::iterator i = Search(key);
		if (*i == key) {
			//Item found in vector
			DB.erase(i);//Deleting item
			count--;
		}
		else
			cout << "\nItem not found in vector";
	}
	else
		cout << "\nVector is empty";
}
void vlist::Print()
{
	//Prints vector elements using iterator
	vector<string>::iterator i;
	for (i = DB.begin(); i != DB.end(); i++)
		cout << endl << *i;
}
