#include <iostream>
#include <array>
#include <vector>
using namespace std;

void choice()
{
    int arr[2] = {6, 9};
    vector<int> vec(2);
    array<int, 2> ay;
    vec.at(0) = 1; //使用at()成员函数，进行越界判断
    ay.at(0) = 2;
    cout << "arr[1]: " << arr[1] <<"  " << &arr[1] << endl; //栈区
    cout << "vec[1]: " << vec[1] <<"  " << &vec[1] << endl; //堆区
    cout << "ay[1]: " << ay[1] <<"  " << &ay[1] << endl;    //栈区
}