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
}//���������������
int count=0;//��̬�������Ѿ�����Ľ�����
BiTNode *creat() 
{
	T[count].lchild=T[count].rchild=NULL;
	return &T[count++];
}//������㲢���ص�ַ 

BiTNode* build(int q1,int z1,int q2,int z2)
{        //����������������н�����Ӧ�Ķ�������
         //����q1,z1,q2,z2�ֱ�Ϊ�����������е���ʼ����ֹ��� 
	BiTNode *root=creat();
	root->c = pre[q1];
	int root_next;
	for(int i=q2;i<=z2;i++)//��һ���Ⱥž��޷����� 
	{
		if(in[i]==pre[q1])
		{
			root_next=i; 
			break;
		}
		
	}//�ҵ����ڵ������������ж�Ӧ��λ�� 
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
		scanf("%s",in);//�õ�����
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
