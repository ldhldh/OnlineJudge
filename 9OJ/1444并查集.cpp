#include<stdio.h>
#define N 10000001
int tree[N];
int sum[N];
int findroot(int x)
{
	if(tree[x]==-1)return x;
	else
	{
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<N;i++)
		{
		    tree[i]=-1;
		    sum[i]=1;
		}
		while(n--!=0)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a=findroot(a);
			b=findroot(b);
			if(a!=b)
			{
			    tree[a]=b;
			    sum[b]+=sum[a];	
			}
		}
		int max=1;
		for(int i=1;i<=N;i++)
		{
			if(tree[i]==-1&&sum[i]>max)max=sum[i];
		}
		printf("%d\n",max);
	}
	return 0;
}
