#include <iostream>
#include "ch7.hpp"

void (*fun)();

int main()
{
    fun = ch7_10fun;
    fun();
}