#include <iostream>
using namespace std;

class Base {

	public:
	virtual ~Base(){};
};
class Der : public Base {};


int main()
{
    Base* base = new Der;
    Der* der = dynamic_cast<Der*>(base); // ERROR - Won't compile

    return 0;
}
