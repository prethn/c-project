#include<iostream>
#include"ch9.hpp"

using std::cin;
using std::cout;
using std::endl;

void do_refun()
{
    int x;
    double a = 10;
    double y = refun(a);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}