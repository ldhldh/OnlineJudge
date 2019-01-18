#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	int c;
	struct link *next;
}*linknode;
typedef struct link node;
int main()
{
	int n;
	linknode head,pre,p;
	while(scanf("%d",&n)!=EOF)
	{
		head=(linknode)malloc(sizeof(node));
		head->next=NULL;
		for(int i=0;i<n;i++)
		{
			linknode newnode=(linknode)malloc(sizeof(node));
			int x;
			scanf("%d",&x);
			newnode->c=x;
			pre=head;
			p=head->next;
			while(p)
			{
				if(newnode->c<p->c)break;
				pre=p;
				p=p->next;
			}
			pre->next=newnode;
			newnode->next=p;
		}
		p=head->next;
		printf("%d",p->c);
		while(p->next)
		{
			p=p->next;
			printf(" %d",p->c);
		}
		printf("\n");
	}
	return 0;
}
