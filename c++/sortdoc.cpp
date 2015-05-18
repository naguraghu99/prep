#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <sstream>
#include <fstream>
using namespace std;
long GetTimeStampOfTheFile(string fileName){
	int location;
	location = fileName.find_last_of( "." );
	string tmp = fileName.substr(0,location);
	vector<string> tokens;
	std::istringstream iss(tmp);
	string token;
	while(getline(iss,token,'_'))
	{    
		string s = token;
		tokens.push_back(s);
	}
	std::string::size_type sz;     
	int size = tokens.size();
	string s = tokens[size-2];
	s += tokens[size-1];
	long timestamp =  atol(s.c_str());
//	cout<<"Time: "<<timestamp<<endl; 
	return timestamp;

}
int main() {
	vector<string> inputVec;
	map<long, vector<string> > timetofilemap;
	string input;
	int inputsize=0,i=0;
	//cout<<"Enter number of files to be sorted: ";
	//cin>>inputsize;
	cout<<"Enter all the files to be sorted "<<endl;
	string line;
	ifstream myfile ("example.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			cout << line << '\n';
			inputVec.push_back(line);
		}
		myfile.close();
	}
/*	while(i != inputsize){
		cin>>input;
		inputVec.push_back(input);
		input.clear();
		i++;
	}
*/	cout<<"Number of files to be started are : ";
	cout<<inputVec.size()<<endl;
	//Extract the time stamp from the file name
	//Insert the tume into sorttedSer and the timetoffilemap
	vector<long> sortedvec;
	vector<string>::iterator iter=inputVec.begin();
	for(;iter != inputVec.end();iter++){
		long time = GetTimeStampOfTheFile(*iter);
		cout<<(*iter)<<": "<<time<<endl;
		if(std::find(sortedvec.begin(), sortedvec.end(), time) == sortedvec.end()){
			sortedvec.push_back(time);
		}
		timetofilemap[time].push_back(*iter);
	}
	sort(sortedvec.begin(),sortedvec.end(),greater<long>());
	vector<long>::iterator it;
	vector<string> finalvec;
	cout<<"Sortted order-----------------------------------"<<endl;
	for(it=sortedvec.begin();it!=sortedvec.end();it++){
		cout<<(*it)<<endl;
		vector<string> tmpvec = timetofilemap[*it];
		vector<string>::iterator tmpiter = tmpvec.begin(); 
		cout<<tmpvec.size()<<endl;
		for(;tmpiter!=tmpvec.end();tmpiter++){
			finalvec.push_back(*tmpiter);
		}
	}
	vector<string>::iterator itr = finalvec.begin();
	for(;itr!=finalvec.end();itr++){
		cout<<*itr<<endl;
	}	
		
}
