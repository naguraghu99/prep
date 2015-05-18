#include<iostream>

using namespace std;

int main()

{

	int a=5;

	double b = 4.567;
	
	char c = 'b';
	int &ref=a;

	ref=c;

	cout << char(ref) << endl;
	cout << char(a) << endl;

}
