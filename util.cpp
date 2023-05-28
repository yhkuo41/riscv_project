#include "util.h"

void print_error_exit(const string &s)
{
    cout << "error: " << s << endl;
    exit(1);
}