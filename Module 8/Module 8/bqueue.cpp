/***********************************PROGRAM HEADER************************************************
Name: Steven Fernandez                        TOTAL POINTS:  25                DUE DATE:  03/12/2021
COURSE:  COP3530
Assignment Name:  Assignment#6                Professor:  Dr. Bullard

Description: (1)manipulatepointers, (2)allocatememorydynamically, 
             (3)implementadefaultconstructor,copyconstructoranddestructor, 
             (4)useonlyonepointertoaddtothebackandtodeletefromthefrontofthequeue.
*********************************************************************************************/

#include "BQUEUE.h"
#include <iostream>
using namespace std;

/*Function Name : BQUEUE
Precondition : state of class has not be initialized
Postcondition : state has been initialized
Description : default constructor sets back to NULL. 
*/

BQUEUE::BQUEUE()
{
    front = NULL;
}

/*Function Name: Print
Precondition: Print function gets called.
Postcondition: the integers in the nodes are cout
Description: if back is equal to 0. the queue is empty
if the queue is not empty the integers starting from
the front of the list is cout.
*/

void BQUEUE::Print()
{
    if (front == NULL)
    {
        cout << "Error in Printing: The queue"
            << " is empty.\n";
    }
   
    else
    {
        bqnode* curr = front;
        do
        {
            cout << curr->time << endl;
            curr = curr->next;
        } while (curr != front);
    }
}

/*Function name: Enqueue
Precondition: There aren't any nodes
Postcondition:Nodes get created
Description: function gets called with an integer.
function checks to see if back==0. if back is equal to a new back is created.
if not a pointer p is created with a new node and it gets assigned to the back
*/

void BQUEUE::Enqueue(int data)
{
    cout << "Inserting " << data
        << " into the queue.\n";
   
    bqnode* temp = new bqnode();
    temp->time = data;
    
    if (front == NULL)
    {
        front = temp;
        front->next = front;
        front->prev = front;
    }
   
    else
    {
        bqnode* curr = front->prev;
        temp->prev = curr;
        curr->next = temp;
        temp->next = front;
        front->prev = temp;
    }
}

/*Function name: Dequeue
Precondition: dequeue gets called
Postcondition: back is deleted.
Description: back gets deleted by checking if there aren't any nodes then return gets called, 1 node if back->next=back then it gets deleted. then 2 or more
and it deletes back
*/

void BQUEUE::Dequeue()
{
    if (front == NULL)
    {
        cout << "Error in Dequeue: The queue"
            << " is empty.\n";
    }
    
    else if (front->next == front)
    {
        cout << "Deleted " << front->time
            << " from the queue.\n";
        delete front;
        front = NULL;

    }
    
    else
    {
        bqnode* temp = front;
        front->prev->next = temp->next;
        front->next->prev = temp->prev;
        front = front->next;
        cout << "Deleted " << temp->time
            << " from the queue.\n";
        delete temp;
    }

}

/*
Function: BQUEUE
Precondition: State of class has not been initialized.
Postcondition: State has been initialize
Description: Copy constructor makes a deep copy.
*/

BQUEUE::BQUEUE(const BQUEUE& obj)
{
    this->front = NULL;
    bqnode* temp = obj.front;
   
    do
    {
        this->Enqueue(temp->time);
        temp = temp->next;

    } while (temp != obj.front);
}

/*Function Name:~BQUEUE
Precondition: checks to see if back is equal to 0.
Postcondition: nodes are going to get destroyed
Description: Destructor destroys nodes by calling dequeue */

BQUEUE::~BQUEUE()
{
    if (front != NULL)
    {
        while (true)
        {
            if (front->next == front)
            {
                delete front;
                front = NULL;
                break;
            }

            bqnode* curr = front->next;
            curr->next->prev = front;
            front->next = curr->next;
            delete curr;
        }
    }
}
