#include<iostream>

using namespace std;

// 递归
void subdivide(char ar[], int low, int high, int level)
{
    if (level == 0) return;
    int mid = (high + low)/2;
    ar[mid] = '|';
    subdivide(ar, low, mid, level-1);
    subdivide(ar, mid, high, level-1);
}
void todosubdivide()
{
    const int len =66;
    const int divs = 6;
    char ruler[len];
    for (int i =1; i < len-2; ++i) ruler[i] = ' ';
    ruler[len - 1] = '\0';
    int max = len -2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    cout << ruler << endl;

    // ------meth1
    // subdivide(ruler, min, max, 2);
    // cout << ruler << endl;

    // ------meth2
    // for (int i= 1; i < divs; ++i)
    // {
    //     subdivide(ruler, min, max, i);
    //     cout << ruler << endl;
    //     for (int j = 1; j < len-2; ++j) ruler[j] = ' '; //请空此次循环赋值，重来
    // }
}
const double* f1(const double* arr, int i)
{
    return arr+i;
}
const double* f2(const double* arr, int i)
{
    return arr+i+1;
}
const double* f3(const double* arr, int i)
{
    return arr+i+2;
}
// 将函数定义为一种类型，新定义的名称为p_fun 这是一个指针。返回值类型为
// const double* 。注意返回值类型的分界是（暂时可以这么说）return 为分界
// 注意灵活把握！
typedef const double* (*p_fun)(const double*, int);
void fun2Ptr()
{
    double arr[9]={1,2,3,4,5,6,7,8,9};

    // meth1
    // p_fun pa = f1;
    // const double* a = pa(arr, 1);
    // cout << "a= " << *a << endl;

    // meth2
    // int i = 0;
    // do
    // {
    //     cout << "请输入 0-2 一个数字: ";
    //     cin >> i;
    //     p_fun pb[3] = {f1,f2, f3};
    //     const double* b = (pb[i])(arr, 0);
    //     cout << "*b = " << *b << endl;
    // } while (i >=0 && i < 3);

    // meth3
    // p_fun pb[3] = {f1,f2, f3};
    // p_fun* pc = pb;
    // const double* a = (*(pc+1))(arr, 1);
    // cout << "a= " << *a << endl;

    // meth4
    // p_fun pb[3] = {f1,f2, f3};
    // p_fun (*pd)[3] = &pb;
    // const double* a = (*pd)[0](arr,1);
    // cout << "a= " << *a << endl;
}

// ch7 编程第10题。
double add (double a, double b)
{
    return a + b;
}
double plus1 (double a, double b)
{
    return a * b;
}
double calculate(double a, double b, double (*p)(double,double))
{
    return  (*p)(a,b);
}

typedef double (*baf) (double, double);
typedef double (*Calculate)(double, double, double (*)(double,double));

void ch7_10fun()
{
    baf p[2] = {add, plus1};
    Calculate fun = calculate;
    int i;
    double a;
    do
    {
        cout << "请输入: ";
        cin >> i;
        a = fun(3,4,p[i]);
        cout << "a= " << a << endl;
    } while (i == 0 || i ==1);
    
}
