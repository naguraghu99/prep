#include<iostream>
using namespace std;
 
int &fun()
{
    static int x = 10;
    cout<<"value of x: "<<x<<endl;
    return x;
}
int main()
{
    const int i = 10;
    fun() = 30;
    cout << fun() <<endl;
    return 0;
}
