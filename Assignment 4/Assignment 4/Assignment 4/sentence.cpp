#include <iostream>
#include <string>
#include "sentence.h"
using namespace std;

//*************************************************************************************
//Name: sentence (default)
//Precondition: no precondition.
//Postcondition: empty sentence list created.
//Description: creates an empty list. 
//*************************************************************************************

sentence::sentence()
{
	front = NULL;
	back = NULL;
}

//*************************************************************************************
//Name: sentence (explicit value)
//Precondition: parameters has been created and initialized.
//Postcondition: filled list is created.
//Description: creates a linked list consisting of the words and spaces to make a sentence.
//*************************************************************************************

sentence::sentence(const string& s)
{
	front = NULL;
	back = NULL;
	int j = 0;

	//goes through the entire string
	for (int i = 0; i < s.length(); i++)
	{
		//find a blank space in the string
		if (s[i] == *" ") 
		{
			if (i - j != 0)
			{
				add_back(s.substr(j, i - j));
			}
			add_back(s.substr(i, 1)); 
			j = i + 1;
		}
		//makes sure to add the term that is at the end of the string since there is no white space after it.
		if (i == s.length() - 1 && s[i] != *" ")
		{
			add_back(s.substr(j));
		}
	}
}

//*************************************************************************************
//Name: sentence (copy constructor)
//Precondition: sentence object is created and initialized.
//Postcondition: sentence object copied into new object.
//Description: copies the object that was passed on through a parameter into a new object.
//*************************************************************************************

sentence::sentence(const sentence& org)
{
	//allocates space for temporary variables
	word* tempA = new word;
	word* tempB = new word;

	//allocates space for front variable
	this->front = new word; //allocates space for front variable
	tempB = org.front;
	this->front = tempA; 

	//while loop to keep going through the original linked list untill it hits the end
	while (tempB != NULL)
	{
		tempA->term = tempB->term; 
		tempB = tempB->next; 

		//goes in if a pointer is not yet at the end after moving to the next node.
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
}

//*************************************************************************************
//Name: length
//Precondition: object sentence has been created and initialized.
//Postcondition: int is returned.
//Description: returns the length of the sentence that is made from the sentence list.
//*************************************************************************************

int sentence::length()
{
	int count = 0;

	//checks if there is anything in the list
	if (this->front == NULL) 
	{
		return 0;
	}
	else
	{
		word* temp = new word; 
		temp = this->front; 

		while (temp != NULL)
		{
			count = count + temp->term.length(); 
			temp = temp->next; 
		}
		return count;
	}
}

//*************************************************************************************
//Name: overload<< (overload operator with chaining)
//Precondition: object sentence and output variable are created and initialized.
//Postcondition: operator is overloaded with chaining.
//Description: Overloads << operator to diplay sentence object with ability for chaining.
//*************************************************************************************

ostream& operator<<(ostream& out, const sentence& org)
{
	//makes sure that object is not empty
	if (org.front == NULL) 
	{
		return out;
	}

	word* cWord = new word;
	cWord = org.front;

	while (cWord != NULL) 
	{
		if (cWord->term.length() != 0) 
		{
			out << cWord->term;
		}

		cWord = cWord->next;
	}

	return out;
}

//*************************************************************************************
//Name: ~sentence(destruction operator)
//Precondition: sentence object has been created and initialized.
//Postcondition: sentence object is deleted.
//Description: dealocates memory from the sentence object.
//*************************************************************************************

sentence::~sentence()
{
	cout << "Destructor has been called\n";

	//creating a new temporary variable
	word* d = new word; 
	while (front != 0)
	{
		d = front; 
		front = front->next; 
		delete d; 
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
	//checks the size before moving on to next step
	if (this->length() != B.length()) 
	{
		return 0;
	}

	word* tempA = new word;
	word* tempB = new word;

	tempA = this->front;
	tempB = B.front;

	while (tempA != NULL && tempB != NULL)
	{
		if (tempA->term != tempB->term) 
		{
			return 0;
		}
		else
		{
			tempA = tempA->next;
			tempB = tempB->next;
		}
	}
	return 1;
}

//*************************************************************************************
//Name: add_back
//Precondition: sentence object has been created and initialized, string parameter has been created and initialized.
//Postcondition: terms are added to the list.
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
		newWord->next = NULL; 
		newWord->term = s; 
		back->next = newWord;
		back = newWord;
	}
}


//*************************************************************************************
//Name: operator=(overload operator with string)
//Precondition: sentence object has been created and initialized, string parameter has been created and initialized.
//Postcondition: =operator is overloaded.
//Description: overloads = operator to set the sentence object to have a term equal to the string parameter.
//*************************************************************************************

void sentence::operator=(const string& s) 
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
//Precondition: two sentence objects have been creaeted and initialized.
//Postcondition: = operator has been overloaded.
//Description: Overloads = operator to set one sentence object equal to another.
//*************************************************************************************

sentence& sentence::operator=(const sentence& w) //essentially the same as copy constructor.
{
	//checks if the object is empty or not before moving to the next step
	if (w.front == NULL) 
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
	//checks of object on the right is empty before moving to the next step
	if (B.length() == 0) 
	{
		return;
	}
	else if (this->length() == 0)  
	{
		*this = B; 
		return;
	}

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
//Precondition: sentence object has been created and initialized, string parameter has been created and initialized.
//Postcondition: a term is removed from the linked-list.
//Description: Removes the first instance of a term that is equal to the given parameter.
//*************************************************************************************

void sentence::remove(const string& s)
{
	word* tempA = new word;
	word* tempB = new word;

	//checking if either the object or the string are empty
	if (s.length() == 0 || this->length() == 0) 
	{
		return;
	}

	tempA = this->front;
	tempB = tempA->next;
	
	//when the first term is the one we are looking for
	if (tempA->term == s)  
	{
		this->front = tempB; 

		if (tempA != NULL)
		{
			delete tempA; 
		}
		return;
	}

	while (tempB != NULL)
	{

		if (tempB->term == s && tempB != back) 
		{
			tempA->next = tempB->next; 

			if (tempB != NULL)
			{
				delete tempB; 
			}
			return;

		}
		else
		{
			tempB = tempB->next; 
			tempA = tempA->next;
		}

		//a case where match was found and is the last element
		if (tempB->term == s && tempB == back) 
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