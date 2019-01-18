#include<stdio.h>
int a[1000];
int main()
{
	int N,i;
	int count=0;
	while(scanf("%d",&N)!=EOF&&N!=0)
	{   
	    count=0;
		for(i=0;i<=N;i++)
		scanf("%d",&a[i]);
		for(i=0;i<N;i++)
		if(a[i]==a[N]) count++;
		printf("%d\n",count);
	}
	return 0;
}
