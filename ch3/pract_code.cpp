#include <iostream>

using namespace std;

 #define SEC 60
 #define MIN 60
 #define HOU 24

 void trans3_4();

 int main()
 {
    trans3_4();
    return 0;
 }

void trans3_4()
{
    long sec;
    int min, hou, day,seco;
    cout << "Enter the number of seconds: ";
    cin >> sec;
    seco = sec % SEC;
    min = sec / SEC % MIN;
    hou = sec / SEC / MIN % HOU;
    day = sec / SEC / MIN / HOU; 
    cout << sec << " seconds = " << day << " days, " << hou << " hours, " << min <<" minutes, " << seco <<" seconds." << endl;
}