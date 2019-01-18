#include<stdio.h>
#include<string.h>
char pre[27];
char in[27];
struct tree{
	struct tree *lchild;
	struct tree *rchild;
	char c;
};
typedef struct tree BiTNode;
BiTNode T[50];
void post(BiTNode *T)
{
	if(T->lchild!=NULL){
		post(T->lchild);
	}
	if(T->rchild!=NULL){
		post(T->rchild); 
	}
	printf("%c",T->c);
}//后序遍历二叉树；
int count=0;//静态数组中已经分配的结点个数
BiTNode *creat() 
{
	T[count].lchild=T[count].rchild=NULL;
	return &T[count++];
}//建立结点并返回地址 

BiTNode* build(int q1,int z1,int q2,int z2)
{        //利用先序和中序序列建立相应的二叉树，
         //其中q1,z1,q2,z2分别为先序、中序序列的起始、终止序号 
	BiTNode *root=creat();
	root->c = pre[q1];
	int root_next;
	for(int i=q2;i<=z2;i++)//少一个等号就无法运行 
	{
		if(in[i]==pre[q1])
		{
			root_next=i; 
			break;
		}
		
	}//找到根节点在中序序列中对应的位置 
	if(root_next!=q2)
	{
		root->lchild=build(q1+1,q1+root_next-q2,q2,root_next-1);
	}
	if(root_next!=z2)
	{
		root->rchild=build(q1+1+root_next-q2,z1,1+root_next,z2);
	}
	return root;	
}
int main()
{
	while(scanf("%s",pre)!=EOF)
	{
		count=0;	
		int l1,l2;
		scanf("%s",in);//得到序列
	    l1=strlen(pre);
		l2=strlen(in);
		BiTNode *T=build(0,l1-1,0,l2-1);
		post(T);
		printf("\n");
	}
	return 0;
}
	/*while(lengt(str[k])>1)
		{
			m=str[0][k];
			for(i=0;i<length(str[k]);i++)
			{
				if(m==str[k][i])break;
			}
			for(j=0;j<i;j++)
			{
				str[++k][j];
			}
		 } */
