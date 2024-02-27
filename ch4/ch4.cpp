#include <iostream>
#include "ch4.hpp"
using namespace std;

void string4_2();

int main()
{
    int sum;
    sum = add(8,5);
    cout << "sum = " << sum << endl; 
    // string4_2();
    // strings();
    // input_str();
    address_input();
}

void string4_2()
{
    char dog[6] = {'d', 'e', 'u',' ', 'v', 'p'};
    // char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'};
    char cat[8] = "fatessa";
    // cout << dog << endl;
    cout << cat << endl;
    cout << "The entire high-level implementation of the model " 
            "is contained in whisper.h and whisper.cpp.";
}