#include<stdio.h>
int hash[1000001];
int main()
{
	long n,m;
	while(scanf("%ld %ld",&n,&m)!=EOF)
	//���ѭ����������&&0<n,m<1000000��Ϊʲô�����г�ʱ,
	//���ӵ�ѭ���������ﲻ�ᳬʱ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{
	//if(n<0||m<0||n>1000000||m>n)break; 
		long i;
		for(i=0;i<1000001;i++)
		hash[i]=0;
		for(i=1;i<=n;i++)
		{
			long x;
			scanf("%ld",&x);
			hash[x+500000]=1;
		}
		
		for(i=1000000;i>=0;i--)
		if(hash[i]==1)
		{
			printf("%ld",i-500000);
			if(--m!=0)
			printf(" ");
			else 
			{
			    printf("\n");
				break;	
			}
		} 
		
	}
	return 0;
} 
