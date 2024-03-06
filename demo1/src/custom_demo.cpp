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