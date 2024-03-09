#include<iostream>
#include<cstring>

using namespace std;

void fun1()
{
    string ch;
    string& ref = ch;
    string* const ptr = &ch;
    getline(cin, ch);
    cout << "ch: " << ch << endl;
    cout << "ref: " << ref << endl;
    cout << "ptr: " << *ptr << endl;
    cout <<  "------------" << endl;
    ref = "abcd";
    cout << "ref: " << ref << endl;
    *ptr = "efgh";
    cout << "*ptr: " << *ptr << endl;
}