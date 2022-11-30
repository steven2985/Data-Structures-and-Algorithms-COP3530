
#include "state.h"
#include <iomanip>  //need to use formatting manipulators

/**********************************************************************************************************************************************************
Name: Default Constructor
Pre - Conditon : The count, capacity, and the dynamic array(pop_DB) have not been initialized.
Post - Condition : The count, capacity, and the dynaic array(pop_DB) have been initialized.
Description : The function initiailizes the state(private data) of the class state_class.It reads the data stored in the datafile "census2020_data.txt"
into the dynamic array, pop_DB.Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.If pop_DB become full,
double_size is called, which doubles the capacity of pop_DB.

**********************************************************************************************************************************************************/
state_class::state_class()
{
    //intially count, capacity, and pop_DB are initialized with the following values:
    count = 0;
    capacity = 5;
    pop_DB = population_record[capacity];
    double_size();
}
/******************************************************************************************************************************************************
Name:Copy constructor
Pre-Condition: Allocated space for dynamic array
Post-Condition: Copied records
Description: copy a state class into this
******************************************************************************************************************************************************/
state_class::state_class(const state_class& s)
{
    //intially count, capacity, and pop_DB are initialized with the following values:
    count = 0;
    capacity = s.capacity;
    pop_DB = new population_record[capacity];
    for (int i = 0; i < s.count; i++) {
        pop_DB[count++] = s.pop_DB[i];
    }
}
/******************************************************************************************************************************************************
Name:Destructor
Pre-Condition: Allocate space for dynamic array
Post-Condition: Deallocate allocated space
Description: It used to freeing the unused allocated space from memory for further use
******************************************************************************************************************************************************/
state_class::~state_class()
{
    delete[] pop_DB;
}

/******************************************************************************************************************************************************
Name: Double Size
Pre-Condition: Checks the count and capacity
Post-Condition: Array capacity is doubled
Description: Check whether count reach capacity, then double capacity of the array
******************************************************************************************************************************************************/
void state_class::double_size()
{

    if (Is_Full()) {
        population_record* temp = pop_DB;
        capacity *= 2;
        pop_DB = new population_record[capacity];
        for (int i = 0; i < count; i++) {
            pop_DB[i] = temp[i];
        }
        delete[] temp;
    }
}

/******************************************************************************************************************************************************
Name:Insert
Pre-Condition: pass a record
Post-Condition: Add record to the next element
Description: Insert a new record at the end
******************************************************************************************************************************************************/
void state_class::Insert(const population_record& r)
{
    if (Is_Full()) {
        double_size();
    }
    pop_DB[count++] = r;
}

/******************************************************************************************************************************************************
Name:search
Pre-Condition:Pass a state name
Post-Condition: return index or -1
Description:search through array for state name match if found return index otherwise -1
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{
    for (int i = 0; i < count; i++) {
        if (pop_DB[i].state_name == state) {
            return i;
        }
    }
    return -1;
}


/******************************************************************************************************************************************************
Name:Remove
Pre-Condition: Pass a state name
Post-Condition: remove state name matched
Description: Search the matched state and remove it from array otherwise do nothind
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{
    int index = Search(state);
    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            pop_DB[i] = pop_DB[i + 1];
        }
        count--;
    }
}


/******************************************************************************************************************************************************
Name:Print_ALL_To_File
Pre-Condition: Pass filename
Post-Condition: write into pass file
Description: Write all data from the record to file
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{
    ofstream out(filename);
    for (int i = 0; i < count; i++) {
        out << pop_DB[i].state_name << pop_DB[i].population << endl;
    }
}
/******************************************************************************************************************************************************
Name:Print_ALL
Pre-Condition:Populated array
Post-Condition: write console
Description:Write population records in console
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{
    //adds in formatting output
    for (int i = 0; i < count; i++) {
        cout << pop_DB[i].state_name << pop_DB[i].population << endl;
    }
}


/******************************************************************************************************************************************************
Name:Print_Range
Pre-Condition: Pass min and max range of population
Post-Condition: Display accordingly
Description:Check the population between min and max then display on console
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
    //cout.width(20); //adds in formatting output
    for (int i = 0; i < count; i++) {
        if (pop_DB[i].population > min && pop_DB[i].population < max) {
            cout << pop_DB[i].state_name << setw(20) << pop_DB[i].population << endl;
        }
    }
}


/******************************************************************************************************************************************************
Name:State_Count
Pre-Condition: min and max population
Post-Condition: count of states with in this range
Description:Check the records of states compare with population match increment count and return count
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
    int s_count = 0;
    for (int i = 0; i < count; i++) {
        if (pop_DB[i].population >= min && pop_DB[i].population <= max) {
            s_count += 1;
        }
    }
    return s_count;
}
/******************************************************************************************************************************************************
Name:Sort
Pre-Condition: an unsorted array
Post-Condition: sorted array
Description: Function use to sort according to population
******************************************************************************************************************************************************/
void state_class::Sort() {
    for (int i = 1; i <= count; i++) {
        population_record key = pop_DB[i];;
        int j = i - 1;
        while (j >= 0 && pop_DB[j].population > key.population) {
            pop_DB[j + 1] = pop_DB[j];
            j = j - 1;
        }
        pop_DB[j + 1] = key;
    }