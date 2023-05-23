#include "stack.h"

void Stack::push(int num)
{
    if (sp < MAX_INPUT_LEN)
    {
        stk[sp] = num;
        sp++;
    }
    else
    {
        print_error_exit("stack full, cant push");
    }
}

int Stack::pop()
{
    if (sp > 0)
    {
        --sp;
        return stk[sp];
    }
    print_error_exit("This is an illegal postfix arithmetic expression.");
    return 0;
}

int Stack::size()
{
    return sp;
}