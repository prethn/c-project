#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

void test_bool()
{
    int x=2;
    cout <<(x > 3) << endl;
    cout.setf(ios::boolalpha); // or ios_base
    cout << (x<3) << endl;
}
void backoutput()
{
    char word[20];
    cin.getline(word, 20);
    int i = strlen(word) - 1;
    int a;
    char flag = 0;
    // for(int i = word.size() - 1; i >=0; i--)
    // {
    //     cout << word[i];
    //     if (i == 0) cout << endl << word.size() << endl;
    // }
    // cout << endl;
    // 回文
    for( a = 0; a < strlen(word); a++)
    {
        if (word[a] != word[i - a])
        {
            flag = 1;
            cout << endl << "error" << endl;
        }
        else {
            cout << word[i-a];
        }
    }
    cout << endl;
    if (!flag) cout << "successful!" << endl;
    char* pt = word;
    cout << ++*pt << endl;
    cout << *++pt << endl;
    // 不要用这样的表达式，有歧义
    // cout << a << "  " << ( 2 + a++  + a++) << "  " << a << endl;
}
void convert()
{
    int a, i;
    string word;
    cin >> word;
    i = word.size();
    char temp[i];
    for(a=0; a < i; ++a)
    {
        temp[i - 1 - a] = word[a];
    }
    cout << "temp: " << temp << endl;
    for(char ch  = 'a'; ch <= 'z'; ++ch)
        cout << ch ;
    cout << endl;
}
void comp_char()
{
    char word[5] = "?ate";
    char flag = 1;
    for (char ch = 'a'; flag ; ++ch)
    {
        word[0] = ch;
        if (strcmp(word,"mate") == 0) flag =0;
        cout << word << endl;
    }
}
void comp_str()
{
    string word = "?ate";
    char flag = 1;
    for (char ch = 'a'; flag ; ++ch)
    {
        word[0] = ch;
        if (word == "mate") flag = 0;
        cout << word << endl;
    }
}
void cmp_while()
{
    char arr[20];
    cin.get(arr, 20);
    int i = 0;
    while(arr[i] != ' ')
    {
        cout << arr[i];
        i++;
    }
    cout << endl;
}
// CLOCKS_PER_SEC 每秒钟包含的系统时间常数
// clock() 系统时间函数
void waiting()
{
    float sec;
    cin >> sec;
    clock_t delay =sec * CLOCKS_PER_SEC;
    clock_t start = clock();
    while(clock() - start < delay);
    cout << "end!" << endl;
}