#include<iostream>
using namespace std;
 
void fun(int &x) 
{
     x = 50;;
}
int main()
{
    int a = 10;
    fun(a);
    cout << a<<endl;;
    return 0;
}
