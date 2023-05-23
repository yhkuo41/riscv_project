#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void print_error_exit(const string &s);
bool isdigit_(const char &c);
int atoi_(int s, int e, const string &input);

#endif // !UTIL_H