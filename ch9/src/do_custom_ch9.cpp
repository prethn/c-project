#include<iostream>
#include"ch9.hpp"

using std::cin;
using std::cout;
using std::endl;
 
int cat = 100;

void do_refun()
{
    int x;
    double ar = 10;
    double y = refun(ar);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
void lfun()
{

    char hc;
    // char ch[];ch[] = "ascii";
    // char ch[6];ch[6] = "ascii";
    char ch[] = "ascii";
    char* ar[] = {ch}; cout << ch << endl;
    while (cin) // 在unix系统中是以 Ctrl+D 结束的
    {
        cout << "---" << endl;
        cin.get(hc);
        cout << "hc: " << hc << endl;
    }
    cout << "hjjkjl" << endl;
    // cin.get(ch);
    // cout << ch << endl;
}