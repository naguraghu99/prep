#include<iostream>
#include "linkedlist.h"
int main(){
	node *start = NULL;
	int data;
	int count;
	cout<<"Enter the number of elements you want to enter: ";
	cin>>count;
	while(count>0){
		cout<<"Enter the number: ";
		cin>>data;
		addToList(&start,data);
		data = 0;
		count--;
	}
	printList(start);
	reverseList(&start);
	printList(start);	
	/*cout<<"Enter the pivot element: ";
	cin>>data;
	reArrangeList(&start,data);
	cout<<"***************************"<<endl;
	printList(start);
	cout<<"*****Pivot Element is located at : "<<findPosition(start,data)<<endl;
	*/
	//delete the kth element in the list
	cout<<"Enter the kth element u wish to delete: ";
		
	int todel;
	cin>>todel;
	if(deleteKthElement(&start,todel)){
		cout<<"Successfully deleted the "<<todel<<"th node"<<endl;
		printList(start);	
	}else {
		cout<<"Failed to delete"<<endl;
	}
	//eraseList(&start);
		
}
