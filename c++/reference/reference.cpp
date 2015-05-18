#include<iostream>
using namespace std;
 
int main()
{
  int x = 10;
  int y = 50; 
  // ref is a reference to x.
  int& ref = x;
 
  // Value of x is now changed to 20
  ref = 20;
  cout << "x = " << x << endl ;
  cout << "ref = " << ref << endl ;
 
  // Value of x is now changed to 30
  x = 30;
  ref = y;
  cout << "x = " << x << endl ;
  cout << "ref = " << ref << endl ;
 
  return 0;
}
