#include<stdio.h>
int main()
{
	int n;
	
	int ans[1000];
	while(scanf("%d",&n)!=EOF&&n>0)
	{
		int i,j;
		int p=1,q=0;
		ans[0]=0;
		printf("0\n");
		for(i=1;i<n;i++)
		{
			int m=2*i-1;
			for(j=0;j<m;j++)
			{
				printf("%d ",ans[j]);
			}
			printf("%d %d\n",p+q,p+q+q);
			int tmp=p;
			p=p+q;
			q=tmp+q+q;
			ans[m]=p;
			ans[m+1]=q;
		}
	}
	return 0;
 } 
