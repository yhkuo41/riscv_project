#include "util.h"

void print_error_exit(const string &s)
{
    cout << "error: " << s << endl;
    exit(1);
}

bool isdigit_(const char &c)
{
    return '0' <= c && c <= '9';
}

int atoi_(int s, int e, const string &input)
{
    int res = 0;
    int sign = 1;
    if (input[s] == '-')
    {
        sign = -1;
        s++;
    }
    while (s < e)
    {
        if (!isdigit_(input[s]))
        {
            print_error_exit("illegal number");
        }
        res = res * 10 + (input[s] - '0');
        s++;
    }
    return res * sign;
}