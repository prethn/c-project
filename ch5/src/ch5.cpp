#include <iostream>
#include "test_ch5.hpp"
using namespace std;

void (*fun)();

int main()
{
    fun = waiting;
    fun();
    return 0;
}