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
//  结构体成员缺省为 public 
// 类的成员缺省为 private
// 类中的成员函数可以用于递归
class Cboy
{
public:
    float height;
    // string name;
    Cboy()
    {
        // name.clear(); 
        height = 190.2;
        cout << "cboy 构造函数1……" << endl;
    }
    Cboy(float h)
    {
        height = h;
        cout << "cboy 构造函数2……" << endl;
    }
    // 析构函数调用规则：先构造的后析构，后构造的先析构
    ~Cboy()
    {
        cout << "cboy 析构函数…… " << endl;
    }
    Cboy(const Cboy& bb)
    {
        height = bb.height;
        // name = bb.name;
        cout << "cboy 的拷贝构造函数……" << endl;
    }
};

class demo
{
    // 如果成员函数不会修改成员变量，就应该加 const（在成员函数后面加） 修饰
// 类的成员函数可以借助成员变量保存数据状态
public:
    // 类的成员没有出现在初始化列表，编译器就采用默认的初始化方法
    mutable int age;
    string name;
    // Cboy& x_boy;
    int time = 0;
    // char* ch = new char; 
    // int* ptr;
    // demo()// (初始化列表) 默认构造函数
    // {
    //     cout << "不带参数构造函数，程序开始运行……" << endl;
    // }
    // demo(string name): name("LL"+ name),age(90)
    // {
    //     cout << "带1参构造函数,程序开始运行……" << endl;
    // }
    // 用类创建对象的时候，先初始化构造函数的形参对象，然后再初始化类的成员
    // 拷贝构造函数
    // 构造函数
    // demo(string name, int age, Cboy& boy): name(name+" 靓仔"),age(age -4 )
    // {
    //     // cout << "aaa" << endl;
    //     // // 隐藏着bug 这个不是调用构造函数
    //     // // 在构造函数名后面加括号不是调用构造函数，而是创建匿名对象。 
    //     // demo();
    //     // cout << "bbb" << endl;
    //     x_boy.name = boy.name;
    //     cout << "demo.g 带3参构造函数,程序开始运行……" << endl;
    // } 

    // Cboy boy 调用一次拷贝构造函数，x_boy(boy) （不是内置数据类型）也调用一次拷贝构造函数
    // 在该函数内传入 Cboy boy 参数，会执行拷贝构造函数，然后该函数执行完之后该变量被析构。
    // 执行完拷贝构造函数之后，紧接着执行上面 Cboy x_boy 的构造函数。
    // 最后执行完下面构造函数{}内部程序之后将 Cboy boy 析构。
    // 要注意析构原则不是按照输出字面顺序来解释，而是按照栈的生成方法来解释的！！！！
    demo(string name, int age):  name(name+" xxx"),age(age -4 ) 
    { 
        // cout << "aaa\n";
        // x_boy.height = boy.height;
        // cout << "aaa" << endl;
        // // 隐藏着bug 这个不是调用构造函数
        // // 在构造函数名后面加括号不是调用构造函数，而是创建匿名对象。 
        // demo();
        // cout << "bbb" << endl;
        cout << "demo.g 带3参构造函数,程序开始运行……" << endl;
        // cout << "bbb\n";

    } 
    ~demo()
    {
        // delete ptr; ptr = nullptr;
        cout << "demo.g 程序退出……" << endl;
    }
    // 编译器提供的是浅拷贝构造函数，需要自己写深拷贝构造函数
    // 浅拷贝容易造成野指针（两个指针通知操作一片内存）。因此需要使用深拷贝，为两个指针分别分配不同内存，然后将数据考过去。
    // demo(const demo& sup)
    // {
    //     name = sup.name + "靓仔";
    //     age = sup.age - 1; 

    //     // 浅拷贝
    //     // ptr = sup.ptr;

    //     // 深拷贝
    //     // ptr = new int; // 1. 分配内存
    //     // // *ptr = *sup.ptr; // 2. 拷贝数据(数据量少)
    //     // memcpy(ptr, sup.ptr, sizeof(int)); // 2. 拷贝数据(数据量多)

    //     cout << "拷贝构造函数……" << endl;
    // }
    // demo(const demo& sup, int i)
    // {
    //     name = sup.name + "靓仔";
    //     age = sup.age - i;
    //     cout << "传参拷贝构造函数……" << endl;
    // }
    // void setvalue(int a, string name1)
    // {
    //     name = name1; age = a;
    // }
    void show() 
    {
        age = 10;
        cout << "age0: " << age << "  name: " << name << endl;
        // cout << "x_boy0 " << x_boy.height << endl;
        show1();
        show2();
        // cout << "ptr: " << ptr << endl;
        // cout <<"  *ptr: " << *ptr  << endl;
        // cout << "boy's name: " << x_boy.name << endl;
    }
    void show1() 
    {
        age = 11;
        cout << "age1: " << age << "  name: " << name << endl;
        // cout << "x_boy1 " << x_boy.height << endl;
        // cout << "ptr: " << ptr << endl;
        // cout <<"  *ptr: " << *ptr  << endl;
        // cout << "boy's name: " << x_boy.name << endl;
    }
    void show2() const
    {
        age = 12;
        cout << "age2: " << age << "  name: " << name << endl;
        // cout << "x_boy2 " << x_boy.height << endl;
        // cout << "ptr: " << ptr << endl;
        // cout <<"  *ptr: " << *ptr  << endl;
        // cout << "boy's name: " << x_boy.name << endl;
    }
};
 // 以值的方式返回对象的时候，可能会调用拷贝析构函数（linux 不会调用）。linux 不会销毁返回变量，而是在后面换个名字继续用
// demo fun()
//  {
//     demo g;
//     g.name = "liHUA"; g.age = 17;
//     cout << "g 的地址: " << &g << endl;
//     return g; 
//  }
int main()
{
    // 类的成员函数涉及到多个对象，这种情况下需要使用 this 指针
    // 以值传递方式传递实参，会调用析构函数 
    // demo g("西施",18,boy);
    // Cboy boy(11);
    const demo g("xxx",11);
    g.show2();
    // g.ptr = new int(3);
    // demo g1(g);
    // // *g1.ptr = 7;
    // g.show(); 
    // g1.show();
    return 0;
}

// cboy 构造函数2……
// cboy 的拷贝构造函数……
// cboy 构造函数1……
// aaa
// demo.g 带3参构造函数,程序开始运行……
// cboy 析构函数……   // 这里析构的是 “cboy 的拷贝构造函数……” 临时副本，当构造函数执行完之后，副本的生命周期结束，所以被析构。
                    // 其他（类成员变量、函数或代码块中的局部变量)(栈）是遵循：先构造的后析构，后构造的先析构
// age: 7  name: xxx xxx
// x_boy 190.2
// demo.g 程序退出……
// cboy 析构函数…… 
// cboy 析构函数…… 