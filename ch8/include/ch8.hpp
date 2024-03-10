#pragma once

#include<string.h>

void fun1();
void fun(double&& rs);
void fun(double& rs);
void fun(const double& rs);
void reload_fun();

struct student{
    std::string name; //string 在标准库中
    double height;
    double wieght;
};

template <typename T>
void swap(T& a, T& b)
{
    b = a ^ b;
    a = a ^ b;
    b = a ^ b;
}

template <> void swap<student>(student& a, student& b)
{
    
}