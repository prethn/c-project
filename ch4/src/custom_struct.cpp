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
