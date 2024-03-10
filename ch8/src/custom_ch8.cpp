#include<iostream>
#include<cstring>
#include<ch8.hpp>

using std::cout;
using std::cin;
using std::endl;

void fun1()
{
    std::string ch;
    std::string& ref = ch;
    std::string* const ptr = &ch;
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
void show(student& a)
{
     cout << "name: "<< a.name << endl;
     cout << "height: "<< a.height << endl;
     cout << "weight: "<< a.wieght << endl;
}
void priority_temp()
{
     student var_a, var_b;
     var_a = {"xiaoming", 1.70, 130.2};
     var_b = {"Lihua", 1.80, 140.5};
     swap(var_a, var_b);
     show(var_a);
     show(var_b);
     cout << "------------" << endl;
     swap(var_a.height, var_b.height);
     show(var_a);
     show(var_b);
}