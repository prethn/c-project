#include <iostream>
#include <cmath>
using namespace std;

// prototype of function
void statement_u2_3();
void sprt_u2_4();

int main()
{
    // statement_u2_3();
    sprt_u2_4();
    return 0; 
}

void statement_u2_3()
{
    int var_a;
    cout << "请输入： ";
    cin >>var_a;
    cout << "come up and c++ me some time.1";
    cout << "come up and c++ me some time.";
    // printf("\n");
    cout <<endl;cout << "You won't regret it!" << endl;
    cout << "the value of var_a : " <<var_a<<endl;
    cout << var_a << endl;
}
void sprt_u2_4()
{
    double area; 
    cout << "Enter the floor area, in square feet, of your home: ";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "That's the equivalent of a square " << side
         << " feet to the side" << endl;
    cout << "How fascinating" << endl;
}