#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree{
	struct tree *lchild;
	struct tree *rchild;
	char c;
}Binode,*Bitree;
typedef struct tree node;

char str[101];
int loc=0;

int build (Bitree &T,int &loc,int n)
{
	if(loc==n)return 0;
	if(str[loc]=='#')
	{
		T=NULL;
		loc++;
	}
	else {
		T=(Bitree)malloc(sizeof(Binode));
		T->c=str[loc++];
		build (T->lchild,loc,n);
		build (T->rchild,loc,n);
	}
	return 0;
}
void Visit(node *T){  
    if(T->c != '#'){  
        printf("%c ",T->c);  
    }  
}  
void in(node *T)
{
	if(T->lchild!=NULL)
	{
		in(T->lchild);	
	}
     	
	
        Visit(T);
    if(T->rchild!=NULL)
	{
		in(T->rchild);	
        	
	}

}

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		int len=strlen(str);
		loc=0;
		node *T=NULL; 
		build(T,loc,len);
		in(T);
		printf("\n");
	}
	return 0;
}
