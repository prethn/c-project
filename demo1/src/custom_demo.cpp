#include "demo.hpp"

void output_MAT()
{
    Eigen::Matrix3d t1_A, t1_B;
    Eigen::Array33d t2_a, t2_b;
    cout << "t1_A: \n" << t1_A << endl;
    t1_A << 1,2,3,4,5,6,7,8,9;
    t1_B = Eigen::Matrix3d::Identity(3, 3);
    t2_a << 1,2,3,4,5,6,7,8,9;
    t2_b = t1_B.array();
    cout << "t1_A: \n" << t1_A 
         << "\nt1_B: \n" << t1_B
         << "\nt1_A*t1_B: \n" << t1_A * t1_B << endl;
    cout << "t2_a: \n" << t2_a 
         << "\nt2_b: \n" << t2_b
         << "\nt2_a*t2_b: \n" << t2_a * t2_b << endl;
}
void demo_doc1()
{
     MatrixXd m = MatrixXd::Random(3,3);// -1 ~ 1
     cout << "constant =" << endl << MatrixXd::Constant(3,3,1.2) << endl;
     m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
     cout << "m =" << endl << m << endl;
     VectorXd v(3);
     v << 1, 2, 3;
     cout << "m * v =" << endl << m * v << endl;
}
void ptr_const()
{
     int age = 90,age1 = 80;
     const int* ptr_age = &age;
     cout << "before_age: " << *ptr_age << " " << ptr_age << endl;
     ptr_age = &age1;
     cout << "after_age1: " << *ptr_age << " " << ptr_age << endl;
     cout << "---------------------" << endl;
     int h1 = 100;
     int* const ptr_height = &h1;
     cout << "before_hight: " << *ptr_height << " " << ptr_height << endl;
     int h2 = 111;
     *ptr_height = h2;
     cout << "after_hight: " << *ptr_height << " " << ptr_height << endl;

}
// 计算每个同学总成绩
int sum_arr(const int (*arr)[3], int size, int num)
{
     int sum = 0;
     for (int a = 0; a < size; ++a)
     {
          // arr 是整个数组地址。
          // *arr指出的是哪一行地址，*arr+a 指出的是哪一行哪一列地址
          // *(*arr+a) 是哪一行哪一列数据
          // sum += *(*arr+a);
          sum += (*arr)[a];
     }
     return sum;
}
void fun_2D()
{
     int sum;
     int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
     cout << *arr << endl;//数组首元素地址也就是arr[0]或者&arr[0][0]
     cout << &arr[0] << endl;//数组a首元素地址也就是a[0]或者&a[0][0]
     cout << *arr+3 << endl;
     cout << &arr[1] << endl;
     cout << **arr+1 << endl;
     // (*arr)[3] 只有在函数头和函数原型上才表示大小，在其他地方表示具体位置的一个数据！！！！
     // 传递的时候要看传递的是什么，指针或是数据
     sum = sum_arr(arr, 3, 0);
     cout << sum << endl;
}