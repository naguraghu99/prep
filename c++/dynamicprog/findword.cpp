/*
   Given a matrix of characters and  word, Aim is to check if the word is present in the matrix
   1) All 8 nighbours should be considered
   2) Need to chech the boundry conditions

   Things To Be Done:
   1. Dynamically create the matrics and populate the date from the user, Form a hash map too
   2. Get the word to be found from the user
   3. Call the function with the matrix and the word to be found, should return a bool
   4. Use recurssion to to find the next letter
   5. If not found return -1
   6. In order to avoid duplicate we will have another matrix with flag bit set
   0 - not accounted
   1 - accounted already 
 */
#include "findword.h"
int m,n;
int **indexMatrix;
bool findUp(char** charmatrix,string tofind,int stringindex,int i,int j){
	i--;
	if(i>=0&& i<m && j<n){
		cout<<"Inside foundUp--"<<charmatrix[i][j]<<" trying to find "<<tofind[stringindex]<<endl;
		if(charmatrix[i][j] == tofind[stringindex]){
			stringindex++;
			if(tofind.length() == stringindex)
				return true;
			return findUp(charmatrix,tofind,stringindex,i,j);
		}else {
			cout<<"Could not find "<<tofind[stringindex]<<endl;
			return false;
		}
	}else {
		return false;
	}
}
bool findDown(char** charmatrix,string tofind,int stringindex,int i,int j){
	i++;
	if(i>=0&& i<m && j<n){
		cout<<"Inside founddown--"<<charmatrix[i][j]<<" trying to find "<<tofind[stringindex]<<endl;
		if(charmatrix[i][j] == tofind[stringindex]){
			stringindex++;
			if(tofind.length() == stringindex)
				return true;
			return findDown(charmatrix,tofind,stringindex,i,j);
		}else {
			cout<<"Could not find "<<tofind[stringindex]<<endl;
			return false;
		}
	}else {
		return false;
	}
}
bool findLeft(char** charmatrix,string tofind,int stringindex,int i,int j){
	j--;
	if(j>=0 && i<m && j<n){
		cout<<"Inside foundleft--"<<charmatrix[i][j]<<" trying to find "<<tofind[stringindex]<<endl;
		if(charmatrix[i][j] == tofind[stringindex]){
			stringindex++;
			if(tofind.length() == stringindex)
				return true;
			return findLeft(charmatrix,tofind,stringindex,i,j);

		}else {
			cout<<"Could not find "<<tofind[stringindex]<<endl;
			return false;
		}
	}else {
		return false;
	}
}
bool findRight(char** charmatrix,string tofind,int stringindex,int i,int j){
	j++;
	if(j>=0&& i<m && j<n){
	 	cout<<"Inside foundRight--"<<charmatrix[i][j]<<" trying to find "<<tofind[stringindex]<<endl;
		if(charmatrix[i][j] == tofind[stringindex]){
			stringindex++;
			if(tofind.length() == stringindex)
				return true;
			return findRight(charmatrix,tofind,stringindex,i,j);
		}else {
			cout<<"Could not find "<<tofind[stringindex]<<endl;
			return false;
		}
	}else {
		return false;
	}
}
bool findLUp(char** charmatrix,string tofind,int stringindex,int i,int j){
	i--;
	j--;
	if(j>=0 && i>=0 && i<m && j<n){
		cout<<"Inside foundLup --"<<charmatrix[i][j]<<" trying to find "<<tofind[stringindex]<<endl;
		if(charmatrix[i][j] == tofind[stringindex]){
			stringindex++;
			if(tofind.length() == stringindex)
				return true;
			return findLUp(charmatrix,tofind,stringindex,i,j);
		}else {
			cout<<"Could not find "<<tofind[stringindex]<<endl;
			return false;
		}
	}else {
		return false;
	}
}
bool findLDown(char** charmatrix,string tofind,int stringindex,int i,int j){
	i++;
	j--;
	if(j>=0 && i>=0 && i<m && j<n){
		cout<<"Inside foundLDown--"<<charmatrix[i][j]<<" trying to find "<<tofind[stringindex]<<endl;
		if(charmatrix[i][j] == tofind[stringindex]){
			stringindex++;
			if(tofind.length() == stringindex)
				return true;
			return findLDown(charmatrix,tofind,stringindex,i,j);
		}else {
			cout<<"Could not find "<<tofind[stringindex]<<endl;
			return false;
		}
	}else {
		return false;
	}
}
bool findRUp(char** charmatrix,string tofind,int stringindex,int i,int j){
	i--;
	j++;
	if(j>=0 && i>=0 && i<m && j<n){
		cout<<"Inside foundRUP--"<<charmatrix[i][j]<<" trying to find "<<tofind[stringindex]<<endl;
		if(charmatrix[i][j] == tofind[stringindex]){
			stringindex++;
			if(tofind.length() == stringindex)
				return true;
			return findRUp(charmatrix,tofind,stringindex,i,j);
		}else {
			cout<<"Could not find "<<tofind[stringindex]<<endl;
			return false;
		}
	}else {
		return false;
	}
}
bool findRDown(char** charmatrix,string tofind,int stringindex,int i,int j){
	i++;
	j++;
	if(j>=0 && i>=0 && i<m && j<n){
		cout<<"Inside foundRDown--"<<charmatrix[i][j]<<" trying to find "<<tofind[stringindex]<<endl;
		if(charmatrix[i][j] == tofind[stringindex]){
			stringindex++;
			if(tofind.length() == stringindex)
				return true;
			return findRDown(charmatrix,tofind,stringindex,i,j);
		}else {
			cout<<"Could not find "<<tofind[stringindex]<<endl;
			return false;
		}
	}else {
		return false;
	}
}

int findWord(char** charmatrix,string tofind){
	int i = 0,j=0,stringindex = 0;
	int count = 0;
	multimap<int,int> startIndexMap;
	for(i =0;i<m;i++){
		bool ifbreak = false;
		for(j=0;j<n;j++){
			if(charmatrix[i][j] == tofind[0])
			{
				cout<<charmatrix[i][j]<<i<<":"<<j<<endl;
			        startIndexMap.insert(std::pair<int,int>(i,j));
			}
		}
	}
	/*if(stringindex == tofind.length()){
		count++;
		return count;
	}*/	
	multimap<int,int>::iterator it = startIndexMap.begin();
	for(;it!=startIndexMap.end();it++){
		i = it->first;
		j = it->second;
		stringindex++;
		cout<<"For "<<i<<","<<j<<"  count--"<<count<<endl;
		if(findUp(charmatrix,tofind,stringindex,i,j)){
			 count++;
		}
		if(findDown(charmatrix,tofind,stringindex,i,j)){
			 count++;
		}
		if(findLeft(charmatrix,tofind,stringindex,i,j)){
			 count++;
		}
		if(findRight(charmatrix,tofind,stringindex,i,j)){
			 count++;
		}
		if(findLUp(charmatrix,tofind,stringindex,i,j)){
			 count++;
		}
		if(findLDown(charmatrix,tofind,stringindex,i,j)){
			 count++;
		}
		if(findRUp(charmatrix,tofind,stringindex,i,j)){
			 count++;
		}
		if(findRDown(charmatrix,tofind,stringindex,i,j)){
			 count++;
		}
		stringindex =0;
	}
	return count;
}
template <typename T>
T **AllocateDynamicArray(int rows,int columns){
	T **dynamicArray;
	dynamicArray = new T*[rows];
	for(int i=0;i<rows;i++){
		dynamicArray[i] = new T [columns];
	}
	return dynamicArray;
}

template <typename T>
void freeDynamicArray(T** dArray){
	delete [] *dArray;
	delete [] dArray;
}
bool isPalindrome(string &input){
	if (input == string(input.rbegin(), input.rend())) {
		cout << input << " is a palindrome";
		return true;
	}
	return false;
}
int main() {
	string toFind,line;

	map<char,bool> alphaToPresence;	
	cout<<"Enter the number of rows in the matrix: ";
	cin>>m;
	cout<<"Enter the number of columns in the matrix: ";
	cin>>n;
	cout<<"Enter the word to be searched: ";
	cin>>toFind;

	char **charmatrix = AllocateDynamicArray<char>(m,n);
	indexMatrix = AllocateDynamicArray<int>(m,n);
	/*ifstream in;
	in.open("Characters.txt");
	if(!in){
		cout<<"Cannot open the input file"<<endl;
		return 0;
	}
	int i=0,j=0;
	string tmp;
	while(in.good()){
		while(getline(in,line)){
			j=0;
			for (unsigned k=0; k<line.length(); k++)
			{

				char c = line.at(k);
				if(c != ' '){
					charmatrix[i][j] = c;
					j++;
				}
			}
			i++;
		}
	}*/
	for(int i=0; i<m;i++){
		for(int j=0;j<n;j++){
			char c;
			cin>>c;
			charmatrix[i][j] = c;	
		}
	}
	for(int a=0; a<m;a++){
		for(int b=0;b<n;b++){
			alphaToPresence[charmatrix[a][b]] = 1;
		}
	}
	string::iterator it = toFind.begin();
	try{
		for(;it!= toFind.end();it++){
			char c = (char)(*it);
			if(alphaToPresence.find(c) == alphaToPresence.end()){
				throw "Word is not present in the matrix";
			}
		}
	}catch(const char *excp){
		cout<<excp<<endl;
		return 0;
	}

	int count = findWord(charmatrix,toFind);
	//Now if there is no exception we need to iterate through the matrix 
	if(toFind.length() != 1 && isPalindrome(toFind)){
		count = count/2;
	}		
	cout<<"Bingo Found the word "<< count<<" times"<<endl;
} 
