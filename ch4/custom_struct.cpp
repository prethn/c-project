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
