#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
int main()
{
	string input,tmp;
	bool firstUpper = false;
	bool firstLower = false;
	cout<<"Enter the line u wish to enter: ";
	getline (cin,input);
	char *line = new char[input.length()+1];
	strcpy(line,input.c_str());
	cout<<line<<" size : "<< input.length()<<endl;
	if(isalpha(line[0])){
		if(islower(line[0]) == 0){
			tmp += tolower(line[0]);
			firstUpper = true;
		}else if(islower(line[0])){
			tmp += toupper(line[0]);
			firstLower = true;
		}
		
	}
	for(int i=1;i<input.length();i++){
		if(firstUpper){
			
			if(isalpha(line[i])){
				if(i%2 != 0){
					tmp += toupper(line[i]);
				}else {
					tmp += tolower(line[i]);
				}
			}else if (line[i] == ' ') {
				tmp += line[i];
			}
		}else if(firstLower){
			if(isalpha(line[i])){
                                if(i%2 != 0){
                                        tmp += tolower(line[i]);
                                }else {
                                        tmp += toupper(line[i]);
                                }
                        }else if (line[i] == ' ') {
                                tmp += line[i];
                        }
		}
	}
	cout<<tmp<<endl;
}
