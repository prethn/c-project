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
// 函数重载，根据参数选择最合适的函数进行重载
void fun(const double& rs)
{
     cout << "const double&: " << rs << endl;
}
void fun(double& rs)
{
     cout << "double&: " << rs << endl;
}
void fun(double&& rs)
{
     cout << "double&&: " << rs << endl;
}
void reload_fun()
{
    const double x = 1.1;
    double y = 2.2;
    cout << "函数重载……" << endl;
    fun(x);
    fun(y);
    fun(x + y);
}
