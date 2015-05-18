#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node;


int main(){
	Node rootnode;
	Node *rootptr;
	cout<<sizeof(rootptr)<<endl;
	cout<<sizeof(int)<<endl;
	cout<<sizeof(rootnode)<<endl;	
}
