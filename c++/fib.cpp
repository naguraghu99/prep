#include <iostream>
using namespace std;
#include <map>
int fib(int input,map<int,int> &fibmap){
	if(input <= 1){
		return input;
	}else if(fibmap.find(input) != fibmap.end()){
		cout<<"found ->fib"<<input<<"="<<fibmap[input]<<endl;
		return fibmap[input];
	}else {
		fibmap[input]=fib(input-1,fibmap)+fib(input-2,fibmap);
		return fib(input-1,fibmap)+fib(input-2,fibmap);
	}
	
}
int main() {
	int input,result;
	map<int,int> fibmap;
	while(1){
		input=0,result=0;
		cout<<"Enter the nth element  "<<endl;
		cin>>input;
		if(fibmap.find(input) != fibmap.end()){
			cout<<"fib"<<input<<"--"<<fibmap[input]<<endl;
		}else {
			for(int i=0;i<input;i++){
				result = fib(i,fibmap);
			}
			fibmap[input]=result;
			cout<<result<<endl;
		}
	}
	return 0;
}
