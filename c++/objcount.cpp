#include <iostream>
#include <map>
using namespace std;
template <class Derived>
class InstanceCounter
{
	static int count;

	protected:

	InstanceCounter()
	{
		++count;
	}

	~InstanceCounter()
	{
		--count;
	}

	public:

	static int instance_count()
	{
		return count;
	}
};

template <class Derived>
int InstanceCounter<Derived>::count = 0;

class Test : public InstanceCounter<Test>
{
};
class sample:public InstanceCounter<sample>
{};
int main()
{
	Test x;
	std::cout << Test::instance_count() << std::endl;
	{
		Test *y = new Test();
		Test z;
		std::cout << Test::instance_count() << std::endl;
		delete y;
		std::cout << Test::instance_count() << std::endl;
	}
	std::cout << Test::instance_count() << std::endl;
	sample s1;
	sample *s2 = new sample();
	cout<<sample::instance_count()<<endl;
}
