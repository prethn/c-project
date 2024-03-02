#include <iostream>
#include <cstring>
#include <ctime>
#include <array>
#include <vector>
#include <random>

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
    cout << "end!\a\n" << endl;
}
// c++11 for
void loopfun()
{
    double arr[20] = {2.1, 3.2, 4.3, 2.2, 9};
    // cin >> arr;
    for (double& a : arr)
    {
        a *= 0.8;
        cout << a << "  ";
    }
    cout << endl;
}
void ctrlLoop()
{
    char ch;
    int count = 0;
    // cin >> ch;
    // while(!cin.fail())
    // while(cin)
    while(cin.get(ch))
    {
        cout << ch;
        ++count;
        // cin.get(ch);
        cout.put(ch);
    }
    cout << endl << count << endl; 
}
void func()
{
    int var_a, var_b, sum;
    cout << "请输入两个整数： ";
    cin >> var_a;
    cin >> var_b;
    if(var_a > var_b)
    {
        var_a = var_a ^ var_b;
        var_b = var_a ^ var_b;
        var_a = var_a ^ var_b;
    }
    for (var_a; var_a <= var_b; ++var_a)
    {
        sum += var_a; 
    }
    cout << "sum: " << sum << endl;
}
void factorial()
{
    const int size = 16;
    // array<long long, size> factor;
    vector<long long> factor (size);
    factor[0] = factor[1] = 1;
    for (int i = 1; i <= size; ++i)
    {
        factor[i] = i * factor[i-1];
    }
    for (int i = 0; i < size; ++i)
    {
        cout << i << "! = " << factor[i] << endl;
    }
}
void saleBook()
{
    const char* arr[12] = {"jan", "feb", "Mar", "apr", "may" ,
        "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    int sale[12], sum = 0;
    for (int i = 0; i < 12; i++)
    {
        cout << "月份：" << arr[i] << " ，销售额： ";
        cin >> sale[i];
        sum += sale[i];
    }
    cout << "sum: " << sum << endl;
}
void sale3Book()
{
    string arr[3][12];
    int sale[3][12];
    int sum[3] = {0};
    const char* arrPer[12] = {"jan", "feb", "Mar", "apr", "may" ,
        "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    for(int a = 0; a < 3; ++a)
    {
        for (int i = 0; i < 12; ++i)
        {
            arr[a][i]= arrPer[i];
            cout << "第 " << a+1 << " 年，" << arrPer[i] << " ";
            // cin >> sale[a][i];
            sale[a][i] = 1;
            cout << sale[a][i] << endl;
            sum[a] += sale[a][i];
        }
    }
    cout << endl;
    for (int i = 0; i < 3; ++i)
    {
        for(int b = 1; b < 4; ++b)
        {
        for (int a = 1; a < 5; ++a)
        {
            cout << "第 " << i+1 << " 年，"<< arr[i][a * b - 1] << ": "<< sale[i][a * b - 1] << "  |  ";
        }
        cout << endl;
        }
        cout << "第 " << i+1 << " 年销售额： " << sum[i] << endl;
    }
}
void Outstar(int pos, int width)
{
    for (int i = 0; i < width; ++i)
    {
        if (i < width - pos)
        {
            cout << ".";
        }
        else
        {
            cout << "*";
        }
        
    }
    cout << endl;
}
void prat5_last()
{
    int width, pos;
    cout << "请输入行数： ";
    cin >> width;
    pos = width - 1;
    for (int i = 0; i < width * 2; ++i)
    {
        if (pos)
        {
            Outstar(pos,width);
            cout << endl;
            pos--;
        }
        else
        {
            Outstar(0,width);
            cout << endl;
        }
    }
}
void pract10()
{
    int row;
    cin >> row;
    for (int i = 1; i <= row; ++i)
    {
        Outstar(i, row);
    }
}