#include <iostream>
#include <cstring>

using namespace std;

void test_bool()
{
    int x=2;
    cout <<(x > 3) << endl;
    cout.setf(ios_base::boolalpha);
    cout << (x<3) << endl;
}