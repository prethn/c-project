#include "ch6.hpp"

void (*fun)();

int main()
{
    fun = exam3;
    fun();
    return 0;
}