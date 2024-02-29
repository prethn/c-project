#include <iostream>
#include "ch4.hpp"
using namespace std;

void (* func)();
void (* fun[])() = {str_obj, string4_2, address_input};//函数表

int main()
{
    int sum, i;
    sum = add(8,5);
    // cout << "sum = " << sum << endl; 

    // string4_2();
    // strings();
    // input_str();
    // address_input();
// 函数指针------------
    // func = str_obj;
    // func();

    // for(i=1; i<3; i++)
    // {
    //     (*fun[i])();
    //     cin.get();
    // }
//-------------
    // str_obj();
    // str_io4_10();
    // awsome1();
    // guest();
    // guest_complex();
    // 函数指针
    func = address4_14;
    func();
}