#include <iostream>
#include "linkedlist.h"
using namespace std;
	
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
        cout<<"Enter the pivot element: ";
        cin>>data;
        reArrangeList(&start,data);
        cout<<"***************************"<<endl;
        printList(start);
        cout<<"*****Pivot Element is located at : "<<findPosition(start,data)<<endl;
        eraseList(&start);
                
}

