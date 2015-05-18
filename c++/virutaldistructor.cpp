#include<iostream>
 
using namespace std;
 
class base {
  public:
    base()     
    { cout<<"Constructing base \n"; }
     virtual ~base()
    { cout<<"Destructing base \n"; }     
};
 
class derived: public base {
  public:
    derived()     
    { cout<<"Constructing derived \n"; }
    ~derived()
    { cout<<"Destructing derived \n"; }
};
class myderived: public derived {
  public:
    myderived()     
    { cout<<"Constructing myderived \n"; }
    ~myderived()
    { cout<<"Destructing myderived \n"; }
};
 
int main(void)
{
  myderived *d = new myderived();  
  base *b = d;
  delete b;
  return 0;
}
