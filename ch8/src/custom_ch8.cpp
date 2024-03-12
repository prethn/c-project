#include<iostream>
#include<cstring>
#include<ch8.hpp>

using std::cout;
using std::cin;
using std::endl;
 
template<> void swap<student> (student&, student&);//显示具体化
template void swap<student> (student&, student&);//显示实例化
void fun1()
{
    std::string ch;
    std::string& ref = ch;
    std::string* const ptr = &ch;
    getline(cin, ch);
    cout << "ch: " << ch << endl;
    cout << "ref: " << ref << endl;
    cout << "ptr: " << *ptr << endl;
    cout <<  "------------" << endl;
    ref = "abcd";
    cout << "ref: " << ref << endl;
    *ptr = "efgh";
    cout << "*ptr: " << *ptr << endl;
}
// 函数重载，根据参数选择最合适的函数进行重载
void fun(const double& rs)
{
     cout << "const double&: " << rs << endl;
}
void fun(double& rs)
{
     cout << "double&: " << rs << endl;
}
void fun(double&& rs)
{
     cout << "double&&: " << rs << endl;
}
void reload_fun()
{
    const double x = 1.1;
    double y = 2.2;
    cout << "函数重载……" << endl;
    fun(x);
    fun(y);
    fun(x + y);
}
void show(student& a)
{
     cout << "name: "<< a.name << endl;
     cout << "height: "<< a.height << endl;
     cout << "weight: "<< a.wieght << endl;
}

template<typename T1, typename T2>
auto gt(T1& a, T2& b) -> T2
{
     return a + b;
}
void priority_temp()
{
     student var_a, var_b;
     var_a = {"xiaoming", 1.70, 130.2};
     var_b = {"Lihua", 1.80, 140.5};
     swap(var_a, var_b);
     show(var_a);
     show(var_b);
     cout << "------------" << endl;
     swap(var_a.height, var_b.height);
     show(var_a);
     show(var_b);
     decltype(var_a.name + var_b.name) ab = var_a.name + " " + var_b.name;
     cout << "ab:" << ab << endl;
     double a = 9.9;
     int b = 1;
// 应该使用函数调用的结果来推断类型，而不是尝试从函数原型直接推断！！
     decltype(gt(a, b)) c = gt(a, b);
     cout << "c= " << c << endl;
}

// template<typename T1, typename T2> auto gt(T1& a, T2& b) -> T2
// double a = 9.9;
// int b = 1;
// 应该使用函数调用的结果来推断类型，而不是尝试从函数原型直接推断！！
// decltype(gt(T1&, T2&)) c = gt(a, b); //T1&, T2& 未定，所以不能这样用
// cout << "c= " << c << endl;


void pract_1(const char* arr, int freq = 0);
// TODO: 打印字符串
void pract_1(const char* arr, int freq)
{
     if(!freq)
     {
          static int i = strlen(arr);
          const char* ch = arr;
          for( int a = 0; a < i; ++a,++ch)
          {
               cout << *ch;
          }
          cout << endl;
     }
     else
     {
          for (int b = 0; b < freq; ++b)
          {
               pract_1(arr);
          }
     }
}
void doPract_1()
{
     char ar[] = "nihao";
     pract_1(ar, 4);
}
template<typename T>
T pract_5(T* a)
{
     T b;
     for(int i = 1; i < 5; ++i)
     {
          if (*(a+i) < *(a+i-1)) 
          {
               b = *(a+i);
               *(a+i) = *(a+i-1);
               *(a+i-1) = b;
          }
          cout << *(a + i - 1) << endl;
     }
     return *(a + 4);
     // cout << "最大值： " << a[4] << endl;
}

void doPract_5()
{
     int a[5] = {1, 3, 7, 2, 4};
     double ar[5] = {4.2, 6.3, 5.1, 1.1, 3.2};
     int b = pract_5(a);
     double br = pract_5(ar);
     cout << "最大值a: " << b << endl;
     cout << "最大值b: " << br << endl;
}


template<typename T> T pract_6(T* a, int freq)
{
    T b;
    for(int i = 1; i < freq; ++i)
    {
    if (*(a+i) < *(a+i-1)) 
        {
            b = *(a+i);
            *(a+i) = *(a+i-1);
            *(a+i-1) = b;
        }
        cout << *(a + i - 1) << endl;
    }
     return *(a + freq - 1);
}
template<> char pract_6<char> (char* a, int freq)
{
    char* b;
    int flag = -1;
    for(int i = 1; i < freq; ++i)
    {
        if (*(a+i) < *(a+i-1)) 
        {
            flag = i-1;
            *b = *(a+i);
            *(a+i) = *(a+i-1);
            *(a+i-1) = *b;
        }
        cout << *(a + i - 1) << endl;
    }
    if (0 <= flag && flag <= freq)
    {
        return *(a + flag);
    }
    else
    {
        return *(a + freq -1);
    }
}
// 
template <> char* pract_6<char*> (char** arr, int freq)
{
    char** a = arr;
    int flag = 0;
    for (int i = 1; i < freq; ++i)
    {
        if (strlen(*a) < strlen(arr[i]))
        {
            flag = i;
            **a = *arr[i];
        }
    }
    return arr[flag];
}
void doPract_6()
{
    int a[6] ={4,2,5,3,7,1};
    double ar[4] = {4.2, 6.3, 5.1, 3.2};
    int var_a = pract_6(a, 6);
    double var_b = pract_6(ar, 4);
    cout << "最大值var_a: " << var_a << endl;
    cout << "最大值var_b: " << var_b << endl;
    char a1[] = "aaaa";
    char a2[] = "baaa1";
    char a3[] = "caaa22";
    char a4[] = "daaa334";
    char a5[] = "eaaa4444";
    char a6[] = "eaaa44441";
    // 二级指针！！
    char* arr[] = { a1, 
                    a2,
                    a3,
                    a4,
                    a5,
                    a6};
    char* arrr = pract_6(arr, 6);
    cout << "最大的字符串: " << arrr << endl;
}