#include<iostream>
#include<cstring>
#include<vector>
#include <array>

using std::vector;
using std::array;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class cppboy
{
public:
    string name;
    int yz;
    
    cppboy(string,int);
    ~cppboy();
    const cppboy& pk(const cppboy& cboy) const
    {
        if (yz < cboy.yz) return cboy;
        return *this;
    }
    void show() const;
    void fun(int yz)
    {
        this->yz = yz;
    }
};

cppboy::cppboy(string name1,int i): name(name1),yz(i) 
{
    cout << "cppboy 构造……\n";
}

cppboy::~cppboy()
{
    cout << "cppboy 析构……\n";
}

void cppboy::show() const
{
    cout << name <<" 最帅" << endl;
}
int main()
{
    cppboy c1("Q",1),c2("W",2),c3("e",3),c4("r",4);
    const cppboy& d = c1.pk(c2).pk(c3).pk(c4);
    c1.fun(7);
    cout << "yz: " << c1.yz << endl;
    d.show(); 
    return 0;
}