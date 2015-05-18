#include<iostream>
using namespace std;
 
class Test
{
    int *ptr;
public:
    Test (int i = 0)      { ptr = new int(i); }
    void setValue (int i) { *ptr = i; }
    void print()          { cout << *ptr << endl; }
    
     //copy constructor
     Test(const Test &t){
	     cout<<"Copy constructor is invoked "<<endl;
	     if(this != &t)
		     *ptr = *(t.ptr);
     }
    //asignment operator overload 
    Test & operator = (const Test &t);
};
 
Test & Test::operator = (const Test &t)
{
	     cout<<"Assignment  operator  is invoked "<<endl;
   // Check for self assignment
   if(this != &t)
     *ptr = *(t.ptr);
 
   return *this;
}
 
int main()
{
    Test t1(5);
    Test t2;
    t2 = t1;
    t1.setValue(10);
    Test t3(t1);
    t2.print();
    t3.print();
    return 0;
}
