#include"custom_ch9.hpp"
#include<iostream>

using std::cout;
using std::endl;

void (*fun)();
extern int cat;

int main()
{
    cout << "cat = " << cat << endl;
    fun = lfun;
    fun();
    return 0;
}
