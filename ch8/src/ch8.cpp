#include <iostream>
#include"ch8.hpp"

using std::cout;
using std::cin;
using std::endl;

void (*ptr_fun)();

int main()
{
    int a=1110, b=222;
    swap(a, b);
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    return 0;
    // ptr_fun = reload_fun;
    // ptr_fun();
}