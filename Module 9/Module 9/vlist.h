#pragma once
#include <vector>
using namespace std;
#ifndef vlist_H
#define vlist_H
class vlist
{
private:
	vector<string> DB;//Vector to store string
	int count;
public:
	vlist();//Default Constructor
	vlist(vlist&);//Copy constructor
	~vlist();//Destructor
	bool is_Empty();//Check if vector is empty or not
	vector<string>::iterator Search(const string&);//Search a string and return iterator to the key
	void Insert(const string&);//Insert string in vector in aplhabetical order
	void Remove(string);//Remove string from vector
	void Print();//Print all elements of vector
	vector<string> getVector();//Return whole vector
};
#endif
