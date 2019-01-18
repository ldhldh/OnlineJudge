#include<stdio.h>
#include<iostream>
using namespace std;
struct Tnode{
	Tnode *lchild;
	Tnode *rchild;
	int c; 
}Tree[2017];
int loc;
Tnode *creat(){
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
int good;
void postOder(Tnode *T){
	if(good==0){
		printf("No");
	}
	else{
	if(T->lchild!=NULL){
	postOder(T->lchild);
	}
	if(T->rchild!=NULL){
		postOder(T->rchild);
	}
	printf("%d ",T->c);
	} 	
}
int str1[1001],str2[1001];

Tnode *Build(int s1,int e1,int s2,int e2){
	if(good==0){
		return NULL;
	}
	Tnode *root=creat();
	root->c=str1[s1];
	int i=e2+2;
	for(int k=s2;k<=e2;k++){
		if(str2[k]==str1[s1]){
				i=k;
				break;	
		}
	}
/*	while(str2[i]!=str1[s1]&&i<=e2){
		i++;
	}*/
	if(i==e2+2){
		good=0;
	}
	else{
	if(i!=s2&&good==1){
	    root->lchild=Build(s1+1,s1+i-s2,s2,i-1);
	}
	if(i!=e2&&good==1){
		root->rchild=Build(s1+1+i-s2,e1,i+1,e2);
	}
	}
	return root;	
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n>0&&n<1001){
		good=1;
		loc=0;
		for(int j=1;j<=n;j++){
			cin>>str1[j];
		}
		for(int j=1;j<=n;j++){
			cin>>str2[j];
		}
		Tnode *T=Build(1,n,1,n);
		postOder(T);
		printf("\n");
	}
	return 0;
}
