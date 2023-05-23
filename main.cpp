#include <iostream>
#include <string>
#include "const.h"
#include "util.h"
#include "getop.h"
#include "stack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Please input a postfix arithmetic expression: " << flush;
    string input;
    cin >> input;
    cout << input << endl;

    int s = 0, e = 0; // record the index at the beginning and end of the op
    char op_type;
    int op2; // for -, / the left and right operands must be distinguished
    Stack stk;

    while ((op_type = getop(s, e, input)) != '.')
    {
        if (op_type == NUMBER)
        {
            stk.push(atoi_(s, e, input));
        }
        else if (op_type == '+')
        {
            stk.push(stk.pop() + stk.pop());
        }
        else if (op_type == '*')
        {
            stk.push(stk.pop() * stk.pop());
        }
        else if (op_type == '-')
        {
            op2 = stk.pop();
            stk.push(stk.pop() - op2);
        }
        else if (op_type == '/')
        {
            op2 = stk.pop();
            if (op2 != 0)
            {
                stk.push(stk.pop() / op2);
            }
            else
            {
                print_error_exit("zero divisor");
            }
        }
        else
        {
            print_error_exit("illegal operator");
        }
        if (input[e] == '.')
        {
            if (stk.size() == 1)
            {
                cout << "The value is: " << stk.pop() << endl;
                return 0;
            }
            print_error_exit("This is an illegal postfix arithmetic expression.");
        }
        // move to the next char of ','
        e++;
        s = e;
    }
    return 0;
}