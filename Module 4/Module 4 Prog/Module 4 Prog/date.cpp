#include "date.h"
#include <iomanip>
//*************************************************************************************
//Name:	Is_Valid
//Precondition: Take in three unsigned integer
//Postcondition: return an intger a if the parameters are not met 
//Description: This function is take in the three unsigned and verify that they match
//
//
//*************************************************************************************
int Is_Valid(unsigned m, unsigned d, unsigned y)
{
	int a = 0;
	if (m < 1 || m > 12)
	{
		a = 2;
		cout << "Month = " << setw(2) << m << " is incorrect" << endl;

	}
	if (d < 0 || d > 31)
	{
		a = 3;
		cout << "day = " << setw(2) << d << " is incorrect" << endl;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) 
	{
		if (d > 31 || d < 0) 
		{
			a = 4;
			cout << "day = " << setw(2) << d << " is incorrect" << endl;
		}
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d > 30 || d < 0)
		{
			a = 4;
			cout << "day = " << setw(2) << d << " is incorrect" << endl;
		}
	}
	if (m == 2 )
	{
		if(d == 29 && y % 4 != 0)
		{
			a = 5;
			cout << "day = " << setw(2) << d << " is incorrect" << endl;
		}
		if (d > 29)
		{
			a = 5;
			cout << "day = " << setw(2) << d << " is incorrect" << endl;
		}
	}
	if (y < 1 || y > 9999)
	{
		a = 1;
		cout << "Year = " << setw(4) << y << " is incorrect" << endl;
	}
	if (a > 0)
	{
		cout << endl;
	}
	return a;
}
//*************************************************************************************
//Name:	Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description:	This is the default constructor which will be called automatically when
//an object is declared.	It will initialize the state of the class
//
//*************************************************************************************
Date::Date()
{
	cout << "Default constructor has been called" << endl;
	myDay = 01;
	myMonth = 01;
	myYear = 0001;
	display();
}


//*************************************************************************************
//Name:	Date
//Precondition: To take in three unsigned intgers
//Postcondition: Verify they matich the parameters in the and match the function Is_Valid 
//Description:
//
//
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << "Explicit-value constructor has been called" << endl;
	if (Is_Valid(m, d, y) == 0)
	{
		myMonth = m;
		myDay = d;
		myYear = y;
		display();
	}
}

//*************************************************************************************
//Name:	Display
//Precondition: There are no precondition
//Postcondition: To print myYear,myDay and myMonth in this format 00\00\0000
//Description: To print myYear, myDay andd myMonth
//
//
//*************************************************************************************
void Date::display()
{
	cout << setfill('0') << setw(2) << myMonth << "\\" << setw(2) << myDay << "\\" << setw(4) << myYear << endl;
	if (myYear > 0 && myYear % 4 == 0)
	{
		cout << "This is a leap year " << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
	}
}

//*************************************************************************************
//Name:	getMonth
//Precondition:There are no precondition
//Postcondition:The post is to return myMonth
//Description: There are no precondition and the post condition are to return getMonth
//
//
//*************************************************************************************
int Date::getMonth()
{
	return myMonth;
}

//*************************************************************************************
//Name:	getDay
//Precondition: There are no precondition
//Postcondition: The post is to return myDay
//Description: There are no precondition and the post condition are to return getMonth
//
//
//*************************************************************************************
int Date::getDay()
{
	return myDay;
}

//*************************************************************************************
//Name:	getYear
//Precondition: There are no precondition
//Postcondition: The post is to return myYear
//Description: There are no precondition and the post condition are to return myYear
//

//
//
//*************************************************************************************
int Date::getYear()
{
	return myYear;
}

//*************************************************************************************
//Name: setMonth
//Precondition: To Take in a unsigned value m and asigne it to myMonth
//Postcondition: The post is to set month
//Description: To take in a unsigned value and asign it to myMonth
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	if (Is_Valid(m, myDay, myYear) == 0)
	{
		myMonth = m;
	}
}

//*************************************************************************************
//Name:	setDay
//Precondition: To Take in a unsigned value d and asigne it to myDay
//Postcondition: The post is to set myDay
//Description:  To take in a unsigned value and asign it to myDay
//
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
	if (Is_Valid(myMonth, d, myYear) == 0)
	{
		myDay = d;
	}
}

//*************************************************************************************
//Name:	getYear
//Precondition: To Take in a unsigned value y and asigne it to myYear
//Postcondition: The post is to set myYear
//Description: To take in a unsigned value and asign it to myDYear
//
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	if (Is_Valid(myMonth, myDay, y) == 0)
	{
		myYear = y;
	}
}
//*************************************************************************************
//Name:	operator<<
//Precondition: to take in stream address and data object
//Postcondition: post the stream into the object
//Description: To take a data class and stream into an object
//
//
//*************************************************************************************
ostream& operator<<(ostream& out, Date& dateObj)
{
	out << setfill('0') << setw(2) << dateObj.myMonth;
	out << "\\";
	out << setfill('0') << setw(2) << dateObj.myDay;
	out << "\\";
	out << setfill('0') << setw(4) << dateObj.myYear;
	return out;
}