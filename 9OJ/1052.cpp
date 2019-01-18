#include<stdio.h>
int a[200];
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		int j=0,x;
		scanf("%d",&x);
		for(i=0;i<n;i++)
		{
			if (a[i]==x)
			{
			j++;
			printf("%d\n",i);
			break;
		    }
		}
		if(j==0)
		printf("-1\n");
	}
	return 0;
}
