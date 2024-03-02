#include "ch6.hpp"

void (*fun)();

int main()
{
    fun = exam1;
    fun();
    return 0;
}