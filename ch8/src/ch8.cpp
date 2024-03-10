#include <iostream>
#include"ch8.hpp"

void (*ptr_fun)();

int main()
{
    ptr_fun = priority_temp;
    ptr_fun();
    return 0;
}