#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <fstream>

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

// 内存泄漏
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
void funswi()
{
    char choice;
    cin >> choice;

    switch (choice)
    {
        case 'a' || 'A':
                    cout << "Aa";
                    break;
        case 'B':
        case 'b': cout << "Bb";
                    break;
        default:cout << "other";
    }
}
void userinfo()
{
    fstream userf;
    string name;
    float height;
    getline(cin, name);
    cin >> height;
    userf.open("../doc/userinfo.txt");
    cout << "name: " << name << endl;
    cout << "height: " << height << endl;
    userf << "name: " << name  << endl;
    userf << "height: " << height << endl;
    userf.close();
}
void userinfo1()
{
    ofstream userf;
    userf.open("../doc/userinfo.txt");
    
}