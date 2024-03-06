#include "demo.hpp"

void (*fun)();

int main()
{
    fun = demo_doc1;
    fun();
    return 0;
}