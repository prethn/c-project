#include "ch6.hpp"

void (*fun)();

int main()
{
    fun = userinfo1;
    fun();
    return 0;
}