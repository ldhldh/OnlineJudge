#include<stdio.h>
int k[100];
int main()
{
	long long a,b;
	int m;
	while(scanf("%d",&m)!=0)
	{
		if(m==0)break;
		scanf("%lld %lld",&a,&b);
		int i=0;
		a+=b;
		do{
			k[i++]=a%m;
			a/=m;
		}while(a!=0);
		for(i=i-1;i>=0;i--)
		{
			printf("%d",k[i]);
		}
		printf("\n");
	}
	return 0;
 } 
