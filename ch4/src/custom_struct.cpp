#include "custom_struct.hpp"

void awsome1()
{
    student LiHua;
    cout << "请依次输入姓名、升高、体重： " << endl;
    getline(cin, LiHua.name);
    cin >> LiHua.height;
    cin >> LiHua.weight;
    cin.get();
    cout << "姓名、升高、体重： " << LiHua.name <<LiHua.height << LiHua.weight << endl;
}
// 结构初始化
void guest()
{
    // 像数组一样使用逗号分隔值列表
    student XiaoMing = 
    {
        1.90,
        190.2,
        "xiaoming"
    };
    student Lihua {1.90, 1.20, "hua"};
    student var_a;
    var_a = Lihua;
//  error --------------
    // student LiHua = 
    // {
    //     1.90;
    //     1.90;
    //     "ligui";
    // };
//----------
    cin.get(var_a.id_val.id_char, 20);
    var_a.id_val.price = 100;
    id_all.price = 99;
    // cout << "xiaoming " << XiaoMing.height 
    // << XiaoMing.weight << XiaoMing.name << endl;
    cout << "var_a: " << id_all.price << " " << var_a.id_val.price << " " << var_a.id_val.id_char << endl;
    // cout << "hua: " << Lihua.height << Lihua.name << Lihua.weight << endl;
}
// 复杂类型应用
void guest_complex()
{
    double donuts = 90;
    double cups = 90;
    student guest[2] = {
        {1.90,1.90,"lihua"},
        {1.22, 1.33,"Ligui"}
    };
    guest[1].commodity = red;
    guest[1].id_val.price = 199;
    // cout << guest[1] << endl;//操作符重载
    cout << &donuts << endl;
    cout << &cups << endl;
}

void address4_14()
{
    int* addr;
    int var_a = 90;
    int& addr2 = var_a;

    addr = &addr2;
    // *addr = addr2;
    // *addr = var_a;

    // int* addr1 = &addr2;
    cout << *addr << endl;
}
//  new
void address4_17()
{
    int dark = 100;
    int* pt = new int;
    *pt = dark;
    cout << "value: " << *pt << endl;
    cout << "location: " << pt << endl;
    cout << "size: " << sizeof pt << endl;
    cout << "size: " << sizeof *pt << endl;
    delete pt;// 会释放 pt 指向的内存，但不会删除指针 pt 本身。
    // 不要重复释放内存块。
    // 对空指针使用 delete 是安全的。
}
// 动态数组
void dyn_arr()
{
    int* psome = new int [2];
    psome[0] = 1;
    psome[1] = 2;
    cout << "psome: " << psome[0] << " & " << psome[1] << endl;
    psome = psome + 1;// 指向下一个元素
    cout << "psome1: " << psome[0] << " & " << psome[1] << endl;
    psome = psome - 1;// 还原 //要复原才能使用 delete 否则报错
    cout << "psome2: " << psome[0] << " & " << psome[1] + 2  << endl;
    cout << sizeof psome[1] << endl;
    delete [] psome;
}
// 
void addr_ptr()
{
    int a, b;
    int* pas[2] = {&a, &b};
    a = 90; b = 22;
    // 指针数组
    cout << "pas: " << *pas[1] << endl;
    cout << "size: " << sizeof *pas[1] << endl;
    // int (*sap)[2];
    // int arr[2] = {1, 2};
}
void addr2D()
{
    int arr[2][3] = {{1, 2, 3}, {90, 5, 22}};
    // ptr是一个指向含有3个整数的数组的指针
    int (*ptr)[3] = arr;
    cout << (*ptr)[1] << endl;
    cout << "location: " << &arr[0] << endl;
    cout << "location: " << &arr[1] << endl;
    cout << "location: " << &(*ptr) << endl;
    cout << "location: " << &(*(ptr+1)) << endl;
    // for(int i = 0; i < 2; ++i) {
    //     for(int j = 0; j < 3; ++j) {
    //         cout << ptr[i][j] << " "; // 使用ptr遍历二维数组
    //     }
    //     cout << endl;
    // }
}
void ptrstr()
{
    char animal[20] = "bear";
    char* ps;
    const char* bird = "wren"; //字符串地址就是其本省
    cout << animal << " " << *(bird +1) << endl;
    cout << animal << " " << bird << endl;
    cout << animal << " " << *bird << endl;
    cout << animal << " at " << (int* )animal << endl;
    cout << animal << " at " << &animal << endl;
    cout << strlen(animal) << endl;
    ps = new char[strlen(animal) + 1];
    strcpy(ps, animal);//赋值内容
    cout << ps << " at " << (int* )ps << endl;  
    // cout << "len" << strlen (*ps) << endl;
    delete [] ps;
}
void confun()
{
    student* ps = new student;
    getline(cin, ps->name);
    cout << "name: " << ps->name << endl;
    cin >> (*ps).height;
    cin >> ps->weight;
    cout << "w: " << (*ps).weight << " & " << "h: " << ps->height << endl;
}

char* getname() //函数指针
{
    char temp[80];
    cin >> temp;
    char* pn = new char [strlen(temp) +1];
    strcpy(pn,temp);//传的是指针，字符串名称是指向整个字符串的指针
    return pn;
}
void getnameAfter()
{
    char* name;
    name = getname();
    cout << name << " at " << (int*) name << endl;
    delete [] name;
}
void multistruct()
{
    xiaoHeiZi a1, a2, a3;
    a1.height = 1;
    a2.height = 2;
    a3.height = 3;
    const xiaoHeiZi* arr[3] = {&a1, &a2, &a3};
    // cout << (*arr[1]).height << endl;
    const xiaoHeiZi** ptrarr = arr; //使用const 编译时多一层安全检查，同时不会因意外而改变其值。
    auto ppb = arr;
    cout <<  (*ppb)->height << endl;
    cout << (*(*ptrarr + 1)).height << endl;//元素偏移
    cout << (**(ptrarr + 1)).height << endl;//指针偏移
}
// 指针转向
void func(int **p, int* b)  //2
{
    cout<<"func:&p="<<&p<<",p="<<p<<endl;
    *p = b;  //3
    cout<<"func:&p="<<&p<<",p="<<p<<endl;
}
void addr2()
{
    int a= 10;
    int b = 100;
    int *q;
    cout<<"&a="<<&a<<",&b="<<&b<<",&q="<<&q<<endl;
    q = &a;
    cout<<"*q="<<*q<<",q="<<q<<",&q="<<&q<<endl;
    func(&q, &b);  //1
    cout<<"*q="<<*q<<",q="<<q<<",&q="<<&q<<endl;
}
// 指针转向
void transptr(int** pt, int* q)
{
    *pt = q;
}
void addr2up()
{
    int a = 9;
    int b = 20;
    int* p = &a;
    cout << "p " << p << " &a " << &a << endl;
    int** q1 = &p;
    cout << "q1 " << q1 << " &p " << &p << endl;
    cout << endl;
    cout << "p " << p << " &p " << &p << endl;
    *q1 = &b;//*q = p; p = &b;
    cout << "*q1 " << *q1 << " &b " << &b << endl;
    transptr(&p, *q1);
    // &p = *q;//非法的 
    cout << "b: " << *p << endl;
 }
 void trans_all()
 {
    xiaoHeiZi arr[2];
    arr[1].height = 2;
    cout << (arr + 1)->height << endl;
 }