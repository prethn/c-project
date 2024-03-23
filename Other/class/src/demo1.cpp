#include<iostream>
#include<cstring>
#include<vector>
#include <array>

using std::vector;
using std::array;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class demo1;
class cboy
{
public:
    int age_;
    float weight_;
    cboy(){cout << "不带参数构造函数……\n";}
    explicit cboy(int age): age_(age){ cout << "int带参数构造函数……\n";}
    explicit cboy(float weight): weight_(weight){ cout << "float带参数构造函数……\n";}
    ~cboy()
    {
        cout << "析构函数……"<< endl;
    }
    // 常量对象只能调用常量成员函数
    void func1(const demo1& d) const;
    void func2(const demo1& d) const;
    void showint(){cout << "age: " << age_ << endl;}
    void showfloat(){cout << "weight: " << weight_ << endl;}
};
// 友元函数是定义在类外部的普通函数，它被赋予了访问类的私有成员（包括私有方法和属性）的权限。
// 友元函数不是类的成员函数，因此它不能通过对象或指针调用，也不通过this指针访问类的实例。
class demo1
{
friend void show(demo1& dd);
friend void cboy::func1(const demo1& d)const;
friend void cboy::func2(const demo1& d)const;
// friend class cboy;
private:
    string name_;
    int age_;

public:
    demo1(string, int);
    ~demo1();
    int showage() const
    {
        return age_;
    }
    string showname() const
    {
        return name_; 
    }
};
demo1::demo1(string name,int age): name_(name),age_(age)
{
    cout << "构造函数……\n";
}

demo1::~demo1()
{
    cout << "析构函数……\n";

}
void show(demo1& dd)
{
    cout << "age:" << dd.age_ << endl;
    cout << "name: " << dd.name_ << endl;
}
void cboy::func1(const demo1& d) const { cout << "age1: " << d.age_ <<endl;}
void cboy::func2(const demo1& d) const { cout << "age2: " << d.name_ <<endl;}
int main()
{
    // TODO: 友元
    // cboy c;
    // demo1 de("girl", 19);
    // // show(de);
    // c.func1(de);
    // c.func2(de);


    cboy cc(2.4);
    // cboy cc = 3;

    // cboy cc = cboy(8);
    // cboy cc;
    // cc = 4;
    // cc.showint();
    cc.showfloat();
    return 0;
}