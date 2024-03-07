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