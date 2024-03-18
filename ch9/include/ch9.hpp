#pragma once
#include<cstring>
#include<iostream>

struct veep
{
    std::string name;
    mutable int age;
    int weight;
};

double refun(double& a);

