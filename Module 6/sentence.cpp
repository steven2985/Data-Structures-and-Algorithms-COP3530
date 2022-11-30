#include <iostream>
#include <string>
#include "sentence.h"
using namespace std;

//*************************************************************************************
//Name: sentence (default)
//Precondition: no precondition
//Postcondition: empty sentence list created
//Description: creates an empty list 
//*************************************************************************************

sentence::sentence()
{
	front = NULL;
	back = NULL;
}

//*************************************************************************************
//Name: sentence (explicit value)
//Precondition: parameters has been created and initialized.
//Postcondition: filled list is created
//Description: creates a linked list consisting of the words and spaces to make a sentence.
//*************************************************************************************

sentence::sentence(const string& s)
{
	front = NULL;
	back = NULL;
	int j = 0; 
	for (int i = 0; i < s.length(); i++) //goes through the entire string
	{
		if (s[i] == *" ") //find a blank space in the string
		{
			if (i - j != 0) //makes sure that it doesn't add NULL nodes to the linked list when multiple white spaces go one after another in a string
			{
				add_back(s.substr(j, i - j)); //separates a term
			}
			add_back(s.substr(i, 1)); //separates a blank space as a separate term
			j = i + 1; 
		}
		if (i == s.length() - 1 && s[i] != *" ") //makes sure to add the term that is at the end of the string since there is no white space after it.
		{
			add_back(s.substr(j));
		}
	}
}

//*************************************************************************************
//Name: sentence (copy constructor)
//Precondition: sentence object is created and initialized
//Postcondition: sentence object copied into new object
//Description: copies the object that was passed on through a parameter into a new object.
//*************************************************************************************

sentence::sentence(const sentence& org)
{
	word* tempA = new word; //allocates space for temporary variables
	word* tempB = new word;

	this->front = new word; //allocates space for front variable
	tempB = org.front; 
	this->front = tempA; //makes temporary variable point toward the originial

	while (tempB != NULL) //keeps going through the original linked list untill it hits the end
	{
		tempA->term = tempB->term; //copies terms
		tempB = tempB->next; //moves to a next term

		if (tempB != NULL) //goes in if a pointer is not yet at the end after moving to the next node.
		{
			tempA->next = new word; //allocates space for the new node
			tempA = tempA->next; //moves to a next term/node
		}
		else
		{
			this->back = tempA; //set the back of the new copied sentence to be its last word
			break;
		}
	}
}

//*************************************************************************************
//Name: length
//Precondition: object sentence has been created and initialized
//Postcondition: int is returned.
//Description: returns the length of the sentence that is made from the sentence list.
//*************************************************************************************

int sentence::length()
{
	int count = 0;
	if (this->front == NULL) //checks if there is anything in the list
	{
		return 0;
	}
	else
	{
		word* temp = new word; //temporary value
		temp = this->front; //have temp point to the front

		while (temp != NULL)
		{
			count = count + temp->term.length(); //increases count by the lenght of each term
			temp = temp->next; //move to a next node/term
		}
		return count;
	}
}

//*************************************************************************************
//Name: overload<< (overload operator with chaining)
//Precondition: object sentence and output variable are created and initialized
//Postcondition: operator is overloaded with chaining
//Description: Overloads << operator to diplay sentence object with ability for chaining.
//*************************************************************************************

ostream& operator<<(ostream& out, const sentence& org)
{
	if (org.front == NULL) //makes sure that object is not empty
	{
		return out;
	}

	word* cWord = new word;
	cWord = org.front;

	while (cWord != NULL) //goes through the enitre list
	{
		if (cWord->term.length() != 0) //makes sure that the word is not empty
		{
			out << cWord->term; //outputs the term to the stream
		}

		cWord = cWord->next; //moves to a next node/term
	}

	return out;
}

//*************************************************************************************
//Name: ~sentence(destruction operator)
//Precondition: sentence object has been created and initialized
//Postcondition: sentence object is deleted
//Description: dealocates memoery from the sentence object.
//*************************************************************************************

sentence::~sentence()
{
	cout << "Destructor has been called\n"; 

	word* d = new word; //creates a new temporary variable
	while (front != 0) 
	{ 
		d = front; //sets the d value to the current word
		front = front->next; //moves to the next node/word
		delete d; //dealocates memory for the previous word.
	}
}

//*************************************************************************************
//Name: isEqual
//Precondition: sentence object has been created and initialized
//Postcondition: bool value is returned
//Description: returns true if two objects are equal and false if they are not.
//*************************************************************************************

bool sentence::isEqual(sentence& B)
{
	if (this->length() != B.length()) //checks the size before moving on
	{
		return 0;
	}

	word* tempA = new word;
	word* tempB = new word;

	tempA = this->front; 
	tempB = B.front;

	while (tempA != NULL && tempB != NULL)
	{
		if (tempA->term != tempB->term) //compares terms
		{
			return 0;
		}
		else
		{
			tempA = tempA->next; //moves to the next node/word/term
			tempB = tempB->next;
		}
	}
	return 1;
}

//*************************************************************************************
//Name: add_back
//Precondition: sentence object has been created and initialized, string parameter has been created and initialized.
//Postcondition: terms are added to the list
//Description: adds terms to the end of the linked list by creating new nodes and assigning values to them.
//*************************************************************************************

void sentence::add_back(const string& s)
{
	if (front == NULL)
	{
		front = new word; //allocates space
		front->term = s; //sets term to the passed string
		front->next = NULL; //moves a NULL character to the next node
		back = front; 
	}
	else
	{
		word* newWord = new word;
		newWord->next = NULL; //moves NULL to a next node
		newWord->term = s; //sets term to the passed string
		back->next = newWord; 
		back = newWord;
	}
}


//*************************************************************************************
//Name: operator=(overload operator with string)
//Precondition: sentence object has been created and initialized, string parameter has been created and initialized
//Postcondition: =operator is overloaded
//Description: overloads = operator to set the sentence object to have a term equal to the string parameter.
//*************************************************************************************

void sentence::operator=(const string& s) //essentially the same as explicit value constructor
{
	front = NULL;
	back = NULL;

	int j = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == *" ")
		{
			if (i - j != 0)
			{
				add_back(s.substr(j, i - j));
			}
			add_back(s.substr(i, 1));
			j = i + 1;
		}
		if (i == s.length() - 1 && s[i] != *" ")
		{
			add_back(s.substr(j));
		}
	}
}

//*************************************************************************************
//Name: operator=(overload operator with sentence)
//Precondition: two sentence objects have been creaeted and initialized
//Postcondition: = operator has been overloaded
//Description: Overloads = operator to set one sentence object equal to another.
//*************************************************************************************

sentence& sentence::operator=(const sentence& w) //essentially the same as copy constructor.
{
	if (w.front == NULL) //checks if the object is empty or not
	{
		this->front = NULL;
		return *this;
	}

	word* tempA = new word;
	word* tempB = new word;

	this->front = new word;
	tempB = w.front;
	this->front = tempA;

	while (tempB != NULL)
	{
		tempA->term = tempB->term;
		tempB = tempB->next;

		if (tempB != NULL)
		{
			tempA->next = new word;
			tempA = tempA->next;
		}
		else
		{
			this->back = tempA;
			break;
		}
	}
	return *this;
}

//*************************************************************************************
//Name: operator+(overload operator with a sentence)
//Precondition: two sentence objects have been created and initialized
//Postcondition: + operator is overloaded 
//Description: overloads + operator to be able to merge one sentence object into the other 
//*************************************************************************************

void sentence::operator+(sentence& B)
{
	if (B.length() == 0) //checks of object on the right is empty
	{
		return;
	}
	else if (this->length() == 0)  //checks if object on the left is empty
	{
		*this = B; //completely copies over the object
		return;
	}
	//from this point down its essentially the same as add-back function
	word* tempA = new word;
	word* tempB = new word;

	tempA = this->back;
	tempB = B.front;


	while (tempB != NULL)
	{
		tempA->next = new word; //allocates memory for the new node
		tempA = tempA->next; //moves to the next node
		tempA->term = tempB->term; //copies over a term
		tempB = tempB->next;
	}
}

//*************************************************************************************
//Name: remove
//Precondition: sentence object has been created and initialized, string parameter has been created and initialized
//Postcondition: a term is removed from the linked-list
//Description: Removes the first instance of a term that is equal to the given parameter.
//*************************************************************************************

void sentence::remove(const string& s)
{
	word* tempA = new word;
	word* tempB = new word;

	if (s.length() == 0 || this->length() == 0) //checks if either the object or the string are empty
	{
		return;
	}

	tempA = this->front;
	tempB = tempA->next;

	if (tempA->term == s)  //scenario when the first term is the one we are looking for
	{
		this->front = tempB; //just moves the front to the right making tempB the new front.

		if (tempA != NULL)
		{
			delete tempA; //deletes the old front
		}
		return;
	}

	while (tempB != NULL) 
	{

		if (tempB->term == s && tempB != back) // found a term that is not the last element in the list
		{
			tempA->next = tempB->next; //back element's next pointer is the front next pointer

			if (tempB != NULL)
			{
				delete tempB; //delete's the matching element
			}
			return;

		}
		else 
		{
			tempB = tempB->next; //moves to a next node
			tempA = tempA->next;
		}

		if (tempB->term == s && tempB == back) //a scenario where match was found and is the last element
		{
			tempA->next = tempB->next; //back element's next pointer is the fronts next pointer
			back = tempA; //back is now equal to the term before the last term
			back->next = NULL; //last term is set to NULL

			if (tempB != NULL)
			{
				delete tempB; //deletes matching element
			}
			return;
		}
	}
}

