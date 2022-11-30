#include "stack.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    stack s;
    string postfix, infix, operand1, operand2, expr, yn;
    do
    {
        cout << "Please enter your postfix expression" << endl;
        cin >> postfix;
        for (int i = 0; i < postfix.length(); i++)
        {
            string c = postfix.substr(i, 1);
            if (c == "+" || c == "-" || c == "*" || c == "/")
            {
                operand2 = s.pop();
                operand1 = s.pop();
                expr = "(" + operand1 + c + operand2 + ")";
                s.push(expr);
            }
            else
            {
                s.push(c);
            }
        }
        infix = s.pop();
        cout << "Infix expression for the above expression is " << endl << infix << endl;
        cout << "Convert another y/n : ";
        cin >> yn;
        cout << endl;
    } while (yn == "y" || yn == "Y");

    return 0;
}