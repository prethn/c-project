#include "demo.hpp"

void (*fun)();

int main()
{
    fun = fun_2D;
    fun();
    return 0;
}