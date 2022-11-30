/***********************************PROGRAM HEADER************************************************
Name: Steven Fernandez                        TOTAL POINTS:  25                DUE DATE:  03/12/2021
COURSE:  COP3530
Assignment Name:  Assignment#6                Professor:  Dr. Bullard

Description: This program accesses your C++language skills.
             After completing this assignment you will be able to perform the following:

	         (1) Manage a vector(allocatm and de-allocate memory, insert inorder, remove, etc).
	         (2) Implement a default constructor and a copy constructor.
	         (3) Implement an insert function to add a string, in order, into a vector
	         (4) Implement a remove function to delete a string from a vector
*********************************************************************************************/

#include <iostream>
#include <string>
#include "vlist.h" 
using namespace std;

int main()
{

	//Testing default constructor
	cout << "***********************************************************" << endl;
	cout << "Test1:Testing the default constructor for string\n";
	vlist String_List;
	cout << "\n*****************End of Test1******************************" << endl;
	//Testing functionality for string list 
	cout << "\n***********************************************************" << endl;
	cout << "Test2: Testing Insert \n";
	String_List.Insert("Hello");
	String_List.Insert("Zebra");
	String_List.Insert("Good_Bye");
	String_List.Insert("Space");
	String_List.Insert("No_One");
	String_List.Print();
	cout << "\n*****************End of Test2******************************" << endl;
	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "Test 3: Testing copy constructor for string \n";
	vlist Copied_String = String_List;
	Copied_String.Print();
	String_List.Print();
	cout << "\n*****************End of Test3******************************" << endl;
	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "Test 4: Testing Remove for string \n";
	cout << "Testing Search and IsEmpty also\n";
	String_List.Remove("Zebra");
	String_List.Remove("Good_Bye");
	String_List.Remove("Hello");
	String_List.Remove("No_One");
	String_List.Remove("Space");
	String_List.Remove("Hello");

	if (String_List.is_Empty())
	{
		cout << "String_List is Empty!" << endl;
	}
	else
	{
		cout << "String_List is NOT Empty!" << endl;
	}
	cout << "*****************End of Test4******************************" << endl;
	cout << endl << endl;
	cout << "When leave main destructor will be called" << endl;

	return 0;
}
