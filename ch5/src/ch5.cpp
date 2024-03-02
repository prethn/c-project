#include <iostream>
#include "test_ch5.hpp"
using namespace std;

void (*fun)();

int main()
{
    fun = prat5_last;
    fun();
    return 0;
}