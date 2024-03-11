#pragma once

#include<string.h>

void fun1();
void fun(double&& rs);
void fun(double& rs);
void fun(const double& rs);
void reload_fun();
void priority_temp();

//有三个参数
struct student{ 
    std::string name; //string 在标准库中
    double height;// 升高
    double wieght; //体重
};

template <typename T>
void swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
    // b = a ^ b;
    // a = a ^ b;
    // b = a ^ b;
}
// 一个函数可以多次声明但只能定义一次 (用inline)
template <> inline void swap<student> (student& a, student& b)
{
    double i;
    i = a.height;
    a.height = b.height;
    b.height = i;
    i = a.wieght;
    a.wieght = b.wieght;
    b.wieght = i;
}