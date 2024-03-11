#include <iostream>
#include"ch8.hpp"

void (*ptr_fun)();

int main()
{
    ptr_fun = doPract_6;
    ptr_fun();
    return 0;
}