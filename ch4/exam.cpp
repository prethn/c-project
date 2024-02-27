#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int add (int a, int b) 
{
    return a+b;
}
void strings()
{
    const int size = 15;
    char name1[size];
    char name2[size] = "C++boy";
    // cin >> name1;//面向空格、回车、tab的输入
    cin.getline(name1,20).getline(name2,20);//面向行输入 getline（name，quantity）
    cout << "name1: " << name1 << endl;
    cout << strlen(name1) << " letters\n";
    cout << "name1 len: " << sizeof (name1) << endl;
    name2[2] = '\0';
    cout << name2 << endl;
}
void input_str()
{
    const char size = 20;
    char name1[size];
    char name2[size];
    cin.get(name1,size).get();
    // cin.get();//需要借助该语句来处理换行符,读取一个字符，否则接收不到第二个输入
    cin.get(name2,size);
    cout << "name2: " << name2 << endl;
    // cout << "name1: " << name1 << endl;
}
// 混合输入字符串和数字
void address_input()
{
    int year;
    (cin >> year).get();//利用cin >> year返回的cin对象，将调用拼接起来
    // cin.get();
    cout << "please input:";
    char address[80];
    cin.getline(address,80);
    //实际上读取到的是一个换行符，需要其他语句接收换行符才能正常输入
    cout << "year " << year << endl;
    cout << "address " << address << endl; 
}
// string 类
void str_obj()
{
    string str1 ,str2, str3;
    cin >> str1;
    str2 = "hello " + str1;
    str3 += "for a day ";
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;

    char charr1;
    char charr2;
    cin >> charr1;
    strcpy(&charr2, &charr1);
    strcat(&charr1, ", world");
}