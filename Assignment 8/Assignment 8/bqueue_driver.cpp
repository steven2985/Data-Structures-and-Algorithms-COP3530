/***********************************PROGRAM HEADER*********************************************************************************
Name: Steven Fernandez                        TOTAL POINTS:  25                DUE DATE:  03/10/2021
COURSE:  COP3530
Assignment Name:  Assignment#6                Professor:  Dr. Bullard

Description: Implement a doubly-linked circular queue of integers. Considerthefollowing class declarations when implementingbqueue.
             As always, you must comment yourdeclaration and implementation files, "bqueue.h" and"bqueue.cpp", respectively.
***********************************************************************************************************************************/
#include "BQUEUE.h"
#include <iostream>
using namespace std;
int main()
{
	BQUEUE k;
	k.Enqueue(60);
	k.Print();
	k.Enqueue(20);
	k.Enqueue(30);
	k.Print();
	k.Enqueue(10);
	k.Print();
	k.Enqueue(50);
	k.Enqueue(40);
	k.Print();
	BQUEUE j = k;
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	return 0;
}
