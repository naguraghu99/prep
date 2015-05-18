#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};
Base::~Base(){
	std::cout << "~Base() is called" <<std::endl;
}
 
class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed"<<std::endl;
    }
};
 
int main()
{
    Base *b=new Derived();
    delete b;
    return 0;
}
