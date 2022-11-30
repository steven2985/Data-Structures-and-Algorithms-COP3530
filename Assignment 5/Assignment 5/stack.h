#include<string>
#include<iostream>
using namespace std;

struct Node
{
    string value;
    struct Node* next;
};

class stack
{
    struct Node* top;

public:

    stack()
    {
        top = 0;
    }

    void push(string value);
    string pop();
};

