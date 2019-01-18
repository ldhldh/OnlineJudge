#include<stdio.h>
int mark[10001]={0};//0表示素数，1表示非素数 
int su[5000];
int size=0;	
void init()
{                 //素数筛法 
	for(int i=2;i<10000;i++)
	{
		if(mark[i]==1)continue;
		su[size++]=i;
		for(int j=i*i;j<=10000;j+=i)
		{
			mark[j]=1;
		}
	}
}
int main()
{
	init();
	/*for(int i=0;i<size;i++)
	printf("%d ",su[i]);*/
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int flag=0;
		for(int i=0;i<size;i++)
		{
			if(su[i]<n&&su[i]%10==1)
			{
				if(flag==0)
				{
				    printf("%d",su[i]);
				    flag=1;
				}
				else 
				printf(" %d",su[i]);
			}
		 }
		 if(flag==0)printf("-1");
		 printf("\n");
	}
	return 0;
}
