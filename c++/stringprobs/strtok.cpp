#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
	string input;
	cin>>input;
	//SubNetwork=803:MEID=803:URncFunction=803:ULocationArea=10683:UServiceArea=59341
	//Need to extract only UServiceArea's value
	char *fptr=NULL,*sptr = NULL,*stringptr;
	stringptr = new char[input.length()+1];
	strcpy(stringptr,input.c_str());
	fptr = strtok(stringptr,":");
	while(fptr){
		string s(fptr);
		size_t found = s.find("UServiceArea");
		if(found == string::npos){
			fptr = strtok(NULL,":");
		}else {
			cout<<fptr<<endl;
			sptr = strtok(fptr,"=");
			sptr = strtok(NULL,"=");
			cout<<sptr<<endl;
			break;
		}
	}	
}
