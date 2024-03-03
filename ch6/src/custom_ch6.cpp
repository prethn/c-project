#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

// 将大写字母转换成小写
void exam1()
{
    string ch;
    char crr;
    getline(cin, ch);
    const char* charr = ch.c_str();
    for (int i = 0; i < ch.size(); ++i)
    {
        if (isupper(*charr))
        {
            crr =  *charr + 32;
        }
        else
        {
            crr = *charr;
        }
        charr++;
        cout << crr;
    }
    cout << endl;
}

void exam2()
{
    char* ch = new char (255);
    char crr;
    cin >> ch;
    for (int i = 0; i < strlen(ch); ++i)
    {
        if (isupper(ch[i]))
        {
            crr = ch[i] + 32;
        }
        else
        {
            crr = ch[i];
        }
        cout << crr;
    }
    cout << endl;
    delete [] ch;
}

void exam3()
{
    char* ch = new char (255);
    char crr;
    cin >> ch;
    for (int i = 0; i < strlen(ch); ++i)
    {
        if (isupper(*ch))
        {
            crr = *ch + 32;
        }
        else
        {
            crr = *ch;
        }
        cout << crr;
        ch += sizeof(char);
    }
    cout << endl;
    delete [] ch;
}