#include<iostream>
using namespace std;
 
int main()
{
   int i=10;
   int *ptr = NULL;
   ptr = &i;
   int &ref = *ptr;
   cout << ref;
}
