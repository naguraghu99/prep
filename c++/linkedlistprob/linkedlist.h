#pragma once
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(){
			data = 0;
			next = NULL;
		}
		~node(){}
};
void reverseList(node** head){
	node* prev = NULL;
	node* current = *head;
	node* next = NULL;
	while (NULL != current){
		next = current->next;
		previous = current;
		current = next;		
	}
	*head = previous;
}
void addToList(node** head,int data){
	node *temp = *head;
	if(temp == NULL){
		node *newnode = new node();
                newnode->data = data;
                newnode->next = NULL;
                *head = newnode;
	}else {
		while(temp->next != NULL){
			temp = temp->next;
		}
		node *newnode = new node();
                newnode->data = data;
                newnode->next = NULL;
		temp->next = newnode;	
	}
}
void eraseList(node **head){
	if(*head == NULL){
		cout<<"List is already empty"<<endl;
	}else {
		node *temp;
		while ((*head)->next != NULL){
			temp = *head;
			*head = (*head)->next;
			delete temp;
		}
		cout<<"Released the allocated memory !!!!"<<endl;
	}
	
	*head = NULL;
}
void joinList(node **node1,node** node2){
	if(*node1 == NULL){
		*node1 = *node2;
	}else{
		node* temp = *node1;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = *node2;
		*node2 = NULL;
	}
}


void reArrangeList(node **n,int data){
	//create two lists add elements in one list that are grater than
	//the pivoet element and lesser in the other
	//Once done point end of lesser to greater
	node *temp,*less,*greater;
	temp = NULL;
	less = NULL;
	greater = NULL;
	node *head = *n;
	while(head != NULL){
		cout<<"data: "<<head->data<<endl;
		if((head)->data < data){
			addToList(&less,(head)->data);
		}else if((head)->data > data){
			addToList(&greater,(head)->data);
		}
		head = (head)->next;
	}
	addToList(&less,data);
	joinList(&less,&greater);
	*n = less;	
}
void printList(node *n){
	while(n != NULL){
		cout<<n->data<<endl;
		n = n->next;
	}
}
int findPosition(node *n,int data){
	int position = 0;
	while(n != NULL){
		position++;
		if(data == n->data){
			break;		
		}
		n = n->next;
	}
	return position;
}
bool deleteKthElement(node **n,int todel){
	int position = 1;
	node* tmp = *n;
	while(NULL != tmp){
		cout<<"position : "<<position<<endl;
		if(position == todel){
			node* todelete;
			todelete = tmp->next;
			tmp->data = tmp->next->data;
			tmp->next = todelete->next;
			if(NULL != todelete)
				delete todelete;
			return true;	
		}
		tmp = tmp->next;
		position++;
	}
	return false;
}
