#include<iostream>
#include<string>
#include "string_class.h"

using namespace std;

//*************************************************************************************
//Name: string_class()
//Precondition: There must be zero arguments in the constructor.
//Postcondition: Initialize object with current_string value = null
//Description: This is a no argument constructor and returns empty current_string
//
//*************************************************************************************

string_class::string_class()

{
    current_string = "";
}

//*************************************************************************************
//Name:string_class(string s)
//Precondition:There must be an arguments in the constructor.
//Postcondition: Initialize object with current_string value with string s
//Description:This is a parameterized constructor and returns current_string by initializing with the input string
//
//*************************************************************************************

string_class::string_class(string arg)

{
    current_string = arg;
}

//*************************************************************************************
//Name:palindrome()
//Precondition:Current string should not be null
//Postcondition: returns boolean value (true or false)
//Description: This checks the input string is palindrome or not
//
//*************************************************************************************

bool string_class::palindrome()

{
    int i = 0;

    int j = current_string.length() - 1;

    //Creates loop for cuurent_string that checks for palidrome

    while (i < j)

    {
        //If the current string is not a

        //palindrome then, return false.

        if (current_string[i] != current_string[j])

        {
            return false;
        }

        i++;

        j--;

    }

    //Returns true if string is palindrome
    return true;

}

//*************************************************************************************
//Name:replace_all
//Precondition:old_string and new_string cannot be null
//Postcondition: must replace old_string with new_string
//Description: This function replaces the old_string with the new_string
//
//*************************************************************************************

string string_class::replace_all(string old_substring, string new_substring)

{
    int i = 0;

    //Define a variable to store the length of the old_substring.

    int repl_len = old_substring.length();

    //Runs the loop to modify current_string.

    while (i < current_string.length())
    {
        int curr_pos = i;
        string curr_sub = "";

        //Get the current substring.

        for (int j = curr_pos; j < curr_pos + repl_len; j++)
        {
            curr_sub = curr_sub + current_string[j];
        }

        //create if function to replace new substring with the old substring if its equal.

        if (curr_sub == old_substring)
        {
            string new_string = "";

            for (int l = 0; l < curr_pos; l++)
            {
                new_string += current_string[l];
            }

            new_string += new_substring;

            for (int l = curr_pos + repl_len; l < current_string.length(); l++)
            {
                new_string += current_string[l];
            }

            current_string = new_string;

        }

        i++;

    }

    //Return a copy of the current_string.

    return current_string;

}

//*************************************************************************************
//Name:ostream& operator<<(ostream& os, const string_class& str)
//Precondition: String with value null or not null
//Postcondition: inserts the sequence of characters that conforms value of str into os
//Description: This function overloads operator<< and returns os
//
//*************************************************************************************

ostream& operator<<(ostream& out, const string_class& obj)

{
    //Print the current_string

    //onto the output stream.

    out << obj.current_string << endl;

    return out;

}