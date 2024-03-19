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

class demo
{
// 类的成员函数可以借助成员变量保存数据状态
public:
    int age;
    string name;
    int time = 0;
    // char* ch = new char; 
    // int* ptr;
    demo(): age(19),name("西施") // (初始化列表) 默认构造函数
    {
        cout << "构造函数，程序开始运行……" << endl;
    }
    demo(string name): name("LL"+ name),age(90)
    {
        cout << "带1参,程序开始运行……" << endl;
    }
    demo(string name1, int age1)
    {
        // cout << "aaa" << endl;
        // // 隐藏着bug 这个不是调用构造函数
        // // 在构造函数名后面加括号不是调用构造函数，而是创建匿名对象。 
        // demo();
        // cout << "bbb" << endl;
        name = name1; age = age1;
        cout << "带2参,程序开始运行……" << endl;
    } 
    ~demo()
    {
        // delete ptr; ptr = nullptr;
        cout << "程序退出……" << endl;
    }
    // 编译器提供的是浅拷贝构造函数，需要自己写深拷贝构造函数
    // 浅拷贝容易造成野指针（两个指针通知操作一片内存）。因此需要使用深拷贝，为两个指针分别分配不同内存，然后将数据考过去。
    demo(const demo& sup)
    {
        name = sup.name + "靓仔";
        age = sup.age - 1; 

        // 浅拷贝
        // ptr = sup.ptr;

        // 深拷贝
        // ptr = new int; // 1. 分配内存
        // // *ptr = *sup.ptr; // 2. 拷贝数据(数据量少)
        // memcpy(ptr, sup.ptr, sizeof(int)); // 2. 拷贝数据(数据量多)

        cout << "拷贝构造函数……" << endl;
    }
    demo(const demo& sup, int i)
    {
        name = sup.name + "靓仔";
        age = sup.age - i;
        cout << "传参拷贝构造函数……" << endl;
    }
    void setvalue(int a, string name1)
    {
        name = name1; age = a;
    }
    void show()
    {
        cout << "age: " << age << "  name: " << name << endl;
        // cout << "ptr: " << ptr << endl;
        // cout <<"  *ptr: " << *ptr  << endl;
    }
};
 // 以值的方式返回对象的时候，可能会调用拷贝析构函数（linux 不会调用）。linux 不会销毁返回变量，而是在后面换个名字继续用
demo fun()
 {
    demo g;
    g.name = "liHUA"; g.age = 17;
    cout << "g 的地址: " << &g << endl;
    return g; 
 }
int main()
{
    // 以值传递方式传递实参，会调用析构函数 
    demo g("西施");
    // g.ptr = new int(3);
    g.show();
    // demo g1(g);
    // // *g1.ptr = 7;
    // g.show();
    // g1.show();
    return 0;
}
