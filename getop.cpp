#include "getop.h"

char getop(int &s, int &e, const string &input)
{
    while (e < MAX_INPUT_LEN && input[e] != ',' && input[e] != '.') {
        e++;
    }
    if (e == MAX_INPUT_LEN && input[MAX_INPUT_LEN - 1] != '.') {
        print_error_exit("postfix arithmetic expression must end with a '.'");
    }
    if (s == e) {
        print_error_exit("op can't be empty");
    }
    // only move 1 char, assuming the expression does not contain any whitespace
    if (e - 1 == s) {
        if (isdigit(input[s])) {
            return NUMBER;
        }
        return input[s];
    }
    return NUMBER;
}
