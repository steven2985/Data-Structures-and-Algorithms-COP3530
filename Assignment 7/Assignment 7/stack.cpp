/***********************************PROGRAM HEADER************************************************
Name: Steven Fernandez                        TOTAL POINTS:  25                DUE DATE:  03/05/2021
COURSE:  COP3530
Assignment Name:  Assignment#5                Professor:  Dr. Bullard

Description: Write a program called "infix.cpp", that uses a stack, implemented as a singly-linked list, to convert a postfix expression to the
             corresponding fully-parenthesized infix expression.
*********************************************************************************************/
#include "stack.h"

void linkedStack::push(string value)
{
    // Push to stack
    struct stackNode* temp;
    temp = new stackNode();
    temp->value = value;
    temp->link = (top != 0) ? top : 0;
    top = temp;
}

string linkedStack::pop()
{
    // Pop from stack
    struct stackNode* temp;
    if (top == 0)
        return "\0";
    temp = top;
    string result = temp->value;
    top = top->link;
    delete temp;
    return result;

}