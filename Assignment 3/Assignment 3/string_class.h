#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <iostream>
using namespace std;

class string_class
{
private:
    string current_string;
public:
    string_class();
    string_class(string s);
    bool palindrome();
    string replace_all(string old_substring, string new_substring);

    friend ostream& operator<<(ostream&, const string_class&);
};
#endif