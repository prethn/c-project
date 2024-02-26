#include <iostream>
#include <climits>
using namespace std;

void clcTypeBit();

int main()
{
    clcTypeBit();
    return 0;
}

void clcTypeBit()
{
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "int is " << sizeof n_int << " byte." << endl;
    cout << "short is " << sizeof n_short << " byte." << endl;
    cout << "long is " << sizeof n_long << " byte." << endl;
    cout << "long long is " << sizeof n_llong << " byte." << endl;
    cout << "char_bit is " << CHAR_BIT << " bit." << endl << endl;

}