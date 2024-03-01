#include <iostream>
#include <array>
#include <cstring>
#include "custom_struct.hpp"

using namespace std;

void  positive_odd()
{
    cout << "hello world" << endl;
    cout << (int*)"hello world" << endl;
}
void getInfo4_13_1()
{
    string fn, ln, score;
    int age;

    cout << "what is fn: ";
    getline(cin,fn);
    // cout << fn << endl;

    cout << "what is ln: ";
    getline(cin,ln);
    // cout << ln << endl;

    cout << "what is score: ";
    getline(cin,score);
    // cout << score << endl; 

    cout << "what is age: ";
    cin >> age;
    // cout << age << endl;

    cout << "name: " << ln << " , " << fn << endl;
    cout << "Grade: " << score << endl;
    cout << "age: " << age << endl;
}
void pract4_13_6()
{
    xiaoHeiZi arr[2] = 
    {
        {"id1", 1.9},
        {"id2", 1.8}
    };
    cout << arr[0].idid << endl;
    cout << arr[0].height << endl;
}
void pract4_13_8()
{
    xiaoHeiZi* arr = new xiaoHeiZi;
    cin >> (*arr).height;
    cin.get();
    getline(cin, (*arr).idid);
    delete arr;
}