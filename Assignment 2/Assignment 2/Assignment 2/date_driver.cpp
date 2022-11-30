/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Steven Fernandez                              TOTAL POINTS:  25                DUE DATE:  01/29/2021
COURSE:  COP 3530
Assignment Name:  Assignment#2                 Professor:  Dr. Bullard

Description:  The program manages a dynamic array of records.
******************************************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "date.h"

using namespace std;

int main()
{

	Date myDate;
	Date herDate(11, 14, 1953);
	Date test1Date(25, 1, 1982); //should generate error message that bad month
	Date test22Date(2, 29, 2020); //ok, should say leep year
	Date test3Date(2, 30, 2021); //should generate error message that bad day
	Date test4Date(1, 25, 0000); //should generate error message that bad year
	Date test5Date(80, 40, 0000); //should generate error message that bad month, day and year

	herDate.display();
	cout << herDate.getMonth() << endl;
	cout << herDate.getDay() << endl;
	cout << herDate.getYear() << endl;
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout << "myDate: " << myDate << " test22Date: " << test22Date << " herDate: " << herDate << endl;

	return 0;

}
