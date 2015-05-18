//DNA Sequence Template
#include<iostream>
#include<string>
// Also assumed that string will have only A and G
//You can include any other header files also if needed which is supported by standard c++ compiler
//idea is finding the i,j such that we have maximum g in the resulting string
//example: 
/*

   (0,0) String -> {0}

   (0,1)                    -> {0,1} -> 0, {1}

   (0,2)                    -> {0,1,2}

                                                                -> 0,{1,2}

                                                                -> 0,1,{2}

   (0,3)                    -> {0,1,2,3}

                                                                -> 0,{1,2}  not needed already processed

                                                                -> 0,{1,2,3}

                                                                -> 0,1,{2,3}

                                                                -> 0,1,2,{3}

   (0,4)                    -> {0,1,2,3,4}

                                                                -> 0,{1,2} not needed already processed

                                                                -> 0,{1,2,3} not needed already processed

                                                                -> 0,{1,2,3,4}

                                                                -> 0,1,{2,3} not needed already processed

                                                                -> 0,1,{2,3,4}

                                                                -> 0,1,2,{3,4}

                                                                -> 0,1,2,3,{4}  

*/
using namespace std;

int calculateMax(string s,int i,int j){
	//here we will swap 
	//A->G
	//G->A with in the interval [i,j]
	//then count number of G and return them
	string locals;
	for(int index1 = 0;index1<i;index1++){
		locals+=s[index1];
	}
	for(int index = i;index<=j;index++){
		if(s[index] == 'G'){
			s[index] = 'A';
		}else {
			s[index] = 'G';
		}
		locals += s[index];
	}
	int count = 0;
	for(int c=0;c<(int)s.length();c++){
		if(locals[c] == 'G'){
			count++;
		}
	}
//	cout<<"string "<<locals<<" i,j: "<<i<<","<<j<<endl;
	return count;
}
int solveDNA(string &s,int N)
{
	if(N<0 || N >1000000){
		return -1;
	}
	//this is global i which will be always 0
	//int i=0;
	//j will run from 0 to N-1
	int j;
	int globalMax = 0;
	int locali = 0;
	int iout,jout;
	for(j=0;j<N;j++){
		//this is for forming subsets with in the intervals
		locali = 0;
		int localMax=0;
		for(locali = 0; locali<=j;locali++){
			string tmp = s;
			localMax = calculateMax(tmp,locali,j);
			if(globalMax < localMax){
				globalMax = localMax;
				iout = locali;
				jout = j;
			}
		}
	}
	cout<<"i: "<<iout<<"j: "<<jout<<endl;
	//Write your code here

	return globalMax;
}

int main( int argc, char *argv[] ) {

	int N;
	string str;
	cin>>N;
	cin>>str;
	
	cout<<solveDNA(str,N);

	return 0;
}
