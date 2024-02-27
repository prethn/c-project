#include <iostream>
#include <climits>
using namespace std;

void clcTypeBit();
void code_u3_14();
void pract_ch3();
void pract_9();

int main()
{
    // clcTypeBit();
    // code_u3_14();
    // pract_ch3();
    pract_9();

    return 0;
}

void clcTypeBit()
{
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    int var_a = 85;

//  数据类型大小
    cout << "int is " << sizeof n_int << " byte." << endl;
    cout << "short is " << sizeof n_short << " byte." << endl;
    cout << "long is " << sizeof n_long << " byte." << endl;
    cout << "long long is " << sizeof n_llong << " byte." << endl;
    cout << "char_bit is " << CHAR_BIT << " bit." << endl << endl;
//  输出格式
    cout << hex << var_a << endl;
    cout << oct << var_a << endl;
    cout << dec << var_a << endl;

    cout.put('$');
    cout << endl << 'A' << endl;
    
    char alarm = '\a';
    cout << alarm << "Don't do that again! \a\n";
    cout << "ben \"Bbuggsie\" Hacker\n was here!\n";

    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float million = 1.0e6;
    cout << "tub = " << tub << endl;
    cout << "mint = " << mint << endl;
    cout << "million = " << million << endl;
}

void code_u3_14()
{
    // 设置输出显示 6 位小数
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    int auks, bats, coots;
    auks = 23;
    bats = 9;
    coots = 7;
    char ch = 'Z';
    cout << static_cast<float> (auks) << endl;
    cout << ch << endl;
    cout << float (bats) << endl;
    cout << (float) coots << endl; 
}
void pract_ch3()
{
    cout.put(char(88));
    cout << endl;
    cout << static_cast<float> (8 * 9 + 12 / 6 +10 % 5) << endl; 
}
 void pract_9()
 {
    double x1 = 9.88;
    double x2 = 1.12;
    auto x3 = 11.23f;
    int sum = int (x1) + int (x2);
    cout << sum << endl << int (x1) << endl << int (x2) << endl << x3 << endl;
 }