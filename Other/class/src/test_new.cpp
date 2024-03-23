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

class cppboy
{
public:
    // string name;
    // int yz;
    static int height;
    cppboy()
    {
        cout << "cppboy 构造1……\n";
    }
    cppboy(string,int);
    ~cppboy();
    // const cppboy& pk(const cppboy& cboy) const
    // {
    //     if (yz < cboy.yz) return cboy;
    //     return *this;
    // }
    void show();
    // void fun(int yz)
    // {
    //     this->yz = yz;
    // }
};
int cppboy::height = 100;
int aaa;
// cppboy::cppboy(string name1,int i): name(name1),yz(i) 
// {
//     cout << "cppboy 构造2……\n";
// }

cppboy::~cppboy()
{
    cout << "cppboy 析构……\n";
}

void cppboy::show() 
{
    // cout << name <<" 最帅" << endl;
}
typedef void (cppboy::* fun)();
int main()
{
    cppboy cp;
    cout << "对象cp的内存大小: " << sizeof(cp) << " 地址： " << (void*)&cp << endl;
    // cppboy *c = nullptr;
    // // c->show();
    // cppboy c1,c2("cboy",19);
    // fun ptr = &cppboy::show;
    // cout << "对象c1的内存大小: " << sizeof(c1) << " 地址： " << &c1 << endl;
    // cout << "对象c2的内存大小: " << sizeof(c2) << " 地址： " << &c2 << endl;
    // cout << "对象c1.name的内存大小: " << sizeof(c1.name) << " 地址： " << (void*)&c1.name << endl;
    // cout << "对象c1.yz的内存大小: " << sizeof(c1.yz) << " 地址： " << (void*)&c1.yz << endl;
    // cout << "对象c1.height的内存大小: " << sizeof(c1.height) << " 地址： " << (void*)&c1.height << endl;
    // cout << "对象pk的内存大小: " << sizeof(c1.pk(c2)) << " 地址： " << &c1.pk(c2) << endl;
    // cout << "对象show的内存大小: " << sizeof(ptr) << " 地址： " << &ptr << endl;
    // cout << " 地址： " << &cppboy::show << endl; // 非法
    // printf("成员函数show 地址：%p ", &cppboy::show);
    // cppboy c1("Q",1),c2("W",2),c3("e",3),c4("r",4);
    // const cppboy& d = c1.pk(c2).pk(c3).pk(c4);
    // c1.fun(7);
    // cout << "yz: " << c1.yz << endl;
    // d.show(); 
    return 0;
}