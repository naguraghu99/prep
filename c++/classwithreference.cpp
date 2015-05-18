#include<iostream>
using namespace std;
  
class Test
{
    int x;
    int &ref;
public:
    Test (int i):x(i), ref(x) {}
    void print() { cout << ref<<endl;; }
    void setX(int i) { x = i; } 

    Test & operator= (const Test &t){
	x = t.x;
	ref = t.ref;	
    }
};
  
int main()
{
    Test t1(10);
    Test t2(20);
    Test t3(t1);
    t2 = t1;
    t2.print();
    t1.setX(40);
    t2 = t1;
    t2.print();
    t3.print();
    return 0;
}

