#pragma once

#include<iostream>
#include<string>
 
using namespace std;

// 共用体（节省内存）
union id
{
    // string name;
    float price;
    long id_num;
    char id_char[20];
} id_all;

// 枚举 创建符号常量，可以代替const
enum color {yellow, red, blue, orange};

struct student
{
    float height;
    float weight;
    // char  name[20];  // meth1
    string name;    // meth2
    id id_val;//程序负责确定当前哪一个成员在活动
    color commodity;
};

// 重载<<运算符
// std::ostream& operator<<(std::ostream& os, const student& s) {
//     os << "height: " << s.height << ", weight: " << s.weight << endl;
//     os << "name: " << s.name << ", id_val" << s.id_val.price << endl;
//     os << "commodity: " << s.commodity << endl;
//     return os;
// }

