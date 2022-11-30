#include <iostream>
#include <string>
#include <fstream>
#include "state.h"
#include <iomanip>  //need to use formatting manipulators
#include <math.h>

using namespace std;

/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Description:  The function initiailizes the state (private data) of the class state_class. It reads the data stored in the datafile "census2020_data.txt"
			  into the dynamic array, pop_DB.  Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
			  double_size is called, which doubles the capacity of pop_DB.

**********************************************************************************************************************************************************/
state_class::state_class()
{
	//intially count, capacity, and pop_DB are initialized with the following values:
	cout << "The default constructor has been called." << endl;
	count = 0;
	capacity = 5;
	pop_DB = new population_record[capacity];
	ifstream in;
	string line;
	in.open("census2020_data.txt");
	while (!in.eof())
	{
		while (getline(in, line)) 
		{
			bool completedState = false; 
			for (int j = line.length(); j > 0; j--) 
			{
				if (!completedState && line[j] == ' ') 
				{
					if (Is_Full()) 
					{
						double_size();
					}
					completedState = true; 
					pop_DB[count].population = stoi(line.substr(j));
					pop_DB[count].state_name = line.substr(0, j);
					count++;
				}
			}
		}
	}
	

}

/******************************************************************************************************************************************************
Name: copy constructor
Pre-Condition: The following have not been initialized: count, capacity, and the dynamic array (pop_DB) 
Post-Condition: The following have been initialized : count, capacity, and the dynamic array (pop_DB)
Description: Performs a deep copy. 
******************************************************************************************************************************************************/
state_class::state_class(const state_class& org)
{
	
	count = org.count;
	capacity = org.capacity;
	pop_DB = new population_record[capacity];
	for (int i = 0; i < count; i++)
	{
		pop_DB[i] = org.pop_DB[i];
	}

}

/******************************************************************************************************************************************************
Name: destructor
Pre-Condition: Nothing has been de-allocated or removed.
Post-Condition: All memory allocated to pop_DB has been removed
Description: De-allocates all memory allocated to pop_DB.
******************************************************************************************************************************************************/
state_class::~state_class()
{
	cout << "The destructor has been called." << endl;

	delete[] pop_DB;
	capacity = 0;
	count = 0;
}




/******************************************************************************************************************************************************
Name: double_size
Pre-Condition: Parameters not doubled.
Post-Condition: Parameters doubled. 
Description: Doubles the size (capacity) of INV
******************************************************************************************************************************************************/
void state_class::double_size()
{
	capacity *= 2;
	population_record* temp = new population_record[capacity];
	for (int i = 0; i < count; i++) 
	{
		temp[i] = pop_DB[i];
	}
	delete[] pop_DB;
	pop_DB = temp;
}

/******************************************************************************************************************************************************
Name: operator+
Pre-Condition: No population record in dynamic array.
Post-Condition: Population record included in dynamic array.
Description: Overload operator+ without chaining.  The function inserts a 
popultation record into the population dynamic array (pop_DB)
******************************************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
	if (Is_Full()) 
	{
		double_size();

	}
	pop_DB[count++] = r;
}

/******************************************************************************************************************************************************
Name: Search
Pre-Condition: Not yet located.
Post-Condition: Located and returned.
Description: Locates (state) in pop_DB if it's there, otherwise -1 is returned.
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{
	for (int i = 0; i < count; i++) {
		if (pop_DB[i].state_name == state)
		{
			return i;
		}
	}
	return -1;
}


/******************************************************************************************************************************************************
Name: Remove 
Pre-Condition: State name passed. 
Post-Condition: Matched state names removed.
Description: Deletes a population record from pop_DB if 
the key field matches the state name
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{
	int target = Search(state);
	while (target != -1)
	{
		for (int i = target; i < count - 1; i++)
		{
			pop_DB[i] = pop_DB[i + 1];
		}
		count--;
		target = Search(state);
	}
}


/******************************************************************************************************************************************************
Name:Print_ALL_To_File
Pre-Condition: Filename passed.
Post-Condition: Write into file passed. 
Description: Prints all the fields of all the population records stored 
in pop_DB to the filename stored in datafile
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{
	ofstream out(filename);
	out.precision(0);
	out.setf(ios::fixed);
	if (out.is_open())
	{
		for (int i = 0; i < count; i++)
		{
			out << left << setw(20) << pop_DB[i].state_name << right << setw(20) << pop_DB[i].population << endl;
		}
	}
}
/******************************************************************************************************************************************************
Name:Print_ALL
Pre-Condition: Populates an array.
Post-Condition: Prints records.
Description: Prints all the fields of all the population records 
stored in pop_DB to the screen.
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{
	cout.precision(0);
	cout.setf(ios::fixed);

	for (int i = 0; i < count; i++) 
	{
		cout << left << setw(20) << pop_DB[i].state_name << "" << pop_DB[i].population << endl;
	}
}


/******************************************************************************************************************************************************
Name: Print_Range 
Pre-Condition: Min and max range of population not passed. 
Post-Condition: Pass min and max of population 
Description: Prints all the fields of all the population records stored in pop_DB with a 
population between min and max to the screen
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
	for (int i = 0; i < count; i++) 
	{
		if (pop_DB[i].population > min && pop_DB[i].population < max) 
		{
			cout << left << setw(20) << pop_DB[i].state_name << "" << pop_DB[i].population << endl;
		}
	}
}


/******************************************************************************************************************************************************
Name: State_Count 
Pre-Condition: Min and max not returned. 
Post-Condition: Min and max returned with total number of states. 
Description: Returns the total number of states with a population
between min and max, inclusive.
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
	int sum = 0;
	for (int i = 0; i < count; i++) 
	{
		if (pop_DB[i].population >= min && pop_DB[i].population <= max) 
		{
			sum++;
		}
	}
	return sum;
}

/******************************************************************************************************************************************************
Name: Sort 
Pre-Condition:Array pop_DB not sorted.
Post-Condition: Sorted array pop_DB.
Description: Sorts the array pop_DB in alphabetical order based on state_name 
field using insertion sort algorithm
******************************************************************************************************************************************************/
void state_class::Sort()
{
	population_record key;
	for (int i = 0; i < count; i++) 
	{
	    key = pop_DB[i];
		int j = i - 1;
		while (j >= 0 && pop_DB[j].state_name > key.state_name)
		{
			pop_DB[j + 1] = pop_DB[j];
			j--;
		}
		pop_DB[j + 1] = key;
	}

}