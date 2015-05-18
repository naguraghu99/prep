#include <iostream>
using namespace std;
#include <map>
int getTotalNumberOfCoins(map<int,int> &relativeToRechargeMap)
{
	int result;
	map<int,int>::iterator iter = relativeToRechargeMap.begin();
	for(;iter != relativeToRechargeMap.end();iter++){
		result += iter->first;
	}

	return result;
}
int getRechargesObtained(map<int,int> &relativeToRechargeMap){
	int size = relativeToRechargeMap.size();
	int result = 0,count=0;
	map<int,int>::iterator iter = relativeToRechargeMap.begin();
	while(count<(size-1)&& iter != relativeToRechargeMap.end()){
		cout<<iter->second<<endl;
		result += iter->second;
		iter++;
		count++;
	}
	return result;
}
int main()
{
	//constraint 1 ≤ N,X,T ≤ 105
	int N,X,T;
	//Take the input from the user 
	//Calculate the total number of coins required for i relatives
	//Calulate he total number recharges obtained from i-1 relatives
	cin>>N;
	int count=0,relative,recharge;
	map<int,int> relativeToRechargeMap;
	if(N>=1 && N<=100000){
		while(count<N){
			cin>>relative;
			cin>>recharge;
			//if((relative >=1 && relative <=100000) &&(recharge >=1 && recharge <=100000)){
				relativeToRechargeMap[relative] = recharge;
			//}else {
			//	return 0;
			//}
			count++;
		} 
		int result = getTotalNumberOfCoins(relativeToRechargeMap)-getRechargesObtained(relativeToRechargeMap);
		cout<<result<<endl;
	}
    return 0;
}

