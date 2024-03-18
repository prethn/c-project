#include"custom_ch9.hpp"
#include<iostream>

using std::cout;
using std::endl;

typedef void (*fun)();
extern int cat;

// 回调函数
void do_fun(fun cbk)
{
    cbk();
}

int main()
{
    // cout << "cat = " << cat << endl;
    do_fun(do_veep);
    return 0;
}
