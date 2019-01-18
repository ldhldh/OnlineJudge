#include <stdio.h>
#include <string.h>
struct binaryTree{
	struct binaryTree *lchild;
	struct binaryTree *rchild;
	int m;
};
typedef struct binaryTree node;
node T[200];
int count=0;
node *creat()
{
	T[count].lchild=T[count].rchild=NULL;
	return &T[count++];
}
node *insert(node *T,int x)
{  //���ز���λ�� 
	if(T==NULL)
	{
		T=creat();
		T->m=x;
		return T;
	}
	else if(x<T->m)	
	{
	    T->lchild=insert(T->lchild,x);	
	 } 
	    	
	else if(x>T->m) 
	{  
	    T->rchild=insert(T->rchild,x);
	   }    
	return T;
}
void pre(node *T)//ǰ����� 
{
	printf("%d ",T->m);
	if(T->lchild!=NULL)
	{
		pre(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		pre(T->rchild);
	}
}
void in(node *T)//�������
{
	if(T->lchild!=NULL)
	{
		in(T->lchild);
	}
	printf("%d ",T->m);
	if(T->rchild!=NULL)
	{
		in(T->rchild);
	}
}
void post(node *T)//�������
{
	if(T->lchild!=NULL)
	{
		post(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		post(T->rchild);
	}
	printf("%d ",T->m);
}
int main()
{
	int i,n,x;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		node *T=NULL;
		for(i=0;i<n;++i)
		{
			scanf("%d",&x);
			T=insert(T,x);	
			}
		//�������������� 
		pre(T);
		printf("\n");
		in(T);
		printf("\n");
		post(T);
		printf("\n");
	}
	return 0;
}
