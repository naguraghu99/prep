#include <iostream>
using namespace std;

int main () {
	int num;
	int *numptr;
	num = 42;
	numptr  = &num;
	cout<<*numptr<<"______"<<num<<endl;
	
}
