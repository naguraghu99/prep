#include <iostream>
using namespace std;

class Base {
	protected:
		int iData;
	public:
		Base() {
			iData = 10;
		}
};

class Derived1 : virtual public  Base {

};

class Derived2 : virtual public  Base {

};

class Derived3 : virtual public Derived1, virtual public Derived2 {
	public:
		int GetData() {
			return iData;
		}
};

int  main ()
{
	Derived3 obj;
	cout << obj.GetData() << endl;
}


