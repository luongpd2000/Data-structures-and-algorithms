#include<bits/stdc++.h>
using namespace std;

// theo th? t? tru?c (Node-Left-Right):
int d=0;
struct node{
	node *left,*right;
	int data;
};
typedef node *tree;

node* createNode(int n){
	node *p=new node;
	p->left=NULL; 
	p->right=NULL;
	p->data=n;
	return p;
}
void insertTree(tree &t,node *p){
	if(t!=NULL){
		if(t->data>p->data) insertTree(t->left,p);
		else insertTree(t->right,p);
	}
	else{
		t=p; 
	}
}
bool isMid(tree t){	// ko c� 2 node con 
	if(t->left!=NULL || t->right!=NULL) return true;
	return false;
}
void printf(tree t){
	if(t==NULL) return;
	if(isMid(t)) d++;
	printf(t->left);
	printf(t->right);
	
}
main(){
	int t; cin>>t;
	while(t--){
		int n,a;
		d=0;
		cin>>n; tree k=NULL;
		while(n--){
			cin>>a;
			node *p=createNode(a);
			insertTree(k,p);
		}
		printf(k);
		cout<<d<<endl;
	}

}