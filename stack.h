#ifndef STACK_H
#define STACK_H

#include "const.h"
#include "util.h"

class Stack
{
    int stk[MAX_INPUT_LEN];
    // stack pointer
    int sp = 0;

public:
    void push(int num);
    int pop();
    int size();
};

#endif  // !STACK_H