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
    char ch, hc;
    cin.get(ch);
    cout << ch << endl;
    while (cin)
    {
        cout << "---" << endl;
        cin.get(hc);
        cout << "hc: " << hc << endl;
    }
    cout << "hjjkjl" << endl;
}