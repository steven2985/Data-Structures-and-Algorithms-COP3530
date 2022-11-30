
#include "state.h"
#include <iomanip>  //need to use formatting manipulators


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
	count = 0;
	capacity = 5;
	pop_DB = new population_record[capacity];

	//you finish the code....

}

/******************************************************************************************************************************************************
Name:
Pre-Condition: STATE WHAT IS TRUE BEFORE THE FUNCITON IS CALLED....
Post-Condition STATE WHAT IS TRUE AFTER THE FUNCITON EXECUTES....
Description: BRIEF DESCRIPTION OF WHAT THE FUNCTION DOES...
******************************************************************************************************************************************************/
state_class::state_class(const state_class & org)
{
	//place your code here
}

/******************************************************************************************************************************************************
Name:
Pre-Condition: STATE WHAT IS TRUE BEFORE THE FUNCITON IS CALLED....
Post-Condition STATE WHAT IS TRUE AFTER THE FUNCITON EXECUTES....
Description: BRIEF DESCRIPTION OF WHAT THE FUNCTION DOES...
******************************************************************************************************************************************************/
state_class::~state_class()
{

	//place your code here
}

/******************************************************************************************************************************************************
Name:
Pre-Condition
Post-Condition
Description:
******************************************************************************************************************************************************/
void state_class::double_size()
{

	//place your code here
}

/******************************************************************************************************************************************************
Name:
Pre-Condition
Post-Condition
Description:
******************************************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
	//place your code here
}

/******************************************************************************************************************************************************
Name:
Pre-Condition
Post-Condition
Description:
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{
	//place your code here
	return -1;
}


/******************************************************************************************************************************************************
Name:
Pre-Condition
Post-Condition
Description:
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{
	//place your code here
}


/******************************************************************************************************************************************************
Name:
Pre-Condition
Post-Condition
Description:
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{
	
	//place your code here
}
/******************************************************************************************************************************************************
Name:
Pre-Condition
Post-Condition
Description:
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{
	//place your code here
}


/******************************************************************************************************************************************************
Name:
Pre-Condition
Post-Condition
Description:
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
	//place your code here
}


/******************************************************************************************************************************************************
Name:
Pre-Condition
Post-Condition
Description:
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
	//place your code here
	return 0;
}

/******************************************************************************************************************************************************
Name:
Pre-Condition
Post-Condition
Description:
******************************************************************************************************************************************************/
void state_class::Sort()
{
	//place your code here

}
