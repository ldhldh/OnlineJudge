#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		double N=1;
		for(int i=1;i <=n ;i++)
		{
			N=N*i;
		}
		printf("%.0f\n",N);
	}
	return 0;
 } 
