/***********************************PROGRAM HEADER************************************************
Name: Steven Fernandez                        TOTAL POINTS:  25                DUE DATE:  03/26/2021
COURSE:  COP3530
Assignment Name:  Assignment Module 10        Professor:  Dr. Bullard

Description: (1)A recursive boolean function called palindrome that accept sonestring argument(fortheuser) and returns 
                true if the string reads the same forward as it does backwards.
			 (2)A recursive function called printReverse that accepts one string argument(fortheuser) and returns the reverse of that string.
			 (3)A non-recursive function called printIterReverse that accepts one string argument(fromtheuser) and returns the reverse of that string.
*********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

bool palindrome(const string& s) { return true; };
string  printReversel(const string& s) { return s; };
string printIterReverse(const string& s) { return s; };

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: palindrome
//Precondition: user entered string
//Postcondition: string has been checked if is palindrome
//Description: Returns true or false based on if a string is a palindrome or not
///////////////////////////////////////////////////////////////////////////////////////////////
bool palindrome(string& s)
{
	string palindromeString;
	if (s.length() == 1 || s.length() == 0) //if length of string is 0 or 1
	{
		return true;
	}
	else if (s[0] == s[s.length() - 1]) //if the first character and the last character are the same
	{
		palindromeString = s.substr(1, s.length() - 2); // removes the front and back of string
		return palindrome(palindromeString); //calls the function again
	}
	else //otherwise it is false
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: palindrome
//Precondition: user entered string
//Postcondition: string has been reversed recursively
//Description: Returns the reversed string recursively
///////////////////////////////////////////////////////////////////////////////////////////////
string printReversel(string& s)
{
	if (s.length() == 1 || s.length() == 0)
	{
		return s;
	}
	else
	{
		string updatedString = s.substr(0, s.length() - 1); //store the string with one less character at the end, apple becomes appl
		return s[s.length() - 1] + printReversel(updatedString); //call the function again while also adding the last character of the string
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: printIterReverse
//Precondition: user entered string
//Postcondition: string has been reversed iteratively
//Description: Returns a reversed string iteratively
///////////////////////////////////////////////////////////////////////////////////////////////
string printIterReverse(string& s)
{
	string reversedString;
	for (int i = s.length() - 1; i >= 0; i--) //start at the back, continue as long as i is greater or equal to zero, decrement
	{
		reversedString += s[i]; //add the current index to the string
	}
	return reversedString;
}

int main()
{
	string s = "";
	string response = "y";

	while (response == "y" || response == "Y")
	{
		cout << " please enter string: ";
		getline(cin, s);
		if (palindrome(s) == true)
		{
			cout << s << " is a palindrome \n";
		}
		else
		{
			cout << s << " is a not palindrome \n";
		}

		cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
		cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
		cout << endl << "Do you wish to continue (y or Y for yes; n or N for no ? ";
		cin >> response;
		cin.ignore();
	}
	return 0;
}
