/***********************************PROGRAM HEADER************************************************
Name: Steven Fernandez                        TOTAL POINTS:  25                DUE DATE:  03/26/2021
COURSE:  COP3530
Assignment Name:  Assignment Module 10B       Professor:  Dr. Bullard

Description: (1)Create a voidfunction called “add_back”that has three formal parameters.
             (2)The main program which createsa single-link list with a pointerto the front and a pointer to the back of the list.
             (3)Convert the “node” declaration and function “fun” implementationinto a C++ declaration and implementation, respectively.
*********************************************************************************************/

#include <iostream>
using namespace std;

struct node
{
public:
    int data;
    node* next;
};

/*Function Name : fun
Precondition : Declaration of a singly-linked list
Postcondition : Print the alternative nodes 
Description : This function prints the alternate nodes in a list forward and backwards
*/

void fun(struct node* start)
{
    if (start == NULL)
        return;
    cout << start->data << " ";
    if (start->next != NULL)
        fun(start->next->next);
    cout << start->data << " ";
}

/*Function Name : add_back
Precondition : The output of alternative nodes 
Postcondition : Passing all data as desire 
Description : Create new node, populate the data field, and set the next pointer
*/

void add_back(node*& front, node*& back, int x)
{
    // create new node that needs to be inserted
    node* new_node = new(node);
    //set the 'next' pointer of the node to NULL
    new_node->next = NULL;
    //populate the data field with the given element x
    new_node->data = x;

    if (front == NULL)
    {
        front = new_node;
        back = front;
    }
    else
    {
        back->next = new_node;
        back = new_node;
    }

}
int main()
{
    //Create a pointer to point to the start and end of the list
    node* front = 0, * back = 0;

    //Create a linked list 1->2->3->4->5->6
    for (int i = 1; i <= 6; i++)
    {
        add_back(front, back, i);
    }
    fun(front);
    return 0;
}



