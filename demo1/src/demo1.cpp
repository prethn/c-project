#include "demo.hpp"

void (*fun)();

int main()
{
    fun = ptr_const;
    fun();
    return 0;
}