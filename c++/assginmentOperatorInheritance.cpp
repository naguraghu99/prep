#include <iostream>
#include <string>
using namespace std;

class A{

public:
	string s;
	A & operator=(A &) {
		cout<<"Base class opertor = is called";
		return *this;
	}
};

class B:public A
{
	public:
		string s2;
/*		B &operator=(const B &b){
			cout<<"derived  class opertor = is called";
			s2  = b.s2;
	}*/
};

int main()
{
	B a1, a2;
	//if derived class doesn't overload the = operator then baseclass == operator overload is used
	a2 = a1;	
	return 0;
}
 
